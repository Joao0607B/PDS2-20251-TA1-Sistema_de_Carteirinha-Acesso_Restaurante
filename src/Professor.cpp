/**
 * @file Professor.cpp
 * @brief Implementação dos métodos da classe Professor.
 * @see Professor.hpp
 */

#include "../include/Professor.hpp"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& cpf,
                     const std::string& departamento)
    // Inicializa a classe base e o membro _departamento na lista de inicialização
    : Cliente(nome, cpf), _departamento(departamento) {
    // Define o valor da refeição específico para professores
    this->setValorRefeicao(13.00);
}

std::string Professor::getDepartamento() const {
    return _departamento;
}

void Professor::printInfo() {
    std::cout << "--- Informações do Professor ---" << std::endl;
    // Reutiliza o método printInfo da classe base para imprimir dados comuns.
    // Isso evita a duplicação de código e facilita a manutenção.
    Cliente::printInfo();
    std::cout << "  Departamento: " << this->getDepartamento() << std::endl;
    std::cout << "------------------------------" << std::endl;
}
