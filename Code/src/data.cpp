/*
 * data.cpp
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */


#include "data.h"

//Construtor
Data::Data(){
	this->dia = 0;
	this->mes = 0;
	this->ano = 0;
	this->hora = 0;
	this->minuto = 0;
}

Data::Data(unsigned int dia, unsigned int mes, int ano, unsigned int hora, unsigned int minuto)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->hora = hora;
	this->minuto = minuto;
}

//Metodos Set

void Data::setDia (unsigned int dia)
{
	this->dia = dia;
}

void Data::setMes (unsigned int mes)
{
	this->mes = mes;
}

void Data::setAno (int ano)
{
	this->ano = ano;
}

void Data::setHora (unsigned int hora)
{
	this->hora = hora;
}

void Data::setMinuto (unsigned int minuto)
{
	this->minuto = minuto;
}

//Metodos Get

unsigned int Data::getDia () const
{
	return dia;
}

unsigned int Data::getMes () const
{
	return mes;
}

unsigned int Data::getAno () const
{
	return ano;
}

unsigned int Data::getHora () const
{
	return hora;
}

unsigned int Data::getMinuto () const
{
	return minuto;
}



std::string Data::getData() const
{
	using namespace std;
	string stringDia=to_string((unsigned long)dia);
	string stringMes=to_string((unsigned long)mes);
	string stringAno=to_string((unsigned long)ano);
	string stringHora=to_string((unsigned long)hora);
	string stringMinuto=to_string((unsigned long)minuto);

	string s = stringDia + "/" + stringMes+"/"+stringAno+" "+stringHora+":"+stringMinuto;
	return s;
}




