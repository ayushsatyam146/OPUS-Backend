#include "../include/NameExpressionSyntax.hpp"

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken identifierToken)
{
    SyntaxKind Kind = SyntaxKind::NameExpression;
    IdentifierToken = identifierToken;
}

std::vector<SyntaxNode> NameExpressionSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        IdentifierToken
    };
    return ChildrenNode;
}