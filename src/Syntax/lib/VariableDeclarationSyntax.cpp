#include "../include/VariableDeclarationSyntax.hpp"

VariableDeclarationSyntax::VariableDeclarationSyntax(SyntaxToken keyword, SyntaxToken identifier, SyntaxToken equalsToken, ExpressionSyntax initializer){
    SyntaxKind Kind = SyntaxKind::VariableDeclaration;
    Keyword = keyword;
    Identifier = identifier;
    EqualsToken = equalsToken;
    Initializer = initializer;
}  

std::vector<SyntaxNode> VariableDeclarationSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        Keyword,
        Identifier,
        EqualsToken,
        Initializer
    };
    return ChildrenNode;
}