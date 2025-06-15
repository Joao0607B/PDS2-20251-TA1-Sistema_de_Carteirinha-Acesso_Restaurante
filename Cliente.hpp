#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Pessoa.hpp"
using namespace std;

class Cliente: public Pessoa{
    private:
        float m_saldo;
        string m_ultimoAcesso;
        bool isBloqueado = true;

    public:
        Cliente(string nome, int cpf): Pessoa(nome, cpf), m_saldo(0){};
        float getSaldo();
        string getUltimoAcesso();
        float setSaldo();
        void bloquearCartao();
        void printInfo();

    private:
        float setSaldo();
        void transferirCredito();
};

#endif
