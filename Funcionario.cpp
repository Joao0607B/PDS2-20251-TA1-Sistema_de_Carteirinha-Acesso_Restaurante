#include "Funcionario.hpp"
#include "Pessoa.hpp"

Funcionario::Funcionario(string nome, string cpf, string usuario, string senha): Pessoa(nome, cpf), _usuario(usuario), _senha(senha){}

void Funcionario::setUsuario(string usuario){this->_usuario = usuario;}
void Funcionario::setSenha(string senha){this->_senha = senha;}
string Funcionario::getUsuario(){return this -> _usuario;}
string Funcionario::getSenha(){return this-> _senha;}

void Funcionario::printInfo(){
    Pessoa::printInfo();
    cout<<"Usuário: "<<getUsuario()<<endl;//Acrescenta a informação "Usuário" na função
}
bool Funcionario::fazerLogin(const string& usuarioDigitado, const string& senhaDigitada){
    if (usuarioDigitado != getUsuario()) {//Se usuarioDigitado for diferente de getUsuario() exibe uma mensagem de erro e retorna false.
        cout << "Erro: Usuário digitado não encontrado." <<endl;
        return false;
    }
    if (senhaDigitada != getSenha()) {//Se senhaDigitado for diferente de getSenha() exibe uma mensagem de erro e retorna false.
        std::cout << "Erro: Senha incorreta." << std::endl;
        return false;
    }
    _logado = true;//define _logado como true se a senha e o usuário  digitadas estiverem corretas.
    cout << "Login realizado com sucesso!" <<endl;
    return true; //retorna true se a senha e o usuário  digitadas estiverem corretas.
}
void Funcionario::fazerLogout(){
    if(_logado){//verifica se alguém está logado no sistema
        _logado = false;//se o usuário estiver logado realiza o Logout.
        cout << "Logout realizado com sucesso!" <<endl;
    }
    else{
        cout<< "Usuário deslogado no momento!"<<endl;
    }
}
void Funcionario::trocarSenha(string& novaSenha, string& confirmarSenha){
    if (confirmarSenha == getSenha()) {//Se confirmarSenha for igual a getSenha() será possivel atualizar a senha.
        setSenha(novaSenha);
        cout<<"Senha atualizada com sucesso!"<<endl;
    }
    else{
        cout<<"Senha digitada incorreta, não foi possível realizar a atualização!"<<endl;//Se confirmarSenha for diferente a getSenha() será exibido uma mensagem de erro.
    }
}
void Funcionario::liberarRefeicao(*Cliente cliente){

}
Funcionario::~Funcionario(){
    
}
