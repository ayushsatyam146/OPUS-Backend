#include "CompilationUnitSyntax.hpp"

CompilationUnitSyntax::CompilationUnitSyntax(StatementSyntax statement, SyntaxToken endOfFileToken)
{
    Statement = statement;
    EndOfFileToken = endOfFileToken;
    Kind = SyntaxKind::CompilationUnit;
} 

std::vector<SyntaxNode> CompilationUnitSyntax::GetChildren(){
    std::vector<SyntaxNode> ChildrenNode{
        Statement,
        EndOfFileToken
    };
    return ChildrenNode;
}