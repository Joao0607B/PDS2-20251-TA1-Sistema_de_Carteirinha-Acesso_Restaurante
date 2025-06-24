#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <iostream>
#include <string>
#include "Pessoa.hpp" 
#include "Cliente.hpp" //classe pai
#include "AdmFump.hpp"
#include "Caixa.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Visitante.hpp"

class Professor: public Cliente {

    private:
        std::string _nome;
        std::string _Matricula;
        std::string _Curso;
        std::float _saldo;
        // std:: string _ultimoAcesso;

    public:
        Professor(std::string nome, std::string Matricula, std::float saldo, std::string Curso);

        std::string virtual getNome() override;  //herança
        std::string virtual getMatricula() override; //herança
        std::string virtual getCurso() override; //herança
        std::float virtual getSaldo() override; //herança

        void virtual setNome(std::string nome) override; //herança
        void virtual setMatricula(std::string Matricula) override; //herança
        void virtual setCurso(std::string Curso) override; //herança
        void virtual setSaldo(std::float saldo) override; //herança

        void virtual printInfo() override; //herança

        //transferirsaldo() outra função talvez
        //BloquearCartao() outra função talvez


        //Alterar departamento, chama setDepartamento
        //Alterar saldo, chama setSaldo
}
#endif 
