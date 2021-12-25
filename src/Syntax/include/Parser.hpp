#include <string>
#include <vector>
#include "lexer.hpp"
#include "SyntaxToken.hpp"
#include "SyntaxFacts.hpp"
#include "BlockStatementSyntax.hpp"
#include "ExpressionSyntax.hpp"
#include "VariableDeclarationSyntax.hpp"
#include "IfStatementSyntax.hpp"
#include "ElseClauseSyntax.hpp"
#include "WhileStatementSyntax.hpp"
#include "ForStatementSyntax.hpp"
#include "ExpressionStatementSyntax.hpp"
#include "AssignmentExpressionSyntax.hpp"
#include "UnaryExpressionSyntax.hpp"
#include "BinaryExpressionSyntax.hpp"
#include "ParenthesizedExpressionSyntax.hpp"
#include "LiteralExpressionSyntax.hpp"
#include "NameExpressionSyntax.hpp"
#include "CompilationUnitSyntax.hpp"

class Parser { 
private:
    std::string _text;
    std::vector<SyntaxToken> _tokens;
    int _position;

    SyntaxToken Peek(int offset);
    SyntaxToken Current();
    SyntaxToken NextToken();
    SyntaxToken MatchToken(SyntaxKind kind);
    StatementSyntax ParseStatement();
    BlockStatementSyntax ParseBlockStatement();
    StatementSyntax ParseVariableDeclaration();
    StatementSyntax ParseIfStatement();
    ElseClauseSyntax ParseElseClause();
    StatementSyntax ParseWhileStatement();
    StatementSyntax ParseForStatement();
    ExpressionStatementSyntax ParseExpressionStatement();
    ExpressionSyntax ParseExpression();
    ExpressionSyntax ParseAssignmentExpression();
    ExpressionSyntax ParseBinaryExpression(int parentPrecedence = 0);
    ExpressionSyntax ParsePrimaryExpression();
    ExpressionSyntax ParseParenthesizedExpression();
    ExpressionSyntax ParseBooleanLiteral();
    ExpressionSyntax ParseNumberLiteral();
    ExpressionSyntax ParseNameExpression();

public:
    Parser(std::string text) ;
    CompilationUnitSyntax ParseCompilationUnit();
};



