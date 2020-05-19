flex calculadoraLexico.l
bison -d calculadoraSintactico.y
#comentar a liña que está xusto encima se usamos OSX e descomentar a inmediatamente inferior
#/usr/local/Cellar/bison/3.4.2/bin/bison -d calculadoraSintactico.y
gcc calculadoraSintactico.tab.c tablaSimbolos.c codigoAuxiliar.c -lm -lfl -o calculadora

