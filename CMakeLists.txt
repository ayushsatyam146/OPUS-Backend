cmake_minimum_required(VERSION 2.4)

project(test_proj) 

add_executable(app 
src/main.cpp  
src/Syntax/lib/AssignmentExpressionSyntax.cpp 
src/Syntax/lib/BinaryExpressionSyntax.cpp 
src/Syntax/lib/BlockStatementSyntax.cpp 
src/Syntax/lib/CompilationUnitSyntax.cpp 
src/Syntax/lib/ElseClauseSyntax.cpp 
src/Syntax/lib/ExpressionStatementSyntax.cpp 
src/Syntax/lib/ExpressionSyntax.cpp 
src/Syntax/lib/ForStatementSyntax.cpp 
src/Syntax/lib/IfStatementSyntax.cpp 
src/Syntax/lib/LiteralExpressionSyntax.cpp 
src/Syntax/lib/NameExpressionSyntax.cpp 
src/Syntax/lib/ParenthesizedExpressionSyntax.cpp 
src/Syntax/lib/Parser.cpp 
src/Syntax/lib/StatementSyntax.cpp 
src/Syntax/lib/SyntaxFacts.cpp 
src/Syntax/lib/SyntaxNode.cpp 
src/Syntax/lib/SyntaxToken.cpp 
src/Syntax/lib/SyntaxTree.cpp 
src/Syntax/lib/UnaryExpressionSyntax.cpp 
src/Syntax/lib/VariableDeclarationSyntax.cpp 
src/Syntax/lib/WhileStatementSyntax.cpp 
src/Syntax/lib/lexer.cpp 
)

set(EXECUTABLE_OUTPUT_PATH src)



