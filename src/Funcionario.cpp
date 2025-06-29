/**
 * @file Funcionario.cpp
 * @brief Implementação dos métodos da classe Funcionario.
 * @see Funcionario.hpp
 */

#include "../include/Funcionario.hpp"
#include "../include/GerenciamentoDeSistema.hpp" // Necessário para _tipoDeRefeicao
#include <iostream>

Funcionario::Funcionario(std::string nome, std::string cpf, std::string usuario, std::string senha)
    : Pessoa(nome, cpf), _usuario(usuario), _senha(senha) {}

void Funcionario::setUsuario(std::string usuario) { this->_usuario = usuario; }
void Funcionario::setSenha(std::string senha) { this->_senha = senha; }
std::string Funcionario::getUsuario() { return this->_usuario; }
std::string Funcionario::getSenha() { return this->_senha; }

void Funcionario::printInfo() {
    Pessoa::printInfo(); // Chama o método da classe base
    std::cout << "  Usuário: " << this->getUsuario() << std::endl;
}

bool Funcionario::fazerLogin(const std::string& usuarioDigitado, const std::string& senhaDigitada) {
    try {
        if (usuarioDigitado != getUsuario()) {
            throw ErroUsuarioNaoEncontrado();
        }
        if (senhaDigitada != getSenha()) {
            throw ErroSenhaIncorreta();
        }
        _logado = true;
        std::cout << "Login realizado com sucesso!" << std::endl;
        return true;
    } catch (const std::exception& e) {
        // Captura todas as exceções derivadas de std::exception
        std::cerr << e.what() << std::endl;
        return false;
    }
}

void Funcionario::fazerLogout() {
    _logado = false;
    std::cout << "Logout realizado com sucesso!" << std::endl;
}

void Funcionario::trocarSenha(std::string& novaSenha, std::string& confirmarSenha) {
    if (confirmarSenha == getSenha()) {
        setSenha(novaSenha);
        std::cout << "Senha atualizada com sucesso!" << std::endl;
    } else {
        std::cout << "Senha atual incorreta, não foi possível realizar a atualização!" << std::endl;
    }
}

void Funcionario::liberarRefeicao(Cliente* cliente) {
    try {
        if (cliente->getSaldo() < cliente->getValorRefeicao()) {
            throw ExcecaoSaldoInsuficiente(); 
        }

        // A lógica de verificação de data esta encapsulada dentro de cliente->registrarAcesso().
        bool sucesso = cliente->registrarAcesso(GerenciamentoDeSistema::_tipoDeRefeicao);

        if (sucesso) {
            std::cout << "Refeição liberada com sucesso pelo funcionário." << std::endl;
        }

    } catch (const ExcecaoSaldoInsuficiente& e) {
        std::cerr << e.what() << std::endl;
    }
}
