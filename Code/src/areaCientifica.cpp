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
void AreaCientifica::show(unsigned int i,unsigned int j) const
{

	for (unsigned int k = 0; k < subAreas.size(); k++)
	{
		std::cout << "    |" << i + 1 << "." << j + 1 << "." << k + 1 << "| " << subAreas.at(k)->getNomeSubAreaCientifica() << "\n";
	}
}
//excecoes
SubAreaCientificaRepetida::SubAreaCientificaRepetida(SubAreaCientifica* subArea)
{
	this->subArea=subArea;

}

bool comparaSubAreas(const SubAreaCientifica* s1, const SubAreaCientifica* s2)
{
	return (s1->getNomeSubAreaCientifica() < s2->getNomeSubAreaCientifica());
}

void AreaCientifica::sortSubAreas()
{
	sort(subAreas.begin(), subAreas.end(), comparaSubAreas);
}