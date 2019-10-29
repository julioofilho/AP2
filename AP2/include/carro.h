#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef CARRO_H
#define CARRO_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iterator>
#include <algorithm>



using namespace std;

class veiculo{
	private: 
		string marca; 
		double preco;
		string chassi; 

//Getters e Setters
	public: 	

		string getMarca();	
		double getPreco();		 
		string getChassi();
		
		
		void setMarca(string marca_); 
		void setPreco(double preco_);
		void setChassi(string chassi_);
		

	
};

#endif // CARRO_H