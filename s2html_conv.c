#include <stdio.h>
#include "s2html_event.h"
#include "s2html_conv.h"

/* 🔥 NEW FUNCTION: Safe HTML printing */
void print_safe(FILE *fp, char *data)
{
	for(int i = 0; data[i]; i++)
	{
		switch(data[i])
		{
			case '<': fprintf(fp, "&lt;"); break;
			case '>': fprintf(fp, "&gt;"); break;
			case '&': fprintf(fp, "&amp;"); break;
			case '\t': fprintf(fp, "    "); break;
			default: fputc(data[i], fp);
		}
	}
}

/* HTML beginning */
void html_begin(FILE* dest_fp, int type)
{
	fprintf(dest_fp, "<!DOCTYPE html>\n");
	fprintf(dest_fp, "<html lang=\"en-US\">\n");
	fprintf(dest_fp, "<head>\n");
	fprintf(dest_fp, "<title>source2html</title>\n");
	fprintf(dest_fp, "<meta charset=\"UTF-8\">\n");
	fprintf(dest_fp, "<link rel=\"stylesheet\" href=\"styles.css\">\n");
	fprintf(dest_fp, "</head>\n");

	fprintf(dest_fp, "<body style=\"background-color:black; color:white;\">\n");
	fprintf(dest_fp, "<pre>\n");
}

/* HTML ending */
void html_end(FILE* dest_fp, int type)
{
	fprintf(dest_fp, "</pre>\n");
	fprintf(dest_fp, "</body>\n");
	fprintf(dest_fp, "</html>\n");
}

/* Core conversion */
void source_to_html(FILE* fp, pevent_t *event)
{
	switch(event->type)
	{
		case PEVENT_PREPROCESSOR_DIRECTIVE:
			fprintf(fp,"<span class=\"preprocess_dir\">");
			print_safe(fp, event->data);
			fprintf(fp,"</span>");
			break;

		case PEVENT_MULTI_LINE_COMMENT:
		case PEVENT_SINGLE_LINE_COMMENT:
			fprintf(fp,"<span class=\"comment\">");
			print_safe(fp, event->data);
			fprintf(fp,"</span>");
			break;

		case PEVENT_STRING:
			fprintf(fp,"<span class=\"string\">");
			print_safe(fp, event->data);
			fprintf(fp,"</span>");
			break;

		case PEVENT_HEADER_FILE:
			fprintf(fp,"<span class=\"header_file\">");
			if(event->property == USER_HEADER_FILE)
			{
				fprintf(fp,"\"");
				print_safe(fp, event->data);
				fprintf(fp,"\"");
			}
			else
			{
				fprintf(fp,"&lt;");
				print_safe(fp, event->data);
				fprintf(fp,"&gt;");
			}
			fprintf(fp,"</span>");
			break;

		case PEVENT_NUMERIC_CONSTANT:
			fprintf(fp,"<span class=\"numeric_constant\">");
			print_safe(fp, event->data);
			fprintf(fp,"</span>");
			break;

		case PEVENT_RESERVE_KEYWORD:
			if(event->property == RES_KEYWORD_DATA)
				fprintf(fp,"<span class=\"reserved_key1\">");
			else
				fprintf(fp,"<span class=\"reserved_key2\">");

			print_safe(fp, event->data);
			fprintf(fp,"</span>");
			break;

		case PEVENT_ASCII_CHAR:
			fprintf(fp,"<span class=\"ascii_char\">");
			print_safe(fp, event->data);
			fprintf(fp,"</span>");
			break;

		case PEVENT_REGULAR_EXP:
		case PEVENT_EOF:
			print_safe(fp, event->data);
			break;

		default:
			print_safe(fp, event->data);
			break;
	}
}