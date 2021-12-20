#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class UnaryExpressionSyntax : ExpressionSyntax {
public:
    SyntaxToken OperatorToken;
    ExpressionSyntax Operand;
    UnaryExpressionSyntax(SyntaxToken operatorToken, ExpressionSyntax operand);
};