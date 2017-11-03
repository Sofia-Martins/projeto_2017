/*
* associacao.cpp
*
*  Created on: 17/10/2017
*      Author: luisa
*/


#include "associacao.h"

Associacao::Associacao() {

	this->dominioAssociacao = NULL;
	this->eventos = {};
	this->emails = {};
	this->associados = {};
	this->gestores = {};
}


Associacao::Associacao(std::string nome, std::vector<Evento*> eventos,
	std::vector<Email*> emails, std::vector<Associado*> associados, std::vector<Gestor*> gestores) {
	this->dominioAssociacao = NULL;
	this->nome = nome;
	this->eventos = eventos;
	this->emails = emails;
	this->associados = associados;
	this->gestores = gestores;
}


//metodos get
std::string Associacao::getNome() const {
	return this->nome;
}


std::vector<Email*> Associacao::getEmails() const {
	return this->emails;
}

std::vector<Associado*> Associacao::getAssociados() const {
	return this->associados;
}

std::vector<Gestor*> Associacao::getGestores() const {
	return this->gestores;
}

std::vector<Evento*> Associacao::getEventos() const {
	return this->eventos;
}


//metodos set
void Associacao::setNome(std::string nome) {
	this->nome = nome;
}

void Associacao::setSigla(std::string sigla)
{
	this->sigla = sigla;
}

void Associacao::setDominio(DominioCientifico* dominio)
{
	this->dominioAssociacao = dominio;
}


//outros metodos

unsigned int Associacao::incIdAssociados(){
	idAssociados++;
	return this->idAssociados;
}

void Associacao::addEmail(Email &email) {
	emails.push_back(&email);
}

void Associacao::addAssociado(Associado &associado) {
	associados.push_back(&associado);
}

void Associacao::addGestor(Gestor &gestor) {
	gestores.push_back(&gestor);
}

void Associacao::addEvento(Evento &evento)
{
	eventos.push_back(&evento);
}

AssociacaoRepetida::AssociacaoRepetida(std::string nome) {
	this->nome = nome;
}
