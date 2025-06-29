/**
 * @file Aluno.hpp
 * @brief Definição da classe Aluno, uma especialização da classe Cliente.
 */

#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Cliente.hpp"
#include <string>

/**
 * @class Aluno
 * @brief Representa um cliente do tipo Aluno, que possui um nível FUMP e um curso.
 * * Esta classe herda de Cliente e ajusta o valor da refeição com base no
 * nível socioeconômico do aluno (nível FUMP).
 */
class Aluno : public Cliente {
private:
    int _nivelFump;   ///< Nível socioeconômico do aluno, usado para definir o preço da refeição.
    std::string _curso; ///< O curso no qual o aluno está matriculado.

public:
    /**
     * @brief Construtor da classe Aluno.
     * @param nome O nome do aluno, passado para o construtor de Cliente.
     * @param cpf O CPF do aluno, passado para o construtor de Cliente.
     * @param nivelFump O nível FUMP do aluno (0 a 5).
     * @param curso O nome do curso do aluno.
     */
    Aluno(const std::string& nome, const std::string& cpf, int nivelFump, const std::string& curso);

    /**
     * @brief Obtém o nível FUMP do aluno.
     * @return Um inteiro representando o nível FUMP.
     */
    int getNivelFump() const;

    /**
     * @brief Define o nível FUMP do aluno e atualiza o valor da refeição de acordo.
     * * O valor da refeição é ajustado com base em uma tabela interna de preços
     * correspondente a cada nível.
     * @param nivel O novo nível FUMP a ser atribuído.
     */
    void setNivelFump(int nivel);

    /**
     * @brief Obtém o curso do aluno.
     * @return Uma string contendo o nome do curso.
     */
    std::string getCurso() const;

    /**
     * @brief Sobrescreve o método printInfo de Cliente para incluir dados específicos do aluno.
     * * Imprime todas as informações do cliente mais o curso e o nível FUMP.
     */
    void printInfo() override;
};

#endif // ALUNO_HPP
