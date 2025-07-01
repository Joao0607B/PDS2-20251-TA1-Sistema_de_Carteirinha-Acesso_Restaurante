#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Cliente.hpp"

class DataMock : public Data {
public:
    DataMock(int d, int m, int a) {
        setData(d, m, a);
    }
//Nesse teste estamos simulando a classe data, mas de forma simplificada, para que ela seja fixa em cada teste. Foi necessario, pois Cliente depende de Data.
};
TEST_CASE("Teste de criação e acesso a saldo") {
    Cliente c("Cliente1", "12345678900");
    CHECK(c.getSaldo() == doctest::Approx(0.0f));

    c.setSaldo(50.0f);
    CHECK(c.getSaldo() == doctest::Approx(50.0f));
  //Nesse teste estamos reaproveitando a função doctest::Approx(x) da biblioteca doctest para comparar números de ponto flutuante. Primeiro criamos um novo cliente, que é inicializado por padrão com o saldo 0.0, depois fazemos um depósito de 50.0, depois comparamos se o valor foi realmente acrescentado no saldo do cliente fazendo outra comparação.
}
TEST_CASE("Teste de depósito positivo e negativo") {
    Cliente c("Cliente2", "98765432100");

    c.depositar(100.0f);
    CHECK(c.getSaldo() == doctest::Approx(100.0f));

    c.depositar(-20.0f); // não altera saldo
    CHECK(c.getSaldo() == doctest::Approx(100.0f));
  //Esse teste se reaproveita da função doctest::Approx(x) da biblioteca doctest para comparar números de ponto flutuante. O objetivo desse teste é provar que o cliente não consegue depositar um saldo negativo.
}
TEST_CASE("Teste de bloqueio e desbloqueio") {
    Cliente c("Cliente3", "11223344556");
    CHECK_FALSE(c.getIsBloqueado());

    c.bloquear();
    CHECK(c.getIsBloqueado());

    c.desbloquear();
    CHECK_FALSE(c.getIsBloqueado());
  //Esse teste comprova se a função bloquear e desbloquear são funcionais, checando se o acesso foi bloqueado após o bloqueio, como tmb provando que o cliente não está bloqueado depois do bloqueio.
}

TEST_CASE("Teste de transferência entre clientes") {
    Cliente c1("Cliente4", "11122233344");
    Cliente c2("Cliente5", "55566677788");

    c1.setSaldo(100.0f);
    c1.transferir(30.0f, &c2);

    CHECK(c1.getSaldo() == doctest::Approx(70.0f));
    CHECK(c2.getSaldo() == doctest::Approx(30.0f));
  //Nesse teste criamos dois clientes, setamos um saldo para o primeiro cliente, depois chamamos a função transferir para o segundo cliente e checamos se o saldo do primeiro cliente é o saldo inicial subtraido do saldo transferido, como também se o saldo do segundo cliente é o saldo transferido pelo primeiro.
}


TEST_CASE("Setters e Getters de Data") {
    Cliente c("Cliente2", "12121212121");
    DataMock almoco(1, 7, 2025);
    DataMock jantar(2, 7, 2025);

    c.setUltimoAlmoco(almoco);
    c.setUltimoJantar(jantar);

    CHECK(c.getUltimoAlmoco() == almoco);
    CHECK(c.getUltimoJantar() == jantar);
}
TEST_CASE("Registro de acesso com cartão bloqueado") {
    Cliente c("Cliente3", "20202020200");
    c.setSaldo(50.0f);
    c.bloquear();

    CHECK_FALSE(c.registrarAcesso('a'));
  //O teste verifica se após um cliente for criado e após o depósito de um valor suficiente para fazer a refeição, se o cliente decide bloquear o seu acesso, ele não consegue fazer sua refeição. Logo o teste se propoe a isso. 
}



