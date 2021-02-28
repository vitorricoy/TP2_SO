#ifndef TP2_SO_SRC_HEADERS_MMU_H
#define TP2_SO_SRC_HEADERS_MMU_H

// Lê a página do endereço recebido por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_lerEndereco(unsigned endereco);

// Escreve na página do endereço recebido por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_escreverEndereco(unsigned endereco);

// Coloca a página apontada por endereço na memória
void MMU_buscaPaginaParaMemoria(unsigned endereco);

extern unsigned numeroPaginasSujas; // Total de páginas sujas escritas no disco
extern short debug; // Flag para o modo de debug

#endif //TP2_SO_SRC_HEADERS_MMU_H