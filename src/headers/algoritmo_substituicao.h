#ifndef TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H
#define TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H

#include "entrada_tabela.h"
#include "memoria_fisica.h"

class AlgoritmoSubstituicao {
    public:
        
        AlgoritmoSubstituicao(MemoriaFisica* memoriaFisica);

        virtual EntradaTabela determinaPagina() = 0;

    protected:
        bool debug;
        MemoriaFisica* memoriaFisica;
};

#endif //TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H