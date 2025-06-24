#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Pessoa.hpp" 
#include "Cliente.hpp"

class Funcionario: public Pessoa{
    //Funcionario é uma subclasse de Pessoa, mas também é a superclasse de Caixa.
    private:
    //Funcionario possui dois atributos privados, são eles _usuario e _senha.
    string _usuario;
    std::string _senha;  

    public:
    Funcionario(string nome, string cpf, string usuario, string senha);//Construtor de Funcionario que recebe dois atributos herdados de Pessoa(nome e cpf) e acrescenta dois argumentos proprios(usuario e senha).
    
    bool _logado = false;//Atributo _logado é public e é responsável somente por indicar se o usuário está logado ou não no sistema.

    string getUsuario();//Aqui temos o Get para permitir acessar o argumento privado _usuario.
    string getSenha();//Aqui temos o Get para permitir acessar o argumento privado _senha.

    void setUsuario(string usuario);//Aqui temos o Set para permitir modificar o argumento privado _usuario.
    void setSenha(string senha);//Aqui temos o Set para permitir modificar o argumento privado _senha.
    
    void printInfo() override;//Esse método faz a subscrita do método printInfo() da classe Pessoa agora permitindo printar também o usuário do objeto.
    bool fazerLogin(const string& usuarioDigitado, const string& senhaDigitada);//O método fazerLogin é um bool que recebe os parametros usuarioDigitado e senhaDigitada e compara com GetUsuario() e GetSenha() e retorna mensagens de erro e false se não forem iguais e retorna true se forem iguais.
    void fazerLogout();//A função logOut é resposável por conferir se um usuário está logado no sistema por meio de _logado, e se estiver logado realiza o logOut e se não estiver logado exibe uma mensagem de erro.
    void trocarSenha(string& novaSenha, string& confirmarSenha);//O método trocarSenha recebe o parâmetro novaSenha que será a senha que o usuário gostaria de definir como nova Senha de acesso e o parâmetro confirmarSenha que será comparada com a senha atual para que seja possivel redefinir a senha.
    void liberarRefeicao(*Cliente cliente);//Verifica o ultimo acesso e o saldo do cliente para liberar a refeição, como também atualiza o ultimo acesso e desconta o valor da refeição do saldo atual.
    ~Funcionario();//O destrutor que será chamado todo final de função, ou final do programa, ou quando o delete for chamado e é responsável por limpar os objetos criados.
};
#endif 
