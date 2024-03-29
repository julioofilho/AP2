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
#include "moto.h"
#include "caminhao.h"

using namespace std;
using std::string;
using std::getline;




concessionaria gerenciar::criarconcessionaria(){
	string nome;
	string primeiroN;
	string sobrenome;
	string cnpj;
	int pessoa;
	vector<automovel*> listaCarro;
	vector<moto*> listaMoto;
	vector<caminhao*> listaCam;
	
	cout << "Informe o nome da concessionaria: ";
	cin.ignore(200,'\n');
	getline(cin,nome);
	
	cout << "Se for:\n Pessoa fisica -> 1\n Pessoa Juridica -> 2\n ";
	cin >> pessoa;
	if(pessoa  == 1){
		cout << endl<< "Digite o nome do proprietario: \n ";
		cin >> primeiroN;
		cout << endl<< "Digite o sobrenome do proprietario: \n";
		cin >> sobrenome;
		cnpj = "";
	}
	else if (pessoa == 2){
		cout << endl<< "Digite o CNPJ da concessionaria: \n";
		cin >> cnpj;
		sobrenome = "";
		primeiroN ="";	
	}

	cout << "Nome: " << primeiroN << endl;
	cout << "Sobrenome: " << sobrenome << endl;
	concessionaria *Conc = new concessionaria(nome,primeiroN,sobrenome,cnpj,listaCarro,listaMoto,listaCam);
	statusConc status = inexistente;

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome() == nome){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				status = existe;
			}
		}

	if (status == inexistente){
			listaLoja.push_back(Conc);
			cout<< endl << "Concessionaria Inaugurada."<< endl;
	}

	return *Conc;

}

concessionaria gerenciar::criarconcessionariaCSV(){
	concessionaria var;
	double preco1;
	int motor1,modelo1,carga1;
	string arq,nomeconcA,primeiroA,sobrenomeA,cnpjA,marcaA,precoA,chassiA,motorA,modeloA,cargaA; 
	string nomeconc_,primeiroAux, sobrenomeAux,cnpjAux;	
	vector<automovel*> listaCarro;
	vector<moto*> listaMoto;
	vector<caminhao*> listaCam;
	
	cout << "Digite o nome do arquivo: ";
	cin>>arq;
	
	ifstream arquivoE;
	
	arquivoE.open(arq+".csv");	
	
	if(arquivoE.is_open()){		
		while(arquivoE.good()){
			getline	(arquivoE,nomeconcA,'/');
			getline	(arquivoE,primeiroA,'/');
			getline	(arquivoE,sobrenomeA,'/');
			getline	(arquivoE,cnpjA,'/');
			getline	(arquivoE,marcaA,'/');
			getline	(arquivoE,precoA,'/');
			getline	(arquivoE,chassiA,'/');
			getline	(arquivoE,motorA,'/');
			getline	(arquivoE,modeloA,'/');
			getline	(arquivoE,cargaA,'/');
	
			
			
			if (cnpjA != "" && cnpjA != "CNPJ"){
				nomeconc_= nomeconcA;
				cnpjAux = cnpjA;
				primeiroAux = "";
				sobrenomeAux = "";
				break;		
			}
			else if(primeiroA != "" && primeiroA != "NOME" ){
				cnpjAux = "";
				nomeconc_= nomeconcA;
				primeiroAux = primeiroA;
				sobrenomeAux = sobrenomeA;
				break;		
			}
		}
		for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome()== nomeconc_){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				return **it;
				arquivoE.close();
			}
		}
		if(arquivoE.is_open()){
	
		concessionaria *Conc = new concessionaria(nomeconc_,primeiroAux,sobrenomeAux,cnpjAux,listaCarro,listaMoto,listaCam);
		listaLoja.push_back(Conc);		
	 	
	 	while(arquivoE.good()){
			getline	(arquivoE,nomeconcA,'/');
			getline	(arquivoE,primeiroA,'/');
			getline	(arquivoE,sobrenomeA,'/');
			getline	(arquivoE,cnpjA,'/');
			getline	(arquivoE,marcaA,'/');
			getline	(arquivoE,precoA,'/');
			getline	(arquivoE,chassiA,'/');
			getline	(arquivoE,motorA,'/');
			getline	(arquivoE,modeloA,'/');
			getline	(arquivoE,cargaA,'/');
			
			
			if (cnpjA != "" && cnpjA != "CNPJ" && primeiroA != "" && primeiroA != "NOME" ){			
					concessionaria *Conc = new concessionaria(nomeconc_,primeiroAux,sobrenomeAux,cnpjAux,listaCarro,listaMoto,listaCam);
					var = *Conc;
					listaLoja.push_back(Conc);				
				}
			else{
				if (motorA != "" and motorA != "MOTOR"){
				motor1 = stoi(string (motorA));	
				preco1 = stod(string (precoA));	
				Conc->add_automovel(marcaA, preco1, chassiA,motor1);	
							
				}
				else if (modeloA != "" and modeloA != "MODELO"){
					modelo1 = stoi(string (modeloA));	
					preco1 = stod(string (precoA));	
					Conc->add_moto(marcaA,preco1,chassiA,modelo1);				
				}
				else if (cargaA != "" and cargaA != "CARGA"){
					carga1 = stoi(string (cargaA));	
					preco1 = stod(string (precoA));	
					Conc->add_caminhao(marcaA,preco1, chassiA,carga1);				
				}
			}	
		}
		cout << endl << "Concessionaria cadastrado." << endl;
		return *Conc;
		arquivoE.close();
		}	
	}	
	else{
		cout << "Erro ao abrir arquivo. Verifique se o nome esta correto. "<< endl;	
	}

	return var;
	
}


