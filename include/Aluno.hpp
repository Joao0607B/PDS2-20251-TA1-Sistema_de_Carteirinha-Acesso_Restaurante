#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Cliente.hpp"
#include <string>

/// \brief Classe que representa um aluno, herda de Cliente
class Aluno : public Cliente {
private:
	int m_nivelFump;
	std::string m_curso;

public:
	Aluno(const std::string& nome, const std::string& cpf,
	      int nivelFump, const std::string& curso);

	/// \brief Retorna o nível FUMP do aluno
	int getNivelFump() const;

	/// \brief Atualiza o nível FUMP do aluno
	void setNivelFump(int nivel);

	/// \brief Retorna o curso do aluno
	std::string getCurso() const;

	/// \brief Imprime dados do aluno
	void printInfo() const override;
};

#endif
