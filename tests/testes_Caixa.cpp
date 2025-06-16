#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Caixa.hpp"
#include "Cliente.hpp" 

TEST_CASE("Teste de login correto e incorreto") {
    Caixa caixa("Ana", 123, "ana123", "senha123");

    string usuario = "ana123";
    string senha = "senha123";
    CHECK(caixa.fazerLogin(usuario, senha) == true);

    string usuarioErrado = "ana";
    string senhaErrada = "senha";
    CHECK(caixa.fazerLogin(usuarioErrado, senhaErrada) == false);
}

TEST_CASE("Teste de troca de senha") {
    Caixa caixa("Ana", 123, "ana123", "senha123");

    string novaSenha = "nova123";
    caixa.trocarSenha(novaSenha);

    string usuario = "ana123";
    CHECK(caixa.fazerLogin(usuario, novaSenha) == true);
}
TEST_CASE("Teste de acesso por nível") {
    Caixa caixa("Joao", 123, "joao", "abc");

    Cliente c1; c1.setNivel(1);
    Cliente c2; c2.setNivel(2);
    Cliente c3; c3.setNivel(4);
    Cliente c4; c4.setNivel(99);

    CHECK(caixa.acessarValor(c1) == 0.0f);
    CHECK(caixa.acessarValor(c2) == 1.0f);
    CHECK(caixa.acessarValor(c3) == 2.0f);
    CHECK(caixa.acessarValor(c4) == 5.60f);
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Caixa.hpp"
#include "../Cliente.hpp"

TEST_CASE("Cliente acessa com sucesso no almoço") {
    Caixa caixa("Caixa1", 111, "caixa", "1234");
    Cliente cliente("Joao", 123456, 2);  // nível 2 => tarifa 1.00

    float valorPago = 1.00;
    string tipoRefeicao = "almoco";
    CHECK(caixa.acessoCliente(cliente, valorPago, tipoRefeicao) == true);
}

TEST_CASE("Cliente tenta acessar com valor insuficiente") {
    Caixa caixa("Caixa1", 111, "caixa", "1234");
    Cliente cliente("Maria", 789456, 4); // nível 4 => tarifa 2.00

    float valorPago = 1.50;
    string tipoRefeicao = "almoco";
    CHECK(caixa.acessoCliente(cliente, valorPago, tipoRefeicao) == false);
}

TEST_CASE("Cliente tenta acessar duas vezes no mesmo dia e refeição") {
    Caixa caixa("Caixa1", 111, "caixa", "1234");
    Cliente cliente("Carlos", 101010, 3); // nível 3 => tarifa 1.00

    float valorPago = 1.00;
    string tipoRefeicao = "almoco";

    // Primeira entrada deve ser permitida
    CHECK(caixa.acessoCliente(cliente, valorPago, tipoRefeicao) == true);

    // Segunda entrada no mesmo dia/tipo deve ser negada
    CHECK(caixa.acessoCliente(cliente, valorPago, tipoRefeicao) == false);
}
