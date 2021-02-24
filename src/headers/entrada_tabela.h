#ifndef TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H
#define TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H

class EntradaTabela {
    public:

        EntradaTabela();

        bool estaSujo();
        bool estaValido();
        unsigned getUltimoAcesso();

        void setSujo(bool sujo);
        void setValido(bool valido);
        void setUltimoAcesso(unsigned ultimoAcesso);

    private:
        bool sujo;
        bool valido;
        unsigned ultimoAcesso;
};

#endif //TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H