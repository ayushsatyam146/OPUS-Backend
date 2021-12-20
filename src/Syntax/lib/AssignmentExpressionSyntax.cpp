#include "../include/AssignmentExpressionSyntax.hpp"

AssignmentExpressionSyntax::AssignmentExpressionSyntax(SyntaxToken identifierToken, SyntaxToken equalsToken, ExpressionSyntax expression) {
    Kind = SyntaxKind::AssignmentExpression;
    IdentifierToken = identifierToken;
    EqualsToken = equalsToken;
    Expression = expression;
}