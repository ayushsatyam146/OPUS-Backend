#include "../include/LiteralExpressionSyntax.hpp"

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken literalToken, int value){
    Kind = SyntaxKind::LiteralExpression;
    LiteralToken = literalToken;
    Value = value;
}