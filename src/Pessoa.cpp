/**
 * @file Pessoa.cpp
 * @brief Implementação dos métodos da classe Pessoa.
 * @see Pessoa.hpp
 */

#include "Pessoa.hpp"
#include <iostream>

// Usando a lista de inicialização do construtor, que é mais eficiente.
Pessoa::Pessoa(std::string nome, std::string cpf): _nome(nome), _cpf(cpf) {}

void Pessoa::setNome(std::string nome) {
    this->_nome = nome;
}

void Pessoa::setCpf(std::string cpf) {
    this->_cpf = cpf;
}

std::string Pessoa::getNome() {
    return this->_nome;
}

std::string Pessoa::getCpf() {
    return this->_cpf;
}

void Pessoa::printInfo() {
    std::cout << "Informações Pessoais:" << std::endl;
    std::cout << "  Nome: " << getNome() << std::endl;
    std::cout << "  CPF: " << getCpf() << std::endl;
}
