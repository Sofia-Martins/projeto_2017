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
	this->id = 0;
}


Associacao::Associacao(std::string nome, std::vector<Evento*> eventos,
	std::vector<Email*> emails, std::vector<Associado*> associados, std::vector<Gestor*> gestores) {
	this->dominioAssociacao = NULL;
	this->nome = nome;
	this->eventos = eventos;
	this->emails = emails;
	this->associados = associados;
	this->gestores = gestores;
	this->id = 0;
}


//metodos get
std::string Associacao::getNome() const {
	return this->nome;
}

std::string Associacao::getSigla() const
{
	return this->sigla;
}

std::vector<Email*> Associacao::getEmails() const {
	return this->emails;
}

bool equalGestor(Gestor* g1, Gestor* g2)
{
	return (g1->getID() == g2->getID());
}
/*
Gestor* Associacao::getGestor(int id) const
{
	Gestor* temp = new Gestor("", id, "", ""); //nome, id, password, email
	auto it = find_if(this->gestores.begin(), this->gestores.end(), temp,equalGestor);
	if()
}
*/
std::vector<Associado*> Associacao::getAssociados() const {
	return this->associados;
}

std::vector<Gestor*> Associacao::getGestores() const {
	return this->gestores;
}

std::vector<Evento*> Associacao::getEventos() const {
	return this->eventos;
}
unsigned int Associacao::getID() const { return this->id; }

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
void Associacao::setID(unsigned int id)
{
	this->id = id;
}

void Associacao::setEventos(std::vector<Evento*> eventos) { this->eventos = eventos; }
void Associacao::setEmails(std::vector<Email*> emails) { this->emails = emails; }
void Associacao::setAssociados(std::vector<Associado*> associados) { this->associados = associados; }
void Associacao::setGestores(std::vector<Gestor*> gestores) { this->gestores = gestores; }


//outros metodos

unsigned int Associacao::incIdAssociados(){
	id++;
	return this->id;
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

void Associacao::eraseAssociado(Associado* associado){
/*	for (unsigned int i = 0; i<associados.size(); i++)
		if (associados.at(i) == associado)
			associados.erase(associados.begin()+i);
*/}


void Associacao::showEventos(Associado* associado) const
{
	for (unsigned int i = 0; i < eventos.size(); i++)
	{
		auto evento = eventos.at(i);
		auto planeadores = evento->getPlaneadores();
		auto organizadores = evento->getOrganizadores();

		if (find(planeadores.begin(), planeadores.end(), associado->getID()) !=planeadores.end()) //se encontrou esse associado
		{
			evento->show();
			std::cout << std::endl;
		}
		else
		{
			if (find(organizadores.begin(), organizadores.end(), associado->getID()) != organizadores.end())
			{
				evento->show();
				std::cout << std::endl;
			}
		}
	}
}

AssociacaoRepetida::AssociacaoRepetida(std::string nome) {
	this->nome = nome;
}
