#ifndef TP2_SO_SRC_HEADERS_MMU_H
#define TP2_SO_SRC_HEADERS_MMU_H

// Lê a página recebida por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_lerPagina(unsigned pagina);

// Escreve na página recebida por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_escreverPagina(unsigned pagina);

// Coloca a página recebida na memória
void MMU_buscaPaginaParaMemoria(unsigned pagina);

extern unsigned numeroPaginasSujas; // Total de páginas sujas escritas no disco
extern short debug; // Flag para o modo de debug

#endif //TP2_SO_SRC_HEADERS_MMU_H