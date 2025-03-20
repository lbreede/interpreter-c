//
// Created by Lennart Breede on 2025-03-19.
//

#include "lexer.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lexer new_lexer(const char *input) {
    Lexer lexer;
    lexer.input = input;
    lexer.position = 0;
    lexer.read_position = 0;
    lexer.ch = input[0];
    read_char(&lexer);
    return lexer;
}

void read_char(Lexer *lexer) {
    if (lexer->read_position >= strlen(lexer->input)) {
        lexer->ch = 0;
    } else {
        lexer->ch = lexer->input[lexer->read_position];
    }
    lexer->position = lexer->read_position;
    lexer->read_position++;
}

void print_lexer(const Lexer lexer) {
    printf("Lexer {\n  input: \"%s\"\n  position: %zu\n  read_position: %zu\n  ch: %c\n}\n",
        lexer.input,
        lexer.position,
        lexer.read_position,
        lexer.ch
        );
}

Token next_token(Lexer *lexer) {
    Token token;

    skip_whitespace(lexer);

    switch (lexer->ch) {
        case '=':
            if (peek_char(lexer) == '=') {
                const char ch = lexer->ch;
                read_char(lexer);
                char *literal = malloc(3*sizeof(char));
                literal[0] = ch;
                literal[1] = lexer->ch;
                literal[2] = 0;
                token = new_token(EQ, ch);

            } else {
                token = new_token(ASSIGN, lexer->ch);
            }
        break;
        case '+':
            token = new_token(PLUS, lexer->ch);
        break;
        case '-':
            token = new_token(MINUS, lexer->ch);
        break;
        case '!':
            if (peek_char(lexer) == '=') {
                const char ch = lexer->ch;
                read_char(lexer);
                char *literal = malloc(3*sizeof(char));
                literal[0] = ch;
                literal[1] = lexer->ch;
                literal[2] = 0;
                token = new_token(NOT_EQ, ch);
            } else {
                token = new_token(BANG, lexer->ch);
            }
        break;
        case '/':
            token = new_token(SLASH, lexer->ch);
        break;
        case '*':
            token = new_token(ASTERISK, lexer->ch);
        break;
        case '<':
            token = new_token(LT, lexer->ch);
        break;
        case '>':
            token = new_token(GT, lexer->ch);
        break;
        case ';':
            token = new_token(SEMICOLON, lexer->ch);
        break;
        case ',':
            token = new_token(COMMA, lexer->ch);
        break;
        case '(':
            token = new_token(LPAREN, lexer->ch);
        break;
        case ')':
            token = new_token(RPAREN, lexer->ch);
        break;
        case '{':
            token = new_token(LBRACE, lexer->ch);
        break;
        case '}':
            token = new_token(RBRACE, lexer->ch);
        break;
        case 0:
            token = new_token(EOF_, lexer->ch);
        break;
        default: {
            if (is_letter(lexer->ch) ) {
                token.literal = read_identifier(lexer);
                token.type = lookup_ident(token.literal);
                return token;
            }
            if (isdigit(lexer->ch)) {
                token.type = INT;
                token.literal = read_number(lexer);
                return token;
            }
            token = new_token(ILLEGAL, lexer->ch);
        }
        break;
    }

    read_char(lexer);
    return token;
}

Token new_token(const TokenType type, const char ch) {
    Token token;
    token.type = type;
    token.literal = malloc(2*sizeof(char));
    token.literal[0] = ch;
    token.literal[1] = 0;
    return token;
}

int is_letter(const char ch) {
    return isalpha(ch) || ch == '_';
}

char *read_identifier(Lexer *lexer) {
    const size_t position = lexer->position;
    while (is_letter(lexer->ch)) {
        read_char(lexer);
    }
    return strndup(lexer->input + position, lexer->position - position);
}

void skip_whitespace(Lexer *lexer) {
    while (isspace(lexer->ch)) {
        read_char(lexer);
    }
}

char *read_number(Lexer *lexer) {
    const size_t position = lexer->position;
    while (isdigit(lexer->ch)) {
        read_char(lexer);
    }
    return strndup(lexer->input + position, lexer->position - position);
}

char peek_char(const Lexer *lexer) {
    if (lexer->read_position >= strlen(lexer->input)) {
        return 0;
    }
    return lexer->input[lexer->read_position];
}
