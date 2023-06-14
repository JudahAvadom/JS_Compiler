#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "include/lexer.h"
#include "include/token.h"

lexer_js* init_lexer(char* src){
    lexer_js* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];
    return lexer;
}

void lexer_advance(lexer_js* lexer){
    if (lexer->i < lexer->src_size && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

token_js* lexer_advance_current(lexer_js* lexer, int type){
    char* value = calloc(2, sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';
    token_js* token = init_token(value, type);
    lexer_advance(lexer);
    return token;
}

token_js* lexer_next_token(lexer_js* lexer)
{
    while (lexer->c != '\0')
    {
        switch (lexer->c)
        {
            case '(': return lexer_advance_current(lexer, parenL);
            default: 
                printf("[Lexer]: Unexpected character `%c` (%d)\n", lexer->c, (int)lexer->c); exit(1); 
                break;
        }
    }
    return init_token(0, endOfFile);
}