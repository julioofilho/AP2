#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "carro.h"


using namespace std;

class automovel : public veiculo{
	private: 
		int tipo_motor;  
		

//Getters e Setters
	public: 

		automovel();
		automovel(string marca, double preco, string chassi, int tipo_motor);
		automovel(string marca, double preco, string chassi, int tipo_motor,string data_);
		int getTipo_motor();
		void setTipo_motor(int motor_);

		friend ostream& operator << (ostream &o, automovel &veiculo);
		friend ofstream& operator << (ofstream &o, automovel &veiculo);
		
};




#endif // AUTOMOVEL_H
