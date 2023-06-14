#ifndef TOKEN_H
#define TOKEN_H 
typedef struct TOKEN_STRUCT
{
    char*value;
    enum 
    {
        tokenID,
        parenL,
        parenR,
        statement,
        endOfFile
    } type;
} token_js;

token_js* init_token(char* value, int type);

static const char* token_type_to_str(int type);

char* token_to_str(token_js* token);

#endif