void gerenciar::salvarConcessionaria(){
	cout << endl << "Deseja salvar qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}
	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	statusConc status = inexistente;
		
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			status = existe;
			ofstream arquivo;
			arquivo.open(nome+".csv");
			arquivo << "NOME CONC;NOME;SOBRENOME;CNPJ;MARCA;PRECO;CHASSI;MOTOR;MODELO;CARGA"<< endl;
			
			string cnpjAux = (**it).get_cnpj();
			if ( cnpjAux == ""){	
				arquivo << nome <<"--"<< (**it).get_primeiro_nome() <<"--" << (**it).get_sobrenome();
			}
			else{
				arquivo << nome <<"--"<< cnpjAux;
			}
			for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
				if ((**it).get_nome() == nome){
				
				arquivo << (**it);
				}
			}
			cout << endl << "Concessionaria " << nome << " salva com sucesso."<< endl;
			
		} 
	}
}



void gerenciar::cadastrarCarro(){

	cout << endl << "Deseja cadastrar o carro em qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;


	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	statusConc status = inexistente;

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			status = existe;
			if ((**it).add_carro()){
				status = carroCadastrado;
			} 
		}
	}
	if (status == inexistente){
		cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	} 
	else if (status == carroCadastrado){
		cout << endl << "Veiculo cadastrado." << endl;
	} 
	else{
		cout << endl << "Veiculo ja cadastrado." << endl;
	}
	return;
}

bool gerenciar::estoques(){

	cout << endl << "Estoque de qual concessionaria quer acessar? " << endl << "Concessionarias:" << endl << endl;
			  
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);

	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			cout << endl << " O estoque da " << nome << " possui: "<< endl;
			cout << (**it);
			return true;
		}
	}
	cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	return false;
}
bool gerenciar::listarConcessionarias(){
	cout << endl << "Estoque de qual concessionaria quer acessar? " << endl << "Concessionarias:" << endl << endl;
			  
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}
	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			cout << endl << " Concessionaria " << nome << endl<< endl;
			if((**it).get_cnpj()==""){
				cout << " Proprietario " << (**it).get_primeiro_nome() << " " << (**it).get_sobrenome() << endl;	
			}
			else{
				cout << endl << " CNJP " << (**it).get_cnpj() << endl;
			}
			cout << " Total de Carros: " << (**it).getSizelistaCarro() << endl;
			cout << " Total de Motos: " << (**it).getSizelistaMoto() << endl;
			cout << " Total de Caminhoes: " << (**it).getSizelistaCam() << endl;
			cout << " Total de Veiculos: " << (**it).getSizelistaCarro()+ (**it).getSizelistaMoto() + (**it).getSizelistaCam() << endl;
			return true;
		}
	}
	cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	return false;	
}
