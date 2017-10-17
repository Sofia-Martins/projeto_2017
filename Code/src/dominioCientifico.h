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
	// metodos de adicao de Ciencias/AreasCientificas/SubAreasCientificas
	void addCiencia(Ciencia* &ciencia);
	void addAreaCientifica(const AreaCientifica* &area);  //FAZER!!!!
	void addSubAreaCientifica(const SubAreaCientifica* &subArea); //FAZER!!!
};

//outras funcoes
bool cienciasIguais(const Ciencia* &ciencia1,const Ciencia* &ciencia2)
{
	return (ciencia1->getNomeCiencia()==ciencia2->getNomeCiencia());
}


//excecoes

class CienciaRepetida
{
private:
	Ciencia* ciencia;
public:
	CienciaRepetida(Ciencia* ciencia);
};


#endif /* CODE_SRC_DOMINIOCIENTIFICO_H_ */
