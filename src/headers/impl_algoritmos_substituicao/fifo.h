#ifndef TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_FIFO_H
#define TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_FIFO_H

#include "../algoritmo_substituicao.h"

class FIFO : public AlgoritmoSubstituicao {
    public:
        
        FIFO(MemoriaFisica* memoriaFisica);

        void determinaPagina();

    private:

};

#endif //TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_FIFO_H