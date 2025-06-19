#include "AdmFump.hpp"
#include <numeric> 

AdmFump::AdmFump(const std::string& nome, const std::string& usuario, const std::string& senha)
	: Funcionario(nome, usuario, senha) {}

void AdmFump::cadastrarAluno(const Aluno& aluno) {
	m_alunos.push_back(aluno);
}

double AdmFump::acessarSaldoTotal() const {
	double total = 0.0;
	for (const auto& aluno : m_alunos) {
		total += aluno.getSaldo();
	}
	return total;
}

int AdmFump::acessarNumeroClientes() const {
	return m_alunos.size();
}

int AdmFump::acessarNumeroRefeicoesPorRestaurante(double precoRefeicao) const {
	int total = 0;
	for (const auto& aluno : m_alunos) {
		total += aluno.calcularRefeicoesPossiveis(precoRefeicao);
	}
	return total;
}

int AdmFump::acessarNumeroAlunosPorNivel(int nivel) const {
	int count = 0;
	for (const auto& aluno : m_alunos) {
		if (aluno.getNivelFump() == nivel) {
			++count;
		}
	}
	return count;
}
