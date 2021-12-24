#include "../include/BlockStatementSyntax.hpp"
#include<vector>

BlockStatementSyntax::BlockStatementSyntax(SyntaxToken openBraceToken, std::vector<StatementSyntax> statements, SyntaxToken closeBraceToken){
    Kind = SyntaxKind::BlockStatement;
    OpenBraceToken = openBraceToken;
    Statements = statements;
    CloseBraceToken = closeBraceToken;
}

std::vector<SyntaxNode> BlockStatementSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode;
    ChildrenNode.push_back(OpenBraceToken);
    ChildrenNode.push_back(CloseBraceToken);
    for (auto statement : Statements) {
        ChildrenNode.push_back(statement);
    }
    return ChildrenNode;
}