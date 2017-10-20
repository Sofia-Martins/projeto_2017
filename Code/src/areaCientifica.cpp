/*
 * areaCientifica.cpp
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

/////////////
#include "areaCientifica.h"


//construtor
AreaCientifica::AreaCientifica(std::string nomeArea,std::string siglaArea)
{
 this->nomeArea=nomeArea;
 this->siglaArea=siglaArea;
}

//metodos set
void AreaCientifica::setNomeAreaCientifica(std::string nomeArea)
{
	this->nomeArea=nomeArea;
}
void AreaCientifica::setSiglaAreaCientifica(std::string siglaArea)
{
	this->siglaArea=siglaArea;
}

//metodos get
std::string AreaCientifica::getNomeAreaCientifica() const
{
	return this->nomeArea;
}
std::string AreaCientifica::getSiglaAreaCientifica() const
{
	return this->siglaArea;
}

//funcoes auxiliares
bool subAreasIguais( SubAreaCientifica* subArea1,SubAreaCientifica* subArea2)
{
	return(subArea1->getNomeSubAreaCientifica() == subArea2->getNomeSubAreaCientifica());
}

//outros metodos
void AreaCientifica::addSubAreaCientifica(SubAreaCientifica* subArea)
{
	std::vector<SubAreaCientifica*>::const_iterator inicio=subAreas.begin(); //apontador para a primeira ciencia
	std::vector<SubAreaCientifica*>::const_iterator fim=subAreas.end(); //apontador para o final do vector ciencias
	bool existeArea=binary_search(inicio, fim, subArea,subAreasIguais);

		if(existeArea)
			throw  SubAreaCientificaRepetida(subArea);
		else
		{
			subAreas.push_back(subArea);
		}
}

//excecoes
SubAreaCientificaRepetida::SubAreaCientificaRepetida(SubAreaCientifica* subArea)
{
	this->subArea=subArea;

}

