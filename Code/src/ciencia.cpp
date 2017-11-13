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
	auto inicio=areas.begin();
	auto fim=areas.end();
	
	for (; inicio != fim; inicio++)
	{
		if (areasIguais(*inicio, area))
			throw AreaCientificaRepetida(area);
	}

	this->areas.push_back(area);

}
void Ciencia::show() const
{
	std::cout << "Ciencia: " << this->nomeCiencia << std::endl;

	for (unsigned int i = 0; i < areas.size(); i++)
	{
		areas.at(i)->show();
	}
}
//excecoes
AreaCientificaRepetida::AreaCientificaRepetida(AreaCientifica* area)
{
	this->area=area;
}
