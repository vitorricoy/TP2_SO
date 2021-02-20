#ifndef TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H
#define TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H

class AlgoritmoSubstituicao {
    public:
        
        AlgoritmoSubstituicao();

        virtual void determinaPagina() = 0;

    protected:
        bool debug;
};

#endif //TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H