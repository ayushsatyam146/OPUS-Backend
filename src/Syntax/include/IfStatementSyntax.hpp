#pragma once
#include "ExpressionSyntax.hpp"
#include "ElseClauseSyntax.hpp"

class IfStatementSyntax : public StatementSyntax {
public:

    SyntaxToken IfKeyword;
    ExpressionSyntax Condition;
    StatementSyntax ThenStatement;
    ElseClauseSyntax ElseClause;

    IfStatementSyntax(SyntaxToken ifKeyword, ExpressionSyntax condition, StatementSyntax thenStatement, ElseClauseSyntax elseClause){
        SyntaxKind Kind = SyntaxKind::IfStatement;
        IfKeyword = ifKeyword;
        Condition = condition;
        ThenStatement = thenStatement;
        ElseClause = elseClause;
    } 
};