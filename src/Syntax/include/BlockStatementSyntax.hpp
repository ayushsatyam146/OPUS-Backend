#pragma once
#include<vector>
#include "StatementSyntax.hpp"
#include "SyntaxToken.hpp"

class BlockStatementSyntax : public StatementSyntax {
public:
    SyntaxToken OpenBraceToken;
    SyntaxToken CloseBraceToken;
    std::vector<StatementSyntax> Statements;
    BlockStatementSyntax(SyntaxToken openBraceToken, std::vector<StatementSyntax> statements, SyntaxToken closeBraceToken);
    std::vector<SyntaxNode> GetChildren();
};