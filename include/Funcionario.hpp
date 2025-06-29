/**
 * @file Funcionario.hpp
 * @brief Definição da classe Funcionario e suas exceções personalizadas.
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.hpp"
#include "Cliente.hpp"
#include <string>
#include <exception>

// Forward declaration para evitar dependência circular
class GerenciamentoDeSistema;

/**
 * @class Funcionario
 * @brief Modela um funcionário do sistema, herdando de Pessoa.
 * * Gerencia a autenticação (login/logout), alteração de senha e a liberação
 * de refeições para os clientes.
 */
class Funcionario : public Pessoa {
private:
    std::string _usuario; ///< O nome de usuário único para login.
    std::string _senha;   ///< A senha de acesso do funcionário.

public:
    /**
     * @brief Construtor da classe Funcionario.
     * @param nome O nome do funcionário, passado para o construtor de Pessoa.
     * @param cpf O CPF do funcionário, passado para o construtor de Pessoa.
     * @param usuario O nome de usuário para login no sistema.
     * @param senha A senha inicial do funcionário.
     */
    Funcionario(std::string nome, std::string cpf, std::string usuario, std::string senha);

    /**
     * @brief Flag que indica o estado de login do funcionário.
     * @note Este membro é público para facilitar a verificação de estado,
     * mas idealmente seria privado com um getter público (ex: `isLogado()`).
     */
    bool _logado = false;

    /**
     * @brief Obtém o nome de usuário do funcionário.
     * @return Uma string contendo o nome de usuário.
     */
    std::string getUsuario();

    /**
     * @brief Obtém a senha do funcionário.
     * @return Uma string contendo a senha.
     */
    std::string getSenha();

    /**
     * @brief Define ou atualiza o nome de usuário.
     * @param usuario O novo nome de usuário.
     */
    void setUsuario(std::string usuario);

    /**
     * @brief Define ou atualiza a senha.
     * @param senha A nova senha.
     */
    void setSenha(std::string senha);

    /**
     * @brief Sobrescreve o método printInfo de Pessoa para incluir o usuário.
     */
    void printInfo() override;

    /**
     * @brief Realiza o processo de login do funcionário.
     * @param usuarioDigitado O usuário fornecido para a tentativa de login.
     * @param senhaDigitada A senha fornecida para a tentativa de login.
     * @return true se o login for bem-sucedido, false caso contrário.
     * @throw ErroUsuarioNaoEncontrado se o usuário não corresponder.
     * @throw ErroSenhaIncorreta se a senha não corresponder.
     */
    bool fazerLogin(const std::string& usuarioDigitado, const std::string& senhaDigitada);

    /**
     * @brief Realiza o logout do funcionário, alterando o estado de _logado para false.
     */
    void fazerLogout();

    /**
     * @brief Permite que o funcionário troque sua própria senha.
     * @param novaSenha A nova senha desejada.
     * @param confirmarSenha A senha atual, para confirmação.
     */
    void trocarSenha(std::string& novaSenha, std::string& confirmarSenha);

    /**
     * @brief Processa a liberação de uma refeição para um cliente.
     * @param cliente Um ponteiro para o objeto Cliente que receberá a refeição.
     * @note Este método contém a lógica de verificação de saldo, bloqueio e registro de acesso.
     */
    void liberarRefeicao(Cliente* cliente);
};

/**
 * @class ExcecaoSaldoInsuficiente
 * @brief Exceção lançada quando um cliente não tem saldo suficiente para uma refeição.
 */
class ExcecaoSaldoInsuficiente : public std::exception {
public:
    /**
     * @brief Retorna a mensagem de erro associada à exceção.
     * @return Um ponteiro para uma string C descrevendo o erro.
     */
    virtual const char* what() const throw() {
        return "Erro: Saldo insuficiente.";
    }
};

/**
 * @class ErroUsuarioNaoEncontrado
 * @brief Exceção lançada durante o login se o nome de usuário não for encontrado.
 */
class ErroUsuarioNaoEncontrado : public std::exception {
public:
    /**
     * @brief Retorna a mensagem de erro associada à exceção.
     * @return Um ponteiro para uma string C descrevendo o erro.
     */
    const char* what() const throw() override {
        return "Erro: Usuário digitado não encontrado.";
    }
};

/**
 * @class ErroSenhaIncorreta
 * @brief Exceção lançada durante o login se a senha estiver incorreta.
 */
class ErroSenhaIncorreta : public std::exception {
public:
    /**
     * @brief Retorna a mensagem de erro associada à exceção.
     * @return Um ponteiro para uma string C descrevendo o erro.
     */
    const char* what() const throw() override {
        return "Erro: Senha incorreta.";
    }
};

#endif // FUNCIONARIO_H
