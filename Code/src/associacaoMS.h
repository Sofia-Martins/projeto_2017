/*
 * associacaoMS.h
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */

#ifndef ASSOCIACAOMS_H_
#define ASSOCIACAOMS_H_


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>  //std::pair
#include "associacao.h"

class AssociacaoMS{
private:
	Associacao* associacao;
	std::string ficheiroAssociacoes;
	std::string ficheiroAssociados;
	std::string ficheiroConferencias;
	std::string ficheiroDominios;
	std::string ficheiroEmails;
	std::string ficheiroEscolasVerao;
	std::string ficheiroGestores;
	std::vector<std::pair<std::string,std::string>> associacoes; //siglas e nomes das associacoes

public:
	//menus
	void menuFicheiroAssociacoes();


	//inputs nos menus
	void menuFicheiroAssociacoesSelection();

	//ler dos ficheiros
	void lerAssociacoes(std::string ficheiroAssociacoes);


};



#endif /* ASSOCIACAOMS_H_ */
