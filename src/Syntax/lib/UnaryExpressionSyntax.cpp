#include "../include/UnaryExpressionSyntax.hpp"

UnaryExpressionSyntax::UnaryExpressionSyntax(SyntaxToken operatorToken, ExpressionSyntax operand) {
    Kind = SyntaxKind::UnaryExpression;
    OperatorToken = operatorToken;
    Operand = operand;
} 