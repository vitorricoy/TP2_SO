#include "memoria.h"
#include "algoritmo_substituicao.h"

class TabelaPaginas {
    public:

        TabelaPaginas(int tamanhoPagina, int tamanhoMemoria, AlgoritmoSubstituicao algoritmo);


    private:
        Memoria memoria;
        AlgoritmoSubstituicao algoritmoSubstituicao;
};