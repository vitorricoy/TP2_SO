#ifndef TP2_SO_SRC_HEADERS_TABELA_PAGINA_H
#define TP2_SO_SRC_HEADERS_TABELA_PAGINA_H

#include "entrada_tabela.h"
#include "algoritmo_substituicao.h"
#include "memoria_fisica.h"


class TabelaPaginas {
    public:

        TabelaPaginas(unsigned tamanhoPagina, unsigned numeroPaginas, MemoriaFisica* memoriaFisica, AlgoritmoSubstituicao* algoritmo, bool debug);
        ~TabelaPaginas();
        
        bool lerEndereco(unsigned endereco);
        bool escreverEndereco(unsigned endereco);


    private:
        EntradaTabela* entradas;
        AlgoritmoSubstituicao* algoritmoSubstituicao;
        MemoriaFisica* memoriaFisica;
        bool debug;
        unsigned tamanhoPagina;
        unsigned numeroPaginas;
};

#endif //TP2_SO_SRC_HEADERS_TABELA_PAGINA_H