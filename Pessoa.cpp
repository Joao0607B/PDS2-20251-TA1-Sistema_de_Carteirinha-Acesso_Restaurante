#include "Pessoa.hpp"

Pessoa::Pessoa(string _nome, int _cpf): nome(_nome), cpf(_cpf){};

void Pessoa::setNome(string _nome){this->nome = _nome;}
void Pessoa::setCpf(int _cpf){this->cpf = _cpf;}

string Pessoa::getNome(){return this -> nome;}
int Pessoa::getCpf(){return this-> cpf;}

void Pessoa::printInfo(){
    cout<<"Cadastro no nome de" <<getNome()<< "realizado com sucesso"<<endl;
}
