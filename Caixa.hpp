#ifndef CAIXA_H
#define CAIXA_H

#include <map>
#include <vector>
#include <set>
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Cliente.hpp"
//#include "Professor.hpp"
//#include "Aluno.hpp"
//#include "AdmFump.hpp"
//#include "Visitante.hpp"

using namespace std;

class Caixa: public Funcionario{
    private:
    string _senha;
    string _usuario;
    string _RU; 
    int _caixa;

    public:
    Caixa(string nome, string senha, string usuario);

    static float preco;
    string bancoDeDados; 
    static map<string, map<int, int>> refeicoesClientes;
    string getDataAtual() const;
    // fazer login e trocar senha seria metodos da classe pai funcionário 

    void setSenha(string senha);
    void setUsuario(string usuario);
    void setRU(string RU);
    void setCaixa(int caixa);

    string getSenha();
    string getUsuario();
    string getRU();
    int getCaixa();

    void criarCadastro(string nome, int cpf, string usuario, string senha) override; // estou fazendo a subscrita do metodo de criar cadastro em Pessoa, que precisa estar em funcionário tmb
    void printInfo() override;
    bool fazerLogin(string& usuarioDigitado, string& senhaDigitada); //override;//precisa estar em Funcionário tmb para fazer o override
    void trocarSenha(string& novaSenha); //override;//precisa estar em funcionário tmb para fazer o override
    float acessarValor(Cliente cliente);
    bool acessoCliente(Cliente cliente, float& valorPago, const string& tipoRefeicao);
    static void resetarEntradas();//para simular um novo dia, pois só pode entrar uma vez por refeição
    void selecionarRU(string RU, int caixa);//para quando a caixa for fazer entrada no sistema selescionar qual RU e caixa ela está    void armazenarSaldoTotalMes();
    void armazenarRefeicoesporDia() const;
    void armazenarRefeicoesServidasMes(const string& bancoDeDados) const; //decidi fazer isso pq por aqui acho que seria o local mais sensato de fazer esse registro no banco de dados
    void armazenarRefeicoesServidasNivel(const string& bancoDeDados) const;
    //void armazenarRefeicoesServidasRU();
    void armazenarSaldoTotalDia(const string& bancoDeDados) const;
    void armazenarSaldoTotalMes(const string& bancoDeDados) const;
    //sujestão: na classe do Adm fump poderia ter um metodo que limpa esse banco de dados no final de algum periodo
}

#endif

#endif
