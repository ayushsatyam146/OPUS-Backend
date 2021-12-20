#include<string>
#include<vector>
#include<iostream>

#include "Syntax/include/lexer.hpp"

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
    // tokens array contains all the tokens of the input after lexing
    
    return 0;
}


// var showTree = false;
//             var variables = new Dictionary<VariableSymbol, object>();
//             var textBuilder = new StringBuilder();
//             Compilation previous = null;

//             while (true)
//             {
//                 Console.ForegroundColor = ConsoleColor.Green;

//                 if (textBuilder.Length == 0)
//                     Console.Write("» ");
//                 else
//                     Console.Write("· ");

//                 Console.ResetColor();

//                 var input = Console.ReadLine();
//                 var isBlank = string.IsNullOrWhiteSpace(input);

//                 if (textBuilder.Length == 0)
//                 {
//                     if (isBlank)
//                     {
//                         break;
//                     }
//                     else if (input == "#showTree")
//                     {
//                         showTree = !showTree;
//                         Console.WriteLine(showTree ? "Showing parse trees." : "Not showing parse trees");
//                         continue;
//                     }
//                     else if (input == "#cls")
//                     {
//                         Console.Clear();
//                         continue;
//                     }
//                     else if (input == "#reset")
//                     {
//                         previous = null;
//                         variables.Clear();
//                         continue;
//                     }
//                 }

//                 textBuilder.AppendLine(input);
//                 var text = textBuilder.ToString();

//                 var syntaxTree = SyntaxTree.Parse(text);

//                 if (!isBlank && syntaxTree.Diagnostics.Any())
//                     continue;

//                 var compilation = previous == null
//                                     ? new Compilation(syntaxTree)
//                                     : previous.ContinueWith(syntaxTree);

//                 var result = compilation.Evaluate(variables);

//                 if (showTree)
//                 {
//                     syntaxTree.Root.WriteTo(Console.Out);
//                 }

//                 if (!result.Diagnostics.Any())
//                 {
//                     Console.ForegroundColor = ConsoleColor.Magenta;
//                     Console.WriteLine(result.Value);
//                     Console.ResetColor();
//                     previous = compilation;
//                 }
//                 else
//                 {
//                     foreach (var diagnostic in result.Diagnostics)
//                     {
//                         var lineIndex = syntaxTree.Text.GetLineIndex(diagnostic.Span.Start);
//                         var line = syntaxTree.Text.Lines[lineIndex];
//                         var lineNumber = lineIndex + 1;
//                         var character = diagnostic.Span.Start - line.Start + 1;

//                         Console.WriteLine();

//                         Console.ForegroundColor = ConsoleColor.DarkRed;
//                         Console.Write($"({lineNumber}, {character}): ");
//                         Console.WriteLine(diagnostic);
//                         Console.ResetColor();

//                         var prefixSpan = TextSpan.FromBounds(line.Start, diagnostic.Span.Start);
//                         var suffixSpan = TextSpan.FromBounds(diagnostic.Span.End, line.End);

//                         var prefix = syntaxTree.Text.ToString(prefixSpan);
//                         var error = syntaxTree.Text.ToString(diagnostic.Span);
//                         var suffix = syntaxTree.Text.ToString(suffixSpan);

//                         Console.Write("    ");
//                         Console.Write(prefix);

//                         Console.ForegroundColor = ConsoleColor.DarkRed;
//                         Console.Write(error);
//                         Console.ResetColor();

//                         Console.Write(suffix);

//                         Console.WriteLine();
//                     }

//                     Console.WriteLine();
//                 }

//                 textBuilder.Clear();
//             }