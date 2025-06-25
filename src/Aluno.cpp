#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& cpf,
             int nivelFump, const std::string& curso)
    : Cliente(nome, cpf), m_nivelFump(nivelFump), m_curso(curso) {}

int Aluno::getNivelFump() const {
    return m_nivelFump;
}

void Aluno::setNivelFump(int nivel) {
    m_nivelFump = nivel;
}

std::string Aluno::getCurso() const {
    return m_curso;
}

void Aluno::printInfo() const {
    std::cout << "Aluno:\n";
    std::cout << "Nome: " << getNome() << "\n";
    std::cout << "CPF: " << getCpf() << "\n";
    std::cout << "Curso: " << m_curso << "\n";
    std::cout << "Nivel FUMP: " << m_nivelFump << "\n";
    std::cout << "Saldo: " << getSaldo() << "\n";
    std::cout << (getBloqueado() ? "Cartão bloqueado\n" : "Cartão liberado\n");
}
