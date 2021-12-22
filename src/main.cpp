#include<string>
#include<vector>
#include<iostream>

#include "Syntax/include/lexer.hpp"

int main(){
    std::string text;
    std::getline(std::cin, text);
    std::cout<<text<<std::endl;
    std::vector <SyntaxToken> tokens;
    Lexer lexer(text);
    SyntaxToken token;
    
    while (token.Kind != SyntaxKind::EndOfFileToken){
        token = lexer.Lex();
        if( token.Kind != SyntaxKind::WhitespaceToken &&
            token.Kind != SyntaxKind::BadToken) 
        {
            tokens.push_back(token);
        }
    } 
    // tokens array contains all the tokens of the input after lexing
    
    return 0;
}

