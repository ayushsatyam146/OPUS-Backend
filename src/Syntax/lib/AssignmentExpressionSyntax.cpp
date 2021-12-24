#include "../include/AssignmentExpressionSyntax.hpp"

AssignmentExpressionSyntax::AssignmentExpressionSyntax(SyntaxToken identifierToken, SyntaxToken equalsToken, ExpressionSyntax expression) {
    Kind = SyntaxKind::AssignmentExpression;
    IdentifierToken = identifierToken;
    EqualsToken = equalsToken;
    Expression = expression;
}

std::vector<SyntaxNode> AssignmentExpressionSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        IdentifierToken,
        EqualsToken,
        Expression
    };
    return ChildrenNode;
}