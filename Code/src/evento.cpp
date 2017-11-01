/*
 * evento.cpp
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#include "evento.h"


/////////////////
//Class Evento //
/////////////////

//Construtor

Evento::Evento(std::vector <int> planeadores, std::vector<int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento)
{
	this->planeadores = planeadores;
	this->organizadores = organizadores;
	this->local = local;
	this->tema = tema;
	this->data = data;
	this->apoioEvento = apoioEvento;
}

// Metodos get

std::vector<int> Evento::getPlaneadores () const{
	return this->planeadores;
}

std::vector<int> Evento::getOrganizadores() const{
	return this->organizadores;
}

std::string Evento::getLocal() const{
	return this->local;
}

std::string Evento::getTema() const{
	return this->tema;
}


// Metodos set

void Evento::setLocal(std::string local){
	this->local = local;
}

void Evento::setTema(std::string tema){
	this->tema = tema;
}


// Outros metodos

void Evento::addPlaneador (int planeador){
	planeadores.push_back(planeador);
}

void Evento::addOrganizador (int organizador){
	organizadores.push_back(organizador);
}

void Evento::removePlaneador (int planeador){
	for (unsigned int i=0; i<planeadores.size(); i++)
		if (planeadores.at(i)==planeador)
			planeadores.erase(planeadores.begin()+i);
}

void Evento::removeOrganizador (int organizador){
	for (unsigned int i=0; i<organizadores.size(); i++)
		if (organizadores.at(i)==organizador)
			organizadores.erase(organizadores.begin()+i);
}



//////////////////////////
//Sub-class Conferencia //
//////////////////////////

//Construtor

Conferencia::Conferencia(std::vector<int> planeadores, std::vector<int> organizadores, std::string local,
		std::string tema, Data data, Apoio apoioEvento,
		unsigned int numeroParticipantes) :Evento(planeadores, organizadores,local, tema, data, apoioEvento) {
	this->numeroParticipantes = numeroParticipantes;
}

// Metodos get

unsigned int Conferencia::getNumeroParticipantes() const{
	return this->numeroParticipantes;
}

// Metodos set

void Conferencia::setNumeroParticipantes(unsigned int numeroParticipantes){
	this->numeroParticipantes = numeroParticipantes;
}


//////////////////////////
//Sub-class EscolaVerao //
//////////////////////////

//Construtor

EscolaVerao::EscolaVerao(std::vector<int> planeadores, std::vector<int> organizadores, std::string local,
		std::string tema, Data data, Apoio apoioEvento,
		std::vector<int> formadores) :Evento(planeadores,organizadores, local, tema, data, apoioEvento) {
	this->formadores = formadores;
}

// Metodos get

std::vector<int> EscolaVerao::getFormadores () const{
	return this->formadores;
}

// Outros metodos

void EscolaVerao::addFormador (int formador){
	formadores.push_back(formador);
}

void EscolaVerao::removeFormador (int formador){
	for (unsigned int i=0; i<formadores.size(); i++)
			if (formadores.at(i)==formador)
				formadores.erase(formadores.begin()+i);
}
