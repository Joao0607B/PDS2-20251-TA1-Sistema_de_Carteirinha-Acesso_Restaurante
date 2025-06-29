/**
 * @file Caixa.cpp
 * @brief Implementação dos métodos da classe Caixa.
 * @see Caixa.hpp
 */
#include "../include/Caixa.hpp"

// Utiliza a lista de inicialização para atribuir os valores passados aos membros da classe.
Caixa::Caixa(std::string nome, std::string cpf, std::string usuario, std::string senha, std::string restaurante, int caixa)
    : Funcionario(nome, cpf, usuario, senha), _restaurante(restaurante), _caixa(caixa) {}

void Caixa::setCaixa(int caixa) {
    this->_caixa = caixa;
}

void Caixa::setRestaurante(std::string restaurante) {
    this->_restaurante = restaurante;
}

int Caixa::getCaixa() {
    return this->_caixa;
}

std::string Caixa::getRestaurante() {
    return this->_restaurante;
}
