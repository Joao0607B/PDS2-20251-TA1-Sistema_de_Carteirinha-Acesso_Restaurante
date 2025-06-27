#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <iostream>

class Data {
private:
    int _dia;
    int _mes;
    int _ano;

    bool isAnoBissexto(int a) const;
    bool validarData(int d, int m, int a) const;

public:
    Data();
    Data(int d, int m, int a);

    void setDia(int d);
    void setMes(int m);
    void setAno(int a);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    std::string toString() const;
    void definirDataAtual();

    bool operator==(const Data& outraData) const;
    bool operator!=(const Data& outraData) const;
};

#endif
