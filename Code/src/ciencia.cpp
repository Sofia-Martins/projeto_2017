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
