/*
 * areaCientifica.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_AREACIENTIFICA_H_
#define CODE_SRC_AREACIENTIFICA_H_

////////////////////////
#include <vector>
#include <iostream>
#include <algorithm>             // std::binary_search
#include "subAreaCientifica.h"
////////////////////////

class AreaCientifica
{
private:
	std::string nomeArea;
	std::vector<SubAreaCientifica*> subAreas;

public:
	//construtor
	AreaCientifica(){nomeArea = {};}; //construtor por defeito
	AreaCientifica(std::string nomeArea); //construtor sem sigla


	//metodos set
	void setNomeAreaCientifica(std::string nomeArea);

	//metodos get
	std::string getNomeAreaCientifica() const;
	std::vector<SubAreaCientifica*> getsubAreas() const {return subAreas;};


	//outros metodos
	void addSubAreaCientifica(SubAreaCientifica* subArea);
	void show(unsigned int i, unsigned int j) const;

	//friends
	friend class Associacao;

};

//excecoes

class SubAreaCientificaRepetida
{
private:
	SubAreaCientifica* subArea;
public:
	SubAreaCientificaRepetida(SubAreaCientifica* subArea);
};




#endif
