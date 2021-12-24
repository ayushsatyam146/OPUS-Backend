#include "../include/BinaryExpressionSyntax.hpp"

BinaryExpressionSyntax::BinaryExpressionSyntax(ExpressionSyntax left, SyntaxToken operatorToken, ExpressionSyntax right) {
    Kind = SyntaxKind::BinaryExpression;
    Left = left;
    OperatorToken = operatorToken;
    Right = right;
}

std::vector<SyntaxNode> BinaryExpressionSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        Left,
        OperatorToken,
        Right,
    };
    return ChildrenNode;
}