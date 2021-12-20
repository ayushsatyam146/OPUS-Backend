#pragma once
#include "SyntaxToken.hpp"
#include "StatementSyntax.hpp"

class ElseClauseSyntax : public SyntaxNode {
public:
    SyntaxToken ElseKeyword;
    StatementSyntax ElseStatement;
    ElseClauseSyntax(SyntaxToken elseKeyword, StatementSyntax elseStatement);
    ElseClauseSyntax();
};