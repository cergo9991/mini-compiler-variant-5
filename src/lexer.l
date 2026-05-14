%option noyywrap nounput noinput yylineno
%x COMMENT
FLOATLIT    (([0-9]+\.[0-9]*|\.[0-9]+)([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+)

%{
#include <cstdlib>
#include <cstring>
#include "parser.hpp"

static int yycolumn = 1;

#define YY_USER_ACTION                                      \
    do {                                                    \
        yylloc.first_line = yylloc.last_line = yylineno;    \
        yylloc.first_column = yycolumn;                     \
        yylloc.last_column = yycolumn + yyleng - 1;         \
        yycolumn += yyleng;                                 \
    } while (0);
%}

%%

[ \t\r]+                    ;
\n                          { yycolumn = 1; }
"//".*                      ;
"/*"                        { BEGIN(COMMENT); }
<COMMENT>"*/"               { BEGIN(INITIAL); }
<COMMENT>\n                 { yycolumn = 1; }
<COMMENT>.                  ;

"return"                    { return RETURN; }
"if"                        { return IF; }
"else"                      { return ELSE; }
"for"                       { return FOR; }
"do"                        { return DO; }
"while"                     { return WHILE; }
"int"                       { return INT_KW; }
"float"                     { return FLOAT_KW; }
"=="                        { return EQ; }
"!="                        { return NE; }
"<="                        { return LE; }
">="                        { return GE; }
"&&"                        { return AND; }
"||"                        { return OR; }

{FLOATLIT}                  { yylval.float_value = std::strtod(yytext, nullptr); return FLOAT_LITERAL; }
[0-9]+                      { yylval.int_value = std::strtoll(yytext, nullptr, 10); return INTEGER; }
[A-Za-z_][A-Za-z0-9_]*      { yylval.str = ::strdup(yytext); return IDENT; }

.                           { return yytext[0]; }

%%
