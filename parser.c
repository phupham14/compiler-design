#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token current_token;

void syntax_error(const char *msg)
{
    printf("Syntax Error: %s (Got '%s')\n", msg, current_token.value);
    exit(1);
}

void advance()
{
    current_token = get_token();
}

void expect(TokenType type)
{
    if (current_token.type != type)
    {
        syntax_error("Unexpected token");
    }
    advance();
}

void parse_factor()
{
    if (current_token.type == IDENT || current_token.type == NUMBER)
    {
        advance();
    }
    else
    {
        syntax_error("Expected IDENT or NUMBER");
    }
}

void parse_term()
{
    parse_factor();
    while (current_token.type == TIMES || current_token.type == SLASH)
    {
        advance();
        parse_factor();
    }
}

void parse_expression()
{
    parse_term();
    while (current_token.type == PLUS || current_token.type == MINUS)
    {
        advance();
        parse_term();
    }
}

void parse_condition()
{
    parse_expression();
    if (current_token.type == EQU || current_token.type == NEQ || current_token.type == LSS ||
        current_token.type == LEQ || current_token.type == GTR || current_token.type == GEQ)
    {
        advance();
        parse_expression();
    }
    else
    {
        syntax_error("Expected comparison operator");
    }
}

void parse_statement()
{
    if (current_token.type == KEYWORD && strcmp(current_token.value, "IF") == 0)
    {
        advance();
        parse_condition();
        if (current_token.type == KEYWORD && strcmp(current_token.value, "THEN") == 0)
        {
            advance();
            parse_statement();
        }
        else
        {
            syntax_error("Expected THEN");
        }
    }
    else if (current_token.type == IDENT)
    {
        advance();
        expect(ASSIGN);
        parse_expression();
    }
    else
    {
        syntax_error("Expected statement");
    }
}

void parse_program()
{
    if (current_token.type == KEYWORD && strcmp(current_token.value, "VAR") == 0)
    {
        advance();
        expect(IDENT);
        expect(ASSIGN);
        expect(NUMBER);
        expect(SEMICOLON);
    }

    parse_statement();
    expect(PERIOD);

    if (current_token.type != EOF_TOKEN)
    {
        syntax_error("Expected EOF");
    }

    printf("Parsing completed successfully.\n");
}
