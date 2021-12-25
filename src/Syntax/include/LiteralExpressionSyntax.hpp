#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class LiteralExpressionSyntax : public ExpressionSyntax {
public:    
    SyntaxToken LiteralToken;
    int Value = 0;

    LiteralExpressionSyntax(SyntaxToken literalToken, int value);
    LiteralExpressionSyntax(SyntaxToken literalToken);
    std::vector<SyntaxNode> GetChildren();
};