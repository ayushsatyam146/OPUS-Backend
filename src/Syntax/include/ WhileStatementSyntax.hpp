#pragma once
#include "StatementSyntax.hpp"
#include "ExpressionSyntax.hpp"
#include "SyntaxToken.hpp"

class WhileStatementSyntax : public StatementSyntax {
public:
    SyntaxToken WhileKeyword;
    ExpressionSyntax Condition;
    StatementSyntax Body;
    WhileStatementSyntax(SyntaxToken whileKeyword, ExpressionSyntax condition, StatementSyntax body);
    std::vector<SyntaxNode> GetChildren();
};