#include "../include/Data.hpp"

// Implementação de isAnoBissexto no .cpp
bool Data::isAnoBissexto(int a) const {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

// Implementação de validarData no .cpp
bool Data::validarData(int d, int m, int a) const {
    if (a < 1) return false;
    if (m < 1 || m > 12) return false;

    std::vector<int> diasNoMes = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isAnoBissexto(a)) { // isAnoBissexto precisa ser Data::isAnoBissexto() ou a classe deve estar no escopo
        diasNoMes[2] = 29;
    }

    if (d < 1 || d > diasNoMes[m]) {
        return false;
    }
    return true;
}

// Implementação do NOVO construtor padrão
Data::Data() {
    this->definirDataAtual();
}

// Construtor existente com valores específicos
Data::Data(int d, int m, int a) {
    if (validarData(d, m, a)) {
        _dia = d;
        _mes = m;
        _ano = a;
    } else {
        std::cout << "Data inserida inválida. Data atual armazenada." << std::endl;
        this->definirDataAtual();
    }
}

// ... (restante do código Data.cpp permanece o mesmo) ...

// Setters
void Data::setDia(int d) {
    if (validarData(d, _mes, _ano)) {
        _dia = d;
    } else {
        std::cout << "Dia inválido. Data não alterada." << std::endl;
    }
}

void Data::setMes(int m) {
    if (validarData(_dia, m, _ano)) {
        _mes = m;
    } else {
        std::cout << "Mês inválido. Data não alterada." << std::endl;
    }
}

void Data::setAno(int a) {
    if (validarData(_dia, _mes, a)) {
        _ano = a;
    } else {
        std::cout << "Ano inválido. Data não alterada." << std::endl;
    }
}

// Getters
int Data::getDia() const {
    return _dia;
}

int Data::getMes() const {
    return _mes;
}

int Data::getAno() const {
    return _ano;
}

// Método para formatar a data como string
std::string Data::toString() const {
    std::string s_dia = std::to_string(_dia);
    std::string s_mes = std::to_string(_mes);
    std::string s_ano = std::to_string(_ano);

    if (_dia < 10) {
        s_dia = "0" + s_dia;
    }
    if (_mes < 10) {
        s_mes = "0" + s_mes;
    }

    return s_dia + "/" + s_mes + "/" + s_ano;
}

// Método para definir a data para a data atual do sistema
void Data::definirDataAtual() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

#ifdef _WIN32
    struct tm tm_local;
    localtime_s(&tm_local, &now_c);
    _dia = tm_local.tm_mday;
    _mes = tm_local.tm_mon + 1;
    _ano = tm_local.tm_year + 1900;
#else
    struct tm* tm_local = std::localtime(&now_c);
    _dia = tm_local->tm_mday;
    _mes = tm_local->tm_mon + 1;
    _ano = tm_local->tm_year + 1900;
#endif
}

// Operador de comparação de igualdade
bool Data::operator==(const Data& outraData) const {
    return (_dia == outraData._dia &&
            _mes == outraData._mes &&
            _ano == outraData._ano);
}

// Operador de comparação de diferença
bool Data::operator!=(const Data& outraData) const {
    return !(*this == outraData);
}
