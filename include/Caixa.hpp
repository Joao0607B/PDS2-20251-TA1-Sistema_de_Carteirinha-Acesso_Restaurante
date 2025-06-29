/**
 * @file Caixa.hpp
 * @brief Definição da classe Caixa, uma especialização da classe Funcionario.
 */
#ifndef CAIXA_H
#define CAIXA_H

#include "Funcionario.hpp"
#include <string>

/**
 * @class Caixa
 * @brief Representa um funcionário do tipo Caixa, responsável pela gestão de um caixa em um restaurante.
 * * Esta classe herda de Funcionario e adiciona atributos específicos como o número do caixa e o restaurante.
 */
class Caixa : public Funcionario {
private:
    int _caixa;             ///< O número identificador do caixa.
    std::string _restaurante; ///< O nome do restaurante onde o caixa está localizado.

public:
    /**
     * @brief Construtor da classe Caixa.
     * @param nome O nome do funcionário, passado para o construtor de Funcionario.
     * @param cpf O CPF do funcionário, passado para o construtor de Funcionario.
     * @param usuario O nome de usuário para login no sistema.
     * @param senha A senha de acesso do funcionário.
     * @param restaurante O nome do restaurante onde o caixa opera.
     * @param caixa O número do caixa.
     */
    Caixa(std::string nome, std::string cpf, std::string usuario, std::string senha, std::string restaurante, int caixa);

    /**
     * @brief Obtém o número do caixa.
     * @return Um inteiro representando o número do caixa.
     */
    int getCaixa();

    /**
     * @brief Obtém o nome do restaurante.
     * @return Uma string contendo o nome do restaurante.
     */
    std::string getRestaurante();

    /**
     * @brief Define o número do caixa.
     * @param caixa O novo número do caixa.
     */
    void setCaixa(int caixa);

    /**
     * @brief Define o nome do restaurante.
     * @param restaurante O novo nome do restaurante.
     */
    void setRestaurante(std::string restaurante);
};

#endif
