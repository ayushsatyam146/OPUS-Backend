#include "../include/ForStatementSyntax.hpp"

ForStatementSyntax::ForStatementSyntax(SyntaxToken keyword, SyntaxToken identifier, SyntaxToken equalsToken, ExpressionSyntax lowerBound, SyntaxToken toKeyword, ExpressionSyntax upperBound, StatementSyntax body) {
    SyntaxKind Kind = SyntaxKind::ForStatement;
    Keyword = keyword;
    Identifier = identifier;
    EqualsToken = equalsToken;
    LowerBound = lowerBound;
    ToKeyword = toKeyword;
    UpperBound = upperBound;
    Body = body;
}

std::vector<SyntaxNode> ForStatementSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        Keyword,
        Identifier,
        EqualsToken,
        LowerBound,
        ToKeyword,
        UpperBound,
        Body
    };
    return ChildrenNode;
}