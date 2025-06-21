#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, string cpf): _nome(nome), _cpf(cpf){};

void Pessoa::setNome(string nome){this->_nome = nome;}
void Pessoa::setCpf(string cpf){this->_cpf = cpf;}

string Pessoa::getNome(){return this -> _nome;}
string Pessoa::getCpf(){return this-> _cpf;}

void Pessoa::criaCadastro(string nome, string cpf) {
    setNome(nome);
    setCpf(cpf);
    cout<<"Cadastro no nome de" <<getNome()<< "realizado com sucesso"<<endl;
}
void Pessoa::printInfo(){
    cout<<"Informações: <<endl;
    cout<<"Nome: "<<getNome()<<endl;
    cout<<"CPF: "<<getCpf()<<endl;
}

