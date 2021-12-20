#include "../include/NameExpressionSyntax.hpp"

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken identifierToken)
{
    SyntaxKind Kind = SyntaxKind::NameExpression;
    IdentifierToken = identifierToken;
}