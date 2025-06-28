#include "Aluno.hpp"
#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Pessoa.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int opcao;
  vector<Aluno *> listaAlunos;
  vector<Professor *> listaProfessores;
  vector<Funcionario *> listaFuncionarios;
  vector<Caixa *> listaCaixa;

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

    switch (opcao) {
    case 1:
      int opcao_cadastro;
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

      // ----------------------------------------------------------------------------------------------------------------
      // CADASTRAR ALUNO  -----------------------------------------------------------------------------------------------
      // ----------------------------------------------------------------------------------------------------------------
      
      if (opcao_cadastro == 1) {
        string nome_Aluno, cpf_Aluno, curso_Aluno;
        int nivelFump_Aluno;

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

        Aluno *aluno = new Aluno(nome_Aluno, cpf_Aluno, nivelFump_Aluno, curso_Aluno);
        listaAlunos.push_back(aluno);
        cout << "\n>> Aluno cadastrado com sucesso!\n";
      } else {
        cout << "\n>> Tipo de cadastro ainda não implementado.\n";
      }
      
      // --------------------------------------------------------------------------------------------------------------------
      // CADASTRAR PROFESSOR  -----------------------------------------------------------------------------------------------
      // --------------------------------------------------------------------------------------------------------------------
      
      if (opcao_cadastro == 2) {
        string nome_Professor, cpf_Professor, departamento_Professor;

        cout << "\n=== Cadastro de Professor ===" << endl;
        cout << "Nome: ";
        cin.ignore(); // para evitar problemas com getline
        getline(cin, nome_Professor);

        cout << "CPF: ";
        getline(cin, cpf_Professor);

        cout << "Departamento: ";
        getline(cin, departamento_Professor);

        // Cria dinamicamente um professor e adiciona à lista
        Professor *professor = new Professor(nome_Professor, cpf_Professor, departamento_Professor);
        listaProfessores.push_back(professor);

        cout << "\n>> Professor cadastrado com sucesso!" << endl;
      } else {
        cout << "\n>> Tipo de cadastro ainda não implementado.\n";
      }
      
      // -------------------------------------------------------------------------------------------------------------------
      // CADASTRAR VISITANTE -----------------------------------------------------------------------------------------------
      // -------------------------------------------------------------------------------------------------------------------
      
      if (opcao_cadastro == 3) {

      }
      
      // ---------------------------------------------------------------------------------------------------------------------
      // CADASTRAR FUNCIONÁRIO -----------------------------------------------------------------------------------------------
      // ---------------------------------------------------------------------------------------------------------------------
  
      if (opcao_cadastro == 4) {
        string nome_Funcionario, cpf_Funcionario, usuario_Funcionario, senha_Funcionario;

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

        // Cria dinamicamente um Funcionario e adiciona à lista
        Funcionario *funcionario = new Funcionario(nome_Funcionario, cpf_Funcionario, usuario_Funcionario, senha_Funcionario);
        listaFuncionarios.push_back(funcionario);

        cout << "\n>> Funcionario cadastrado com sucesso!" << endl;
      } else {
        cout << "\n>> Tipo de cadastro ainda não implementado.\n";
      }
      
      // ---------------------------------------------------------------------------------------------------------------
      // CADASTRAR CAIXA -----------------------------------------------------------------------------------------------
      // ---------------------------------------------------------------------------------------------------------------
      
      if (opcao_cadastro == 5) {
        string nome_Caixa, cpf_Caixa, usuario_Caixa, senha_Caixa, restaurante_Caixa; int caixa_Caixa;

        cout << "\n=== Cadastro de Caixa ===" << endl;
        cout << "Nome: ";
        cin.ignore(); // para evitar problemas com getline
        getline(cin, nome_Funcionario);

        cout << "CPF: ";
        getline(cin, cpf_Funcionario);

        cout << "Usuario: ";
        getline(cin, usuario_Funcionario);

        cout << "senha: ";
        getline(cin, senha_Funcionario);

        // Cria dinamicamente um Caixa e adiciona à lista
        Caixa *caixa = new Caixa(nome_Caixa, cpf_Caixa, usuario_Caixa, senha_Caixa, restaurante_Caixa, caixa_Caixa);
        listaCaixa.push_back(caixa);

        cout << "\n>> Caixa cadastrado com sucesso!" << endl;
      } else {
        cout << "\n>> Tipo de cadastro ainda não implementado.\n";
      }
      
      // -----------------------------------------------------------------------------------------------------------------
      // CADASTRAR Fump -------------------------------------------------------------------------------------------------
      // -----------------------------------------------------------------------------------------------------------------
      
      AdmFump
      if (opcao_cadastro == 6) {
        string nome_admfump, cpf_admfump, usuario_admfump, senha_admfump;

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

        // Cria dinamicamente um Caixa e adiciona à lista
        AdmFump *admFump = new AdmFump(nome_admfump, cpf_admfump, usuario_admfump, senha_admfump);
        listaAdmFump.push_back(admFump);

        cout << "\n>> AdmFump cadastrado com sucesso!" << endl;
      } else {
        cout << "\n>> Tipo de cadastro ainda não implementado.\n";
      }
      // -----------------------------------------------------------------------------------------------------------------
      // -----------------------------------------------------------------------------------------------------------------
      //                                              CADASTROS FINALIZADOS
      // -----------------------------------------------------------------------------------------------------------------
      // -----------------------------------------------------------------------------------------------------------------
      
      break;
    case 2:
      cout << "\n>> Verificando entrada no restaurante...\n";
      // chamar função de entrada aqui
      break;
    case 3:
      cout << "\n>> Mostrando informações do usuário...\n";
      // chamar função de informações aqui
      break;
    case 4:
      cout << "\n>> Saindo do sistema. Até logo!\n";
      break;
    default:
      cout << "\n>> Opção inválida. Tente novamente.\n";
    }

  } while (opcao != 4);

  return 0;
}
