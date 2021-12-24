#include "../include/ParenthesizedExpressionSyntax.hpp"

ParenthesizedExpressionSyntax::ParenthesizedExpressionSyntax(SyntaxToken openParenthesisToken, ExpressionSyntax expression, SyntaxToken closeParenthesisToken) {
    Kind = SyntaxKind::ParenthesizedExpression;
    OpenParenthesisToken = openParenthesisToken;
    Expression = expression;
    CloseParenthesisToken = closeParenthesisToken;
}

std::vector<SyntaxNode> ParenthesizedExpressionSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        OpenParenthesisToken,
        Expression,
        CloseParenthesisToken
    };
    return ChildrenNode;
}