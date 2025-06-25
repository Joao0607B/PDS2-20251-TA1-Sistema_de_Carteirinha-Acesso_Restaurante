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
    try{
        if (usuarioDigitado != getUsuario()) {//Se usuarioDigitado for diferente de getUsuario() lança a exceção ErroUsuarioNaoEncontrado().
            throw ErroUsuarioNaoEncontrado();
        }
        
        if (senhaDigitada != getSenha()) {//Se senhaDigitado for diferente de getSenha() lança a exceção ErroSenhaIncorreta()
            throw ErroSenhaIncorreta();  
        }
        _logado = true;//define _logado como true se a senha e o usuário  digitadas estiverem corretas.
        cout << "Login realizado com sucesso!" <<endl;
        return true; //retorna true se a senha e o usuário  digitadas estiverem corretas.
    }
    catch (ErroUsuarioNaoEncontrado& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    catch (ErroSenhaIncorreta& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
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
    try{
        if(cliente->getBloqueado()){//Verifica por meio do método da Classe cliente (getBloqueado) que é um bool que retorna true se o cliente estiver bloqueado e não liberao acesso se estiver bloqueado.
        cout<<"Cliente Bloqueado!Acesso negado."<<endl;
        return;
        }
        Data hoje;//Crio um objeto da classe data para determinar a data de hoje.
        hoje.definirDataAtual();//Chama a função de Data que determina a data atual.

        if (GerenciamentoDoSistema::refeicao == 'a') {//nessa função eu verifico se o cliente já almocou hoje
            if (cliente->getUltimoAlmoco().compararData(hoje)) {//Para verificar se ele já almoçou eu chamo a função que retorna o ultimo almoço dele e depois chamo a função que compara as datas e comparo a data do ultimo almoco com a data de hoje.
                std::cout << "Refeição já realizada no turno de almoço." << std::endl;
                return;
            } else {
                cliente->setUltimoAlmoco(hoje);//se o cliente não tiver almoçado ainda a função atualiza a data do ultimo almoço com a data de hoje.
                std::cout << "Almoço liberado com sucesso!" << std::endl;
            }
        }
        else if(GerenciamentoDoSistema::refeicao == 'j'){
            // Verifica se o cliente já jantou hoje
            if (cliente->getUltimaJanta().compararData(hoje)) {//Para verificar se ele já jantou eu chamo a função que retorna o ultimo almoço dele e depois chamo a função que compara as datas e comparo a data da ultima janta com a data de hoje.
            std::cout << "Refeição já realizada no turno de janta." << std::endl;
            return;
            } else {
            // Libera janta e atualiza data
                cliente->setUltimaJanta(hoje);//se o cliente não tiver almoçado ainda a função atualiza a data do ultimo almoço com a data de hoje.
                std::cout << "Janta liberada com sucesso!" << std::endl;
            }   
        } else {
            std::cout << "Tipo de refeição inválido." << std::endl;
        }
        float valorRefeicao = cliente->getValorRefeicaoAtual();//cria um atributo local(float) que recebe o valor da refeição de cada cliente.
        float saldoAtual = cliente->getSaldo();//cria um atributo local(float) que recebe o valor do saldo de cada cliente.

        if (saldoAtual < valorRefeicao) {//Verifica se o saldo  atual do clinte é suficiente para realizar a refeição e se não for lança uma exceção.
        throw ExcecaoSaldoInsuficiente();
        }
        cliente->setSaldo(saldoAtual - valorRefeicao);//Aqui estamos atualizando o saldo, ou seja descontando do saldo o valor da refeição que está sendo liberada.
        cout << "Refeição liberada" << endl;
    }
    catch (ExcecaoSaldoInsuficiente& e) {//fazendo o tratamento da exceção localmente
        std::cerr << e.what() << std::endl;
    }
}
Funcionario::~Funcionario(){
     cout << "Destruindo objeto Funcionario: " <<endl;
}
