#include "Caixa.hpp"

static float preco;
map<int, bool> Caixa::clientes_que_ja_entraram;

Caixa::Caixa(string nome, string usuario, string senha): Funcionario(nome), _usuario(usuario), _senha(senha){};

void Caixa::setNome(string nome){this->_nome = nome;}
void Caixa::setUsuario(string usuario){this->_usuario = usuario;}
void Caixa::setSenha(string senha){this->_senha = senha;}
void Caixa::setRU(string RU){this->_RU = RU;}
void Caixa::setCaixa(int caixa){this->_caixa = caixa;}

string Caixa::getNome(){return this -> _nome;}
string Caixa::getUsuario(){return this -> _usuario;}
string Caixa::getSenha(){return this-> _senha;}
string Caixa::getRU(){return this-> _RU;}
int Caixa::getCaixa(){return this-> _caixa;}

void Caixa::criarCadastro(string nome, int cpf, string usuario, string senha){
    Funcionario::criaCadastro(nome, cpf);
    setUsuario(usuario);
    setSenha(senha);
}
void Caixa:: printInfo(){
    Funcionario::printInfo();
}
bool Caixa::fazerLogin(string& usuarioDigitado, string& senhaDigitada){
    return(usuarioDigitado == getUsuario() && senhaDigitada == getSenha());
}
void Caixa::trocarSenha(string& novaSenha){
    setSenha(novaSenha);
}
//cada aluno quando vai fazer o cadastro vai colocar seu nível e acessamos o nível pela matrícula?
//esse método é necessário?
float Caixa::acessarValor(Cliente cliente){
    float nivel = cliente.getNivel();//Cliente precisa de um getNivel

    if(nivel == 1){
        preco = 0;
    }
    else if(nivel == 2){
        preco = 1;
    }
    else if(nivel == 3){
        preco = 1;
    }
    else if(nivel == 4){
        preco == 2;
    }
    else{
        preco = 5.60;
    }
}
void Caixa::acessoCliente(Cliente cliente, float& valorPago){
    int cpf = cliente.getCpf(); //o getCpf tem que ser herdado de cliente, que foi herdado de pessoa
    float tarifa = acessarValor(cliente);

    if (clientes_que_ja_entraram.find(cpf) != clientes_que_ja_entraram.end()) {
        cout << "Acesso negado: o cliente " << cliente.getNome() << " já entrou hoje.\n";//getnome tmb terá que ser herdado
        return false;
    }
    if (valorPago < tarifa) {
        cout << "Acesso negado: valor insuficiente. Tarifa: R$" << tarifa << ", pago: R$" << valorPago << "\n";
        return false;
    }
    clientes_que_ja_entraram[cpf] = true;
    cout << "Acesso liberado para " << cliente.getNome()<<endl;
    return true;
}
void Caixa::resetarEntradas() {
    clientes_que_ja_entraram.clear();
}
void Caixa::selecionarRU(string RU, int caixa){
    setRU(string RU);
    setCaixa(int caixa);
}
