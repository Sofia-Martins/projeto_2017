/*
 * subAreaCientifica.cpp
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

//////////////////////////////////////
#include "subAreaCientifica.h"
//////////////////////////////////////

//construtor
SubAreaCientifica::SubAreaCientifica(std::string nomeSubArea,std::string siglaSubArea)
{
	this->nomeSubArea=nomeSubArea;
	this->siglaSubArea=siglaSubArea;
}

//metodos set
void SubAreaCientifica::setNomeSubAreaCientifica(std::string nomeSubArea)
{
	this->nomeSubArea=nomeSubArea;
}
void SubAreaCientifica::setSiglaSubAreaCientifica(std::string siglaSubArea)
{
	this->siglaSubArea=siglaSubArea;
}

//metodos get
std::string SubAreaCientifica::getNomeSubAreaCientifica() const
{
	return this->nomeSubArea;
}
std::string SubAreaCientifica::getSiglaSubAreaCientifica() const
{
	return this->siglaSubArea;
}


