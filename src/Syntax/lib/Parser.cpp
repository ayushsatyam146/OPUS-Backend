#include <string>
#include <vector>
#include "../include/Parser.hpp"


SyntaxToken Parser::Peek(int offset){
    int index = _position + offset;
    if (index >= _tokens.size()){
        return _tokens[_tokens.size() - 1]; 
    }
    return _tokens[index];
}

SyntaxToken Parser::Current() {return Peek(0);}

SyntaxToken Parser::NextToken(){
    SyntaxToken current = Current();
    _position++;
    return current;
}

SyntaxToken Parser::MatchToken(SyntaxKind kind){
    if (Current().Kind == kind) return NextToken();
    return *new SyntaxToken(kind, Current().Position, "", 0);
}

StatementSyntax Parser::ParseStatement(){
    switch (Current().Kind){
        case SyntaxKind::OpenBraceToken:
            return ParseBlockStatement();
        case SyntaxKind::LetKeyword:
        case SyntaxKind::VarKeyword:
            return ParseVariableDeclaration();
        case SyntaxKind::IfKeyword:
            return ParseIfStatement();
        case SyntaxKind::WhileKeyword:
            return ParseWhileStatement();
        case SyntaxKind::ForKeyword:
            return ParseForStatement();
        default:
            return ParseExpressionStatement();
    }
}

BlockStatementSyntax Parser::ParseBlockStatement()
{
    std::vector<StatementSyntax> statements;

    SyntaxToken openBraceToken = MatchToken(SyntaxKind::OpenBraceToken);

    while (Current().Kind != SyntaxKind::EndOfFileToken &&
            Current().Kind != SyntaxKind::CloseBraceToken)
    {
        SyntaxToken startToken = Current();

        StatementSyntax statement = ParseStatement();
        statements.push_back(statement);
        if (Current() == startToken)
            NextToken();
    }

    SyntaxToken closeBraceToken = MatchToken(SyntaxKind::CloseBraceToken);

    return *new BlockStatementSyntax(openBraceToken, statements, closeBraceToken);
}

StatementSyntax Parser::ParseVariableDeclaration(){
    SyntaxKind expected = Current().Kind == SyntaxKind::LetKeyword ? SyntaxKind::LetKeyword : SyntaxKind::VarKeyword;
    SyntaxToken keyword = MatchToken(expected);
    SyntaxToken identifier = MatchToken(SyntaxKind::IdentifierToken);
    SyntaxToken equals = MatchToken(SyntaxKind::EqualsToken);
    ExpressionSyntax initializer = ParseExpression();
    return *new VariableDeclarationSyntax(keyword, identifier, equals, initializer);
}

StatementSyntax Parser::ParseIfStatement(){
    SyntaxToken keyword = MatchToken(SyntaxKind::IfKeyword);
    ExpressionSyntax condition = ParseExpression();
    StatementSyntax statement = ParseStatement();
    ElseClauseSyntax elseClause = ParseElseClause();
    return *new IfStatementSyntax(keyword, condition, statement, elseClause);
}

ElseClauseSyntax Parser::ParseElseClause(){
    if (Current().Kind != SyntaxKind::ElseKeyword) 
        return *new ElseClauseSyntax();
    SyntaxToken keyword = NextToken();
    StatementSyntax statement = ParseStatement();
    return *new ElseClauseSyntax(keyword, statement);
}

StatementSyntax Parser::ParseWhileStatement(){
    SyntaxToken keyword = MatchToken(SyntaxKind::WhileKeyword);
    ExpressionSyntax condition = ParseExpression();
    StatementSyntax body = ParseStatement();
    return *new WhileStatementSyntax(keyword, condition, body);
}

StatementSyntax Parser::ParseForStatement(){
    SyntaxToken keyword = MatchToken(SyntaxKind::ForKeyword);
    SyntaxToken identifier = MatchToken(SyntaxKind::IdentifierToken);
    SyntaxToken equalsToken = MatchToken(SyntaxKind::EqualsToken);
    ExpressionSyntax lowerBound = ParseExpression();
    SyntaxToken toKeyword = MatchToken(SyntaxKind::ToKeyword);
    ExpressionSyntax upperBound = ParseExpression();
    StatementSyntax body = ParseStatement();
    return *new ForStatementSyntax(keyword, identifier, equalsToken, lowerBound, toKeyword, upperBound, body);
}

