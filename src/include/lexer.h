#ifndef LEXER_H
#define LEXER_H 

#include "token.h"

typedef struct LEXER_STRUCT
{
    char* src;
    char c;
    unsigned int i;
} lexer_js;

lexer_js* init_lexer(char* src);

token_js* lexer_next_token(lexer_js* lexer);

#endif