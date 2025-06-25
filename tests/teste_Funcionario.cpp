#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Funcionario.hpp"

TEST_CASE("Teste de getters e setters de Funcionario") {
    Funcionario f("Funcionario1", "123.456.789-00", "funcionario123", "senha123");

    CHECK(f.getUsuario() == "funcionario123");
    CHECK(f.getSenha() == "senha123");

    f.setUsuario("novoUsuario");
    f.setSenha("novaSenha");

    CHECK(f.getUsuario() == "novoUsuario");
    CHECK(f.getSenha() == "novaSenha");
}
TEST_CASE("Teste de login correto e incorreto") {
    Funcionario f("Funcionario2", "000.000.000-00", "funcionario456", "senha456");

    // Login correto
    CHECK(f.fazerLogin("funcionario456", "senha456") == true);

    // Login com usuário errado
    CHECK(f.fazerLogin("funcionario789", "senha456") == false);

    // Login com senha errada
    CHECK(f.fazerLogin("funcionario456", "senhaErrada") == false);
}
TEST_CASE("Teste de troca de senha") {
    Funcionario f("Funcionario3", "111.222.333-44", "funcionario789", "senhaAtual");

    string nova = "novaSenha";
    string correta = "senhaAtual";
    string incorreta = "outraSenha";

    // Caso de sucesso
    f.trocarSenha(nova, correta);
    CHECK(f.getSenha() == "novaSenha");

    // Tentativa com senha errada (não deve trocar)
    f.trocarSenha(nova, incorreta);
    CHECK(f.getSenha() == "novaSenha");
}

TEST_CASE("Teste de fazerLogout") {
    Funcionario f("Funcionario3", "987.654.321-00", "funcionario101", "senha789");

    // Simula login e é esperado sucesso
    f.fazerLogin("funcionario101", "senha789");
    CHECK(f._logado == true);

    // Logout deve funcionar
    f.fazerLogout();
    CHECK(f._logado == false);

    // Tentar logout novamente (já está deslogado então não deveria fazer logout de novo)
    f.fazerLogout();
    CHECK(f._logado == false);
}
