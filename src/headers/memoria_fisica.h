#ifndef TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H
#define TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H

#include "entrada_tabela.h"


void MemoriaFisica_inicializar(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas, short debug);

short MemoriaFisica_enderecoEstaValido(unsigned endereco);
short MemoriaFisica_enderecoEstaSujo(unsigned endereco);

void MemoriaFisica_setEnderecoValido(unsigned endereco, short valido);
void MemoriaFisica_setEnderecoSujo(unsigned endereco, short sujo);

short MemoriaFisica_colocaPaginaMemoria(unsigned endereco);

void MemoriaFisica_preencherStringTabelaPaginas(char* string);

void MemoriaFisica_atualizarUltimoAcesso(unsigned endereco);

extern unsigned tamanhoMemoria;
extern unsigned paginasOcupadas;
extern unsigned numeroPaginas;
extern EntradaTabela* tabelaPaginas ;
extern short debug;
extern unsigned* paginasNaMemoria;
extern unsigned contador;

#endif //TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H