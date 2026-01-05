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

class VariableNode: public ASTNode{
    public: std::string name;
    VariableNode(const std::string& n): name(n) { }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ')  << "Variable: " << name << std::endl;
    }
};

#endif //AST_HPP
