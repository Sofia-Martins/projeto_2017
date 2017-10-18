/*
 * associacao.cpp
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */


#include "associacao.h"

std::string Associacao::getNome() const{
	return this->nome;
}


std::vector<Email*> Associacao::getEmails() const{
	return this->emails;
}

std::vector<Associado*> Associacao::getAssociados() const{
	return this->associados;
}

std::vector<Gestor*> Associacao::getGestores() const{
	return this->gestores;
}

std::vector<Evento*> Associacao::getEventos() const{
	return this->eventos;
}

//metodos set
void Associacao::setNome(std::string nome){
	this->nome = nome;
}

void Associacao::setSigla(std::string sigla)
{
	this->sigla=sigla;
}


//other metodos
void Associacao::addEmail(Email &email){
	this->getEmails().push_back(&email);
}

void Associacao::addAssociado(Associado &associado){
	this->getAssociados().push_back(&associado);
}

void Associacao::addGestor(Gestor &gestor){
	this->getGestores().push_back(&gestor);
}

AssociacaoRepetida::AssociacaoRepetida(std::string nome){
	this->nome = nome;
}


