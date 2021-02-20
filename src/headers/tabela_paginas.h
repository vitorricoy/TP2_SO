#include "memoria.h"
#include "algoritmo_substituicao.h"

class TabelaPaginas {
    public:

        TabelaPaginas(unsigned tamanhoPagina, unsigned tamanhoMemoria, AlgoritmoSubstituicao* algoritmo, bool debug);

        bool lerEndereco(unsigned endereco);
        bool escreverEndereco(unsigned endereco);


    private:
        Memoria memoria;
        AlgoritmoSubstituicao* algoritmoSubstituicao;
        bool debug;
};