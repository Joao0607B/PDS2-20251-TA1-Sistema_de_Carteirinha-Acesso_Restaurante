/**
 * @file Pessoa.hpp
 * @brief Definição da classe base Pessoa, que representa um indivíduo no sistema.
 */

#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

/**
 * @class Pessoa
 * @brief Superclasse que modela as características comuns a todos os indivíduos.
 * * Armazena informações básicas como nome e CPF. Serve como classe base para
 * outras classes mais específicas como Cliente e Funcionario.
 */
class Pessoa {
private:
    std::string _nome; ///< Armazena o nome completo da pessoa.
    std::string _cpf;  ///< Armazena o Cadastro de Pessoas Físicas (CPF).

public:
    /**
     * @brief Construtor da classe Pessoa.
     * @param nome O nome da pessoa.
     * @param cpf O CPF da pessoa.
     */
    Pessoa(std::string nome, std::string cpf);

    /**
     * @brief Define ou atualiza o nome da pessoa.
     * @param nome O novo nome a ser atribuído.
     */
    void setNome(std::string nome);

    /**
     * @brief Define ou atualiza o CPF da pessoa.
     * @param cpf O novo CPF a ser atribuído.
     */
    void setCpf(std::string cpf);

    /**
     * @brief Obtém o nome da pessoa.
     * @return Uma string contendo o nome da pessoa.
     */
    std::string getNome();

    /**
     * @brief Obtém o CPF da pessoa.
     * @return Uma string contendo o CPF da pessoa.
     */
    std::string getCpf();

    /**
     * @brief Imprime as informações da pessoa no console.
     * * Este método é virtual e pode ser sobrescrito pelas classes derivadas
     * para incluir informações adicionais.
     */
    virtual void printInfo();
};

#endif // PESSOA_H
