#include "../include/SyntaxToken.hpp"

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, std::string text, int value) {
    Kind = kind;
    Position = position;
    Text = text;
    Value = value; 
}

SyntaxToken::SyntaxToken() {
    Kind = BadToken;
    Position = 0;
    Text = "";
    Value = 0; 
}

std::vector<SyntaxNode> SyntaxToken::GetChildren() {
    return Children;
} 
