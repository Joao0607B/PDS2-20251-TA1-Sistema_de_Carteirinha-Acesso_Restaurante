#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, int cpf): _nome(nome), _cpf(cpf){};

void Pessoa::setNome(string nome){this->_nome = nome;}
void Pessoa::setCpf(int cpf){this->_cpf = cpf;}

string Pessoa::getNome(){return this -> _nome;}
int Pessoa::getCpf(){return this-> _cpf;}

void Pessoa::printInfo(){
    cout<<"Cadastro no nome de" <<getNome()<< "realizado com sucesso"<<endl;
}
void Pessoa::criaCadastro(string nome, int cpf) {
    setNome(nome);
    setCpf(cpf);
}
