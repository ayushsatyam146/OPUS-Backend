#include "../include/UnaryExpressionSyntax.hpp"

UnaryExpressionSyntax::UnaryExpressionSyntax(SyntaxToken operatorToken, ExpressionSyntax operand) {
    Kind = SyntaxKind::UnaryExpression;
    OperatorToken = operatorToken;
    Operand = operand;
} 

std::vector<SyntaxNode> UnaryExpressionSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        OperatorToken,
        Operand
    };
    return ChildrenNode;
}