//
// Created by Lennart Breede on 2025-03-19.
//

#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include "token.h"

typedef struct {
    const char *input;
    size_t position;
    size_t read_position;
    char ch;
} Lexer;

Lexer new_lexer(const char *input);
void read_char(Lexer *lexer);
void print_lexer(Lexer lexer);
Token next_token(Lexer *lexer);
Token new_token(TokenType type, char ch);
int is_letter(char ch);
char *read_identifier(Lexer *lexer);
void skip_whitespace(Lexer *lexer);
char *read_number(Lexer *lexer);
char peek_char(const Lexer *lexer);

#endif //LEXER_H
