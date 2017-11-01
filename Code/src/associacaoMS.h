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
#include <cstdlib>
//#include <unistd.h>  //funcao sleep() em linux
#include <stdlib.h>
#include <stdio.h>
#include <climits>
#include <utility>  //std::pair
#include "associacao.h"
#include "associado.h"
#include "areaCientifica.h"
#include "dominioCientifico.h"
#include "subAreaCientifica.h"


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
	std::vector<std::pair<std::string,std::string > > associacoes; //siglas e nomes das associacoes (sigla,nome)

public:

	//menu 1
	void menuBemVindo();
	void menuBemVindoSelecao();

	//menu 2
	void menuFicheiroAssociacoes();
	void menuFicheiroAssociacoesSelecao();
	void lerAssociacoes(std::string ficheiroAssociacoes);

	//menu 3
	void menuAssociacoes();
	void lerDominios();
	void lerAssociados();
	void lerEmails();
	void lerConferencias();
	void lerEscolasVerao();

	//menu 4
	void menuLogin(Associacao &ac1);


	//menu final
	void menuTermino();




};



#endif /* ASSOCIACAOMS_H_ */
