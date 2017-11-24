/*
 * dominioCientifico.cpp
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

/////////////////////////////////
#include "dominioCientifico.h"
////////////////////////////////

//funcoes auxiliares
bool cienciasIguais(const Ciencia* ciencia1,const Ciencia* ciencia2)
{
	return (ciencia1->getNomeCiencia()==ciencia2->getNomeCiencia());
}

// metodos de adicao de Ciencias/AreasCientificas/SubAreasCientificas
void DominioCientifico::addCiencia(Ciencia* ciencia)
{

	std::vector<Ciencia*>::const_iterator inicio=ciencias.begin(); //apontador para a primeira ciencia
	std::vector<Ciencia*>::const_iterator fim=ciencias.end(); //apontador para o final do vector ciencias
	bool existeCiencia = false;

	for (unsigned int i = 0; i < ciencias.size(); i++)
	{
		if (ciencias.at(i)->getNomeCiencia() == ciencia->getNomeCiencia())
			existeCiencia = true;
	}
	if(existeCiencia)
		throw  CienciaRepetida(ciencia);
	else
	{
		ciencias.push_back(ciencia);
	}

}

//metodos get
std::vector<Ciencia*> DominioCientifico::getCiencia() const{
	return ciencias;
}

//outros metodos
void DominioCientifico::show() const
{
	for (unsigned int i = 0; i < ciencias.size(); i++)
	{
		std::cout << "|" << i + 1 << "| " << ciencias.at(i)->getNomeCiencia() << "\n";
		ciencias.at(i)->show(i);
	}
}

void DominioCientifico::sortCiencias()
{
	for (int i = 0; i < ciencias.size(); i++)
	{
		ciencias.at(i)->sortAreas();
	}

	sort(ciencias.begin(), ciencias.end(), comparaCiencias);
}
//excecoes
CienciaRepetida::CienciaRepetida(Ciencia* ciencia)
{
	this->ciencia=ciencia;
}

bool comparaCiencias(const Ciencia* c1, const Ciencia* c2)
{
	return (c1->getNomeCiencia() < c2->getNomeCiencia());
}