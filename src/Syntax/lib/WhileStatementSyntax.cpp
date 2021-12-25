#include "../include/WhileStatementSyntax.hpp"

WhileStatementSyntax::WhileStatementSyntax(SyntaxToken whileKeyword, ExpressionSyntax condition, StatementSyntax body){
    SyntaxKind Kind = SyntaxKind::WhileStatement;
    WhileKeyword = whileKeyword;
    Condition = condition;
    Body = body;
}

std::vector<SyntaxNode> WhileStatementSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        WhileKeyword,
        Condition,
        Body
    };
    return ChildrenNode;
}