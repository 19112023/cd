% {
   #include<stdio.h>
% }

% %
[ \n\t]+ {fprintf(yyout, "%s");}
.       { fprintf(yyout, "%s", yytext); }
% %

int main()
{

    extern FILE *yyin, *yyout;
    yyin = fopen("Input.txt", "r");
    yyout = fopen("Output.txt", "w");
 
    yylex();
    return 0;
}