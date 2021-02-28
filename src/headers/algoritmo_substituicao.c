#include <string.h>
#include "algoritmo_substituicao.h"
#include "impl_algoritmos_substituicao/fifo.h"
#include "impl_algoritmos_substituicao/lru.h"
#include "impl_algoritmos_substituicao/novo.h"
#include "impl_algoritmos_substituicao/segunda_chance.h"

char* algoritmoSubstituicao;

// Inicializa a variável que guarda qual o algoritmo de substituição escolhido
unsigned AlgoritmoSubstituicao_determinaPagina() {
    
    // Verifica qual foi o algoritmo escolhido e chama a função correspondente
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

// Determina a página que deve ser removida de acordo com o algoritmo escolhido
void algoritmoSubstituicao_inicializar(char* algSub) {
    algoritmoSubstituicao = algSub;
}