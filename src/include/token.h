#ifndef TOKEN_H
#define TOKEN_H 
typedef struct TOKEN_STRUCT
{
    char*value;
    enum 
    {
        braceL,
        braceR,
        dot,
        endOfFile,
        parenL,
        parenR,
        semi,
        statement,
        string,
        tokenID,
    } type;
} token_js;

token_js* init_token(char* value, int type);

static const char* token_type_to_str(int type);

char* token_to_str(token_js* token);

#endif