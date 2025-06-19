#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <vector>
#include <string>
#include "Cliente.hpp"

class Aluno : public Cliente {
public:
	Aluno(const std::string& nome, const std::string& cpf, double saldo, int nivelFump);

	int getNivelFump() const;
	void alterarNivelFump(int novoNivel);
	void anexarDocumento(const std::string& documento);
	int calcularRefeicoesPossiveis(double valorRefeicao) const;

private:
	int m_nivelFump;
	std::vector<std::string> m_documentos;
};

#endif // ALUNO_HPP
