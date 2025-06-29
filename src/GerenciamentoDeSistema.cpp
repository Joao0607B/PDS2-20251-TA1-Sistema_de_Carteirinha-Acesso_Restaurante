#include "../include/GerenciamentoDeSistema.hpp"
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <algorithm> 

char GerenciamentoDeSistema::_tipoDeRefeicao = 'a';

void GerenciamentoDeSistema::registrarTransacao(const string& tipo, Cliente* cliente, double valor, Funcionario* funcionario, Cliente* cliente_destino) {
    ofstream arquivo_transacoes("Transacoes.txt", ios::app);
    if (!arquivo_transacoes.is_open()) {
        cerr << "ERRO CRITICO: Nao foi possivel abrir Transacoes.txt para registro." << endl;
        return;
    }
    Data hoje;
    hoje.definirDataAtual();

    arquivo_transacoes << "Data: " << hoje.toString();
    // Formatação baseada no TIPO de transação
    if (tipo == "Refeicao") {
        arquivo_transacoes << " Refeição: " << _tipoDeRefeicao
                           << " Cliente: " << cliente->getCpf()
                           << " Valor pago: " << valor;
    } else if (tipo == "Deposito") {
        arquivo_transacoes << " Deposito Cliente: " << cliente->getCpf()
                           << " Valor: " << valor
                           << " Funcionario: " << funcionario->getUsuario();
    } else if (tipo == "Transferencia") {
        arquivo_transacoes << " Transferencia de: " << cliente->getCpf()
                           << " para: " << cliente_destino->getCpf()
                           << " Valor: " << valor;
    }

    arquivo_transacoes << endl;
    arquivo_transacoes.close();
}

GerenciamentoDeSistema::GerenciamentoDeSistema(){
    carregarDados();
};

GerenciamentoDeSistema::~GerenciamentoDeSistema(){
    salvarDados();
    for (Cliente* c : _clientes) delete c;
    for (Funcionario* f : _funcionarios) delete f;
}; //Salva os dados nos arquivos e libera a memória alocada dinamicamente.
    
void GerenciamentoDeSistema::cadastrarCliente(Cliente* cliente){
    if(encontrarCliente(cliente->getCpf()) == nullptr){
        _clientes.push_back(cliente);
        salvarDados();
    }else{
        cout << "Existe outro cliente cadastrado com esse cpf." << endl;
    }
};
    
void GerenciamentoDeSistema::cadastrarFuncionario(Funcionario* funcionario){
    if(encontrarFuncionario(funcionario->getCpf()) == nullptr){
        _funcionarios.push_back(funcionario);
        salvarDados();
    }else{
        cout << "Existe outro funcionário cadastrado com esse cpf." << endl;
    }
};
    
void GerenciamentoDeSistema::apagarCliente(string cpf_cliente){
    auto it = find(_clientes.begin(), _clientes.end(), cpf_cliente);
    if (it != _clientes.end()) {
        _clientes.erase(it);
    } else {
        cout << "O cliente do cpf " << cpf_cliente << " nao foi encontrado." << endl;
    }

};
    
void GerenciamentoDeSistema::apagarFuncionario(string cpf_funcionario){
    auto it = find(_funcionarios.begin(), _funcionarios.end(), cpf_funcionario);
    if (it != _funcionarios.end()) {
        _funcionarios.erase(it);
    } else {
        cout << "O funcionario do cpf " << cpf_funcionario << " nao foi encontrado." << endl;
    }
}; 

bool GerenciamentoDeSistema::verificarLogin(string cpf_funcionario){
    if(encontrarFuncionario(cpf_funcionario) != nullptr){
        if(encontrarFuncionario(cpf_funcionario)->_logado==true){
            return true;
        }else{
            cout << "Este funcionário não está logado." << endl;
        }
        
    }else{
        cout << "Funcionário não encontrado." << endl;
    }
    return false;
};

void GerenciamentoDeSistema::depositarCrédito(string cpf_cliente, float valor, string cpf_funcionario){
    if(verificarLogin(cpf_funcionario)){
        encontrarCliente(cpf_cliente)->depositar(valor);
    }
};
    
void GerenciamentoDeSistema::processarRefeicao(string cpf_cliente, string cpf_funcionario){
    if(verificarLogin(cpf_funcionario)){
        if(encontrarCliente(cpf_cliente) != nullptr){
            encontrarFuncionario(cpf_funcionario)->liberarRefeicao(encontrarCliente(cpf_cliente));
        }
        this->registrarTransacao("Refeicao", encontrarCliente(cpf_cliente), encontrarCliente(cpf_cliente)->getValorRefeicao(), encontrarFuncionario(cpf_funcionario));
        cout << "Refeição registrada." << endl;
    }
};
    
bool GerenciamentoDeSistema::acessarSistema(string usuario, string senha){};

