#ifndef TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H
#define TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H

#include "entrada_tabela.h"

// Inicializa as variáveis relacionadas à tabela de páginas
void TabelaPaginas_inicializar(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas);

// Desaloca a memória alocada dinamicamente pela função de inicialização
void TabelaPaginas_destruir();

// Determina se o endereço fornecido está na memória
short TabelaPaginas_enderecoEstaValido(unsigned endereco);

// Determina se o endereço fornecido está sujo
short TabelaPaginas_enderecoEstaSujo(unsigned endereco);

// Atribui o valor dado à flag de válido do endereço fornecido
void TabelaPaginas_setEnderecoValido(unsigned endereco, short valido);

// Atribui o valor dado à flag de sujo do endereço fornecido
void TabelaPaginas_setEnderecoSujo(unsigned endereco, short sujo);

// Coloca a página dada por endereço na memória, retornando 1 caso tenha sucesso e 0 caso contrário
short TabelaPaginas_colocaPaginaMemoria(unsigned endereco);

// Substitui a página dada por 'enderecoRemovido' pela página dada por 'endereco' na memória
void TabelaPaginas_substituiPaginasMemoria(unsigned endereco, unsigned enderecoRemovido);

// Atualiza o momento do último acesso ao endereço dado por 'endereco'
void TabelaPaginas_atualizarUltimoAcesso(unsigned endereco);

// Preenche a string dada com a representação em string da tabela de páginas
void TabelaPaginas_preencherStringTabelaPaginas(char* string);

extern unsigned numeroPaginasMemoria; // Número de páginas que podem ser salvas na memória
extern unsigned paginasOcupadas; // Número de páginas ocupadas na memória
extern unsigned numeroPaginas; // Número total de páginas do programa
extern EntradaTabela* tabelaPaginas; // Tabela de páginas com as informações lógicas de cada página
extern unsigned* paginasNaMemoria; // Endereço de cada página salva na memória
extern unsigned contadorOperacoes; // Contador das operações do programa utilizado como contador do tempo do programa

#endif //TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H