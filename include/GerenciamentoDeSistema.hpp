#ifndef GERENCIAMENTO_DE_SISTEMA_H
#define GERENCIAMENTO_DE_SISTEMA_H

#include <iostream>
#include <vector>
#include <string>

#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Professor.hpp"
#include "Aluno.hpp"
#include "Data.hpp"
#include "../data/Funcionarios.txt"
#include "../data/Clientes.txt"
#include "../data/Transações.txt"

using namespace std;

class GerenciamentoDeSistema {
private:
    vector<Cliente*> _clientes;
    vector<Funcionario*> _funcionarios;
   
    Cliente* encontrarCliente(const string& cpf);
    Funcionario* encontrarFuncionario(const string& usuario);
    void registrarTransacao(const string& tipo, Cliente* cliente, double valor, Funcionario* funcionario, Cliente* cliente_destino = nullptr);

public:
    static char _tipoDeRefeicao; //a = almoço, j = jantar
    GerenciamentoDeSistema();//Carrega os dados dos arquivos ao iniciar o sistema.
    ~GerenciamentoDeSistema(); //Salva os dados nos arquivos e libera a memória alocada dinamicamente.

    void cadastrarCliente(Cliente* cliente);
    void cadastrarFuncionario(Funcionario* funcionario);
    void apagarCliente(string cpf_cliente);
    void apagarFuncionario(string cpf_funcionario);
    bool verificarLogin(string cpf_funcionario);

    bool acessarSistema(string usuario, string senha);
    void depositarCrédito(string cpf_cliente, float valor, string cpf_funcionario);
    void processarRefeicao(string cpf_cliente, string cpf_funcionario);

    void salvarDados();
    void carregarDados();
    
    void exibirClientes();
    void exibirFuncionarios();
    
    Cliente* encontrarCliente(const string& cpf);
    Funcionario* encontrarFuncionario(const string& usuario);
};

#endif
