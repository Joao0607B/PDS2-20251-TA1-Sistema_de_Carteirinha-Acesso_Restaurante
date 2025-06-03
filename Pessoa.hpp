#ifndef PESSOA_H
#define PESSOA_H
#include<iostream>
#include<string>
using namespace std;

class Pessoa{
    private:
    string nome;
    int cpf;

    public:
    Pessoa(string _nome, int _cpf);

    void setNome(string _nome);
    void setCpf(int _cpf);

    string getNome();
    int getCpf();

    virtual void printInfo();
};
#endif
