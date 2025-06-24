#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.hpp"
#include "Data.hpp"
using namespace std;

class Cliente: public Pessoa{
    private:
        float _saldo;
        bool isBloqueado;
        float valorRefeicao;
        Data ultimoAlmoco;
        Data ultimoJantar;

    public:
        Cliente(Pessoa(string nome, string cpf)); // inicia o saldo com 0, bloqueado como false, ultimoAlmoco e últimoJantar como string vazia
};

#endif
