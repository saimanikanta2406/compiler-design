%{
#include <stdio.h>

int whitespace_count = 0;
int newline_count = 0;
%}

%%

[ \t]+      { whitespace_count += yyleng; }
\n          { newline_count++; }
.           { /* ignore other characters */ }

%%

int main()
{
    printf("Enter the input (Ctrl+D to stop):\n");
    yylex();
    printf("\nNumber of whitespaces: %d", whitespace_count);
    printf("\nNumber of newlines: %d\n", newline_count);
    return 0;
}

int yywrap()
{
    return 1;
}
