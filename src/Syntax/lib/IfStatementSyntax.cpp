#include "../include/IfStatementSyntax.hpp"

IfStatementSyntax::IfStatementSyntax(SyntaxToken ifKeyword, ExpressionSyntax condition, StatementSyntax thenStatement, ElseClauseSyntax elseClause){
    SyntaxKind Kind = SyntaxKind::IfStatement;
    IfKeyword = ifKeyword;
    Condition = condition;
    ThenStatement = thenStatement;
    ElseClause = elseClause;
} 

std::vector<SyntaxNode> IfStatementSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        IfKeyword,
        Condition,
        ThenStatement,
        ElseClause
    };
    return ChildrenNode;
}