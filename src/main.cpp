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
    unsigned tamanhoPagina = atoi(argv[3]);
    unsigned tamanhoMemoria = atoi(argv[4]);
    bool debug = argc == 5;
    
    FILE* arquivo = fopen(arquivoEntrada, "r");

    unsigned endereco;
    char rw;

    while(fscanf(arquivo, "%x %c", &endereco, &rw) != EOF) {
        unsigned s = 0, temp = tamanhoPagina;
        while (temp > 1) {
            temp = temp >> 1;
            s++;
        }
        //Tratar ação
    }

    return 0;
}