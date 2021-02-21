#ifndef TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_LRU_H
#define TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_LRU_H

#include "../algoritmo_substituicao.h"
#include "../entrada_tabela.h"

class LRU : public AlgoritmoSubstituicao {
    public:
        
        LRU(MemoriaFisica* memoriaFisica);

        EntradaTabela determinaPagina();
        
    private:

};

#endif //TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_LRU_H