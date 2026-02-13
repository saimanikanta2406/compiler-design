%{
#include <stdio.h>
int char_count = 0;
int word_count = 0;
int line_count = 0;
%}
%%
"//".*      ;    
"/*"([^*]|\n|(\*+([^*/]|\n)))*"*"+"/"   ;  
[ \t]+      ;    
\n          { line_count++; }
[a-zA-Z_][a-zA-Z0-9_]*   { word_count++; char_count += yyleng; }
[0-9]+      { word_count++; char_count += yyleng; }
\"([^\\\n]|(\\.))*\"   { word_count++; char_count += yyleng; }

.           { char_count++; }

%%
int main()
{
    yyin = fopen("sample.c", "r");

    if (yyin == NULL)
    {
        printf("File not found!\n");
        return 1;
    }
    yylex();
    printf("\n============================\n");
    printf("   COUNTING RESULT\n");
    printf("============================\n");
    printf("Total Characters : %d\n", char_count);
    printf("Total Words      : %d\n", word_count);
    printf("Total Lines      : %d\n", line_count);
    printf("============================\n");
    fclose(yyin);
    return 0;
}
int yywrap()
{
    return 1;
}