ExpressionStatementSyntax Parser::ParseExpressionStatement(){
    ExpressionSyntax expression = ParseExpression();
    return *new ExpressionStatementSyntax(expression);
}

ExpressionSyntax Parser::ParseExpression(){
    return ParseAssignmentExpression();
}

ExpressionSyntax Parser::ParseAssignmentExpression(){
    if (Peek(0).Kind == SyntaxKind::IdentifierToken &&
        Peek(1).Kind == SyntaxKind::EqualsToken)
    {
        SyntaxToken identifierToken = NextToken();
        SyntaxToken operatorToken = NextToken();
        ExpressionSyntax right = ParseAssignmentExpression();
        return *new AssignmentExpressionSyntax(identifierToken, operatorToken, right);
    }
    return ParseBinaryExpression(0);
}

ExpressionSyntax Parser::ParseBinaryExpression(int parentPrecedence ){
    ExpressionSyntax left;
    int unaryOperatorPrecedence = SyntaxFacts::GetUnaryOperatorPrecedence(Current().Kind);
    if (unaryOperatorPrecedence != 0 && unaryOperatorPrecedence >= parentPrecedence)
    {
        SyntaxToken operatorToken = NextToken();
        ExpressionSyntax operand = ParseBinaryExpression(unaryOperatorPrecedence);
        left = *new UnaryExpressionSyntax(operatorToken, operand);
    }
    else
    {
        left = ParsePrimaryExpression();
    }

    while (true)
    {
        int precedence = SyntaxFacts::GetBinaryOperatorPrecedence(Current().Kind);
        if (precedence == 0 || precedence <= parentPrecedence)
            break;

        SyntaxToken operatorToken = NextToken();
        ExpressionSyntax right = ParseBinaryExpression(precedence);
        left = *new BinaryExpressionSyntax(left, operatorToken, right);
    }

    return left;
}

ExpressionSyntax Parser::ParsePrimaryExpression(){
    switch (Current().Kind)
    {
        case SyntaxKind::OpenParenthesisToken:
            return ParseParenthesizedExpression();

        case SyntaxKind::FalseKeyword:
        case SyntaxKind::TrueKeyword:
            return ParseBooleanLiteral();

        case SyntaxKind::NumberToken:
            return ParseNumberLiteral();

        case SyntaxKind::IdentifierToken:
        default:
            return ParseNameExpression();
    }
}

ExpressionSyntax Parser::ParseParenthesizedExpression(){
    SyntaxToken left = MatchToken(SyntaxKind::OpenParenthesisToken);
    ExpressionSyntax expression = ParseExpression();
    SyntaxToken right = MatchToken(SyntaxKind::CloseParenthesisToken);
    return *new ParenthesizedExpressionSyntax(left, expression, right);
}

ExpressionSyntax Parser::ParseBooleanLiteral(){
    bool isTrue = Current().Kind == SyntaxKind::TrueKeyword;
    SyntaxToken keywordToken = isTrue ? MatchToken(SyntaxKind::TrueKeyword) : MatchToken(SyntaxKind::FalseKeyword);
    return *new LiteralExpressionSyntax(keywordToken, isTrue);
}

ExpressionSyntax Parser::ParseNumberLiteral()
{
    SyntaxToken numberToken = MatchToken(SyntaxKind::NumberToken);
    return *new LiteralExpressionSyntax(numberToken);
}

ExpressionSyntax Parser::ParseNameExpression()
{
    SyntaxToken identifierToken = MatchToken(SyntaxKind::IdentifierToken);
    return *new NameExpressionSyntax(identifierToken);
}

Parser::Parser(std::string text) { 
    std::vector<SyntaxToken> tokens;
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

    _text = text;
    _tokens = tokens; 
}

CompilationUnitSyntax Parser::ParseCompilationUnit(){
    StatementSyntax statement = ParseStatement();
    SyntaxToken endOfFileToken = MatchToken(SyntaxKind::EndOfFileToken);
    return *new CompilationUnitSyntax(statement, endOfFileToken);
}



