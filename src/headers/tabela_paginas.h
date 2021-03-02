#ifndef TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H
#define TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H

#include "entrada_tabela.h"

// Inicializa as variáveis relacionadas à tabela de páginas
void TabelaPaginas_inicializar(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas);

// Desaloca a memória alocada dinamicamente pela função de inicialização
void TabelaPaginas_destruir();

// Determina se a página fornecida está na memória
short TabelaPaginas_paginaEstaValida(unsigned pagina);

// Determina se a página fornecida está suja
short TabelaPaginas_paginaEstaSuja(unsigned pagina);

// Atribui o valor dado à flag de válido da página fornecida
void TabelaPaginas_setPaginaValida(unsigned pagina, short valido);

// Atribui o valor dado à flag de sujo da página fornecida
void TabelaPaginas_setPaginaSuja(unsigned pagina, short sujo);

// Coloca a página dada na memória, retornando 1 caso tenha sucesso e 0 caso contrário
short TabelaPaginas_colocaPaginaMemoria(unsigned pagina);

// Substitui a página dada por 'paginaRemovida' pela página dada por 'pagina' na memória
void TabelaPaginas_substituiPaginasMemoria(unsigned pagina, unsigned paginaRemovida);

// Atualiza o momento do último acesso à página recebida
// e reinicia a flag de segunda chance
void TabelaPaginas_atualizarValoresPaginaAcessada(unsigned pagina);

// Preenche a string dada com a representação em string da tabela de páginas
void TabelaPaginas_preencherStringTabelaPaginas(char* string);

extern unsigned numeroPaginasMemoria; // Número de páginas que podem ser salvas na memória
extern unsigned paginasOcupadas; // Número de páginas ocupadas na memória
extern unsigned numeroPaginas; // Número total de páginas do programa
extern EntradaTabela* tabelaPaginas; // Tabela de páginas com as informações lógicas de cada página
extern unsigned* paginasNaMemoria; // Tabela de páginas reversa com o identificador de cada página salva na memória
extern unsigned contadorOperacoes; // Contador das operações do programa utilizado como contador do tempo do programa

#endif //TP2_SO_SRC_HEADERS_MEMORIA_FISICA_H