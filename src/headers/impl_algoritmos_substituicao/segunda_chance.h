#ifndef TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_SEGUNDA_CHANCE_H
#define TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_SEGUNDA_CHANCE_H

#include "../algoritmo_substituicao.h"
#include "../entrada_tabela.h"

class SegundaChance : public AlgoritmoSubstituicao {
    public:
        
        SegundaChance(MemoriaFisica* memoriaFisica);

        EntradaTabela determinaPagina();

        
    private:

};

#endif //TP2_SO_SRC_HEADERS_IMPL_ALGORITMOS_SUBSTITUICAO_SEGUNDA_CHANCE_H