#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef CAMINHAO_H
#define CAMINHAO_H



#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "carro.h"

using namespace std;

class caminhao : public veiculo{
	private: 
		int tipo_carga;  
		

	public: 

		caminhao();
		caminhao(string marca, double preco, string chassi, int tipo_carga_);	
		caminhao(string marca, double preco, string chassi, int tipo_carga_,string data_);
		
		~caminhao();
		int getTipo_carga();
		void setTipo_carga(int tipo_carga_);

		friend ostream& operator << (ostream &o, caminhao &veiculo);
		friend ofstream& operator << (ofstream &o, caminhao &veiculo);

		bool operator==(const caminhao &cam) const;
		bool operator==(const string &marca) const;
	
};




#endif // CAMINHAO_H