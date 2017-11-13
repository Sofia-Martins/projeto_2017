/*
 * areaCientifica.cpp
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

/////////////
#include "areaCientifica.h"
#include <algorithm>


//construtor
AreaCientifica::AreaCientifica(std::string nomeArea){
	this->nomeArea = nomeArea;
}



//metodos set
void AreaCientifica::setNomeAreaCientifica(std::string nomeArea)
{
	this->nomeArea=nomeArea;
}

//metodos get
std::string AreaCientifica::getNomeAreaCientifica() const
{
	return this->nomeArea;
}


//funcoes auxiliares
bool subAreasIguais( SubAreaCientifica* subArea1,SubAreaCientifica* subArea2)
{
	return(subArea1->getNomeSubAreaCientifica() == subArea2->getNomeSubAreaCientifica());
}

//outros metodos
void AreaCientifica::addSubAreaCientifica(SubAreaCientifica* subArea)
{
	auto inicio=subAreas.begin(); 
	auto fim=subAreas.end(); 
	
	for (; inicio != fim; inicio++)
	{
		if(subAreasIguais(*inicio, subArea))
			throw  SubAreaCientificaRepetida(subArea);
	}

	subAreas.push_back(subArea);
}
void AreaCientifica::show() const
{
	std::cout << "AREA CIENTIFICA: " << this->nomeArea << std::endl;

	for (unsigned int i = 0; i < subAreas.size(); i++)
	{
		subAreas.at(i)->show();
	}
}
//excecoes
SubAreaCientificaRepetida::SubAreaCientificaRepetida(SubAreaCientifica* subArea)
{
	this->subArea=subArea;

}
