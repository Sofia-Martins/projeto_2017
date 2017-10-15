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


