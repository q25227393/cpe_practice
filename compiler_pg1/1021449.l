%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "y.tab.h"
%}

letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
num {digit}+
op [\+ \*]
%%
[Pp][Rr][Ii][Nn][Tt] {return PRINT;}
"+" {return PLUS;}  
"*" {return STAR;}
";" {return SEMI;}
"=" {return Equal;}
"(" {return Left_parenthesis;}
")" {return Right_parenthesis;}
"," {return Comma;}
{id} {yylval.string = strdup(yytext);
return (id);}
{num} {yylval.string = strdup(yytext);
return (num);}
%%

