#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Pessoa.hpp"
using namespace std;

class Cliente: public Pessoa{
    private:
        float _saldo;
        string _ultimoAcesso;
        bool isBloqueado = false;
        int nivelFUMP;

    public:
        Cliente(string nome, int cpf): Pessoa(nome, cpf), _saldo(0){};
        float getSaldo();
        string getUltimoAcesso();
        void bloquearCartao();
        void printInfo() override; //Herança de pessoa

    private:
        float setSaldo(float valor);
        void transferirCredito(float valor);
        string setUltimoAcesso();
};

#endif
