#include "algoritmo_substituicao.h"

char* algoritmoSubstituicao;

unsigned AlgoritmoSubstituicao_determinaPagina() {
    if(strcmp(algoritmoSubstituicao, "fifo")) {
        return FIFO();
    }
    if(strcmp(algoritmoSubstituicao, "lru")) {
        return LRU();
    }
    if(strcmp(algoritmoSubstituicao, "2c")) {
        return segundaChance();
    }
    if(strcmp(algoritmoSubstituicao, "novo")){
        return Novo();
    }
}

void algoritmoSubstituicao_inicializar(char* algSub) {
    algoritmoSubstituicao = algSub;
}