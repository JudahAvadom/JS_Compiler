#ifndef LEXER_H
#define LEXER_H 

#include <stdio.h>
#include "token.h"

typedef struct LEXER_STRUCT
{
    char* src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_js;

lexer_js* init_lexer(char* src);

token_js* lexer_parse_id(lexer_js* lexer);

void lexer_advance(lexer_js* lexer);

token_js* lexer_advance_current(lexer_js* lexer, int type);

void lexer_skip_whitespace(lexer_js* lexer);

token_js* lexer_parse_string(lexer_js* lexer);

token_js* lexer_next_token(lexer_js* lexer);

#endif