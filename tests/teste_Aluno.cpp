#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Aluno.hpp"

TEST_CASE("Criação de Aluno com nível FUMP válido e curso definido") {
    Aluno a("João", "12345678900", 3, "Engenharia Elétrica");

    CHECK(a.getNome() == "João");
    CHECK(a.getCpf() == "12345678900");
    CHECK(a.getCurso() == "Engenharia Elétrica");
    CHECK(a.getNivelFump() == 3);
    CHECK(a.getValorRefeicao() == doctest::Approx(1.0f));
}

TEST_CASE("Níveis FUMP válidos definem corretamente o valor da refeição") {
    Aluno a("Maria", "11122233344", 0, "Direito");

    a.setNivelFump(0);
    CHECK(a.getValorRefeicao() == doctest::Approx(5.60f));

    a.setNivelFump(1);
    CHECK(a.getValorRefeicao() == doctest::Approx(0.0f));

    a.setNivelFump(2);
    CHECK(a.getValorRefeicao() == doctest::Approx(1.0f));

    a.setNivelFump(3);
    CHECK(a.getValorRefeicao() == doctest::Approx(1.0f));

    a.setNivelFump(4);
    CHECK(a.getValorRefeicao() == doctest::Approx(2.0f));

    a.setNivelFump(5);
    CHECK(a.getValorRefeicao() == doctest::Approx(2.90f));
}

TEST_CASE("Nível FUMP inválido não altera valor da refeição") {
    Aluno a("Lucas", "22233344455", 2, "Medicina");

    // Valor inicial esperado
    CHECK(a.getNivelFump() == 2);
    CHECK(a.getValorRefeicao() == doctest::Approx(1.0f));

    // Tenta alterar para nível inválido
    a.setNivelFump(10); // inválido
    CHECK(a.getNivelFump() == 2); // nível não muda
    CHECK(a.getValorRefeicao() == doctest::Approx(1.0f));

    a.setNivelFump(-1); // também inválido
    CHECK(a.getNivelFump() == 2);
    CHECK(a.getValorRefeicao() == doctest::Approx(1.0f));
}

TEST_CASE("Getters da classe Aluno") {
    Aluno a("Bruna", "99988877766", 4, "Arquitetura");

    CHECK(a.getCurso() == "Arquitetura");
    CHECK(a.getNivelFump() == 4);
    CHECK(a.getValorRefeicao() == doctest::Approx(2.0f));
}
