#include "../include/BlockStatementSyntax.hpp"

BlockStatementSyntax::BlockStatementSyntax(SyntaxToken openBraceToken, std::vector<StatementSyntax> statements, SyntaxToken closeBraceToken){
    Kind = SyntaxKind::BlockStatement;
    OpenBraceToken = openBraceToken;
    Statements = statements;
    CloseBraceToken = closeBraceToken;
}