typedef double (*func_t) (double); // Tipo Función

struct entrada_taboa { // Tipo de datos que se emplearán en la estructura
    char *nome;
    int tipo; //1-> é unha variable ------- 2-> é unha función
    union {
        double var; // Aquialmacenamos as variables
        func_t fnctptr; // Aqui almacenamos as funcións
    } valor;
    int c; //1-> é unha constante(non se pode modificar)
           //2-> é unha entrada normal dunha variable ou numero
    struct entrada_taboa *next; // Campo que enlaza con el siguiente dato de la estructura
};

typedef struct entrada_taboa entrada_taboa;

extern entrada_taboa *taboa_simbolos;

void inicializarTaboaSimbolos();
void deleteTaboa();
void liberarEntrada(entrada_taboa **nodo);
void resetTaboa();
void imprimirVariables();
void imprimirFuncions();
entrada_taboa *setValorTaboa (char const *sym_nome, int sym_tipo, int sym_const);
entrada_taboa *obterValorTaboa (char const *sym_nome);
entrada_taboa *entradaNula (char const *sym_nome);
entrada_taboa *entradaNumero (double numero);
void cambiarValorVariable(char const *sym_nome, double novoValor);
double valorVariable(char const *sym_nome);
int esVariable(char const *sym_nome);
int esConstante(char const *sym_nome);
int esFuncion(char const *sym_nome);
