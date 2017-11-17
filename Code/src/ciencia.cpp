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
void Ciencia::show(unsigned int i) const
{

	for (unsigned int j = 0; j < areas.size(); j++)
	{
		std::cout << "  |" << i + 1 << "." << j + 1 << "| " << areas.at(j)->getNomeAreaCientifica() << "\n";
		areas.at(j)->show(i,j);	
	}
}
//excecoes
AreaCientificaRepetida::AreaCientificaRepetida(AreaCientifica* area)
{
	this->area=area;
}
