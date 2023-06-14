#ifndef LEXER_H
#define LEXER_H 

typedef struct LEXER_STRUCT
{
    char* src;
    char c;
    unsigned int i;
} lexer_js;

lexer_js* init_lexer(char* src);

#endif