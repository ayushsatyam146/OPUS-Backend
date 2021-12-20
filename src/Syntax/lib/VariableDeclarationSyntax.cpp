#include "../include/VariableDeclarationSyntax.hpp"

VariableDeclarationSyntax::VariableDeclarationSyntax(SyntaxToken keyword, SyntaxToken identifier, SyntaxToken equalsToken, ExpressionSyntax initializer){
    SyntaxKind Kind = SyntaxKind::VariableDeclaration;
    Keyword = keyword;
    Identifier = identifier;
    EqualsToken = equalsToken;
    Initializer = initializer;
}  