#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class LiteralExpressionSyntax : public ExpressionSyntax {
public:    
    SyntaxToken LiteralToken;
    int Value;

    LiteralExpressionSyntax(SyntaxToken literalToken, int value);
};