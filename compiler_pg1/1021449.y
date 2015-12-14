%{
#include <ctype.h>
#include <stdio.h> /* C 內建函數 */
#include <string.h> /* 用來幫數比較字串函數 */
void add_to_table(char *); /* 將變數加入 Symbol Table 之函數 */
void yyerror(char *); /* 偵錯函數 */
int check(char *); /* 檢查是否與 Symbol Table 內的變數重複之函數 */
void dump_symbol_table();
char * symbol_table[100]; /* Symbol Table 的指標型 Array */
int NumberOfID; /* 計算 Symbol Table 內的個數值 */
int i; /* 計數變數 */
%}

%token BASIC WRITE TRUE FALSE BLEFT BRIGHT AND OR NOT SLEFT
SRIGHT ASSIGN Equal Left_parenthesis Right_parenthesis Comma Print Semicolon  num

%union
{
char *string;
}

%token <string> num
%token <string> id
%token PLUS STAR SEMI Equal Comma Right_parenthesis Left_parenthesis PRINT

%%
Stm: Stm{printf("%s\n", "Statement");}SEMI Stm {printf("%s\n", "Statemant");} {dump_symbol_table();}
       | id{add_to_table(strdup($1));} Equal Exp{printf("%S\n", "Assign");}
       | Print Left_parenthesis Explist Right_parenthesis  {printf("%s\n","Print");}
       ;
Exp: Exp Binop Exp {printf("%s\n", "Op");}
  | Left_parenthesis Stm Comma Exp Right_parenthesis {printf("%S\n", "Sequence");}
  | id
  | num
  ;
Explist: Exp Comma Explist{printf("%s\n", "Pair");}
        | Exp {printf("%s\n", "Last");}
        ;
Binop: PLUS
       | STAR
       ;

%%
void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}
int  yywrap()
{
    return 1;
}

int main(void)
{
    NumberOfID = 0; /* 放入初始值 */
    yyparse();
    dump_symbol_table();
    return 0;
}
void add_to_table(char *temp)
{
    symbol_table[NumberOfID] = temp;
    NumberOfID = NumberOfID + 1;
}
void dump_symbol_table()
{
    printf("Identifiers in the symbol table: ");
    for(i = 0; i < NumberOfID; i++ ){
        printf("%s ",symbol_table[i]);
    }
    printf("\n");
}
int check(char *temp){
    for(i = 0; i < NumberOfID; i++ ){
        if(strcmp(symbol_table[i],temp) == 0)
            return 1;
        return 0;
    }
}
