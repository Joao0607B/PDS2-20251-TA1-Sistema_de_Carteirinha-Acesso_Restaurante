#ifndef PESSOA_H
#define PESSOA_H
#include<iostream>
#include<string>
using namespace std;

class Pessoa{
    private:
    string _nome;
    int _cpf;

    public:
    Pessoa(string nome, int cpf);

    void setNome(string nome);
    void setCpf(int cpf);

    string getNome();
    int getCpf();

    virtual void printInfo();
    virtual void criaCadastro(string nome, int cpf);
    // adicionei o método criar cadastro que poderá ser subscrito pelas outras subclasses, por exemplo, a classe aluno poderá receber o parâmetro matrícula
    void ~Pessoa();
};
#endif
