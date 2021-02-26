#ifndef TP2_SO_SRC_HEADERS_MMU_H
#define TP2_SO_SRC_HEADERS_MMU_H

short MMU_lerEndereco(unsigned endereco);

short MMU_escreverEndereco(unsigned endereco);

void MMU_buscaPaginaParaMemoria(unsigned endereco);

extern unsigned numeroPaginasSujas;

#endif //TP2_SO_SRC_HEADERS_MMU_H