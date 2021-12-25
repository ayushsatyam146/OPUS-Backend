#include "../include/LiteralExpressionSyntax.hpp"

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken literalToken, int value){
    Kind = SyntaxKind::LiteralExpression;
    LiteralToken = literalToken;
    Value = value;
}

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken literalToken){
    Kind = SyntaxKind::LiteralExpression;
    LiteralToken = literalToken; 
}

std::vector<SyntaxNode> LiteralExpressionSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        LiteralToken
    };
    return ChildrenNode;
}