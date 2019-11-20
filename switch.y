%{
#include<stdio.h>
int flag=1;
%}

%token ID NUM CASE SWITCH BREAK

%% 

S : stmt
  ;
stmt : SWITCH '(' ID ')' '{' expr1 '}'
     ;
expr1 : CASE NUM ':' expr ';' BREAK ';' expr1
     | BREAK ';'
     |
     ;
expr : E '+' E
E : ID
  | NUM
  ;

%%

int yyerror(){

flag=0;
printf("INVALID!");

}

void main(){

printf("Expression: ");
yyparse();
if(flag){ printf("VALID!"); }

}
