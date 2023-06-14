#include "include/lexer.h"
#include <stdlib.h>
#include <ctype.h>

lexer_js* init_lexer(char* src){
    lexer_js* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->i = 0;
    lexer->c = src[lexer->i];
    return lexer;
}

token_js* lexer_next_token(lexer_js* lexer)
{
    return init_token(0, endOfFile);
}