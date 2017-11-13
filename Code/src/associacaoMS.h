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
#include <functional>
#include <cstdlib>
//#include <unistd.h>  //funcao sleep() em linux
#include <stdlib.h>
#include <stdio.h>
#include <climits>
#include <utility>  //std::pair
#include <algorithm>
#include "associacao.h"
#include "associado.h"
#include "areaCientifica.h"
#include "dominioCientifico.h"
#include "subAreaCientifica.h"


class AssociacaoMS {
private:
	Associacao* associacao;
	std::string ficheiroAssociacoes;
	std::string ficheiroAssociados;
	std::string ficheiroConferencias;
	std::string ficheiroDominios;
	std::string ficheiroEmails;
	std::string ficheiroEscolasVerao;
	std::string ficheiroGestores;
	std::vector<std::pair<std::string, std::string > > associacoes; //siglas e nomes das associacoes (sigla,nome)

public:

	//menu 1
	void menuBemVindo();
	void menuBemVindoSelecao();

	//menu 2.1
	void menuAbrirFicheiroAssociacoes(std::string & nomeFicheiroAssociacoes);
	void menuCriaAssociacao();
	void enviarNovaAssociacaoFicheiro(std::string & nomeFicheiroAssociacoes);
	void criaGestor (std::string siglaAssociacao,bool criaAssociacao, int idMenu);
	void criaFicheirosNovaAssociacao(std::string siglaAssociacao);
	void enviarNovoGestorFicheiro(std::string & nomeFicheiroGestores);

	//menu 2.2
	void menuFicheiroAssociacoes();
	void menuFicheiroAssociacoesSelecao();
	void lerAssociacoes();

	//menu 3
	void menuAssociacoes();
	void lerDominios();
	void lerAssociados();
	void lerEmails();
	void lerConferencias();
	void lerEscolasVerao();
	void lerGestores();

	//menu 4
	void menuLogin();
	void getID(unsigned int id, std::string pass);
	void criaConta();

	//menu 5
	void menuSessaoGestor(unsigned int id);

	void menuSessaoAssociado(unsigned int id);
	void menuSessaoContributor(Associado* associado);
	void menuSessaoSubscriber(Associado* associado);
	void menuSessaoOther(Associado* associado);  //menu do associado que não é nem um contributor nem um subscriber

	void alteraAssociado();

	//menu final
	void menuTermino();




};



#endif /* ASSOCIACAOMS_H_ */
