#include "include/tokens.hpp"
#include "include/ast.hpp"
#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <format>

class Parser {
    private:
    std::vector<Token> tokens;
    size_t current;
    int line;

    Token currentToken() {
        if(current >= tokens.size()) {
            return Token(TokenType::END, "", line);
        }
        return tokens[current];
    }
    
    Token [[nodiscard]] consume(TokenType expected, const std::string& errorMsg) {
        Token token = currentToken();
        if(token.type == expected) {
            ++current;
            return token;
        }
        throw std::runtime_error(std::format("{} at line {}", errorMsg, line));
    }
};
