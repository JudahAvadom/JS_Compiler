#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "include/lexer.h"
#include "include/token.h"

lexer_js *init_lexer(char *src)
{
    lexer_js *lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];
    return lexer;
}

void lexer_advance(lexer_js *lexer)
{
    if (lexer->i < lexer->src_size && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

token_js *lexer_parse_id(lexer_js *lexer)
{
    int token_type = tokenID;
    char *value = calloc(1, sizeof(char));
    while (isalpha(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexer_advance(lexer);
    }
    if (strcmp(value, "return") == 0)
        token_type = statement;

    return init_token(value, token_type);
}

token_js *lexer_advance_current(lexer_js *lexer, int type)
{
    char *value = calloc(2, sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';
    token_js *token = init_token(value, type);
    lexer_advance(lexer);
    return token;
}

void lexer_skip_whitespace(lexer_js* lexer)
{
  while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
    lexer_advance(lexer);
}


token_js *lexer_next_token(lexer_js *lexer)
{
    while (lexer->c != '\0')
    {
        lexer_skip_whitespace(lexer);
        if (isalpha(lexer->c))
            return lexer_parse_id(lexer);
        switch (lexer->c)
        {
            case '(': return lexer_advance_current(lexer, parenL);
            case ')': return lexer_advance_current(lexer, parenR);
            default:
                printf("[Error]: Unexpected character `%c` (%d)\n", lexer->c, (int)lexer->c);
                exit(1);
                break;
        }
    }
    return init_token(0, endOfFile);
}