#include "Professor.hpp"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& cpf,
                     const std::string& departamento)
    : Cliente(nome, cpf), m_departamento(departamento) {}

std::string Professor::getDepartamento() const {
    return m_departamento;
}

void Professor::printInfo() const {
    std::cout << "Professor:\n";
    std::cout << "Nome: " << getNome() << "\n";
    std::cout << "CPF: " << getCpf() << "\n";
    std::cout << "Departamento: " << m_departamento << "\n";
    std::cout << "Saldo: " << getSaldo() << "\n";
    std::cout << (getBloqueado() ? "Cartão bloqueado\n" : "Cartão liberado\n");
}
