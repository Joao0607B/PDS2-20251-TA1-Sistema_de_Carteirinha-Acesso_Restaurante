#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.hpp"
#include "Data.hpp"
using namespace std;

class Cliente: public Pessoa{
    private:
        float _saldo;
        bool _isBloqueado;
        float _valorRefeicao;
        Data _ultimoAlmoco;
        Data _ultimoJantar;

    public:
        Cliente(string nome, string cpf); // inicia o saldo com 0, bloqueado como false, valor da refeição como R$17,50
        void setSaldo(float valor);
        float getSaldo();
        void transferir(float valor, Cliente *outroCliente);
        void depositar(float valor);
        void bloquear();
        void desbloquear();
        void setUltimoAlmoco();
        void setUltimoJantar();
        Data getUltimoAlmoco();
        Data getUltimoJantar();
        void printInfo() override;
        bool getIsBloqueado();
        float getValorRefeicao();
        void setValorRefeicao(float valor);
        void registrarAcesso (char tipoDeRefeicao);

};

#endif
