/**
 * @file GerenciamentoDeSistema.cpp
 * @brief Implementação dos métodos da classe GerenciamentoDeSistema, o núcleo do sistema.
 * @see GerenciamentoDeSistema.hpp
 */

#include "../include/GerenciamentoDeSistema.hpp"
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <algorithm>
#include <iostream>

using namespace std;

// Definição e inicialização da variável estática
char GerenciamentoDeSistema::_tipoDeRefeicao = 'a';

// --- Construtor e Destrutor ---

GerenciamentoDeSistema::GerenciamentoDeSistema() {
    carregarDados();
    std::cout << "Sistema de Gerenciamento iniciado." << std::endl;
}

GerenciamentoDeSistema::~GerenciamentoDeSistema() {
    salvarDados();
    // Libera a memória alocada dinamicamente para cada objeto
    for (Cliente* c : _clientes) {
        delete c;
    }
    for (Funcionario* f : _funcionarios) {
        delete f;
    }
    std::cout << "Sistema encerrado e memória liberada." << std::endl;
}

// --- Métodos Privados ---

void GerenciamentoDeSistema::registrarTransacao(const std::string& tipo, Cliente* cliente, double valor, Funcionario* funcionario, Cliente* cliente_destino) {
    std::ofstream arquivo_transacoes("data/Transacoes.txt", std::ios::app);
    if (!arquivo_transacoes.is_open()) {
        std::cerr << "ERRO CRITICO: Nao foi possivel abrir Transacoes.txt para registro." << std::endl;
        return;
    }
    Data hoje;
    arquivo_transacoes << "Data: " << hoje.toString();

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
    arquivo_transacoes << std::endl;
    arquivo_transacoes.close();
}

Cliente* GerenciamentoDeSistema::encontrarCliente(const std::string& cpf) {
    for (Cliente* cliente : _clientes) {
        if (cliente->getCpf() == cpf) {
            return cliente;
        }
    }
    return nullptr;
}

Funcionario* GerenciamentoDeSistema::encontrarFuncionario(const std::string& usuario) {
    for (Funcionario* funcionario : _funcionarios) {
        if (funcionario->getUsuario() == usuario) {
            return funcionario;
        }
    }
    return nullptr;
}

// --- Métodos Públicos ---

void GerenciamentoDeSistema::cadastrarCliente(Cliente* cliente) {
    if (encontrarCliente(cliente->getCpf()) == nullptr) {
        _clientes.push_back(cliente);
        salvarDados();
        std::cout << "Cliente " << cliente->getNome() << " cadastrado com sucesso." << std::endl;
    } else {
        std::cout << "ERRO: Já existe um cliente cadastrado com o CPF " << cliente->getCpf() << "." << std::endl;
        delete cliente;
    }
}

void GerenciamentoDeSistema::cadastrarFuncionario(Funcionario* funcionario) {
    if (encontrarFuncionario(funcionario->getUsuario()) == nullptr) {
        _funcionarios.push_back(funcionario);
        salvarDados();
        std::cout << "Funcionário " << funcionario->getNome() << " cadastrado com sucesso." << std::endl;
    } else {
        std::cout << "ERRO: Já existe um funcionário cadastrado com o usuário " << funcionario->getUsuario() << "." << std::endl;
        delete funcionario;
    }
}

void GerenciamentoDeSistema::apagarCliente(std::string cpf_cliente) {
    auto it = std::find_if(_clientes.begin(), _clientes.end(),
                           [&](Cliente* c) { return c->getCpf() == cpf_cliente; });

    if (it != _clientes.end()) {
        delete *it;
        _clientes.erase(it);
        std::cout << "Cliente com CPF " << cpf_cliente << " removido com sucesso." << std::endl;
        salvarDados();
    } else {
        std::cout << "ERRO: Cliente com CPF " << cpf_cliente << " não foi encontrado." << std::endl;
    }
}

void GerenciamentoDeSistema::apagarFuncionario(std::string cpf_funcionario) {
     auto it = std::find_if(_funcionarios.begin(), _funcionarios.end(),
                           [&](Funcionario* f) { return f->getCpf() == cpf_funcionario; });

    if (it != _funcionarios.end()) {
        delete *it;
        _funcionarios.erase(it);
        std::cout << "Funcionário com CPF " << cpf_funcionario << " removido com sucesso." << std::endl;
        salvarDados();
    } else {
        std::cout << "ERRO: Funcionário com CPF " << cpf_funcionario << " não foi encontrado." << std::endl;
    }
}

bool GerenciamentoDeSistema::verificarLogin(std::string cpf_funcionario) {
    for (const auto& func : _funcionarios) {
        if (func->getCpf() == cpf_funcionario) {
            if (func->_logado) {
                return true;
            } else {
                return false;
            }
        }
    }
    std::cout << "Funcionário não encontrado." << std::endl;
    return false;
}

bool GerenciamentoDeSistema::acessarSistema(std::string usuario, std::string senha) {
    Funcionario* func = encontrarFuncionario(usuario);
    if (func) {
        return func->fazerLogin(usuario, senha);
    }
    std::cout << "ERRO: Usuário '" << usuario << "' não encontrado." << std::endl;
    return false;
}

void GerenciamentoDeSistema::depositarCrédito(std::string cpf_cliente, float valor, std::string cpf_funcionario) {
    if (!verificarLogin(cpf_funcionario)) return;

    Cliente* cliente = encontrarCliente(cpf_cliente);
    Funcionario* funcionario = nullptr;
    for(const auto& f : _funcionarios) { if(f->getCpf() == cpf_funcionario) { funcionario = f; break; } }
    
    if (cliente && funcionario) {
        cliente->depositar(valor);
        this->registrarTransacao("Deposito", cliente, valor, funcionario);
        std::cout << "Depósito realizado com sucesso." << std::endl;
    } else {
        std::cout << "ERRO: Cliente ou funcionário não encontrado para realizar o depósito." << std::endl;
    }
}

