/**
 * @file GerenciamentoDeSistema.hpp
 * @brief Definição da classe GerenciamentoDeSistema, o núcleo do sistema de restaurante.
 */

#ifndef GERENCIAMENTO_DE_SISTEMA_H
#define GERENCIAMENTO_DE_SISTEMA_H

#include <iostream>
#include <vector>
#include <string>

#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Professor.hpp"
#include "Aluno.hpp"

/**
 * @class GerenciamentoDeSistema
 * @brief Orquestra todas as operações do sistema de restaurante.
 * * Gerencia os vetores de clientes e funcionários, controla o acesso,
 * processa transações e lida com a persistência de dados em arquivos.
 * @warning O uso de 'using namespace std;' em arquivos de cabeçalho é desaconselhado.
 * Foi removido para seguir as boas práticas.
 */
class GerenciamentoDeSistema {
private:
    std::vector<Cliente*> _clientes;      ///< Vetor de ponteiros para todos os clientes cadastrados.
    std::vector<Funcionario*> _funcionarios; ///< Vetor de ponteiros para todos os funcionários cadastrados.
public:
    /**
     * @brief Busca um cliente no sistema pelo CPF.
     * @param cpf O CPF do cliente a ser encontrado.
     * @return Um ponteiro para o objeto Cliente se encontrado, senão nullptr.
     */
    Cliente* encontrarCliente(const std::string& cpf);

    /**
     * @brief Busca um funcionário no sistema pelo nome de usuário.
     * @param usuario O nome de usuário do funcionário.
     * @return Um ponteiro para o objeto Funcionario se encontrado, senão nullptr.
     */
    Funcionario* encontrarFuncionario(const std::string& usuario);

    /**
     * @brief Registra uma transação (refeição, depósito, etc.) no arquivo Transacoes.txt.
     * @param tipo O tipo da transação (ex: "Refeicao", "Deposito").
     * @param cliente O cliente principal envolvido na transação.
     * @param valor O valor monetário da transação.
     * @param funcionario O funcionário que processou a transação (pode ser nullptr).
     * @param cliente_destino O cliente de destino, usado para transferências (pode ser nullptr).
     */
    void registrarTransacao(const std::string& tipo, Cliente* cliente, double valor, Funcionario* funcionario, Cliente* cliente_destino = nullptr);

    /**
     * @brief Variável estática que define o tipo de refeição atual do sistema.
     * 'a' para almoço, 'j' para jantar.
     */
    static char _tipoDeRefeicao;

    /**
     * @brief Construtor. Carrega os dados dos arquivos ao iniciar o sistema.
     */
    GerenciamentoDeSistema();

    /**
     * @brief Destrutor. Salva os dados e libera a memória alocada para clientes e funcionários.
     */
    ~GerenciamentoDeSistema();

    /**
     * @brief Cadastra um novo cliente no sistema.
     * @param cliente Um ponteiro para o objeto Cliente a ser adicionado.
     */
    void cadastrarCliente(Cliente* cliente);

    /**
     * @brief Cadastra um novo funcionário no sistema.
     * @param funcionario Um ponteiro para o objeto Funcionario a ser adicionado.
     */
    void cadastrarFuncionario(Funcionario* funcionario);

    /**
     * @brief Remove um cliente do sistema com base no CPF.
     * @param cpf_cliente O CPF do cliente a ser removido.
     */
    void apagarCliente(std::string cpf_cliente);

    /**
     * @brief Remove um funcionário do sistema com base no CPF.
     * @param cpf_funcionario O CPF do funcionário a ser removido.
     */
    void apagarFuncionario(std::string cpf_funcionario);

    /**
     * @brief Verifica se um funcionário está atualmente logado no sistema.
     * @param cpf_funcionario O CPF do funcionário a ser verificado.
     * @return true se o funcionário estiver logado, false caso contrário.
     * @note Esta função parece usar CPF para buscar, mas a busca interna é por usuário. Cuidado com a inconsistência.
     */
    bool verificarLogin(std::string cpf_funcionario);

    /**
     * @brief Tenta autenticar um funcionário no sistema.
     * @param usuario O nome de usuário para login.
     * @param senha A senha para login.
     * @return true se o acesso for bem-sucedido, false caso contrário.
     */
    bool acessarSistema(std::string usuario, std::string senha);

    /**
     * @brief Adiciona crédito ao saldo de um cliente.
     * @param cpf_cliente O CPF do cliente que receberá o crédito.
     * @param valor O montante a ser depositado.
     * @param cpf_funcionario O CPF do funcionário que está realizando a operação.
     */
    void depositarCrédito(std::string cpf_cliente, float valor, std::string cpf_funcionario);

    /**
     * @brief Processa uma refeição para um cliente, debitando o valor e registrando a transação.
     * @param cpf_cliente O CPF do cliente que está fazendo a refeição.
     * @param cpf_funcionario O CPF do funcionário que está processando a refeição.
     */
    void processarRefeicao(std::string cpf_cliente, std::string cpf_funcionario);

    /**
     * @brief Salva o estado atual dos clientes e funcionários nos arquivos .txt.
     */
    void salvarDados();

    /**
     * @brief Carrega os dados dos clientes e funcionários a partir dos arquivos .txt.
     */
    void carregarDados();

    /**
     * @brief Exibe as informações de todos os clientes cadastrados no console.
     */
    void exibirClientes();

    /**
     * @brief Exibe as informações de todos os funcionários cadastrados no console.
     */
    void exibirFuncionarios();
};

#endif // GERENCIAMENTO_DE_SISTEMA_H
