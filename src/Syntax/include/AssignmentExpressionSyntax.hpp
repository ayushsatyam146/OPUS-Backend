#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class AssignmentExpressionSyntax : public ExpressionSyntax {
public: 
    SyntaxToken IdentifierToken;
    SyntaxToken EqualsToken;
    ExpressionSyntax Expression;

    AssignmentExpressionSyntax(SyntaxToken identifierToken, SyntaxToken equalsToken, ExpressionSyntax expression);
};