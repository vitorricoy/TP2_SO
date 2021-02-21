#ifndef TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_FIFO_H
#define TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_FIFO_H

#include "../algoritmo_substituicao.h"
#include "../entrada_tabela.h"

class FIFO : public AlgoritmoSubstituicao {
    public:
        
        FIFO(MemoriaFisica* memoriaFisica);

        EntradaTabela determinaPagina();

    private:

};

#endif //TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_FIFO_H