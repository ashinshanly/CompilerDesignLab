%{
#include<stdio.h>
int flag=0;
%}

%token num
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
Arithmeticxpression: E {
printf("Result = %d\n",$$);
return 0;
};

E : E'+'E { $$ = $1+$3; }
  |E'-'E { $$ = $1-$3; } 
  |E'*'E { $$ = $1*$3; }
  |E'/'E { $$ = $1/$3; }
  |E'%'E { $$ = $1%$3; }
  |'('E')' { $$ = $2; }
  | num { $$ = $1; } 
  ;

%%

void yyerror(){
flag=1; 
printf("\n Exression is invalid");
}

void main()
{
printf("\nExpression: ");
yyparse();
}

