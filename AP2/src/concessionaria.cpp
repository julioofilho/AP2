#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "concessionaria.h"

#include "carro.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;

concessionaria::concessionaria(){
	nome = "";
	cnpj = "";
}

concessionaria::concessionaria(string nome_, string primeiro_nome_,string sobrenome_, string cnpj_, const vector<automovel*>listaCarro, const vector<moto*>listaMoto,const vector<caminhao*>listaCam){
	nome = nome_;
	primeiro_nome = primeiro_nome_;
	sobrenome = sobrenome_;
	cnpj = cnpj_;
	listaConcCarro = listaCarro;
	listaConcMoto = listaMoto;
	listaConcCam = listaCam;
	++(++numeroConc);
}

concessionaria::concessionaria(string nome_, string cnpj_, const vector<automovel*>listaCarro, const vector<moto*>listaMoto,const vector<caminhao*>listaCam){
	nome = nome_;
	cnpj = cnpj_;
	listaConcCarro = listaCarro;
	listaConcMoto = listaMoto;
	listaConcCam = listaCam;
	++(++numeroConc);
}


int concessionaria::getSizelistaCarro(){
	return listaConcCarro.size();	
}
int concessionaria::getSizelistaMoto(){
	return listaConcMoto.size();	
}
int concessionaria::getSizelistaCam(){
	return listaConcCam.size();	
}
	

string concessionaria::get_nome(){
	return nome; 
}
string concessionaria::get_primeiro_nome(){
	return primeiro_nome; 
}
string concessionaria::get_sobrenome(){
	return sobrenome; 
}
string concessionaria::get_cnpj(){
	return cnpj; 
}

bool concessionaria::add_automovel(string marca, double preco, string chassi,int motor){
		automovel *autom = new automovel(marca, preco, chassi,motor);		
		listaConcCarro.push_back(autom);
		return true;
}
bool concessionaria::add_moto(string marca, double preco, string chassi,int modelo){	
		moto *autom = new moto(marca, preco, chassi,modelo);
		listaConcMoto.push_back(autom);
		return true;	
}
bool concessionaria::add_caminhao(string marca, double preco, string chassi,int carga){		
		caminhao *autom = new caminhao(marca, preco, chassi,carga);
		listaConcCam.push_back(autom);
		return true;
}


bool concessionaria::add_carro(){
	string chassi;
	string marca;
	double preco;
	int motor;
	int carga;
	int modelo;
	int escolha;
	cout << endl << "-> informe o tipo de Veiculo:";
	cout << endl << "-> Carro -> 1";
	cout << endl << "-> Moto -> 2";
	cout << endl << "-> Caminhao -> 3"<< endl;
	cin >> escolha;
	
	
	
	if (escolha == 1){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Tipo do motor:\n(1 para gasolina, 2 para eletrico): "<< endl;	
		cin >> motor;
		
		automovel *autom = new automovel(marca, preco, chassi,motor);
		
		
		
		listaConcCarro.push_back(autom);
		
	
	}
	if (escolha == 2){
		cout << endl << "-> Digite os dados da Moto";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Modelo (1-esportivo 2-comum): "<< endl;	
		cin >> modelo;
		
		moto *autom = new moto(marca, preco, chassi,modelo);
		

		listaConcMoto.push_back(autom);
	}
	if (escolha == 3){
		cout << endl << "-> Digite os dados do Caminhao";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Tipo da carga(1-Normal 2-Perigosa): "<< endl;	
		cin >> carga;
		
		caminhao *autom = new caminhao(marca, preco, chassi,carga);
	
		listaConcCam.push_back(autom);
	}
	else if(escolha != 1 && escolha !=2 && escolha != 3){
		cout << endl << "Opcao invalida.\n\n";
		
	}
	return true;
}

   ostream& operator<<(ostream &o, concessionaria &concessionaria){
	for (vector<automovel*>::iterator i = concessionaria.listaConcCarro.begin(); i != concessionaria.listaConcCarro.end(); ++i)
	{
		o << (**i) << endl;
	}
	for (vector<moto*>::iterator i = concessionaria.listaConcMoto.begin(); i != concessionaria.listaConcMoto.end(); ++i)
	{
		o << (**i) << endl;
	}
	for (vector<caminhao*>::iterator i = concessionaria.listaConcCam.begin(); i != concessionaria.listaConcCam.end(); ++i)
	{
		o << (**i) << endl;
	}
	return o;
}
ofstream& operator<<(ofstream &of, concessionaria &concessionaria){
	for (vector<automovel*>::iterator i = concessionaria.listaConcCarro.begin(); i != concessionaria.listaConcCarro.end(); ++i)
	{
		of << (**i);
	}
	for (vector<moto*>::iterator i = concessionaria.listaConcMoto.begin(); i != concessionaria.listaConcMoto.end(); ++i)
	{
		of << (**i);
	}
	for (vector<caminhao*>::iterator i = concessionaria.listaConcCam.begin(); i != concessionaria.listaConcCam.end(); ++i)
	{
		of << (**i);
	}
	
	return of;
}



bool concessionaria::operator==(const concessionaria &conc) const{
	if (this->nome == conc.nome){
		return true;
	} else {
		return false;
	}
}











