#include "../include/ElseClauseSyntax.hpp"

ElseClauseSyntax::ElseClauseSyntax(SyntaxToken elseKeyword, StatementSyntax elseStatement) {
    SyntaxKind Kind = SyntaxKind::ElseClause;
    ElseKeyword = elseKeyword;
    ElseStatement = elseStatement;
}

ElseClauseSyntax::ElseClauseSyntax() {}

std::vector<SyntaxNode> ElseClauseSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        ElseKeyword,
        ElseStatement
    };
    return ChildrenNode;
}