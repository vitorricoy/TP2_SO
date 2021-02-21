#ifndef TP2_SO_SRC_HEADERS_MMU_H
#define TP2_SO_SRC_HEADERS_MMU_H

#include "entrada_tabela.h"
#include "algoritmo_substituicao.h"
#include "memoria_fisica.h"


class MMU {
    public:

        MMU(MemoriaFisica* memoriaFisica, unsigned* contadorPaginasSujas, AlgoritmoSubstituicao* algoritmo, bool debug);
        
        bool lerEndereco(unsigned endereco);
        bool escreverEndereco(unsigned endereco);
        
        void buscaPaginaParaMemoria(unsigned endereco);

    private:
        AlgoritmoSubstituicao* algoritmoSubstituicao;
        MemoriaFisica* memoriaFisica;
        unsigned* contadorPaginasSujas;
        bool debug;
};

#endif //TP2_SO_SRC_HEADERS_MMU_H