#ifndef TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_NOVO_H
#define TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_NOVO_H

#include "../algoritmo_substituicao.h"
#include "../entrada_tabela.h"

class Novo : public AlgoritmoSubstituicao {
    public:
        
        Novo(MemoriaFisica* memoriaFisica);

        EntradaTabela determinaPagina();

    private:

};

#endif //TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_NOVO_H