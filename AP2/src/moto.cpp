#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "moto.h"
#include "carro.h"
#include "concessionaria.h"

using namespace std;

moto::moto(){
	setMarca("");
	setPreco(0);
	setChassi("");
	setModelo(0);
	
}

moto::moto(string marca_, double preco_, string chassi_,int modelo_){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setModelo(modelo_);
	
}
moto::moto(string marca_, double preco_, string chassi_,int modelo_,string){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setModelo(modelo_);
	
}



int moto::getModelo(){
	return modelo;
}

void moto::setModelo(int modelo_){
	modelo = modelo_;
}

ostream& operator<< (ostream &o, moto &veiculo_){
	o << "*********MOTO**********" << endl
	  << "> Marca: " << veiculo_.getMarca() << endl
	  << "> Preco: " << veiculo_.getPreco() << endl
	  << "> Modelo: " << veiculo_.getModelo()<< " (1-esportivo , 2-comum)"<< endl
	  << "> Numero do Chassi: " << veiculo_.getChassi() << endl;
	return o;
}
ofstream& operator<< (ofstream &om, moto &veiculo_){
	om << endl << "--"<< veiculo_.getMarca()<<"--" << veiculo_.getPreco()<<"--"<< veiculo_.getChassi()<<"--" << veiculo_.getModelo();
	return om;
}

