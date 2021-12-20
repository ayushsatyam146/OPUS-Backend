#include "../include/ExpressionStatementSyntax.hpp"

ExpressionStatementSyntax::ExpressionStatementSyntax(ExpressionSyntax expression) {
    SyntaxKind Kind = SyntaxKind::ExpressionStatement;
    Expression = expression;
}