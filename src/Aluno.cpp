/**
 * @file Aluno.cpp
 * @brief Implementação dos métodos da classe Aluno.
 * @see Aluno.hpp
 */

#include "../include/Aluno.hpp"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& cpf,
             int nivelFump, const std::string& curso)
    : Cliente(nome, cpf), _curso(curso) {
    // A lógica de atribuição do nível e do valor da refeição
    // é encapsulada no método setNivelFump.
    this->setNivelFump(nivelFump);
}

int Aluno::getNivelFump() const {
    return _nivelFump;
}

void Aluno::setNivelFump(int nivel) {
    // A estrutura switch é utilizada para mapear o nível FUMP
    // a um valor de refeição específico.
    switch (nivel) {
    case 0:
        this->setValorRefeicao(5.60);
        break;
    case 1:
        this->setValorRefeicao(0.0);
        break;
    case 2:
    case 3: // Níveis 2 e 3 compartilham o mesmo valor
        this->setValorRefeicao(1.0);
        break;
    case 4:
        this->setValorRefeicao(2.0);
        break;
    case 5:
        this->setValorRefeicao(2.90);
        break;
    default:
        // Se o nível for inválido, uma mensagem é exibida e o nível atual não é alterado.
        std::cout << "Nível FUMP inválido. O valor da refeição não foi alterado." << std::endl;
        return;
    }
    // O nível só é atualizado se for um valor válido.
    _nivelFump = nivel;
}

std::string Aluno::getCurso() const {
    return _curso;
}

void Aluno::printInfo() {
    std::cout << "--- Informações do Aluno ---" << std::endl;
    // Reutiliza a implementação da classe base para evitar duplicação de código.
    Cliente::printInfo(); 
    std::cout << "  Curso: " << this->getCurso() << std::endl;
    std::cout << "  Nivel FUMP: " << this->getNivelFump() << std::endl;
}
