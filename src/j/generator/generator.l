
%option noyywrap
%{ 
	#define ONE_LINE_COMMENT 1001
	#define INLINE_COMMENT 1002
	#define FOR 1003
	#define ID 1004
	#define END 1005
	#define SEPARATOR 1006
	#define EXCEPT_CURRENT_OFFSET 1007

	#include<stdio.h>
	using namespace std;

	#define INNERSET_NUMBER = 1;
%}
%%
<ONE_LINE_COMMENT>\n { BEGIN(INITIAL); }
<INLINE_COMMENT>\*\/ { BEGIN(INTIAL); }
<ONE_LINE_COMMENT,INLINE_COMMENT>[a-z]([a-z]|[0-9]|\_)* { return ID; }
<ONE_LINE_COMMENT,INLINE_COMMENT>for { return FOR; }
<ONE_LINE_COMMENT,INLINE_COMMENT>end { return END; }
<ONE_LINE_COMMENT,INLINE_COMMENT>except_current_offset { return EXCEPT_CURRENT_OFFSET; }
<ONE_LINE_COMMENT,INLINE_COMMENT>separator=' { BEGIN(SEPARATOR); }
<SEPARATOR>[^'] { return SEPARATOR; }
<SEPARATOR>' { BEGIN(INITIAL); }
\/\/ { BEGIN(ONE_LINE_COMMENT); }
\/\* { BEGIN(INLINE_COMMENT); }
.|\n {return yytext[0];}
%%

int main(int argc, char *argv[])
{
	FILE *template;

    if (argc == 2 && (template = fopen(argv[1], "r")))
        yyin = template;
    yylex();
    return 0;
}