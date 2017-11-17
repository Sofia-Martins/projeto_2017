/*
 * ciencia.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */


#ifndef CODE_SRC_CIENCIA_H_
#define CODE_SRC_CIENCIA_H_

/////////////////////////////
#include "areaCientifica.h"
#include <iostream>
#include <algorithm>  
/////////////////////////////


class Ciencia
{

private:
	std::string nomeCiencia;
	std::vector<AreaCientifica*> areas;
public:
	//construtor
	Ciencia(){nomeCiencia = "";};
	Ciencia(std::string nomeCiencia);

	//metodos set
	void setNomeCiencia(std::string nomeCiencia);

	//metodos get
	std::string getNomeCiencia() const;
	std::vector<AreaCientifica*> getAreas() const{return areas;};

	//outros metodos
	void addAreaCientifica(AreaCientifica* area);
	void show(unsigned int i) const;

	//friends
	friend class Associacao;
};

//excecoes

class AreaCientificaRepetida
{


private:
	AreaCientifica* area;
public:
	AreaCientificaRepetida(AreaCientifica* area);
};



#endif /* CODE_SRC_CIENCIA_H_ */
