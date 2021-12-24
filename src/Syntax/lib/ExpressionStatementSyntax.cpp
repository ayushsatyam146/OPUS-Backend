#include "../include/ExpressionStatementSyntax.hpp"

ExpressionStatementSyntax::ExpressionStatementSyntax(ExpressionSyntax expression) {
    SyntaxKind Kind = SyntaxKind::ExpressionStatement;
    Expression = expression;
}

std::vector<SyntaxNode> ExpressionStatementSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        Expression
    };
    return ChildrenNode;
}