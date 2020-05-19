%{
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lex.yy.c"
#include "codigoAuxiliar.h"
int yylex (void);
void yyerror(const char* msg) {
      fprintf(stderr, "%s\n", msg);
   }
   extern FILE *yyin;
%}
%union{
  double numero;
  char *variable;
}
%token <variable> VAR
%token <numero> NUM

%token EXIT
%token IMPRIME
%token RESET
%token HELP
%token LOAD
%left '-' '+'
%left '*' '/'
%precedence NEG // Negación
%type <numero> exp
%right '^'
%precedence '='
%%
input:
  %empty
  | input line
;
line: '\n'
      | exp ';' '\n' {printf ("->%.10g\n", $1); }
      | exp '\n'
      | EXIT '\n'{
        deleteTaboa();
        printf("Memoria liberada...\n");
        printf("Un saúdo\n");
        exit(0);
      }
      | IMPRIME '\n'{
        imprimirVariables();
      }
      | RESET '\n'{
        printf("Reiniciando a táboa de símbolos...\n");
        resetTaboa();
        printf("Táboa reiniciada, xa podes añadir variables.\n");
      }
      | HELP '\n'{
        axuda();
      }
;
exp:
  NUM                  {$$=$1;}
  | VAR '=' exp        {
                          entrada_taboa *entrada;
                          entrada =obterValorTaboa($1);
                          if(entrada==NULL){
                            setValorTaboa($1, 1, 2);
                          }
                          if(esFuncion($1) || esConstante($1)){
                            printf("..::ERRO: Non e posible acceder a esta variable::..\n");
                          }
                          cambiarValorVariable($1, $3);
                          $$ = $3;
                      }
| VAR                {
                          entrada_taboa *entrada;
                          entrada =obterValorTaboa($1);
                          if(entrada==NULL){
                            printf("..::ERRO: A variable %s non esta inicializada::..\n", $1);
                            return -1;
                          }
                          $$ = valorVariable($1);
                      }
  | VAR '('exp')'      {
                          entrada_taboa *entrada;
                          entrada =obterValorTaboa($1);
                          if(entrada==NULL ){
                            printf("..::ERRO: A funcion que pretendes empregar non esta na taboa de simbolos, usa o comando -> **help** para comprobar que funcions se poden executar::..\n");
                            return -1;
                          }
                          if(!esFuncion($1)){
                            printf("..::ERRO: A funcion que pretendes empregar non esta na taboa de simbolos, usa o comando -> **help** para comprobar que funcions se poden executar::..\n");
                            return -1;
                          }
                          $$ = (*(entrada->valor.fnctptr))($3);
                        }
  | exp '+' exp        {$$ = $1 + $3;}
  | exp '-' exp        {$$ = $1 - $3;}
  | exp '*' exp        {$$ = $1 * $3;}
  | exp '/' exp        {
                          if($3!=0){
                            $$ = $1 / $3;
                          }else{
                            printf("..::ERRO: Non se pode dividir entre 0::..\n");
                            return -1;
                          }
                        }
  | exp '^' exp        {$$ = pow ($1, $3);}
  | '(' exp ')'        {$$ = $2;}
  | '-' exp  %prec NEG {$$=-$2;}
;
%%
int  main(int argc,char **argv){
  printf("\n\n.......:::::::::::::CALCULADORA DE COMPILADORES E INTERPRETES:::::::::::::.......\n\n");
  printf("***INICIANDO CALCULADORA***\n");
  printf("->Podes ver as funcións, operacións e comandos co comando -> **help**\n\n");
  inicializarTaboaSimbolos();
  if (argc>1){
    yyin=fopen(argv[1],"rt");
  }else{
    yyin=stdin;
  }
  while(1){
    yyparse();
  }

  return 0;
}
