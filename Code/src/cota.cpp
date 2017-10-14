/*
 * cota.cpp
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */
#include "cota.h"

//construtor
	Cota::Cota(bool emDia,unsigned int atraso)
	{
		this->emDia=emDia;
		this->atraso=atraso;
	}

//métodos set
	void Cota::setEmDia(bool emDia)
	{
		this->emDia=emDia;
	}
	void Cota::setAtraso(unsigned int atraso)
	{
		this->atraso=atraso;
	}

//métodos get
	bool Cota::getEmDia() const
	{
		return emDia;
	}
	unsigned int Cota::getAtraso() const
	{
		return atraso;
	}




