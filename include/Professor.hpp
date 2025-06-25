#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Cliente.hpp"
#include <string>

/// \brief Classe que representa um professor, herda de Cliente
class Professor : public Cliente {
private:
	std::string m_departamento;

public:
	Professor(const std::string& nome, const std::string& cpf,
	          const std::string& departamento);

	/// \brief Retorna o departamento do professor
	std::string getDepartamento() const;

	/// \brief Imprime informações do professor
	void printInfo() const override;
};

#endif
