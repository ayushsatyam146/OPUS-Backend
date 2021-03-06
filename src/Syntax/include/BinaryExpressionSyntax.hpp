#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class BinaryExpressionSyntax : public ExpressionSyntax{
public:
    ExpressionSyntax Left;
    SyntaxToken OperatorToken;
    ExpressionSyntax Right;
    
    BinaryExpressionSyntax(ExpressionSyntax left,SyntaxToken operatorToken, ExpressionSyntax right);
    std::vector<SyntaxNode> GetChildren();
};