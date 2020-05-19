#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tablaSimbolos.h"
#include "calculadoraSintactico.tab.h"

entrada_taboa *taboa;

//Inicializa os valores da taboa de simbolos
void inicializarTaboaSimbolos(){
	entrada_taboa *Pi = setValorTaboa("pi", 1, 1);
	Pi->valor.var = M_PI;
	entrada_taboa *E = setValorTaboa("e", 1, 1);
	E->valor.var = M_E;
	entrada_taboa *Cos = setValorTaboa("cos", 2, 1);
	Cos->valor.fnctptr = cos;
	entrada_taboa *Sin = setValorTaboa("sin", 2, 1);
	Sin->valor.fnctptr = sin;
	entrada_taboa *Tan = setValorTaboa("tan", 2, 1);
	Tan->valor.fnctptr = tan;
	entrada_taboa *Ln = setValorTaboa("ln", 2, 1);
	Ln->valor.fnctptr = log;
	entrada_taboa *Sqrt = setValorTaboa("sqrt", 2, 1);
	Sqrt->valor.fnctptr=sqrt;
}

//Borra a taboa de simbolos por completo
void deleteTaboa(){
        liberarEntrada(&taboa);
        taboa=NULL;
}

//Libera unha entrada da taboa
void liberarEntrada(entrada_taboa **nodo){
        if ((*nodo)->next!=NULL){
            liberarEntrada(&((*nodo)->next));
        }
        free((*nodo)->nome);
        free(*nodo);
}

//Resetea os valores da taboa de simbolos por completo
void resetTaboa(){
    deleteTaboa();
    inicializarTaboaSimbolos();
}

//Imprime as variables presentes na taboa de simbolos (Non imprime as constantes)
void imprimirVariables(){
    printf("\n---Variables na taboa de simbolos:---\n");
    entrada_taboa *s=taboa;
    while(s != NULL){
        if(s->nome != NULL && s->tipo == 1 && s->c==2){
            printf("->%s = %f\n", s->nome, s->valor.var);
        }
        s=s->next;
    }
}

//Imprime as funcions matematicas presentes na taboa de simbolos
void imprimirFuncions(){
    printf("\n---Funcions na taboa de simbolos:---\n");
    entrada_taboa *s=taboa;

    while(s != NULL){
        if(s->nome != NULL && s->tipo == 2){
            printf("->%s\n", s->nome);
        }
        s=s->next;
    }
}


//Crea unha nova entrada na taboa de simbolos
entrada_taboa *setValorTaboa (char const *sym_nome, int sym_tipo, int sym_const) {
    entrada_taboa *ptr = (entrada_taboa *) malloc (sizeof (entrada_taboa));
    ptr->nome = (char *) malloc (strlen (sym_nome) + 1);
    strcpy (ptr->nome,sym_nome);
    ptr->tipo = sym_tipo;
    ptr->valor.var = 0;
    ptr->c = sym_const;
    ptr->next = (struct entrada_taboa *)taboa;
    taboa = ptr;
    return ptr;
}

//Retorna a entrada da taboa correspondente. En caso de non existir, retorna NULL
entrada_taboa *obterValorTaboa (char const *sym_nome) {
    entrada_taboa *ptr;
    for (ptr = taboa; ptr != (entrada_taboa *) 0; ptr = (entrada_taboa *)ptr->next){
        if (strcmp (ptr->nome, sym_nome) == 0){
            return ptr;
        }
    }
    return NULL;
}
//Aqui comezan as funcions mais utiles para o usuario da taboa de simbolos
//Retornaa o valor numerico de unha variable
double valorVariable(char const *sym_nome){
	double resultado;
	entrada_taboa *entrada;
	entrada =obterValorTaboa(sym_nome);
	if(entrada == NULL){
			//printf("A variable da que se quere obter o valor non esta instanciada na taboa de simbolos\n");
			return -1;
	}
	if(entrada->tipo==2){
		//printf("Esta variable correspondese co nome dunha funcion matematica\n");
		return -1;
	}
	resultado=entrada->valor.var;
	return resultado;
}

//Cambia o valor numerico dunha variable
void cambiarValorVariable(char const *sym_nome, double novoValor){
	entrada_taboa *entrada;
	entrada =obterValorTaboa(sym_nome);
	if(entrada == NULL){
			//printf("A variable a que se lle quere cambiar o valor non esta instanciada na taboa de simbolos\n");
			return;
	}
	if(entrada->c==1){
		//printf("Esta variable correspondese con unha constante e polo tanto non se pode modificar\n");
		return;
	}
	if(entrada->tipo==2){
		//printf("Esta variable correspondese co nome dunha funcion matematica\n");
		return;
	}
	entrada->valor.var=novoValor;
}

int esVariable(char const *sym_nome){
	entrada_taboa *entrada;
	entrada =obterValorTaboa(sym_nome);
	if(entrada->tipo==1 && entrada->c==2){
		return 1;
	}else{
		return 0;
	}
}
int esConstante(char const *sym_nome){
	entrada_taboa *entrada;
	entrada =obterValorTaboa(sym_nome);
	if(entrada->tipo==1 && entrada->c==1){
		return 1;
	}else{
		return 0;
	}
}
int esFuncion(char const *sym_nome){
	entrada_taboa *entrada;
	entrada =obterValorTaboa(sym_nome);
	if(entrada->tipo==2){
		return 1;
	}else{
		return 0;
	}
}