void GerenciamentoDeSistema::salvarDados() {
    //Salvar clientes
    ofstream arquivo_clientes("data/Clientes.txt");
    if (!arquivo_clientes.is_open()) {
        cerr << "Erro ao abrir o arquivo Clientes.txt para escrita." << endl;
        return;
    }

    for (Cliente* cliente : _clientes) {
        if (Aluno* aluno = dynamic_cast<Aluno*>(cliente)) {
            arquivo_clientes << "A," // 'A' para Aluno
                             << aluno->getNome() << ","
                             << aluno->getCpf() << ","
                             << aluno->getSaldo() << ","
                             << aluno->getNivelFump() << ","
                             << aluno->getCurso() << endl;
        } else if (Professor* professor = dynamic_cast<Professor*>(cliente)) {
            arquivo_clientes << "P," // 'P' para Professor
                             << professor->getNome() << ","
                             << professor->getCpf() << ","
                             << professor->getSaldo() << ","
                             << professor->getDepartamento() << endl;
        } else {
            // Cliente Visitante
            arquivo_clientes << "C," // 'C' para Cliente
                             << cliente->getNome() << ","
                             << cliente->getCpf() << ","
                             << cliente->getSaldo() << endl;
        }
    }
    arquivo_clientes.close();
    cout << "Dados dos clientes salvos em Clientes.txt" << endl;


    //Salvar funcionários
    ofstream arquivo_funcionarios("Funcionarios.txt");
    if (!arquivo_funcionarios.is_open()) {
        cerr << "Erro ao abrir o arquivo Funcionarios.txt para escrita." << endl;
        return;
    }

    for (Funcionario* func : _funcionarios) {
        arquivo_funcionarios << func->getNome() << ","
                             << func->getCpf() << ","
                             << func->getUsuario() << ","
                             << func->getSenha() << endl;
    }
    arquivo_funcionarios.close();
    cout << "Dados dos funcionários salvos em Funcionarios.txt" << endl;
}

void GerenciamentoDeSistema::carregarDados() {
    for (Cliente* c : _clientes) delete c;
    _clientes.clear();

    for (Funcionario* f : _funcionarios) delete f;
    _funcionarios.clear();

    ifstream arquivo_clientes("Clientes.txt");
    if (!arquivo_clientes.is_open()) {
        cerr << "Arquivo Clientes.txt nao encontrado. Nenhum cliente carregado." << endl;
    } else {
        string linha;
        while (getline(arquivo_clientes, linha)) {
            stringstream ss(linha);
            string tipo_str, nome, cpf, saldo_str, dado1, dado2;
            
            getline(ss, tipo_str, ',');
            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, saldo_str, ',');
            
            float saldo = stof(saldo_str);
            char tipo = tipo_str[0];

            Cliente* novo_cliente = nullptr;
            if (tipo == 'A') { // É um Aluno
                getline(ss, dado1, ','); // Nivel Fump
                getline(ss, dado2);      // Curso
                novo_cliente = new Aluno(nome, cpf, stoi(dado1), dado2);
            } else if (tipo == 'P') { // É um Professor
                getline(ss, dado1);      // Departamento
                novo_cliente = new Professor(nome, cpf, dado1);
            } else { // É um Cliente genérico
                novo_cliente = new Cliente(nome, cpf);
            }
            
            if (novo_cliente) {
                novo_cliente->setSaldo(saldo);
                _clientes.push_back(novo_cliente);
            }
        }
        arquivo_clientes.close();
        cout << _clientes.size() << " clientes carregados de Clientes.txt" << endl;
    }

    ifstream arquivo_funcionarios("Funcionarios.txt");
    if (!arquivo_funcionarios.is_open()) {
        cerr << "Arquivo Funcionarios.txt nao encontrado. Nenhum funcionario carregado." << endl;
    } else {
        string linha;
        while (getline(arquivo_funcionarios, linha)) {
            stringstream ss(linha);
            string nome, cpf, usuario, senha;

            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, usuario, ',');
            getline(ss, senha);

            _funcionarios.push_back(new Funcionario(nome, cpf, usuario, senha));
        }
        arquivo_funcionarios.close();
        cout << _funcionarios.size() << " funcionarios carregados de Funcionarios.txt" << endl;
    }
}

void GerenciamentoDeSistema::exibirClientes(){
    for(Cliente* c: _clientes){
        c->printInfo();
    }
};
    
void GerenciamentoDeSistema::exibirFuncionarios(){
        for(Funcionario* f: _funcionarios){
        f->printInfo();
    }
};

Cliente* GerenciamentoDeSistema::encontrarCliente(const string& cpf) {
    for (Cliente* cliente : _clientes) {
        if (cliente->getCpf() == cpf) {
            return cliente; // Retorna o ponteiro para o cliente encontrado
        }
    }
    return nullptr; // Se o loop terminar sem encontrar o cliente, retorna um ponteiro nulo
}
 
Funcionario* GerenciamentoDeSistema::encontrarFuncionario(const string& usuario) {
    for (Funcionario* funcionario : _funcionarios) {
        if (funcionario->getUsuario() == usuario) {
            return funcionario; // Retorna o ponteiro para o funcionário encontrado
        }
    }
    return nullptr; // Se o loop terminar sem encontrar o funcionário, retorna um ponteiro nulo
}
