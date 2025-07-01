#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Professor.hpp"

TEST_CASE("Teste de criação de Professor") {
    Professor p("João Silva", "11122233344", "Matemática");

    CHECK(p.getNome() == "João Silva");
    CHECK(p.getCPF() == "11122233344");
    CHECK(p.getDepartamento() == "Matemática");
    CHECK(p.getValorRefeicao() == doctest::Approx(13.0f)); // valor fixo para professor
}

TEST_CASE("Teste de printInfo do Professor") {
    Professor p("Maria Costa", "99988877766", "Física");

    // Apenas checa se método existe e executa sem erro.
    // A verificação visual da saída pode ser feita manualmente ou com captura de stdout.
    p.printInfo();
    CHECK(true); // dummy check
}

TEST_CASE("Teste de saldo e refeição do Professor") {
    Professor p("Carlos Lima", "55544433322", "Biologia");

    p.setSaldo(20.0f);
    CHECK(p.getSaldo() == doctest::Approx(20.0f));

    p.fazerRefeicao('a'); // almoço
    CHECK(p.getSaldo() == doctest::Approx(7.0f)); // 20 - 13 = 7

    p.fazerRefeicao('j'); // jantar
    CHECK(p.getSaldo() == doctest::Approx(-6.0f)); // saldo pode ficar negativo dependendo da lógica
}
