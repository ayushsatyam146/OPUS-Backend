#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class UnaryExpressionSyntax : public ExpressionSyntax {
public:
    SyntaxToken OperatorToken;
    ExpressionSyntax Operand;
    UnaryExpressionSyntax(SyntaxToken operatorToken, ExpressionSyntax operand);
    std::vector<SyntaxNode> GetChildren();
};