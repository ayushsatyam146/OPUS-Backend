#pragma once 
#include<map>
#include<iterator>

enum SyntaxKind {
    // Tokens
    BadToken,
    EndOfFileToken,
    WhitespaceToken,
    NumberToken,
    PlusToken,
    MinusToken,
    StarToken,
    SlashToken,
    BangToken,
    EqualsToken,
    AmpersandAmpersandToken,
    PipePipeToken,
    EqualsEqualsToken,
    BangEqualsToken,
    LessToken,
    LessOrEqualsToken,
    GreaterToken,
    GreaterOrEqualsToken,
    OpenParenthesisToken,
    CloseParenthesisToken,
    OpenBraceToken,
    CloseBraceToken,
    IdentifierToken,

    // Keywords
    ElseKeyword,
    FalseKeyword,
    ForKeyword,
    IfKeyword,
    LetKeyword,
    ToKeyword,
    TrueKeyword,
    VarKeyword,
    WhileKeyword,

    // Nodes
    CompilationUnit,
    ElseClause,

    // Statements
    BlockStatement,
    VariableDeclaration,
    IfStatement,
    WhileStatement,
    ForStatement,
    ExpressionStatement,

    // Expressions
    LiteralExpression,
    NameExpression,
    UnaryExpression,
    BinaryExpression,
    ParenthesizedExpression,
    AssignmentExpression,
};


const std::map<SyntaxKind,std::string> SyntaxKindText = {   
    {SyntaxKind::BadToken,"BadToken"},
    {SyntaxKind::EndOfFileToken,"EndOfFileToken"},
    {SyntaxKind::WhitespaceToken,"WhitespaceToken"},
    {SyntaxKind::NumberToken,"NumberToken"},
    {SyntaxKind::PlusToken,"PlusToken"},
    {SyntaxKind::MinusToken,"MinusToken"},
    {SyntaxKind::StarToken,"StarToken"},
    {SyntaxKind::SlashToken,"SlashToken"},
    {SyntaxKind::BangToken,"BangToken"},
    {SyntaxKind::EqualsToken,"EqualsToken"},
    {SyntaxKind::AmpersandAmpersandToken,"AmpersandAmpersandToken"},
    {SyntaxKind::PipePipeToken,"PipePipeToken"},
    {SyntaxKind::EqualsEqualsToken,"EqualsEqualsToken"},
    {SyntaxKind::BangEqualsToken,"BangEqualsToken"},
    {SyntaxKind::LessToken,"LessToken"},
    {SyntaxKind::LessOrEqualsToken,"LessOrEqualsToken"},
    {SyntaxKind::GreaterToken,"GreaterToken"},
    {SyntaxKind::GreaterOrEqualsToken,"GreaterOrEqualsToken"},
    {SyntaxKind::OpenParenthesisToken,"OpenParenthesisToken"},
    {SyntaxKind::CloseParenthesisToken,"CloseParenthesisToken"},
    {SyntaxKind::OpenBraceToken,"OpenBraceToken"},
    {SyntaxKind::CloseBraceToken,"CloseBraceToken"},
    {SyntaxKind::IdentifierToken,"IdentifierToken"},

    // Keywords
    {SyntaxKind::ElseKeyword,"ElseKeyword"},
    {SyntaxKind::FalseKeyword,"FalseKeyword"},
    {SyntaxKind::ForKeyword,"ForKeyword"},
    {SyntaxKind::IfKeyword,"IfKeyword"},
    {SyntaxKind::LetKeyword,"LetKeyword"},
    {SyntaxKind::ToKeyword,"ToKeyword"},
    {SyntaxKind::TrueKeyword,"TrueKeyword"},
    {SyntaxKind::VarKeyword,"VarKeyword"},
    {SyntaxKind::WhileKeyword,"WhileKeyword"},

    // Nodes
    {SyntaxKind::CompilationUnit,"CompilationUnit"},
    {SyntaxKind::ElseClause,"ElseClause"},

    // Statements
    {SyntaxKind::BlockStatement,"BlockStatement"},
    {SyntaxKind::VariableDeclaration,"VariableDeclaration"},
    {SyntaxKind::IfStatement,"IfStatement"},
    {SyntaxKind::WhileStatement,"WhileStatement"},
    {SyntaxKind::ForStatement,"ForStatement"},
    {SyntaxKind::ExpressionStatement,"ExpressionStatement"},

    // Expressions
    {SyntaxKind::LiteralExpression,"LiteralExpression"},
    {SyntaxKind::NameExpression,"NameExpression"},
    {SyntaxKind::UnaryExpression,"UnaryExpression"},
    {SyntaxKind::BinaryExpression,"BinaryExpression"},
    {SyntaxKind::ParenthesizedExpression,"ParenthesizedExpression"},
    {SyntaxKind::AssignmentExpression,"AssignmentExpression"},
};