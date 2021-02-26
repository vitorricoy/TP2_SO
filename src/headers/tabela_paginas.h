#ifndef TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H
#define TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H

#include "entrada_tabela.h"


void TabelaPaginas_inicializar(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas);

short TabelaPaginas_enderecoEstaValido(unsigned endereco);
short TabelaPaginas_enderecoEstaSujo(unsigned endereco);

void TabelaPaginas_setEnderecoValido(unsigned endereco, short valido);
void TabelaPaginas_setEnderecoSujo(unsigned endereco, short sujo);

short TabelaPaginas_colocaPaginaMemoria(unsigned endereco);
void TabelaPaginas_substituiPaginasMemoria(unsigned endereco, unsigned enderecoRemovido);

void TabelaPaginas_preencherStringTabelaPaginas(char* string);

void TabelaPaginas_atualizarUltimoAcesso(unsigned endereco);

void TabelaPaginas_destruir();

extern unsigned numeroPaginasMemoria;
extern unsigned paginasOcupadas;
extern unsigned numeroPaginas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;
extern unsigned contador;

#endif //TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H