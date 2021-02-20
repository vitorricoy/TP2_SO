#ifndef TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H
#define TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H

class AlgoritmoSubstituicao {
    public:
        
        AlgoritmoSubstituicao(MemoriaFisica* memoriaFisica);

        virtual void determinaPagina() = 0;

        bool precisaDeSubstituicao();

    protected:
        bool debug;
        MemoriaFisica* memoriaFisica;
};

#endif //TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H