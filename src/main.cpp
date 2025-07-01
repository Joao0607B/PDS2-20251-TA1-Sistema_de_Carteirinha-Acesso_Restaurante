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
    cout << " [2] Entrar no Restaurante" << endl;
    cout << " [3] Verificar Informação" << endl;
    cout << " [4] Sair" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Opção: ";
    cin >> opcao;
    system("cls");                                                                     // LIMPA A TELA

    switch (opcao) {
        case 1:
            //int opcao_cadastro;
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
            system("cls");                                                                     // LIMPA A TELA
            // ----------------------------------------------------------------------------------------------------------------
            // CADASTRAR ALUNO  -----------------------------------------------------------------------------------------------
            // ----------------------------------------------------------------------------------------------------------------
            
            if (opcao_cadastro == 1) {
                //string nome_Aluno, cpf_Aluno, curso_Aluno;
                //int nivelFump_Aluno;

                cout << "\n=== Cadastro de Aluno ===" << endl;
                cout << "Nome: ";
                cin.ignore(); // limpa buffer antes do getline
                getline(cin, nome_Aluno);
                cout << "CPF: ";
                getline(cin, cpf_Aluno);
                cout << "Nível FUMP (ex: 1, 2, 3): ";
                cin >> nivelFump_Aluno;
                cin.ignore(); // limpa antes de novo getline
                cout << "Curso: ";
                getline(cin, curso_Aluno);

                Cliente* cliente_Aluno = new Aluno(nome_Aluno, cpf_Aluno,nivelFump_Aluno, curso_Aluno); 

                sistema.cadastrarCliente(cliente_Aluno);                                                // ATENÇÃO
                cout << "\n>> Aluno cadastrado com sucesso!\n";
            } else {
                cout << "\n>> Tipo de cadastro ainda não implementado.\n";
            }
            system("cls");                                                                     // LIMPA A TELA
            // --------------------------------------------------------------------------------------------------------------------
            // CADASTRAR PROFESSOR  -----------------------------------------------------------------------------------------------
            // --------------------------------------------------------------------------------------------------------------------
            
            if (opcao_cadastro == 2) {
                //string nome_Professor, cpf_Professor, departamento_Professor;

                cout << "\n=== Cadastro de Professor ===" << endl;
                cout << "Nome: ";
                cin.ignore(); // para evitar problemas com getline
                getline(cin, nome_Professor);

                cout << "CPF: ";
                getline(cin, cpf_Professor);

                cout << "Departamento: ";
                getline(cin, departamento_Professor);
                
                Cliente* cliente_Professor = new Professor(nome_Professor, cpf_Professor,departamento_Professor);

                sistema.cadastrarCliente(cliente_Professor);                                  // ATENÇÃO !!
                cout << "\n>> Professor cadastrado com sucesso!" << endl;
            } else {
                cout << "\n>> Tipo de cadastro ainda não implementado.\n";caixa_Caixa;
            }
            system("cls");                                                                     // LIMPA A TELA
            // -------------------------------------------------------------------------------------------------------------------
            // CADASTRAR VISITANTE -----------------------------------------------------------------------------------------------
            // -------------------------------------------------------------------------------------------------------------------
            
            if (opcao_cadastro == 3) {
                //string nome_visitante, cpf_visitante;

                cout << "Nome: ";
                cin.ignore(); // para evitar problemas com getline
                getline(cin, nome_visitante);

                cout << "CPF: ";
                getline(cin, cpf_visitante);
                
                Cliente* cliente_Visitante = new Cliente(nome_visitante, cpf_visitante);

                sistema.cadastrarCliente(cliente_Visitante);                                        // ATENÇÃO !!
                cout << "\n>> Visitante cadastrado com sucesso!" << endl;
            } else {
                cout << "\n>> Tipo de cadastro ainda não implementado.\n";
            }
             system("cls");                                                                     // LIMPA A TELA
                //Cliente(std::string nome, std::string cpf);

                // ---------------------------------------------------------------------------------------------------------------------
            // CADASTRAR FUNCIONÁRIO -----------------------------------------------------------------------------------------------
            // ---------------------------------------------------------------------------------------------------------------------
        
            if (opcao_cadastro == 4) {
               // string nome_Funcionario, cpf_Funcionario, usuario_Funcionario, senha_Funcionario;

                cout << "\n=== Cadastro de Funcionario ===" << endl;
                cout << "Nome: ";
                cin.ignore(); // para evitar problemas com getline
                getline(cin, nome_Funcionario);

                cout << "CPF: ";
                getline(cin, cpf_Funcionario);

                cout << "Usuario: ";
                getline(cin, usuario_Funcionario);

                cout << "senha: ";
                getline(cin, senha_Funcionario);
                
                Funcionario* _Funcionario = new Funcionario(nome_Funcionario, cpf_Funcionario,usuario_Funcionario, senha_Funcionario);

                sistema.cadastrarFuncionario(_Funcionario); // ATENÇÃO !!
                cout << "\n>> Funcionario cadastrado com sucesso!" << endl;
            } else {
                cout << "\n>> Tipo de cadastro ainda não implementado.\n";
            }
            system("cls");                                                                     // LIMPA A TELA
            // ---------------------------------------------------------------------------------------------------------------
            // CADASTRAR CAIXA -----------------------------------------------------------------------------------------------
            // ---------------------------------------------------------------------------------------------------------------
            
            if (opcao_cadastro == 5) {
                //string nome_Caixa, cpf_Caixa, usuario_Caixa, senha_Caixa, restaurante_Caixa;
                //int caixa_Caixa;

                cout << "\n=== Cadastro de Caixa ===" << endl;
                cout << "Nome: ";
                cin.ignore(); // para evitar problemas com getline
                getline(cin, nome_Caixa);

                cout << "CPF: ";
                getline(cin, cpf_Caixa);

                cout << "Usuario: ";
                getline(cin, usuario_Caixa);

                cout << "senha: ";
                getline(cin, senha_Caixa);

                cout << "restaurante: ";
                getline(cin, restaurante_Caixa);

                cout << "Caixa: ";
                cin >> caixa_Caixa;
                cin.ignore(); // limpa o '\n' deixado no buffer pelo cin


                Funcionario* Funcionario_Caixa = new Caixa (nome_Caixa, cpf_Caixa,usuario_Caixa, senha_Caixa, restaurante_Caixa, caixa_Caixa );

                sistema.cadastrarFuncionario(Funcionario_Caixa); // ATENÇÃO !!
                cout << "\n>> Caixa cadastrado com sucesso!" << endl;
            } else {
                cout << "\n>> Tipo de cadastro ainda não implementado.\n";
            }
            system("cls");                                                                     // LIMPA A TELA
            // -----------------------------------------------------------------------------------------------------------------
            // CADASTRAR Fump -------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            
            if (opcao_cadastro == 6) {
                //string nome_admfump, cpf_admfump, usuario_admfump, senha_admfump;

                cout << "\n=== Cadastro de AdmFump ===" << endl;
                cout << "Nome: ";
                cin.ignore(); // para evitar problemas com getline
                getline(cin, nome_admfump);

                cout << "CPF: ";
                getline(cin, cpf_admfump);

                cout << "Usuario: ";
                getline(cin, usuario_admfump);

                cout << "senha: ";
                getline(cin, senha_admfump);
                
                Funcionario* Funcionario_Fump = new Funcionario (nome_admfump, cpf_admfump,usuario_admfump, senha_admfump);

                sistema.cadastrarFuncionario(Funcionario_Fump);
                cout << "\n>> AdmFump cadastrado com sucesso!" << endl;
            } else {
                cout << "\n>> Tipo de cadastro ainda não implementado.\n";
            }
            system("cls");                                                                     // LIMPA A TELA
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            //                                              CADASTROS FINALIZADOS
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            break;
            

        case 2: 
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            //                                              VERIFICAR ENTRADA NO RESTAURANTE
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            cout << "\n>> Verificando entrada no restaurante...\n";
            //string cpf_restaurante, usuario_restaurante, senha_restaurante;
            //char tipoRefeicao;

            cout << "Digite seu CPF: ";
            cin >> cpf_restaurante;
            cout << "Digite o tipo de refeição (A para almoço, J para jantar): ";
            cin >> tipoRefeicao;

            cout << "Digite o usuario do funcionario: ";
            cin >> usuario_restaurante;
            cout << "Digite a senha do funcionario: ";
            cin >> senha_restaurante;
            
            
            Funcionario* funcionarioResponsavel_Entrada = sistema.encontrarFuncionario(usuario_restaurante);
            if (funcionarioResponsavel_Entrada != nullptr)
                cout<<"Funcionario encontrado!"<<endl;
            
            sistema.processarRefeicao(cpf_restaurante, funcionarioResponsavel_Entrada->getCpf());
            system("cls");                                                                     // LIMPA A TELA
            break;
            
        case 3:
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            //                                              ADICIONAR CREDITO
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            cout << "\n>>Adicionar credito \n";
            //string cpf_credito,usuario_credito, senha_credito;
            //float valor_credito;
            
            cout << "Digite seu CPF: ";
            cin >> cpf_credito;
            cout << "Digite o valor a ser adicionado: ";
            cin >> valor_credito;
            
            cout << "Digite o usuario do funcionario: ";
            cin >> usuario_credito;
            cout << "Digite a senha do funcionario: ";
            cin >> senha_credito;

            Funcionario* funcionarioResponsavel_credito = sistema.encontrarFuncionario(usuario_info);
            if (funcionarioResponsavel_credito != nullptr)
                cout<<"Funcionario encontrado!"<<endl;

            sistema.depositarCrédito(cpf_credito, valor_credito, funcionarioResponsavel_credito->getCpf());
            cout<<"Credito adicionado com sucesso !"<<endl;
            system("cls");                                                                     // LIMPA A TELA
            break;
            
        case 4:
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            //                                              MOSTRAR INFORMAÇÕES DO USUÁRIO
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            int opcao_info;
            //string cpf_info, usuario_info, senha_info;
            
            cout << "\n>> Mostrando informações do usuário...\n";
            
            cout << "\n>> Selecione o tipo de usuário para ver as informações:\n";
            cout << " [1] Aluno\n";
            cout << " [2] Professor\n";
            cout << " [3] Visitante\n";
            cout << " [4] Funcionário\n";
            cout << " [5] Caixa\n";
            cout << " [6] AdmFump\n";
            cout << "----------------------------------------\n";
            cout << "Opção: ";
            cin >> opcao_info;

            if ( opcao_info < 4){
                
            cout << "Digite seu CPF: ";
            cin >> cpf_info;

            Cliente* clienteEncontrado = sistema.encontrarCliente(cpf_info);
            if (clienteEncontrado != nullptr)
                cout<<"Foi Encontrado :" << endl;
                clienteEncontrado->printInfo();
            }
            else{
                cout << "Digite seu usuario: ";
                cin >> usuario_info;
                cout << "Digite sua senha: ";
                cin >> senha_info;

                Funcionario* funcionarioEncontrado = sistema.encontrarFuncionario(usuario_info);
                if (funcionarioEncontrado != nullptr)
                    cout<<"Foi Encontrado :" << endl;
                    funcionarioEncontrado->printInfo();
            }
            system("cls");                                                                     // LIMPA A TELA
            break;
            
        case 5:
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            //                                             SALVAR DADOS
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            cout << "\n>> Salvar Dados\n";
            sistema.salvarDados();
            system("cls");                                                                     // LIMPA A TELA
            break;
            
        case 6:
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            //                                              SAIR DO SISTEMA
            // -----------------------------------------------------------------------------------------------------------------
            // -----------------------------------------------------------------------------------------------------------------
            opcao = 1;
            cout << "\n>> Saindo do sistema. Até logo!\n";
            system("cls");                                                                     // LIMPA A TELA
            break;
            
        default:
            cout << "\n>> Opção inválida. Tente novamente.\n";
            system("cls");                                                                     // LIMPA A TELA

    }
    } while (opcao != 1);

    return 0;
}
