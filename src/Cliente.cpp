/**
 * @file Cliente.cpp
 * @brief Implementação dos métodos da classe Cliente.
 * @see Cliente.hpp
 */

#include "../include/Cliente.hpp"
using namespace std;

// Utiliza a lista de inicialização para maior eficiência
Cliente::Cliente(string nome, string cpf):Pessoa(nome,cpf), _saldo(0), _valorRefeicao(17.50){}; // inicia o saldo com 0, bloqueado como false, ultimoAlmoco e últimoJantar como string vazia
        
void Cliente::setSaldo(float valor){_saldo = valor; this->printInfo();};

        
float Cliente::getSaldo(){return _saldo;};
        
void Cliente::transferir(float valor, Cliente *outroCliente){
    if(this->_isBloqueado){
        cout << this->getNome() << " está bloqueado e não pode fazer transferências." <<endl;
        return;
    }

    if (this->getSaldo()-valor>=0)
    {
        this->setSaldo(this->getSaldo()-valor);
        outroCliente->setSaldo(outroCliente->getSaldo()+valor);
        return;
    }else{
        cout << "Saldo insuficiente." <<endl;
    }
};
        
void Cliente::depositar(float valor){
    if(valor>=0){
        this->setSaldo(this->getSaldo()+valor);
    }else{
        cout << "Houve uma tentativa de depositar um valor negativo." << endl;
    }
};
        
void Cliente::bloquear(){
    _isBloqueado = true;
    cout << this->getNome() << " foi bloqueado." << endl;
};
        
void Cliente::desbloquear(){
    _isBloqueado = false;
    cout << this->getNome() << " foi desbloqueado." << endl;
};
        
void Cliente::setUltimoAlmoco(Data data){
    _ultimoAlmoco = data;
};
        
void Cliente::setUltimoJantar(Data data){
    _ultimoJantar = data;
};
        
Data Cliente::getUltimoAlmoco(){return _ultimoAlmoco;};
        
Data Cliente::getUltimoJantar(){return _ultimoJantar;};
        
void Cliente::printInfo(){
    Pessoa::printInfo(); // Chama o método da classe base para imprimir nome e CPF
    std::cout << "  Saldo: R$ " << this->getSaldo() << std::endl;
    std::cout << "  Valor da refeição: R$ " << this->getValorRefeicao() << std::endl;
    std::cout << "  Data do último almoço: " << this->getUltimoAlmoco().toString() << std::endl;
    std::cout << "  Data do último jantar: " << this->getUltimoJantar().toString() << std::endl;
    std::cout << "  Status: " << (this->getIsBloqueado() ? "Cartão bloqueado" : "Cartão liberado") << std::endl;
};
        
bool Cliente::getIsBloqueado(){return _isBloqueado;};
        
float Cliente::getValorRefeicao(){return _valorRefeicao;};
        
void Cliente::setValorRefeicao(float valor){_valorRefeicao = valor;};
        
bool Cliente::registrarAcesso(char tipoDeRefeicao) {
    Data hoje; // Pega a data atual
    
    // Verifica se o cartão está bloqueado
    if (this->getIsBloqueado()) {
        std::cout << "ERRO: Acesso negado. O cartão está bloqueado." << std::endl;
        return false;
    }

    // Verifica se o cliente tem saldo suficiente
    if (this->getSaldo() < this->getValorRefeicao()) {
        std::cout << "ERRO: Acesso negado. Saldo insuficiente." << std::endl;
        return false;
    }

    // Lógica para registrar almoço ou jantar
    switch (tipoDeRefeicao) {
        case 'a':
            if (this->getUltimoAlmoco() == hoje) {
                std::cout << "ERRO: Acesso negado. Almoço já registrado hoje." << std::endl;
                return false;
            }
            this->setUltimoAlmoco(hoje);
            break;
        case 'j':
            if (this->getUltimoJantar() == hoje) {
                std::cout << "ERRO: Acesso negado. Jantar já registrado hoje." << std::endl;
                return false;
            }
            this->setUltimoJantar(hoje);
            break;
        default:
            std::cout << "ERRO: Tipo de refeição não reconhecido." << std::endl;
            return false;
    }
    
    // Deduz o valor da refeição do saldo
    this->setSaldo(this->getSaldo() - this->getValorRefeicao());
    return true; // Retorna true se tudo deu certo
}
