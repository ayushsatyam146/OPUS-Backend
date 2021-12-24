#pragma once
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class NameExpressionSyntax : public ExpressionSyntax {
public:
    SyntaxToken IdentifierToken;
    NameExpressionSyntax(SyntaxToken identifierToken);    
    std::vector<SyntaxNode> GetChildren();
};