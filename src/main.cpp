#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc != 4 && argc != 5) {
        printf("Argumentos incorretos.");
        return 0;
    }
    char* algoritmoSubstituicao = argv[1];
    char* arquivoEntrada = argv[2];
    int tamanhoPagina = atoi(argv[3]);
    int tamanhoMemoria = atoi(argv[4]);
    bool debug = argc == 5;
    
    return 0;
}