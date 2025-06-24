#ifndef CAIXA_H
#define CAIXA_H
#include "Funcionario.hpp"

class Caixa:public Funcionario{
    //Caixa é uma subclasse de Funcionario.
    private:
    //Caixa possui dois atributos privados, são eles _caixa e _restaurante.
    int _caixa;
    string _restaurante;

    public:
    Caixa(string nome, string cpf, string usuario, string senha, string restaurante, int caixa);//Construtor de Funcionario que recebe dois atributos herdados de Funcionario(nome,cpf, usuario e senha) e acrescenta dois argumentos proprios(restaurante e caixa).
    int getCaixa();//Aqui temos o Get para permitir acessar o argumento privado _caixa.
    string getRestaurante();//Aqui temos o Get para permitir acessar o argumento privado _restaurante.

    void setCaixa(int caixa);//Aqui temos o Set para permitir modificar o argumento privado _caixa.
    void setRestaurante(string restaurante);//Aqui temos o Set para permitir modificar o argumento privado _restaurante.
};

#endif
