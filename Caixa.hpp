#ifndef CAIXA_H
#define CAIXA_H

#include "Pessoa.hpp"
#include "Funcionario.hpp"

class Caixa: public Funcionario{
    private:
    string _senha;
    string _usuario;

    public:
    Caixa(string nome, string departamento, string senha, string usuario);

    // fazer login e trocar senha seria metodos da classe pai funcionário 

    void setSenha(string senha);
    void setUsuario(string usuario);

    string getSenha();
    int getUsuario();
    //o valor a pagar para cada nível vai estar no banco de dados?

    float acessar_valor_apagar();
    void liberar_acesso_cliente();
    void bloquear_acesso();
    void selecionar_RU();
    //RU vai estar no banco de dados?
}


#endif
