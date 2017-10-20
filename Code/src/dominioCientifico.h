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
#include <algorithm>             // std::binary_search
#include "ciencia.h"
////////////////////////

class DominioCientifico
{

private:
	std::vector<Ciencia*> ciencias;

public:
	// metodos de adicao de Ciencias
	void addCiencia(Ciencia* ciencia);
	void addSubAreaCientifica(SubAreaCientifica* subArea);
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
