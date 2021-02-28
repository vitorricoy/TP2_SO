#ifndef TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H
#define TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H

// Estrutura para guardar os valore de uma entrada da tabela de páginas
typedef struct EntradaTabela {
        short sujo; // Flag para página suja
        short valido; // Flag para página válida (está na memória)
        unsigned ultimoAcesso; // Momento do último acesso à página
        unsigned tempoEntrada; // Momento de entrada da página na memória
        short segundaChance; // Flag do algoritmo de segunda chance da página
        unsigned posicaoMemoria; // Posição da memória em que a página está inserida (caso seja válida)
} EntradaTabela;

#endif //TP2_SO_SRC_HEADERS_ENTRADA_TABELA_H