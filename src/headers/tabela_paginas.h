#ifndef TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H
#define TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H

#include "entrada_tabela.h"


void TabelaPaginas_inicializar(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas, short debug);

short TabelaPaginas_enderecoEstaValido(unsigned endereco);
short TabelaPaginas_enderecoEstaSujo(unsigned endereco);

void TabelaPaginas_setEnderecoValido(unsigned endereco, short valido);
void TabelaPaginas_setEnderecoSujo(unsigned endereco, short sujo);

short TabelaPaginas_colocaPaginaMemoria(unsigned endereco);

void TabelaPaginas_preencherStringTabelaPaginas(char* string);

void TabelaPaginas_atualizarUltimoAcesso(unsigned endereco);

extern unsigned tamanhoMemoria;
extern unsigned paginasOcupadas;
extern unsigned numeroPaginas;
extern EntradaTabela* tabelaPaginas ;
extern short debug;
extern unsigned* paginasNaMemoria;
extern unsigned contador;

#endif //TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H