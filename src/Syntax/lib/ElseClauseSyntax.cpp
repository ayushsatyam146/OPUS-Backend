#include "../include/ElseClauseSyntax.hpp"

ElseClauseSyntax::ElseClauseSyntax(SyntaxToken elseKeyword, StatementSyntax elseStatement) {
    SyntaxKind Kind = SyntaxKind::ElseClause;
    ElseKeyword = elseKeyword;
    ElseStatement = elseStatement;
}