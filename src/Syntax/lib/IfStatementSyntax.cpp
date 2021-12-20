#include "../include/IfStatementSyntax.hpp"

IfStatementSyntax::IfStatementSyntax(SyntaxToken ifKeyword, ExpressionSyntax condition, StatementSyntax thenStatement, ElseClauseSyntax elseClause){
    SyntaxKind Kind = SyntaxKind::IfStatement;
    IfKeyword = ifKeyword;
    Condition = condition;
    ThenStatement = thenStatement;
    ElseClause = elseClause;
} 