#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "carro.h"

void veiculo::setMarca(string marca_){
	marca = marca_;
}
void veiculo::setPreco(double preco_){
	preco = preco_;
}
void veiculo::setChassi(string chassi_){
	chassi = chassi_;
}

string veiculo::getMarca(){
	return marca;
}


double veiculo::getPreco(){
	return preco;
}
string veiculo::getChassi(){
	return chassi;
}

