/**
 * @file Professor.hpp
 * @brief Definição da classe Professor, uma especialização da classe Cliente.
 */

#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Cliente.hpp"
#include <string>

/**
 * @class Professor
 * @brief Representa um cliente do tipo Professor, associado a um departamento.
 * * Esta classe herda de Cliente e define um valor de refeição fixo para professores.
 */
class Professor : public Cliente {
private:
    std::string _departamento; ///< O departamento ao qual o professor está vinculado.

public:
    /**
     * @brief Construtor da classe Professor.
     * @param nome O nome do professor, passado para o construtor de Cliente.
     * @param cpf O CPF do professor, passado para o construtor de Cliente.
     * @param departamento O departamento do professor.
     * @note Define o valor da refeição como 13.00 no construtor.
     */
    Professor(const std::string& nome, const std::string& cpf,
              const std::string& departamento);

    /**
     * @brief Obtém o departamento do professor.
     * @return Uma string contendo o nome do departamento.
     */
    std::string getDepartamento() const;

    /**
     * @brief Sobrescreve o método printInfo de Cliente para incluir o departamento.
     */
    void printInfo() override;
};

#endif // PROFESSOR_HPP
