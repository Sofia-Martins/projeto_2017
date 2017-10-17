/*
 * associacao.cpp
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */


#include "associacao.h"

std::string Associacao::getNome(){
	return this->nome;
}


std::vector Associacao::getEmails(){
	return this->emails;
}

std::vector Associacao::getAssociados(){
	return this->associados;
}

std::vector Associacao::getGestores(){
	return this->gestores;
}

//metodos set
void Associacao::setNome(std::string nome){
	this->nome = nome;
}


//other metodos
void Associacao::addEmail(Email email){
	this->getEmails().push_back(email);
}

void Associacao::addAssociado(Associado associado){
	this->getAssociados().push_back(associado);
}

void Associacao::addGestor(Gestor gestor){
	this->getGestores().push_back(gestor);
}


