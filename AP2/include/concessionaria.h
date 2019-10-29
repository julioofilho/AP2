#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>


#include "carro.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"


using namespace std;


class concessionaria{

private:
	string nome;
	string primeiro_nome;
	string sobrenome;
	string cnpj;
	vector<automovel*> listaConcCarro;
	vector<moto*> listaConcMoto;
	vector<caminhao*> listaConcCam;

public:
	static int numeroConc;

	concessionaria();

	concessionaria(string nome_,string cnpj_, const vector<automovel*>listaCarro,const vector<moto*>listaMoto,const vector<caminhao*>listaCam);
	concessionaria(string nome_, string primeiro_nome_,string sobrenome_,string cnpj_, const vector<automovel*>listaCarro,const vector<moto*>listaMoto,const vector<caminhao*>listaCam);
	
	string get_nome();
	string get_primeiro_nome();
	string get_sobrenome();
	string get_cnpj();
	
	int getSizelistaCarro();
	int getSizelistaMoto();
	int getSizelistaCam();
	

	bool add_carro();
	bool lista_carro();
	bool add_automovel(string marca, double preco, string chassi,int motor);
	bool add_moto(string marca, double preco, string chassi,int modelo);
	bool add_caminhao(string marca, double preco, string chassi,int carga);
	int estoque();
	
	
	bool operator==(concessionaria a){
		return a.get_cnpj() == cnpj;
	}


	friend ostream& operator<< (ostream &o, concessionaria &concessionaria);
	friend ofstream& operator<< (ofstream &o, concessionaria &concessionaria);
	bool operator==(const concessionaria &conc) const;


};

#endif 