void GerenciamentoDeSistema::processarRefeicao(std::string cpf_cliente, std::string cpf_funcionario) {
    if (!verificarLogin(cpf_funcionario)) return;
    
    Cliente* cliente = encontrarCliente(cpf_cliente);
    Funcionario* funcionario = nullptr;
    for(const auto& f : _funcionarios) { if(f->getCpf() == cpf_funcionario) { funcionario = f; break; } }

    if (cliente && funcionario) {
        try {
            if (cliente->registrarAcesso(_tipoDeRefeicao)) {
                this->registrarTransacao("Refeicao", cliente, cliente->getValorRefeicao(), funcionario);
                std::cout << "Refeição registrada com sucesso." << std::endl;
            } else {
                std::cout << "Não foi possível processar a refeição." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Falha na transação: " << e.what() << std::endl;
        }
    } else {
        std::cout << "ERRO: Cliente ou funcionário não encontrado para processar a refeição." << std::endl;
    }
}

void GerenciamentoDeSistema::salvarDados() {
    ofstream arquivo_clientes("data/Clientes.txt");
    if (!arquivo_clientes.is_open()) {
        cerr << "Erro ao abrir o arquivo Clientes.txt para escrita." << endl;
        return;
    }

    for (Cliente* cliente : _clientes) {
        std::string dados_base = "," + cliente->getNome() + "," + cliente->getCpf() + "," +
                                 to_string(cliente->getSaldo()) + "," +
                                 cliente->getUltimoAlmoco().toString() + "," +
                                 cliente->getUltimoJantar().toString();

        if (Aluno* aluno = dynamic_cast<Aluno*>(cliente)) {
            arquivo_clientes << "A" << dados_base << ","
                             << aluno->getNivelFump() << ","
                             << aluno->getCurso() << endl;
        } else if (Professor* professor = dynamic_cast<Professor*>(cliente)) {
            arquivo_clientes << "P" << dados_base << ","
                             << professor->getDepartamento() << endl;
        } else {
            arquivo_clientes << "C" << dados_base << endl;
        }
    }
    arquivo_clientes.close();
    cout << "Dados dos clientes salvos em Clientes.txt" << endl;

    ofstream arquivo_funcionarios("data/Funcionarios.txt");
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

    ifstream arquivo_clientes("data/Clientes.txt");
    if (!arquivo_clientes.is_open()) {
        cerr << "Arquivo Clientes.txt nao encontrado. Nenhum cliente carregado." << endl;
    } else {
        string linha;
        while (getline(arquivo_clientes, linha)) {
            if (linha.empty()) continue;
            
            stringstream ss(linha);
            string tipo_str, nome, cpf, saldo_str, almoco_str, jantar_str, dado_extra1, dado_extra2;
            
            getline(ss, tipo_str, ',');
            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, saldo_str, ',');
            getline(ss, almoco_str, ',');
            getline(ss, jantar_str, ',');
            
            float saldo = 0.0f;
            if (!saldo_str.empty()) {
                try { saldo = stof(saldo_str); }
                catch (const std::exception& e) { /* Ignora erro */ }
            }

            char tipo = tipo_str[0];
            Cliente* novo_cliente = nullptr;

            if (tipo == 'A') {
                getline(ss, dado_extra1, ',');
                getline(ss, dado_extra2);
                novo_cliente = new Aluno(nome, cpf, stoi(dado_extra1), dado_extra2);
            } else if (tipo == 'P') {
                getline(ss, dado_extra1);
                novo_cliente = new Professor(nome, cpf, dado_extra1);
            } else {
                novo_cliente = new Cliente(nome, cpf);
            }
            
            if (novo_cliente) {
                novo_cliente->setSaldo(saldo);

                int dia, mes, ano;
                if (sscanf(almoco_str.c_str(), "%d/%d/%d", &dia, &mes, &ano) == 3) {
                    novo_cliente->setUltimoAlmoco(Data(dia, mes, ano));
                }
                if (sscanf(jantar_str.c_str(), "%d/%d/%d", &dia, &mes, &ano) == 3) {
                    novo_cliente->setUltimoJantar(Data(dia, mes, ano));
                }
                
                _clientes.push_back(novo_cliente);
            }
        }
        arquivo_clientes.close();
        cout << _clientes.size() << " clientes carregados de Clientes.txt" << endl;
    }

    ifstream arquivo_funcionarios("data/Funcionarios.txt");
    if (!arquivo_funcionarios.is_open()) {
        cerr << "Arquivo Funcionarios.txt nao encontrado. Nenhum funcionario carregado." << endl;
    } else {
        string linha;
        while (getline(arquivo_funcionarios, linha)) {
             if (linha.empty()) continue;
             
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

void GerenciamentoDeSistema::exibirClientes() {
    std::cout << "\n--- LISTA DE CLIENTES ---\n";
    if (_clientes.empty()) {
        std::cout << "Nenhum cliente cadastrado.\n";
    }
    for (Cliente* c : _clientes) {
        c->printInfo();
        std::cout << "------------------------\n";
    }
}

void GerenciamentoDeSistema::exibirFuncionarios() {
    std::cout << "\n--- LISTA DE FUNCIONÁRIOS ---\n";
    if (_funcionarios.empty()) {
        std::cout << "Nenhum funcionário cadastrado.\n";
    }
    for (Funcionario* f : _funcionarios) {
        f->printInfo();
        std::cout << "---------------------------\n";
    }
}