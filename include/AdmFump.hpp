#ifndef ADM_FUMP_HPP
#define ADM_FUMP_HPP

#include <vector>
#include <string>
#include "Funcionario.hpp"
#include "Aluno.hpp"

class AdmFump : public Funcionario {
public:
	AdmFump(const std::string& nome, const std::string& cpf,
	        const std::string& usuario, const std::string& senha);

	void cadastrarAluno(const Aluno& aluno);
	double acessarSaldoTotal() const;
	int acessarNumeroClientes() const;
	int acessarNumeroRefeicoesPorRestaurante(const std::string& restaurante) const;
	int acessarNumeroAlunosPorNivel(int nivel) const;

private:
	std::vector<Aluno> m_alunos;
	std::vector<std::string> m_restaurantes;
	std::vector<int> m_refeicoesPorRestaurante;
};

#endif // ADM_FUMP_HPP
