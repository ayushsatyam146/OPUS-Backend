#include "../include/SyntaxTree.hpp"
#include "../include/Parser.hpp" 

SyntaxTree::SyntaxTree(std::string text){
    Parser parser(text);
    Root = parser.ParseCompilationUnit(); 
    Text = text;  
}

std::vector<SyntaxToken> SyntaxTree::ParseTokens(std::string text){
    Lexer lexer(text);
    std::vector<SyntaxToken> parseTokens;
    while (true){
        SyntaxToken token = lexer.Lex();
        if (token.Kind == SyntaxKind::EndOfFileToken){
            break;
        }
        parseTokens.push_back(token);
    }
    return parseTokens;
}
