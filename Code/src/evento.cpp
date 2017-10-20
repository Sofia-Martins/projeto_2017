/*
 * evento.cpp
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#include "evento.h"

//Class Evento

//Construtor
Evento::Evento(std::vector <Associado*> planeadores, std::string local, std::string tema, Data data, Apoio apoioEvento)
{
	this->planeadores = planeadores;
	this->organizadores = planeadores;
	this->local = local;
	this->tema = tema;
	this->data = data;
	this->apoioEvento = apoioEvento;
}

//Sub-class Conferencia

//Construtor

Conferencia::Conferencia(std::vector<Associado*> planeadores, std::string local,
		std::string tema, Data data, Apoio apoioEvento,
		unsigned int numeroParticipantes) :Evento(planeadores, local, tema, data, apoioEvento) {
	this->numeroParticipantes = numeroParticipantes;
}

//Sub-class EscolaVerao

//Construtor

EscolaVerao::EscolaVerao(std::vector<Associado*> planeadores, std::string local,
		std::string tema, Data data, Apoio apoioEvento,
		std::vector<Associado*> formadores) :Evento(planeadores, local, tema, data, apoioEvento) {
	this->formadores = formadores;
}

