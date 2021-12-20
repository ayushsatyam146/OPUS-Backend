#pragma once
#include "StatementSyntax.hpp"
#include "SyntaxToken.hpp"
#include "ExpressionSyntax.hpp"

class ForStatementSyntax : public StatementSyntax {
public:
    SyntaxToken Keyword;
    SyntaxToken Identifier;
    SyntaxToken EqualsToken;
    ExpressionSyntax LowerBound;
    SyntaxToken ToKeyword;
    ExpressionSyntax UpperBound;
    StatementSyntax Body;
    ForStatementSyntax(SyntaxToken keyword, SyntaxToken identifier, SyntaxToken equalsToken, ExpressionSyntax lowerBound, SyntaxToken toKeyword, ExpressionSyntax upperBound, StatementSyntax body);
};