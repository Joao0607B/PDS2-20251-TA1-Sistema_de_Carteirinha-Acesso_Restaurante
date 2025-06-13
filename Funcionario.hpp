//aqui seria o funcionário ou cliente? 

#ifndef FUNCIONÁRIO_HPP
#define FUNCIONÁRIO_HPP

#include <iostream>
#include <string>
#include "Pessoa.hpp" //classe pai
#include "Cliente.hpp"
#include "AdmFump.hpp"
#include "Caixa.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Visitante.hpp"


class Funcionario: public Pessoa{

    private:
        std::string _nome;
        std::string _departamento;
        std::float _saldo;
        // std:: string _ultimoAcesso;

    public:
        Funcionario(std::string nome, std::departamento departamento, std::float saldo);

        std::string virtual getNome();
        std::string virtual getDepartamento();
        std::float virtual getSaldo();

        void virtual setNome(std::string nome);
        void virtual setDepartamento(std::string departamento);
        void virtual setSaldo(std::float saldo);

        void virtual printInfo(); //printa nome, departamento e saldo

        //transferirsaldo() outra função talvez
        //BloquearCartao() outra função talvez


        //Alterar departamento, chama setDepartamento
        //Alterar saldo, chama setSaldo
}
#endif 
