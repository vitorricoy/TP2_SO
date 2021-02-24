#include <stdlib.h>
#include <stdio.h>
#include "memoria_fisica.h"
#include "entrada_tabela.h"

unsigned tamanhoMemoria;
unsigned paginasOcupadas;
unsigned numeroPaginas;
EntradaTabela* tabelaPaginas;

void MemoriaFisica_inicializar(unsigned tamMem, unsigned tamPag, unsigned numPag, short dbg){
    tamanhoMemoria = tamMem;
    tabelaPaginas = (EntradaTabela*) malloc(numPag * sizeof(EntradaTabela));
    numeroPaginas = numPag;
    paginasOcupadas = 0;
    debug = dbg;
}

short MemoriaFisica_enderecoEstaValido(unsigned endereco) {
    return tabelaPaginas[endereco].valido;
}

short MemoriaFisica_enderecoEstaSujo(unsigned endereco) {
    return tabelaPaginas[endereco].sujo;
}

void MemoriaFisica_setEnderecoValido(unsigned endereco, short valido) {
    tabelaPaginas[endereco].valido = valido;
}

short MemoriaFisica_colocaPaginaMemoria(unsigned endereco) {
    if(paginasOcupadas < numeroPaginas) {
        paginasOcupadas++;
        MemoriaFisica_setEnderecoValido(endereco, 1);
        MemoriaFisica_setEnderecoSujo(endereco, 0);
        return 1;
    }
    return 0;
}
extern unsigned tamanhoMemoria;
extern unsigned paginasOcupadas;
extern unsigned numeroPaginas;
extern EntradaTabela* tabelaPaginas ;
extern short debug;
void MemoriaFisica_setEnderecoSujo(unsigned endereco, short sujo) {
    tabelaPaginas[endereco].sujo = sujo;
}

void MemoriaFisica_preencherStringTabelaPaginas(char* string) {
    sprintf(string, "Pagina     Valido   Sujo   Tempo do Ultimo Acesso\n");
    for(unsigned I=0; I<numeroPaginas; I++) {
        sprintf(string+50*(I+1), "%#010x %d        %d      %d\n", I, tabelaPaginas[I].valido, tabelaPaginas[I].sujo, tabelaPaginas[I].ultimoAcesso);
    }
}