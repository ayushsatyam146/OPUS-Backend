#include "SyntaxKind.hpp"
#include <string>
#include <vector>

class SyntaxFacts  {
public:
    static int GetUnaryOperatorPrecedence(SyntaxKind kind);
    static int GetBinaryOperatorPrecedence(SyntaxKind kind);
    static SyntaxKind GetKeywordKind(std::string text);
    static std::string GetText(SyntaxKind kind);
    static std::vector<SyntaxKind> SyntaxFacts::GetBinaryOperatorKinds();
    static std::vector<SyntaxKind> SyntaxFacts::GetUnaryOperatorKinds();
};