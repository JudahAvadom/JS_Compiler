#include "include/token.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

token_js* init_token(char* value, int type)
{
    token_js* token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;
    return token;
}