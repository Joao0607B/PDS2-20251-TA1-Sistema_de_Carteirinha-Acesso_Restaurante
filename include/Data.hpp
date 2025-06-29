/**
 * @file Data.hpp
 * @brief Definição da classe Data para manipulação e validação de datas.
 */

#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <iostream>

/**
 * @class Data
 * @brief Modela uma data do calendário, permitindo validação e formatação.
 * * A classe armazena dia, mês e ano como inteiros. Ela garante que apenas
 * datas válidas sejam armazenadas e fornece métodos para obter a data atual,
 * formatá-la como string e realizar comparações.
 */
class Data {
private:
    int _dia;   ///< Armazena o dia do mês (1-31).
    int _mes;   ///< Armazena o mês do ano (1-12).
    int _ano;   ///< Armazena o ano.

    /**
     * @brief Verifica se um determinado ano é bissexto.
     * @param a O ano a ser verificado.
     * @return true se o ano for bissexto, false caso contrário.
     */
    bool isAnoBissexto(int a) const;

    /**
     * @brief Valida se uma combinação de dia, mês e ano forma uma data real.
     * @param d O dia a ser validado.
     * @param m O mês a ser validado.
     * @param a O ano a ser validado.
     * @return true se a data for válida, false caso contrário.
     */
    bool validarData(int d, int m, int a) const;

public:
    /**
     * @brief Construtor padrão. Inicializa a data com a data atual do sistema.
     */
    Data();

    /**
     * @brief Construtor com parâmetros.
     * @param d O dia.
     * @param m O mês.
     * @param a O ano.
     * @note Se a data fornecida for inválida, o objeto é inicializado com a data atual.
     */
    Data(int d, int m, int a);

    /**
     * @brief Define o dia do mês.
     * @param d O novo dia. A alteração só ocorre se a nova data for válida.
     */
    void setDia(int d);

    /**
     * @brief Define o mês do ano.
     * @param m O novo mês. A alteração só ocorre se a nova data for válida.
     */
    void setMes(int m);

    /**
     * @brief Define o ano.
     * @param a O novo ano. A alteração só ocorre se a nova data for válida.
     */
    void setAno(int a);

    /**
     * @brief Obtém o dia.
     * @return O dia atual do objeto.
     */
    int getDia() const;

    /**
     * @brief Obtém o mês.
     * @return O mês atual do objeto.
     */
    int getMes() const;

    /**
     * @brief Obtém o ano.
     * @return O ano atual do objeto.
     */
    int getAno() const;

    /**
     * @brief Formata a data como uma string no formato "DD/MM/AAAA".
     * @return Uma string representando a data.
     */
    std::string toString() const;

    /**
     * @brief Define a data do objeto para a data atual do sistema.
     */
    void definirDataAtual();

    /**
     * @brief Sobrecarga do operador de igualdade.
     * @param outraData O objeto Data a ser comparado.
     * @return true se as duas datas forem idênticas, false caso contrário.
     */
    bool operator==(const Data& outraData) const;

    /**
     * @brief Sobrecarga do operador de diferença.
     * @param outraData O objeto Data a ser comparado.
     * @return true se as duas datas forem diferentes, false caso contrário.
     */
    bool operator!=(const Data& outraData) const;
};

#endif // DATA_H
