#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class ParenthesizedExpressionSyntax : public ExpressionSyntax {
public:
    SyntaxToken OpenParenthesisToken;
    ExpressionSyntax Expression;
    SyntaxToken CloseParenthesisToken;

    ParenthesizedExpressionSyntax(SyntaxToken openParenthesisToken, ExpressionSyntax expression, SyntaxToken closeParenthesisToken);    
    std::vector<SyntaxNode> GetChildren();
};