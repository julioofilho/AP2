#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef GERENCIAR_H
#define GERENCIAR_H

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "automovel.h"
#include "concessionaria.h"

enum statusConc{
	inexistente = 0,
	existe = 1,
	carroCadastrado = 2
};

class gerenciar{
	
private: 
	vector <concessionaria*> listaLoja;

public:
	//gerenciar();
	//~gerenciar();
	
	bool listarConcessionarias();
	concessionaria criarconcessionaria();
	concessionaria criarconcessionariaCSV();
	
	void salvarConcessionaria();
	void cadastrarCarro();
	bool estoques();

};

#endif 