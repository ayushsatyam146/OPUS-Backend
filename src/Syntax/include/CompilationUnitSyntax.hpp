#include "SyntaxNode.hpp"
#include "SyntaxToken.hpp"
#include "StatementSyntax.hpp"

class CompilationUnitSyntax : public SyntaxNode {
public:
    StatementSyntax Statement;
    SyntaxToken EndOfFileToken;
    CompilationUnitSyntax(StatementSyntax statement, SyntaxToken endOfFileToken);
    CompilationUnitSyntax();
    std::vector<SyntaxNode> GetChildren();
};