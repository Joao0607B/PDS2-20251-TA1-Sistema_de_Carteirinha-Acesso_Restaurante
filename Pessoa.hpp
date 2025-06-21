#ifndef PESSOA_H
#define PESSOA_H
#include<iostream>
#include<string>
using namespace std;

class Pessoa{
//Pessoa é a superclasse geral,logo se apresenta no topo do diagrama de herança de classes.
    private
//Pessoa possui dois argumentos/atributos privados(_nome e _cpf)
    string _nome; 
    string _cpf;

    public:
    Pessoa(string nome, string cpf);//Construtor que recebe os arqumentos nome e cpf e é criado toda vez que um objeto é criado.

    void setNome(string nome);//Aqui temos o Set para permitir modificar o argumento privado _nome.
    void setCpf(string cpf);//Aqui temos o Set para permitir modificar o argumento privado _cpf.

    string getNome();//Aqui temos o Get para permitir acessar o argumento privado _nome.
    string getCpf();//Aqui temos o Get para permitir acessar o argumento privado _cpf.

    virtual void printInfo();
    virtual void criaCadastro(string nome, string cpf);
    // adicionei o método criar cadastro que poderá ser subscrito pelas outras subclasses, por exemplo, a classe aluno poderá receber o parâmetro matrícula
    ~Pessoa();
};
#endif
