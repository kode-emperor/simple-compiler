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

    Token parseIdentifier() {
        std::string ident{};
        while(isalnum(currentChar()) || currentChar() == '_') {
            ident += currentChar();
            gotoNextChar();
        }

        //check if identifier word is a reserved word
        if( ident == "print" ||
            ident == "int" || ident == "input") {
            return Token(TokenType::RESERVED, ident, line);
        }
        return Token(TokenType::IDENTIFIER, ident, line);
    }
    
public:

    Lexer(const std::string & src): source(src), position(0), line(1) {
        
    }

    Token getNextToken() {
        skipWhitespace();

        if(currentChar() == '\0') {
            return Token(TokenType::END, "", line );
        }

        //parse numbers 
        if(isdigit(currentChar())) {
            return parseInteger();
        }

        //identifiers and reserved words
        if(isalpha(currentChar())) {
            return parseIdentifier();
        }
        const char ch = currentChar();
        return Token(TokenType::UNKNOWN, std::string(1, ch), line);
    }

    std::vector<Token> tokenise() {
        std::vector<Token> tokens;

        Token token;

        do {
            token = getNextToken();
            tokens.push_back(token);
        } while(token.type != TokenType::END);
        return tokens;
    }
};

#endif //LEXER_HPP
