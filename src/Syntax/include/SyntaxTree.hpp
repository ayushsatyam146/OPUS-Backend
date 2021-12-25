#include "CompilationUnitSyntax.hpp"
#include "lexer.hpp"

class SyntaxTree {
public:
    std::string Text;
    CompilationUnitSyntax Root; 
    SyntaxTree(std::string text);
    std::vector<SyntaxToken> ParseTokens(std::string text);
};