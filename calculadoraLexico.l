%option noyywrap
DIGITO [0-9]
ENTEIRO {DIGITO}*
LETRA [a-zA-Z]
CARACTER [a-zA-Z0-9]
FLOTANTEEXP {ENTEIRO}[eE][+-]?{ENTEIRO}
FLOTANTEDEC {ENTEIRO}"."{ENTEIRO}
FLOTANTEDECEXP {FLOTANTEDEC}[eE][+-]?{ENTEIRO}
OPERADOR [\+\-\*\/\=\(\)\;\^]
PATH [\!][A-Za-z0-9\.\/]*
AXUDA "help"|"HELP"
RESET "reset"|"RESET"
TABLA "imprime"|"IMPRIME"
%{
#include <stdio.h>
#include <stdlib.h>
#include "tablaSimbolos.h"
#include "calculadoraSintactico.tab.h"
entrada_taboa *entrada;
%}
%%
{ENTEIRO} { //Numeros enteiros
  yylval.numero = atof(yytext);
  return NUM;
}
{FLOTANTEDEC} { //Numeros con decimais
  yylval.numero = atof(yytext);
  return NUM;
}
{FLOTANTEEXP} { //Numeros en notación cientifica
  yylval.numero = atof(yytext);
  return NUM;
}
{FLOTANTEDECEXP} { //Numeros en notación cientifica con decimais
  yylval.numero = atof(yytext);
  return NUM;
}
{OPERADOR} {
  return yytext[0];
} //Retornamos calquera operador

"exit" {
  printf("Pechando a sesion...\n");
  return EXIT;
}
"imprime" {
  return IMPRIME;
}
"reset" {
  return RESET;
}
"help" {
  return HELP;
}
"load "+{PATH} {

  FILE *fp=fopen(yytext+6,"r+");
  if (fp==NULL){
    printf("..::ERRO: O ficheiro pasado non está dispoñible::..\n");
  }else{
    yyin=fp;
  }

}
{LETRA}+{CARACTER}* {
  yylval.variable = (char *) malloc(sizeof (yytext));
	yylval.variable = strdup(yytext);
	return VAR;
}
<<EOF>> {
  fclose(yyin);
  yyin=stdin;
  yyrestart(stdin);
  return '\n';
}

\n  return '\n';
[\n\t\b\f]
%%
