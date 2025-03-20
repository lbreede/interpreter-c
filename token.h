//
// Created by Lennart Breede on 2025-03-19.
//

#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    ILLEGAL,
    EOF_,

    IDENT,
    INT,

    ASSIGN,
    PLUS,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,

    LT,
    GT,
    EQ,
    NOT_EQ,

    COMMA,
    SEMICOLON,

    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    FUNCTION,
    LET,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN,
} TokenType;

typedef struct {
    TokenType type;
    char *literal;
} Token;

void print_token(Token token);
TokenType lookup_ident(const char *ident);

#endif //TOKEN_H
