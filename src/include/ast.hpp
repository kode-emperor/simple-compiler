#ifndef AST_HPP
#define AST_HPP

#include <memory>
#include <string>
#include <vector>
#include <iostream>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

class IntegerNode: public ASTNode {
    public:
    int value;
    IntegerNode(int val): value(val) { }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Number" << value << std::endl;
    }
};

#endif //AST_HPP
