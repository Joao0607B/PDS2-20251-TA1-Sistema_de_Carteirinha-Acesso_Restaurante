/**
 * @file Cliente.hpp
 * @brief Definição da classe Cliente, que herda de Pessoa e gerencia dados financeiros e de acesso do cliente.
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.hpp"
#include "Data.hpp"
#include <string>

/**
 * @class Cliente
 * @brief Modela um cliente do restaurante, com funcionalidades de saldo, bloqueio e registro de refeições.
 * * Esta classe herda de Pessoa e serve como base para tipos de clientes mais específicos,
 * como Aluno e Professor.
 */
class Cliente : public Pessoa {
private:
    float _saldo;            ///< Armazena o saldo atual do cliente.
    bool _isBloqueado;       ///< Status de bloqueio do cartão (true se bloqueado).
    float _valorRefeicao;    ///< O custo padrão de uma refeição para este cliente.
    Data _ultimoAlmoco;      ///< Registra a data da última refeição do tipo almoço.
    Data _ultimoJantar;      ///< Registra a data da última refeição do tipo jantar.

public:
    /**
     * @brief Construtor da classe Cliente.
     * @param nome O nome do cliente, passado para o construtor de Pessoa.
     * @param cpf O CPF do cliente, passado para o construtor de Pessoa.
     * @note Inicializa o saldo como 0.0, o status de bloqueio como false e o valor da refeição com 17.50.
     */
    Cliente(std::string nome, std::string cpf);

    /**
     * @brief Define o saldo do cliente.
     * @param valor O novo valor para o saldo.
     */
    void setSaldo(float valor);

    /**
     * @brief Obtém o saldo atual do cliente.
     * @return O valor do saldo em ponto flutuante.
     */
    float getSaldo();

    /**
     * @brief Transfere um valor do saldo deste cliente para outro.
     * @param valor O montante a ser transferido.
     * @param outroCliente Um ponteiro para o cliente que receberá o valor.
     */
    void transferir(float valor, Cliente *outroCliente);

    /**
     * @brief Adiciona um valor ao saldo do cliente.
     * @param valor O valor a ser depositado.
     */
    void depositar(float valor);

    /**
     * @brief Bloqueia o cartão do cliente, impedindo transações.
     */
    void bloquear();

    /**
     * @brief Desbloqueia o cartão do cliente, permitindo transações.
     */
    void desbloquear();

    /**
     * @brief Define a data do último almoço para a data definida.
     * @param data A data do último almoço.
     */
    void setUltimoAlmoco(Data data);

    /**
     * @brief Define a data do último jantar para a data definida.
     * @param data A data do último jantar.
     */
    void setUltimoJantar(Data data);

    /**
     * @brief Obtém a data da última refeição do tipo almoço.
     * @return Um objeto Data correspondente ao último almoço.
     */
    Data getUltimoAlmoco();

    /**
     * @brief Obtém a data da última refeição do tipo jantar.
     * @return Um objeto Data correspondente ao último jantar.
     */
    Data getUltimoJantar();

    /**
     * @brief Sobrescreve o método printInfo de Pessoa para incluir dados do cliente.
     * * Imprime nome, CPF, saldo, valor da refeição, as datas do último almoço e jantar e o status de bloqueio.
     */
    void printInfo() override;

    /**
     * @brief Verifica se o cliente está bloqueado.
     * @return true se o cliente estiver bloqueado, false caso contrário.
     */
    bool getIsBloqueado();

    /**
     * @brief Obtém o valor padrão da refeição para este cliente.
     * @return O custo da refeição.
     */
    float getValorRefeicao();

    /**
     * @brief Define um novo valor para a refeição.
     * @param valor O novo custo da refeição.
     */
    void setValorRefeicao(float valor);

    /**
     * @brief Registra um acesso (refeição), atualizando a data correspondente.
     * @param tipoDeRefeicao Um char indicando o tipo de refeição ('a' para almoço, 'j' para jantar).
     * @return Retorna um booleano indicando se a operação foi bem-sucedida.
     */
    bool registrarAcesso(char tipoDeRefeicao);
};

#endif // CLIENTE_H
