#include <stdio.h>
#include <string.h>
#include "s2html_event.h"
#include "s2html_conv.h"

int main(int argc, char *argv[])
{
	FILE *sfp, *dfp;
	pevent_t *event;
	int line_number = 1;
	int enable_line = 0;

	/* Usage check */
	if(argc < 3)
	{
		printf("USAGE : ./source_to_html <src_file.c> <output.html> <-n>\n");
		return 1;
	}

	/* Check -n option */
	if(argc == 4 && strcmp(argv[3], "-n") == 0)
	{
		enable_line = 1;
	}

	/* Open source file */
	if((sfp = fopen(argv[1], "r")) == NULL)
	{
		printf("Error opening source file\n");
		return 2;
	}

	/* Open destination file */
	if((dfp = fopen(argv[2], "w")) == NULL)
	{
		printf("Error creating output file\n");
		fclose(sfp);
		return 3;
	}

	/* Start HTML */
	html_begin(dfp, HTML_OPEN);

	/* Add first line number if enabled */
	if(enable_line)
		fprintf(dfp, "<span style=\"color:red;\">%d </span>", line_number);

	/* Process file */
	do
	{
		event = get_parser_event(sfp);

		/* Print line numbers */
		if(enable_line && event->type == PEVENT_REGULAR_EXP)
		{
			for(int i = 0; event->data[i]; i++)
			{
				if(event->data[i] == '\n')
				{
					source_to_html(dfp, event);
					line_number++;
					fprintf(dfp, "<span style=\"color:red;\">%d </span>", line_number);
					goto next;
				}
			}
		}

		source_to_html(dfp, event);

		next:
		;
	} while(event->type != PEVENT_EOF);

	/* End HTML */
	html_end(dfp, HTML_CLOSE);

	printf("Conversion to HTML file done successfully\n");

	fclose(sfp);
	fclose(dfp);

	return 0;
}