#include <stdio.h>
#include <stdlib.h>
void axuda(){
  printf("\n\n.......:::::::::::::CALCULADORA DE COMPILADORES E INTERPRETES:::::::::::::.......\n\n");
  printf("***AXUDA PARA O USUARIO***\n");
  printf("->Só se permite unha *SOA* operación por liña\n\n\n");
  printf("->Existen as seguintes --OPERACIÓNS ARITMÉTICAS BÁSICAS--:\n\n");
  printf("\t---*SUMA*->[+]\n");
  printf("\t\t*exemplo*\t5 + 4;\n\t\t\t\t-> 9\n\n");
  printf("\t---*RESTA*->[-]\n");
  printf("\t\t*exemplo*\t5 - 4;\n\t\t\t\t-> 1\n\n");
  printf("\t---*PRODUCTO*->[*]\n");
  printf("\t\t*exemplo*\t5 * 4;\n\t\t\t\t-> 20\n\n");
  printf("\t---*COCIENTE*->[/]\n");
  printf("\t\t*exemplo*\t30 / 2;\n\t\t\t\t-> 15\n\n");
  printf("\t---*POTENCIA*->[^]\n");
  printf("\t\t*exemplo*\t5 ^ 4;\n\t\t\t\t-> 625\n\n");
  printf("->Existen dúas opcións á hora de realizar as --OPERACIÓNS--:\n\n");
  printf("\t---Se *NON* utilizas punto e coma ó final das sentencias non se nos mostra nada á saída\n");
  printf("\t\t*exemplo:*\t4 + 5\n\t\t\t\t->\t(o interprete espera por máis ordes)\n");
  printf("\t---Se *SI* utilizas punto e coma ó final das sentencias móstrase o resultado á saída\n");
  printf("\t\t*exemplo*\t4 + 5;\n\t\t\t\t-> 9\n\n\n");
  printf("->Existen as seguintes --FUNCIÓNS MATEMÁTICAS--:\n\n");
  printf("\t---*COSENO*->cos\n");
  printf("\t\t*exemplo*\tcos(0);\n\t\t\t\t-> 1\n\n");
  printf("\t---*SENO*->sin()\n");
  printf("\t\t*exemplo*\tsin(0);\n\t\t\t\t-> 0\n\n");
  printf("\t---*TANXENTE*->tan()\n");
  printf("\t\t*exemplo*\ttan(0);\n\t\t\t\t-> 0\n\n");
  printf("\t---*LOGARITMO NEPERIANO*->ln()\n");
  printf("\t\t*exemplo*\tln(1);\n\t\t\t\t-> 0\n\n");
  printf("\t---*RAÍZ CADRADA*->sqrt()\n");
  printf("\t\t*exemplo*\tsqrt(64);\n\t\t\t\t-> 8\n\n");
  printf("\t---*Todas estas funcións pódenselle aplicar a VARIABLES\n");
  printf("\t---*Tamén se pode almacenar a SAÍDA destas funcións en VARIABLES\n");
  printf("\t\t*exemplo*\ta=sqrt(64)\n\t\t\t\ta;\n\t\t\t\t->8\n");
  printf("->Para a xestión da calculadora temos disploñibles os seguintes --COMANDOS--:\n\n");
  printf("\t---*EXIT*->[exit]\n");
  printf("\t\t*funcionalidade*\tPermite o peche da calculadora e polo tanto a saída do programa.\n\n");
  printf("\t---*HELP*->[help]\n");
  printf("\t\t*funcionalidade*\tMostra as opcións que oferta a calculadora.\n\n");
  printf("\t---*RESET*->[reset]\n");
  printf("\t\t*funcionalidade*\tResetea a taboa de símbolos ó estado no que estaba cando se iniciou a calculadora\n\n");
  printf("\t---*IMPRIME*->[imprime]\n");
  printf("\t\t*funcionalidade*\tImprime o estado da taboa de simbolos.\n\n");
  printf("\t---*LOAD*->[load] ![nome_arquivo]\n");
  printf("\t\t*funcionalidade*\tRealiza as operacións que estén presentes no arquivo adxunto.\n\n");
}
