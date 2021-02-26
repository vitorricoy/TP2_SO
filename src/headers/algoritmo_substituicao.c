#include <string.h>
#include "algoritmo_substituicao.h"
#include "impl_algoritmos_substituicao/fifo.h"
#include "impl_algoritmos_substituicao/lru.h"
#include "impl_algoritmos_substituicao/novo.h"
#include "impl_algoritmos_substituicao/segunda_chance.h"

char* algoritmoSubstituicao;

unsigned AlgoritmoSubstituicao_determinaPagina() {
    if(!strcmp(algoritmoSubstituicao, "fifo")) {
        return FIFO();
    }
    if(!strcmp(algoritmoSubstituicao, "lru")) {
        return LRU();
    }
    if(!strcmp(algoritmoSubstituicao, "2a")) {
        return segundaChance();
    }
    return novo();
}

void algoritmoSubstituicao_inicializar(char* algSub) {
    algoritmoSubstituicao = algSub;
}