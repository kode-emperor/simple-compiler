#ifndef LEXER_HPP
#define LEXER_HPP
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include "token.hpp"

class Lexer {
private:
    std::string source;
    size_t position;
    int line;

    char currentChar() {
        if(position >= source.length())
        return '\0';
        return source[position];
    }

    void gotoNextChar() {
        if(currentChar() == '\n') line++;
        position++;
    }

    void skipWhitespace() {
        while(isspace(currentChar())) {
            gotoNextChar();
        }
    }


    Token parseInteger() {
        std::string num{};
        while(isdigit(currentChar())) {
            num += currentChar();
            gotoNextChar();
        }
        return Token(TokenType::INTEGER, num, line);
    }
public:

};

#endif //LEXER_HPP
