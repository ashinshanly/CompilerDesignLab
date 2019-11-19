%{
#include<stdio.h> 
int count=0;
%}
%token IF RELOP S NUMBER ID

%%
stmt : if_stmt { printf("No of nested IF statements=%d\n",count); return 0; }
     ;
if_stmt : IF'('cond')''{'if_stmt'}' {count++;}
	| S;
	;
cond : x RELOP x
     ;
x : ID
  | NUMBER
  ;
%%

int yyerror()
{
 printf("Invalid Expression\n");
 return 0;
}
void main()
{
 printf("Enter the statement: ");
 yyparse();
} 
