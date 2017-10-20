/*
 * ciencia.cpp
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#include "ciencia.h"

//construtor
Ciencia::Ciencia(std::string nomeCiencia)
{
	this->nomeCiencia=nomeCiencia;
}

//metodos set
void Ciencia::setNomeCiencia(std::string nomeCiencia)
{
	this->nomeCiencia=nomeCiencia;
}

//metodos get
std::string Ciencia::getNomeCiencia() const
{
	return this->nomeCiencia;
}

//funcoes auxiliares
bool areasIguais(AreaCientifica* area1,AreaCientifica* area2)
{
	return (area1->getNomeAreaCientifica() == area2->getNomeAreaCientifica());
}

//outros metodos
void Ciencia::addAreaCientifica(AreaCientifica* area)
{
	std::vector<AreaCientifica*>::const_iterator inicio=areas.begin(); //apontador para a primeira ciencia
	std::vector<AreaCientifica*>::const_iterator fim=areas.end(); //apontador para o final do vector ciencias
	bool existeArea=binary_search(inicio, fim, area,areasIguais);

	if(existeArea)
		throw  AreaCientificaRepetida(area);
	else
	{
		areas.push_back(area);
	}

}

//excecoes
AreaCientificaRepetida::AreaCientificaRepetida(AreaCientifica* area)
{
	this->area=area;
}
