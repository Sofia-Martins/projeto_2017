/*
 * dominioCientifico.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_DOMINIOCIENTIFICO_H_
#define CODE_SRC_DOMINIOCIENTIFICO_H_

/////////////////////////
#include <map>
#include <iostream>
#include <algorithm>             // std::binary_search
#include "ciencia.h"
////////////////////////

class DominioCientifico
{

private:
	std::vector<Ciencia*> ciencias;

public:
	DominioCientifico(){ciencias = {};}
	// metodos de adicao de Ciencias
	void addCiencia(Ciencia* ciencia);

	//metodos get
	std::vector<Ciencia*> getCiencia() const;

	//metodos set
	void setCiencia(std::vector<Ciencia*> ciencias) {this->ciencias = ciencias;}

	//outros metodos
	void show() const;

	//friends
	friend class Associacao;
};


//excecoes

class CienciaRepetida
{
private:
	Ciencia* ciencia;
public:
	CienciaRepetida(Ciencia* ciencia);
};


#endif /* CODE_SRC_DOMINIOCIENTIFICO_H_ */
