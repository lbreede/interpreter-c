//
// Created by Lennart Breede on 2025-03-19.
//

#include "token.h"

#include <stdio.h>
#include <string.h>

const char *token_type_to_string(const TokenType type) {
    switch (type) {
        case ILLEGAL: return "Illegal";
        case EOF_: return "Eof";
        case IDENT: return "Ident";
        case INT: return "Int";
        case ASSIGN: return "Assign";
        case PLUS: return "Plus";
        case MINUS: return "Minus";
        case BANG: return "Bang";
        case ASTERISK: return "Asterisk";
        case SLASH: return "Slash";
        case LT: return "Lt";
        case GT: return "Gt";
        case EQ: return "Eq";
        case NOT_EQ: return "NotEq";
        case COMMA: return "Comma";
        case SEMICOLON: return "Semicolon";
        case LPAREN: return "Lparen";
        case RPAREN: return "Rparen";
        case LBRACE: return "Lbrace";
        case RBRACE: return "Rbrace";
        case FUNCTION: return "Function";
        case LET: return "Let";
        case TRUE: return "True";
        case FALSE: return "False";
        case IF: return "If";
        case ELSE: return "Else";
        case RETURN: return "Return";
        default: return "Unknown";
    }
}

void print_token(const Token token) {
    const char *type = token_type_to_string(token.type);
    if (token.type == IDENT || token.type == ILLEGAL) {
        printf("%s(\"%s\")\n", type, token.literal);
    } else if (token.type == INT) {
        printf("%s(%s)\n", type, token.literal);
    } else {
        printf("%s\n", type);
    }
}


TokenType lookup_ident(const char *ident) {
    if (strcmp(ident, "let") == 0) {
        return LET;
    }
    if (strcmp(ident, "fn") == 0) {
        return FUNCTION;
    }
    if (strcmp(ident, "true") == 0) {
        return TRUE;
    }
    if (strcmp(ident, "false") == 0) {
        return FALSE;
    }
    if (strcmp(ident, "if") == 0) {
        return IF;
    }
    if (strcmp(ident, "else") == 0) {
        return ELSE;
    }
    if (strcmp(ident, "return") == 0) {
        return RETURN;
    }
    return IDENT;}