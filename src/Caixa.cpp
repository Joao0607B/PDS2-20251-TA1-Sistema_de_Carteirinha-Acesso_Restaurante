#include "Caixa.hpp"

Caixa::Caixa(string nome, string cpf, string usuario, string senha, string restaurante, int caixa): Funcionario(nome, cpf, usuario, senha), _restaurante(""), _caixa(0){}

void Caixa::setCaixa(int caixa){this->_caixa = caixa;}
void Caixa::setRestaurante(string restaurante){this->_restaurante = restaurante;}
int Caixa::getCaixa(){return this -> _caixa;}
string Caixa::getRestaurante(){return this-> _restaurante;}
