#include "Aluno.hpp"
#include <iostream>
#include <cmath>

Aluno::Aluno(const std::string& nome, double saldo, int nivelFump)
	: Cliente(nome, saldo), m_nivelFump(nivelFump) {}

int Aluno::getNivelFump() const {
	return m_nivelFump;
}

void Aluno::setNivelFump(int nivelFump) {
	m_nivelFump = nivelFump;
}

int Aluno::calcularRefeicoesPossiveis(double precoRefeicao) const {
	if (precoRefeicao <= 0.0) return 0;
	return static_cast<int>(std::floor(getSaldo() / precoRefeicao));
}

void Aluno::adicionarCredito(double valor) {
	if (valor > 0) {
		double novoSaldo = getSaldo() + valor;
		setSaldo(novoSaldo);
	}
}

void Aluno::transferirCredito(Cliente& outro, double valor) {
	if (valor > 0 && getSaldo() >= valor) {
		setSaldo(getSaldo() - valor);
		outro.setSaldo(outro.getSaldo() + valor);
	}
}

void Aluno::bloquearCartao() {
	m_bloqueado = true;
}

void Aluno::atualizarCadastro(int novoNivelFump, bool bloquear, double novoSaldo) {
	m_nivelFump = novoNivelFump;
	m_bloqueado = bloquear;
	setSaldo(novoSaldo);
}
