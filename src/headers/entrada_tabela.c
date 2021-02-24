#include "entrada_tabela.h"

EntradaTabela::EntradaTabela() {
    this->sujo = false;
    this->valido = false;
    this->ultimoAcesso = 0;
}

bool EntradaTabela::estaSujo() {
    return this->sujo;
}

bool EntradaTabela::estaValido() {
    return this->valido;
}

void EntradaTabela::setSujo(bool sujo) {
    this->sujo = sujo;
}

void EntradaTabela::setValido(bool valido) {
    this->valido = valido;
}

unsigned EntradaTabela::getUltimoAcesso() {
    return this->ultimoAcesso;
}

void EntradaTabela::setUltimoAcesso(unsigned ultimoAcesso) {
    this->ultimoAcesso = ultimoAcesso;
}