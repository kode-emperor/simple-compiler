#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>

constexpr int kProgramFirstLine = 1;
enum class TokenType {
    IDENTIFIER, // for variable names e.g name = 32
    INTEGER, // integer literals e.g 10
    OPERATOR, // operands + / * - 
    RESERVED, // print int input
    END, // end of input ;
    UNKNOWN
};


struct Token {
    TokenType type;
    std::string value;
    int line;

    Token(
        TokenType type = TokenType::UNKNOWN,
        std::string value = "",
        int line = kProgramFirstLine
    ):type(type), value(value), line(line)
    {

    }
};

#endif