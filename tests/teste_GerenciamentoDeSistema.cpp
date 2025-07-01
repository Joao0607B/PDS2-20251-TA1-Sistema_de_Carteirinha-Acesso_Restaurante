#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/GerenciamentoDeSistema.hpp"
#include "../include/Aluno.hpp"
#include "../include/Professor.hpp"
#include "../include/Funcionario.hpp"

Funcionario* criarFuncionarioLogado(std::string nome, std::string cpf, std::string usuario, std::string senha) {
    auto* f = new Funcionario(nome, cpf, usuario, senha);
    f->fazerLogin(usuario, senha); // loga direto
    return f;
    //Criamos um mock básico que cria um funcionário já logado para realização dos testes.
}
TEST_CASE("Cadastro e busca de cliente") {
    GerenciamentoDeSistema sistema;

    Cliente* c1 = new Cliente("Cliente1", "111");
    sistema.cadastrarCliente(c1);
    //Criamos um cliente c1 e cadastramos ele no sistema

    CHECK(sistema.encontrarCliente("111") == c1);
    CHECK(sistema.encontrarCliente("000") == nullptr);
    //Nesse teste conferimos se o Cliente foi cadastrado no sistema e também conferimos se não há cadastros inválidos de clientes no sistema.
}

TEST_CASE("Cadastro e busca de funcionário") {
    GerenciamentoDeSistema sistema; 

    Funcionario* f1 = new Funcionario("Funcionario1", "222", "func1", "123");
    sistema.cadastrarFuncionario(f1);
    //Criamos um funcionário f1 e cadastramos ele no sistema.

    CHECK(sistema.encontrarFuncionario("func1") == f1);
    CHECK(sistema.encontrarFuncionario("naoExiste") == nullptr);
    //Nesse teste conferimos se o Funcionário foi cadastrado no sistema e também conferimos se não há cadastros inválidos de funcionários no sistema.
}

TEST_CASE("Remoção de cliente") {
    GerenciamentoDeSistema sistema;
    Cliente* c2 = new Cliente("Cliente2", "123");
    sistema.cadastrarCliente(c2);
    //Criamos um cliente c2 e cadastramos ele no sistema

    sistema.apagarCliente("123");
    CHECK(sistema.encontrarCliente("123") == nullptr);
    //Nesse teste conferimos se o cliente após apagado do sistema será encontrado. 
}

TEST_CASE("Remoção de funcionário") {
    GerenciamentoDeSistema sistema;
    Funcionario* f2 = new Funcionario("Funcionario2", "999", "func2", "321");
    sistema.cadastrarFuncionario(f2);
    //Criamos um funcionário f2 e cadastramos ele no sistema.

    sistema.apagarFuncionario("999");
    CHECK(sistema.encontrarFuncionario("func2") == nullptr);
    //Nesse teste conferimos se o funcionário após apagado do sistema será encontrado. 
}

TEST_CASE("Login de funcionário") {
    GerenciamentoDeSistema sistema;
    Funcionario* f3 = new Funcionario("Funcionario3", "555", "func3", "senha");
    sistema.cadastrarFuncionario(f3);
    //Criamos um funcionário f3 e cadastramos ele no sistema.

    CHECK_FALSE(sistema.verificarLogin("555")); // ainda não logado
    CHECK(sistema.acessarSistema("func3", "senha") == true);
    CHECK(sistema.verificarLogin("555")); // agora sim está logado
    //Verificamos se o cliente está logado no sistema.
}

TEST_CASE("Depósito com funcionário logado") {
    GerenciamentoDeSistema sistema;

    Cliente* c3 = new Cliente("Cliente3, "333");
    sistema.cadastrarCliente(c3);
    //Criamos um cliente c3 e cadastramos ele no sistema

    Funcionario* f4 = criarFuncionarioLogado("Funcionario4", "444", "func4", "senha");
    sistema.cadastrarFuncionario(f4);
    //Criamos um funcionário f4 e cadastramos ele no sistema.

    sistema.depositarCredito("333", 100.0f, "444");

    CHECK(c3->getSaldo() == doctest::Approx(100.0f));
    //Nesse teste verificamos se o depósito foi feito corretamente
}

TEST_CASE("Processar refeição válida") {
    GerenciamentoDeSistema sistema;

    Cliente* c4 = new Cliente("Cliente4", "888");
    c4->setSaldo(50.0f);
    sistema.cadastrarCliente(c4);

    Funcionario* f5 = criarFuncionarioLogado("Funcionario5", "777", "func5", "senha");
    sistema.cadastrarFuncionario(f5);

    sistema.processarRefeicao("888", "777");

    // Deve ter sido debitado o valor da refeição (17.50)
    CHECK(c4->getSaldo() == doctest::Approx(32.5f));
}
