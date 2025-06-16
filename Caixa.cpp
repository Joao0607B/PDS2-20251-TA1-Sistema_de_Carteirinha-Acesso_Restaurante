#include "Caixa.hpp"
#include <ctime>
#include <fstream>
#include <sstream>

static float preco;
map<string, map<int, int>> Caixa::refeicoesClientes;
string bancoDeDados = "banco_de_dados";
Caixa::Caixa(string nome, int cpf, string usuario, string senha): Funcionario(nome), Funcionario(cpf), _usuario(usuario), _senha(senha){};

void Caixa::setUsuario(string usuario){this->_usuario = usuario;}
void Caixa::setSenha(string senha){this->_senha = senha;}
void Caixa::setRU(string RU){this->_RU = RU;}
void Caixa::setCaixa(int caixa){this->_caixa = caixa;}

string Caixa::getUsuario(){return this -> _usuario;}
string Caixa::getSenha(){return this-> _senha;}
string Caixa::getRU(){return this-> _RU;}
int Caixa::getCaixa(){return this-> _caixa;}

void Caixa::criarCadastro(string nome, int cpf, string usuario, string senha){//estou subscrevendo o método Pessoa/Funcinário
    Funcionario::criaCadastro(nome, cpf);
    setUsuario(usuario);
    setSenha(senha);
}
void Caixa:: printInfo(){//estou reutilizando de Funcionário/Pessoa
    Funcionario::printInfo();
    cout<<"Usuário: "<<getUsuario()<<endl;
}
bool Caixa::fazerLogin(string& usuarioDigitado, string& senhaDigitada){
    return(usuarioDigitado == getUsuario() && senhaDigitada == getSenha());
}
void Caixa::trocarSenha(string& novaSenha){
    setSenha(novaSenha);
}
//cada aluno quando vai fazer o cadastro vai colocar seu nível e acessamos o nível pela matrícula?
//esse método é necessário?
float Caixa::acessarValor(Cliente cliente){
    float nivel = cliente.getNivel();//Cliente precisa de um getNivel

    if(nivel == 1){
        preco = 0;
    }   
    else if(nivel == 2){
        preco = 1;
    }
    else if(nivel == 3){
        preco = 1;
    }
    else if(nivel == 4){
        preco = 2;
    }
    else{
        preco = 5.60;
    }
    return preco;
}
bool Caixa::acessoCliente(Cliente cliente, float& valorPago, const string& tipoRefeicao){
    int cpf = cliente.getCpf(); //o getCpf tem que ser herdado de cliente, que foi herdado de pessoa
    float tarifa = acessarValor(cliente);
    string data = getDataAtual();
    string chave = data + "_" + tipoRefeicao;

    if (refeicoesClientes[chave].count(cpf)) {
        cout << "Acesso negado: o cliente " << cliente.getNome() << " já entrou hoje.\n";//getnome tmb terá que ser herdado
        return false;
    }
    if (valorPago < tarifa) {
        cout << "Acesso negado: valor insuficiente. Tarifa: R$" << tarifa << ", pago: R$" << valorPago << "\n";
        return false;
    }
    int nivel = cliente.getNivel();
    refeicoesClientes[chave][cpf] = nivel; 
    cout << "Acesso liberado para " << cliente.getNome()<<endl;
    armazenarRefeicoesporDia();
    return true;
}
void Caixa::resetarEntradas() { 
    string data = getDataAtual();
    for (auto it = refeicoesClientes.begin(); it != refeicoesClientes.end(); ) {
        if (it->first.find(data) == 0) {
            it = refeicoesClientes.erase(it);
        } else {
            ++it;
        }
    }
    armazenarRefeicoesporDia();//para usar depois de cada refeição
}
void Caixa::selecionarRU(string RU, int caixa){
    setRU(RU);
    setCaixa(caixa);
}
string Caixa::getDataAtual() const {//para pegar a data para colocar no banco de dados
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buf[11];
    strftime(buf, sizeof(buf), "%Y-%m-%d", now);
    return std::string(buf);
}
void Caixa::armazenarRefeicoesporDia() const {
    ofstream arquivo(bancoDeDados, ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de banco de dados.\n";
        return;
    }
    map<string, int> totalPorDia;// para mapear o total(almoco e janta)

    for (const auto& par : refeicoesClientes) {
    const string& chave = par.first;        // exemplo: "2025-06-15_almoco"
    size_t pos = chave.find('_');           // encontra o '_' entre a data e o tipoRefeicao
    string data = chave.substr(0, pos);     // extrai só a data: "2025-06-15"
    int total = par.second.size();          // quantos clientes únicos comeram nessa refeição
    totalPorDia[data] += total;             // soma almoço e janta no mesmo dia
    }
    arquivo << "=== Total de refeições por dia ===\n";
    for (const auto& dia : totalPorDia) {
        arquivo << dia.first << ":total=" << dia.second << "\n";
    }
    arquivo << "==================================\n\n";
    arquivo.close();
}
void Caixa::armazenarRefeicoesServidasMes(const string& bancoDeDados) const {
    map<std::string, int> totalPorMes;

        for (const auto& par : refeicoesClientes) {
        const string& chave = par.first; 
        size_t posData = chave.find('_');
        string data = chave.substr(0, posData); 
        string mes = data.substr(0, 7);         

        int total = par.second.size(); 
        totalPorMes[mes] += total;
    }

    ofstream arquivo(bancoDeDados, ios::app); // abre em modo append
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << bancoDeDados << endl;
        return;
    }

    arquivo << "=== Total de refeições por mês ===\n";
    for (const auto& mes : totalPorMes) {
        arquivo << mes.first << ":" << mes.second << "\n";
    }

    arquivo << "==================================\n\n";
    arquivo.close();
}
void Caixa::armazenarRefeicoesServidasNivel(const string& bancoDeDados) const{
    map<string, map<int, int>> totalPorMesPorNivel;

    for (const auto& par : refeicoesClientes) {
        const string& chave = par.first;              
        size_t pos = chave.find('_');
        string data = chave.substr(0, pos);           
        string mes = data.substr(0, 7);                

        const map<int, int>& mapaCpfNivel = par.second;
        for (const auto& cliente : mapaCpfNivel) {
            int nivel = cliente.second;
            totalPorMesPorNivel[mes][nivel]++;
        }
    }

    ofstream arquivo(bancoDeDados, ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << bancoDeDados << "\n";
        return;
    }

    arquivo << "=== Total por mês por nível ===\n";
    for (const auto& mes : totalPorMesPorNivel) {
        const string& nomeMes = mes.first;
        for (const auto& nivel : mes.second) {
            arquivo << nomeMes << ":nivel_" << nivel.first << ":" << nivel.second << "\n";
        }
    }
    arquivo << "================================\n\n";
    arquivo.close();
}
void Caixa::armazenarSaldoTotalDia(const string& bancoDeDados) const{
    map<string, float> saldoPorDia;

    for (const auto& par : refeicoesClientes) {
        const string& chave = par.first;             
        size_t pos = chave.find('_');
        string data = chave.substr(0, pos);         

        const auto& mapaCpfNivel = par.second;
        for (const auto& entrada : mapaCpfNivel) {
            int nivel = entrada.second;

            Cliente clienteTemporario;
            clienteTemporario.setNivel(nivel);            

            float valor = acessarValor(clienteTemporario);
            saldoPorDia[data] += valor;
        }
    }

    ofstream arquivo(bancoDeDados, ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << bancoDeDados << "\n";
        return;
    }

    arquivo << "=== Saldo total por dia ===\n";
    for (const auto& dia : saldoPorDia) {
        arquivo << dia.first << ";" << dia.second << "\n";
    }
    arquivo << "===========================\n\n";
    arquivo.close();
}
void Caixa::armazenarSaldoTotalMes(const string& bancoDeDados) const{
    map<string, float> saldoPorMes;

    
    for (const auto& par : refeicoesClientes) {
        const string& chave = par.first;             
        size_t pos = chave.find('_');
        string data = chave.substr(0, pos);         
        string mes = data.substr(0, 7);              

        const auto& mapaCpfNivel = par.second;
        for (const auto& entrada : mapaCpfNivel) {
            int nivel = entrada.second;

            Cliente clienteTemporario;
            clienteTemporario.setNivel(nivel);

            float valor = acessarValor(clienteTemporario);
            saldoPorMes[mes] += valor;
        }
    }

    ofstream arquivo(bancoDeDados, ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << bancoDeDados<< "\n";
        return;
    }

    arquivo << "=== Saldo total por mês ===\n";
    for (const auto& mes : saldoPorMes) {
        arquivo << mes.first << ";" << mes.second << "\n";
    }
    arquivo << "===========================\n\n";
    arquivo.close();
}
