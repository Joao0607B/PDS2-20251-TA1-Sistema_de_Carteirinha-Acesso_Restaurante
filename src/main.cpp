#include "../include/Aluno.hpp"
#include "../include/Cliente.hpp"
#include "../include/Funcionario.hpp"
#include "../include/Pessoa.hpp"
#include "../include/Caixa.hpp"
#include "../include/Professor.hpp"
#include "../include/Data.hpp"
#include "../include/GerenciamentoDeSistema.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    GerenciamentoDeSistema sistema;
    int opcao_cadastro, nivelFump_Aluno, caixa_Caixa;
    string nome_Aluno, cpf_Aluno, curso_Aluno, nome_Professor, cpf_Professor, departamento_Professor;
    string nome_visitante, cpf_visitante, nome_Funcionario, cpf_Funcionario, usuario_Funcionario, senha_Funcionario;
    string nome_Caixa, cpf_Caixa, usuario_Caixa, senha_Caixa, restaurante_Caixa;
    string nome_admfump, cpf_admfump, usuario_admfump, senha_admfump;
    string cpf_restaurante, usuario_restaurante, senha_restaurante;
    string cpf_credito, usuario_credito, senha_credito;
    string cpf_info, usuario_info, senha_info;
    char tipoRefeicao;
    float valor_credito;

    int opcao = 0;

    do {
        cout << "\n========================================" << endl;
        cout << "        BEM-VINDO AO RU UNIVERSITÁRIO   " << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opção:" << endl;
        cout << " [1] Cadastrar" << endl;
        cout << " [2] Fazer Login (funcionário)" << endl;
        cout << " [3] Adicionar Crédito" << endl;
        cout << " [4] Sair" << endl;
        cout << " [5] Salvar Dados" << endl;
        cout << " [6] Verificar Informação" << endl;
        cout << " [7] Liberar Refeção" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Opção: ";
        cin >> opcao;
        cout <<"\n"<<endl;
        cout <<"\n"<<endl;
       

        switch (opcao) {
            case 1: {
                cout << "\n>> Selecione o tipo de usuário para cadastro:\n";
                cout << " [1] Aluno\n";
                cout << " [2] Professor\n";
                cout << " [3] Visitante\n";
                cout << " [4] Funcionário\n";
                cout << " [5] Caixa\n";
                cout << " [6] AdmFump\n";
                cout << "----------------------------------------\n";
                cout << "Tipo: ";
                cin >> opcao_cadastro;
                cout <<"\n"<<endl;
                cout <<"\n"<<endl;
                

                cin.ignore();  // limpar buffer

                if (opcao_cadastro == 1) {
                    cout << "\n=== Cadastro de Aluno ===" << endl;
                    cout << "Nome: ";
                    getline(cin, nome_Aluno);
                    cout << "CPF: ";
                    getline(cin, cpf_Aluno);
                    cout << "Nível FUMP: ";
                    cin >> nivelFump_Aluno;
                    cin.ignore();
                    cout << "Curso: ";
                    getline(cin, curso_Aluno);
                    Cliente* cliente = new Aluno(nome_Aluno, cpf_Aluno, nivelFump_Aluno, curso_Aluno);
                    sistema.cadastrarCliente(cliente);
                    cout << "\n>> Aluno cadastrado com sucesso!\n";
                } else if (opcao_cadastro == 2) {
                    cout << "\n=== Cadastro de Professor ===" << endl;
                    cout << "Nome: ";
                    getline(cin, nome_Professor);
                    cout << "CPF: ";
                    getline(cin, cpf_Professor);
                    cout << "Departamento: ";
                    getline(cin, departamento_Professor);
                    Cliente* cliente = new Professor(nome_Professor, cpf_Professor, departamento_Professor);
                    sistema.cadastrarCliente(cliente);
                    cout << "\n>> Professor cadastrado com sucesso!\n";
                } else if (opcao_cadastro == 3) {
                    cout << "\n=== Cadastro de Visitante ===" << endl;
                    cout << "Nome: ";
                    getline(cin, nome_visitante);
                    cout << "CPF: ";
                    getline(cin, cpf_visitante);
                    Cliente* cliente = new Cliente(nome_visitante, cpf_visitante);
                    sistema.cadastrarCliente(cliente);
                    cout << "\n>> Visitante cadastrado com sucesso!\n";
                } else if (opcao_cadastro == 4) {
                    cout << "\n=== Cadastro de Funcionário ===" << endl;
                    cout << "Nome: ";
                    getline(cin, nome_Funcionario);
                    cout << "CPF: ";
                    getline(cin, cpf_Funcionario);
                    cout << "Usuário: ";
                    getline(cin, usuario_Funcionario);
                    cout << "Senha: ";
                    getline(cin, senha_Funcionario);
                    Funcionario* funcionario = new Funcionario(nome_Funcionario, cpf_Funcionario, usuario_Funcionario, senha_Funcionario);
                    sistema.cadastrarFuncionario(funcionario);
                    cout << "\n>> Funcionário cadastrado com sucesso!\n";
                } else if (opcao_cadastro == 5) {
                    cout << "\n=== Cadastro de Caixa ===" << endl;
                    cout << "Nome: ";
                    getline(cin, nome_Caixa);
                    cout << "CPF: ";
                    getline(cin, cpf_Caixa);
                    cout << "Usuário: ";
                    getline(cin, usuario_Caixa);
                    cout << "Senha: ";
                    getline(cin, senha_Caixa);
                    cout << "Restaurante: ";
                    getline(cin, restaurante_Caixa);
                    cout << "Número do Caixa: ";
                    cin >> caixa_Caixa;
                    cin.ignore();
                    Funcionario* funcionario = new Caixa(nome_Caixa, cpf_Caixa, usuario_Caixa, senha_Caixa, restaurante_Caixa, caixa_Caixa);
                    sistema.cadastrarFuncionario(funcionario);
                    cout << "\n>> Caixa cadastrado com sucesso!\n";
                } else if (opcao_cadastro == 6) {
                    cout << "\n=== Cadastro de AdmFump ===" << endl;
                    cout << "Nome: ";
                    getline(cin, nome_admfump);
                    cout << "CPF: ";
                    getline(cin, cpf_admfump);
                    cout << "Usuário: ";
                    getline(cin, usuario_admfump);
                    cout << "Senha: ";
                    getline(cin, senha_admfump);
                    Funcionario* funcionario = new Funcionario(nome_admfump, cpf_admfump, usuario_admfump, senha_admfump);
                    sistema.cadastrarFuncionario(funcionario);
                    cout << "\n>> AdmFump cadastrado com sucesso!\n";
                } else {
                    cout << "\n>> Tipo de cadastro inválido.\n";
                }
                break;
            }

            case 2: {
                cout << "\n>> Verificando entrada no restaurante...\n";
                cout << "Digite o tipo de refeição (A para almoço, J para jantar): ";
                cin >> tipoRefeicao;
                cout << "Digite o usuário do funcionário: ";
                cin >> usuario_restaurante;
                cout << "Digite a senha do funcionário: ";
                cin >> senha_restaurante;
                GerenciamentoDeSistema::_tipoDeRefeicao = tipoRefeicao;
                Funcionario* f = sistema.encontrarFuncionario(usuario_restaurante);
                if (f != nullptr) {
                    sistema.acessarSistema(usuario_restaurante, senha_restaurante);
                }
                break;
            }

            case 3: {
                cout << "\n>> Adicionar crédito\n";
                cout << "Digite seu CPF: ";
                cin >> cpf_credito;
                cout << "Digite o valor a ser adicionado: ";
                cin >> valor_credito;
                cout << "Digite o usuário do funcionário: ";
                cin >> usuario_credito;
                Funcionario* fun = sistema.encontrarFuncionario(usuario_credito);
                if(sistema.encontrarFuncionario(usuario_credito)->_logado == false){
                    cout << "Digite a senha do funcionário: ";
                    cin >> senha_credito;
                    if (fun != nullptr) {
                        sistema.acessarSistema(usuario_credito, senha_credito);
                    }

                }
                //cout << "Digite a senha do funcionário: ";
                //cin >> senha_credito;
                Funcionario* f = sistema.encontrarFuncionario(usuario_credito);
                if (f != nullptr) {
                    cout << "Funcionário encontrado.\n";
                    sistema.depositarCrédito(cpf_credito, valor_credito, f->getCpf());
                    cout << "Crédito adicionado com sucesso!\n";
                } else {
                    cout << "Funcionário não encontrado.\n";
                }
                break;
            }

            case 4: {
                cout << "\n>> Saindo do sistema. Até logo!\n";
                break;
            }

            case 5: {
                cout << "\n>> Salvando dados...\n";
                sistema.salvarDados();
                cout << "Dados salvos com sucesso.\n";
                break;
            }

            case 6: {
                int tipo;
                cout << "\n>> Mostrar informações\n";
                cout << " [1] Aluno\n [2] Professor\n [3] Visitante\n [4] Funcionário/Caixa/Fump\n";
                cout << "Tipo: ";
                cin >> tipo;
                cout <<"\n"<<endl;
                cout <<"\n"<<endl;

                if (tipo >= 1 && tipo <= 3) {
                    cout << "Digite seu CPF: ";
                    cin >> cpf_info;
                    Cliente* c = sistema.encontrarCliente(cpf_info);
                    if (c != nullptr) {
                        c->printInfo();
                    } else {
                        cout << "Cliente não encontrado.\n";
                    }
                } else {
                    cout << "Digite seu usuário: ";
                    cin >> usuario_info;
                    cout << "Digite sua senha: ";
                    cin >> senha_info;
                    Funcionario* f = sistema.encontrarFuncionario(usuario_info);
                    if (f != nullptr) {
                        f->printInfo();
                    } else {
                        cout << "Funcionário não encontrado.\n";
                    }
                }
                break;
            }
            case 7: {// Liberar Refeção
                cout << "Digite seu usuário: ";
                cin >> usuario_info;
                Funcionario* f = sistema.encontrarFuncionario(usuario_info);
                if(sistema.encontrarFuncionario(usuario_info)->_logado == false){
                    cout << "Digite sua senha: ";
                    cin >> senha_info;
                    if (f != nullptr) {
                        sistema.acessarSistema(usuario_info, senha_info);
                    }

                }
                cout << "Digite o CPF do cliente: ";
                cin >> cpf_info;
                sistema.processarRefeicao(cpf_info, f->getCpf());
                break;
            }
            default:
                cout << "\n>> Opção inválida. Tente novamente.\n";
                break;
        }

       
    } while (opcao != 4);  // sair apenas quando a opção for "Sair"

    return 0;
}
