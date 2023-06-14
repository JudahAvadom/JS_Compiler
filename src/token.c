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

static const char* token_type_to_str(int type){
    switch (type)
    {
        case braceL: return "braceL";
        case braceR: return "braceR";
        case dot: return "dot";
        case parenL: return "parenL";
        case parenR: return "parenR";
        case semi: return "semi";
        case tokenID: return "tokenID";
    }
    return "not_stringable";
}

char* token_to_str(token_js* token){
    const char* type_str = token_type_to_str(token->type);
    const char* template = "\t type: %s, int_type: %d, value: `%s`";
    char* str = calloc(strlen(type_str) + strlen(template) + 8, sizeof(char));
    sprintf(str, template, type_str, token->type, token->value);
    return str;
}