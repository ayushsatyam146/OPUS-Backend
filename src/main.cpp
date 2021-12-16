#include<string>
#include<vector>
#include<iostream>
#include "include/lexer.hpp"

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

    // // For printing tokens for test 
    for(int i = 0;i < tokens.size(); i++){
        SyntaxToken tok = tokens[i];
        std::cout<<"["<<tok.Kind<<", "<<tok.Text<<"]\n";
    }
    return 0;
}