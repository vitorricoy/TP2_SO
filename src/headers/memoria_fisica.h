#ifndef TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H
#define TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H

#include "entrada_tabela.h"

class MemoriaFisica {
    public:
        MemoriaFisica(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas, bool debug);
        ~MemoriaFisica();

        bool enderecoEstaValido(unsigned endereco);
        bool enderecoEstaSujo(unsigned endereco);

        void setEnderecoValido(unsigned endereco, bool valido);
        void setEnderecoSujo(unsigned endereco, bool sujo);

    private:
        unsigned tamanhoMemoria;
        EntradaTabela* tabelaPaginas;
};

#endif //TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H