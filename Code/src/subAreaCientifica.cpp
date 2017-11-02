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
SubAreaCientifica::SubAreaCientifica(std::string nomeSubArea)
{
	this->nomeSubArea=nomeSubArea;
}

//metodos set
void SubAreaCientifica::setNomeSubAreaCientifica(std::string nomeSubArea)
{
	this->nomeSubArea=nomeSubArea;
}


//metodos get
std::string SubAreaCientifica::getNomeSubAreaCientifica() const
{
	return this->nomeSubArea;
}



