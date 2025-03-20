
#include "lexer.h"


int main(void) {
    Lexer lexer = new_lexer("let five = 5;"
                            "let ten = 10;"
                            ""
                            "let add = fn(x, y) {"
                            "  x + y;"
                            "};"
                            ""
                            "let result = add(five, ten);"
                            "!-/*5;"
                            "5 < 10 > 5;"
                            ""
                            "if (5 < 10) {"
                            "    return true;"
                            "} else {"
                            "    return false;"
                            "}"
                            ""
                            "10 == 10;"
                            "10 != 9;"
                            );


    Token token = next_token(&lexer);
    while (token.type != EOF_) {
        print_token(token);
        token = next_token(&lexer);
    }
        print_token(token);
    return 0;
}

