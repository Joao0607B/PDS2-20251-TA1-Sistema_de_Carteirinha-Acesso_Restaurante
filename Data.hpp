#ifndef DATA_H
#define DATA_H

#include "Pessoa.hpp"
#include <string>
#include <vector>
using namespace std;

class Data{
    private:
        int _dia;
        int _mes;
        int _ano;

        bool isAnoBissexto(int a) const {
            return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        }

        //Verifica se uma data é possível. e.g. se o ano é positivo, se o mês é entre 1 e 12, etc.
        bool validarData(int d, int m, int a) const {
            if (a < 1) return false; 
            if (m < 1 || m > 12) return false;

            // Vetor para armazenar o número de _dias em cada mês (ignorando o índice 0)
            vector<int> _diasNoMes = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (isAnoBissexto(a)) {
                _diasNoMes[2] = 29;
            }

            if (d < 1 || d > _diasNoMes[m]) {
                return false; 
            }
            return true;
        }

    public:
        // Construtor
        Data(int d = 5, int m = 10, int a = 2001) {
            if (validarData(d, m, a)) {
                _dia = d;
                _mes = m;
                _ano = a;
            } else {
                std::cout << "Data inserida inválida. Data armazenada: 05/10/2001." << std::endl;
                _dia = 1;
                _mes = 1;
                _ano = 2000;
            }
        }

        //Setters e getters
        void setDia(int d) {
            if (validarData(d, _mes, _ano)) {
                _dia = d;
            } else {
                std::cout << "Dia inválido. Data não alterada." << std::endl;
            }
        }

        void setMes(int m) {
            if (validarData(_dia, m, _ano)) {
                _mes = m;
            } else {
                std::cout << "Mês inválido. Data não alterada." << std::endl;
            }
        }

        void setAno(int a) {
            if (validarData(_dia, _mes, a)) {
                _ano = a;
            } else {
                std::cout << "Ano inválido. Data não alterada." << std::endl;
            }
        }

        int getDia() const {
            return _dia;
        }

        int getMes() const {
            return _mes;
        }

        int getAno() const {
            return _ano;
        }

        string toString(){
            string d, m, a;
            if (_dia<10)
            {
                d.append("0");
                d.append(to_string(_dia));
            }
            if (_mes<10)
            {
                m.append("0");
                m.append(to_string(_mes));
            }
            return d+m+a;
            
        }
};

#endif