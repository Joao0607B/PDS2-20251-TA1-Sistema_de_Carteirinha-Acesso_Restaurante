#include "Cliente.hpp"
using namespace std;
/*
        float _saldo;
        bool _isBloqueado;
        float valorRefeicao;
        Data ultimoAlmoco;
        Data ultimoJantar;
*/
Cliente::Cliente(string nome, string cpf):Pessoa(nome,cpf), _saldo(0), _valorRefeicao(17.50){}; // inicia o saldo com 0, bloqueado como false, ultimoAlmoco e últimoJantar como string vazia
        
void Cliente::setSaldo(float valor){
    _saldo = valor;
};
        
float Cliente::getSaldo(){
    return _saldo;
};
        
void Cliente::transferir(float valor, Cliente *outroCliente){
    this->setSaldo(this->getSaldo()-valor);
    outroCliente->setSaldo(outroCliente->getSaldo()+valor);
};
        
void Cliente::depositar(float valor){
    this->setSaldo(this->getSaldo()+valor);
};
        
void Cliente::bloquear(){
    _isBloqueado = true;
};
        
void Cliente::desbloquear(){
    _isBloqueado = false;
};
        
void Cliente::setUltimoAlmoco(){
    _ultimoAlmoco.definirDataAtual();
};
        
void Cliente::setUltimoJantar(){
    _ultimoJantar.definirDataAtual();
};
        
Data Cliente::getUltimoAlmoco(){
    return _ultimoAlmoco;
};
        
Data Cliente::getUltimoJantar(){
    return _ultimoJantar;
};
        
        
void Cliente::printInfo(){
    cout<< "Nome: " << this->getNome() << endl;
    cout<< "CPF: " << this->getCpf() << endl;
    cout<< "Saldo: " << this->getSaldo() << endl;
    cout<< "Valor da refeição: " << this->getValorRefeicao() << endl;
    cout<< "Data do último almoço: " << this->getUltimoAlmoco().toString() << endl;
    cout<< "Data do último jantar: " << this->getUltimoJantar().toString() << endl;
};
        
bool Cliente::getIsBloqueado(){
    return _isBloqueado;
};
        
float Cliente::getValorRefeicao(){
    return _valorRefeicao;
};
        
void Cliente::setValorRefeicao(float valor){
    _valorRefeicao = valor;
};
        
void Cliente::registrarAcesso (char tipoDeRefeicao){
    switch (tipoDeRefeicao)
    {
    case 'a':
        _ultimoAlmoco.definirDataAtual();
        break;
    
    case 'j':
        _ultimoJantar.definirDataAtual();
        break;    
    default:
        cout << "Operação incorreta" << endl;
        break;
    }
};

