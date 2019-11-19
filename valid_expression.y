%{
#include<stdio.h>
int valid =1;
%}
%token ID NUMBER
%left '=' '+' '-'
%left '*' '/'
%%
stmt: expr
    ;
expr: expr '=' expr
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    | ID
    ;
%%
int yyerror() { 
valid=0;
printf("Invalid!");
return 0;
}
void main(){
printf("Expression: ");

yyparse();
if(valid) { printf("Valid Expression!"); }
}
yywrap(){}
