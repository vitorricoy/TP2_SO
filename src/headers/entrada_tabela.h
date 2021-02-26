#ifndef TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H
#define TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H

typedef struct EntradaTabela {
        short sujo;
        short valido;
        unsigned ultimoAcesso;
        unsigned tempoEntrada;
        short segundaChance;
        unsigned posicaoMemoria;
} EntradaTabela;

#endif //TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H