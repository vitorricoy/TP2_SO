#ifndef TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H
#define TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H

class EntradaTabela {
    public:

        EntradaTabela();

        bool estaSujo();
        bool estaValido();

        void setSujo(bool sujo);
        void setValido(bool valido);

    private:
        bool sujo;
        bool valido;
};

#endif //TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H