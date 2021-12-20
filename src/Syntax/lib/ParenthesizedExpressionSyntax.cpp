#include "../include/ParenthesizedExpressionSyntax.hpp"

ParenthesizedExpressionSyntax::ParenthesizedExpressionSyntax(SyntaxToken openParenthesisToken, ExpressionSyntax expression, SyntaxToken closeParenthesisToken) {
    Kind = SyntaxKind::ParenthesizedExpression;
    OpenParenthesisToken = openParenthesisToken;
    Expression = expression;
    CloseParenthesisToken = closeParenthesisToken;
}