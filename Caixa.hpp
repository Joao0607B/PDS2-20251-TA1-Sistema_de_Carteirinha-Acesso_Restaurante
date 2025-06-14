#ifndef CAIXA_H
#define CAIXA_H

#include <map>
#include "Pessoa.hpp"
#include "Funcionario.hpp"
//#include "Cliente.hpp"
//#include "Professor.hpp"
//#include "Aluno.hpp"
//#include "AdmFump.hpp"
//#include "Visitante.hpp"

class Caixa: public Funcionario{
    private:
    string _senha;
    string _usuario;
    string _RU; 
    int _caixa;
    
    static map<int, bool> _clientes_que_ja_entraram;// para manter o controle por refeição

    public:
    Caixa(string nome, string senha, string usuario);

    static float preco;
    
    // fazer login e trocar senha seria metodos da classe pai funcionário 

    void setSenha(string senha);
    void setUsuario(string usuario);
    void setRU(string RU);
    void setCaixa(int caixa);

    string getSenha();
    int getUsuario();
    string getRU();
    int getCaixa();

    void criarCadastro(string nome, int cpf, string usuario, string senha) override; // estou fazendo a subscrita do metodo de criar cadastro em Pessoa, que precisa estar em funcionário tmb
    void printInfo() override;
    bool fazerLogin(string& usuarioDigitado, string& senhaDigitada); //override;//precisa estar em Funcionário tmb para fazer o override
    void trocarSenha(string& novaSenha); //override;//precisa estar em funcionário tmb para fazer o override
    static float acessarValor(Cliente cliente);
    bool acessoCliente(Cliente cliente, float& valorPago);
    //void bloquear_acesso();
    static void resetarEntradas();//para simular um novo dia, pois só pode entrar uma vez por refeição
    void selecionarRU(string RU, int caixa);
    
}


#endif
