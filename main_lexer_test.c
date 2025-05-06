#include "lexer.h"
#include <stdio.h>

const char *token_type_to_string(TokenType type)
{
    switch (type)
    {
    case PLUS:
        return "PLUS";
    case MINUS:
        return "MINUS";
    case TIMES:
        return "TIMES";
    case SLASH:
        return "SLASH";
    case EQU:
        return "EQU";
    case NEQ:
        return "NEQ";
    case LSS:
        return "LSS";
    case LEQ:
        return "LEQ";
    case GTR:
        return "GTR";
    case GEQ:
        return "GEQ";
    case LPARENT:
        return "LPARENT";
    case RPARENT:
        return "RPARENT";
    case LBRACK:
        return "LBRACK";
    case RBRACK:
        return "RBRACK";
    case ASSIGN:
        return "ASSIGN";
    case SEMICOLON:
        return "SEMICOLON";
    case COMMA:
        return "COMMA";
    case PERIOD:
        return "PERIOD";
    case PERCENT:
        return "PERCENT";
    case IDENT:
        return "IDENT";
    case NUMBER:
        return "NUMBER";
    case KEYWORD:
        return "KEYWORD";
    case EOF_TOKEN:
        return "EOF";
    default:
        return "UNKNOWN";
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    init_lexer(argv[1]);

    Token token;
    do
    {
        token = get_token();
        printf("Token: %-12s Value: %s\n", token_type_to_string(token.type), token.value);
    } while (token.type != EOF_TOKEN);

    close_lexer();
    return 0;
}
