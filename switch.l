%{
#include "y.tab.h"
%}

%%

[0-9]+ { return NUM; }
"switch" { return SWITCH; }
"case" { return CASE; }
"break" { return BREAK; }
[a-zA-Z] { return ID; }
[ \t] {;}
\n { return 0; }
. { return yytext[0]; }
%%

int yywrap(){ return 1; }
