#ifndef PESSOA_H
#define PESSOA_H
#include<iostream>
#include<string>
using namespace std;

class Pessoa{
//Pessoa é a superclasse geral,logo se apresenta no topo do diagrama de herança de classes.
    private:
//Pessoa possui dois argumentos/atributos privados(_nome e _cpf)
    string _nome; 
    string _cpf;

    public:
    Pessoa(string nome, string cpf);//Construtor que recebe os arqumentos nome e cpf e é criado toda vez que um objeto é criado.

    void setNome(string nome);//Aqui temos o Set para permitir modificar o argumento privado _nome.
    void setCpf(string cpf);//Aqui temos o Set para permitir modificar o argumento privado _cpf.

    string getNome();//Aqui temos o Get para permitir acessar o argumento privado _nome.
    string getCpf();//Aqui temos o Get para permitir acessar o argumento privado _cpf.

    virtual void printInfo();//O método printInfo() virtual que poderá ser alterado nas subclasse. Sua função na classe Pessoa é printar as informações pessoais do usuário, que nessa classe é o nome e o cpf.
    ~Pessoa();//O destrutor que será chamado todo final de função, ou final do programa, ou quando o delete for chamado e é responsável por limpar os objetos criados.
};
#endif
