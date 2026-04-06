#ifndef S2HTML_EVENT_H
#define S2HTML_EVENT_H

#include <stdio.h>

/* Event data properties */
#define USER_HEADER_FILE        1
#define STD_HEADER_FILE         2
#define RES_KEYWORD_DATA        3
#define RES_KEYWORD_NON_DATA    4

#define PEVENT_DATA_SIZE 1024

/* Parser event types */
typedef enum
{
    PEVENT_NULL,
    PEVENT_PREPROCESSOR_DIRECTIVE,
    PEVENT_RESERVE_KEYWORD,
    PEVENT_NUMERIC_CONSTANT,
    PEVENT_STRING,
    PEVENT_HEADER_FILE,
    PEVENT_REGULAR_EXP,
    PEVENT_SINGLE_LINE_COMMENT,
    PEVENT_MULTI_LINE_COMMENT,
    PEVENT_ASCII_CHAR,
    PEVENT_EOF
} pevent_e;

/* Event structure */
typedef struct
{
    pevent_e type;     // Event type
    int property;      // Additional info (like keyword type, header type)
    int length;        // Length of data
    char data[PEVENT_DATA_SIZE]; // Parsed content
} pevent_t;

/* Function prototype */
pevent_t *get_parser_event(FILE *fp);

#endif
/**** End of file ****/