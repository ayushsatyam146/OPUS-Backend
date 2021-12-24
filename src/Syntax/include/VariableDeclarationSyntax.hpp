#pragma once
#include "SyntaxToken.hpp"
#include "StatementSyntax.hpp"
#include "ExpressionSyntax.hpp"

class VariableDeclarationSyntax : public StatementSyntax {
public:
    SyntaxToken Keyword;
    SyntaxToken Identifier;
    SyntaxToken EqualsToken;
    ExpressionSyntax Initializer;

    VariableDeclarationSyntax(SyntaxToken keyword, SyntaxToken identifier, SyntaxToken equalsToken, ExpressionSyntax initializer); 
    std::vector<SyntaxNode> GetChildren();
};