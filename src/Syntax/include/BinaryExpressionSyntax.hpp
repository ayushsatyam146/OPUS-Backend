#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class BinaryExpressionSyntax : public ExpressionSyntax
{
    ExpressionSyntax Left;
    SyntaxToken OperatorToken;
    ExpressionSyntax Right;
    
    BinaryExpressionSyntax(ExpressionSyntax left,SyntaxToken operatorToken, ExpressionSyntax right);
};