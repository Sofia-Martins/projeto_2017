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

void Associacao::showContributors() const
{
	std::cout << "--- CONTRIBUTORS ---" << std::endl;
	for (unsigned int i = 0; i < associados.size(); i++)
	{
		auto associado = associados.at(i);

		if (associado->isContributor() == true)
		{
			std::cout << "ID: " << associado->getID() << std::endl;
			std::cout << "Instituicao: " << associado->getInstituicao() << std::endl;
			std::cout << "Nome: " << associado->getNome() << std::endl;
			std::cout << "Email: " << associado->getEmail() << std::endl << std::endl;
		}
	}
}

void Associacao::showSubscribers() const
{
	std::cout << "--- SUBSCRIBERS ---" << std::endl;
	for (unsigned int i = 0; i < associados.size(); i++)
	{
		auto associado = associados.at(i);

		if (associado->isSubscriber() == true)
		{
			std::cout << "ID: " << associado->getID() << std::endl;
			std::cout << "Instituicao: " << associado->getInstituicao() << std::endl;
			std::cout << "Nome: " << associado->getNome() << std::endl;
			std::cout << "Email: " << associado->getEmail() << std::endl << std::endl;
		}
	}
}

void Associacao::showGestores() const
{
	std::cout << "--- GESTORES ---" << std::endl;
	for (unsigned int i = 0; i < gestores.size(); i++)
	{
			auto gestor = gestores.at(i);

			std::cout << "ID: " << gestor->getID() << std::endl;
			std::cout << "Nome: " << gestor->getNome() << std::endl;
			std::cout << "Email: " << gestor->getEmail() << std::endl << std::endl;
		}
}
unsigned int Associacao::incIdAssociados(){
	id++;
	return this->id;
}

void Associacao::addEmail(Email* email) {

	auto remetente = email->getRemetente();
	auto destinatario = email->getDestinatario();
	emails.push_back(email);

	for (unsigned int i = 0; i < associados.size(); i++)
	{
		if (associados.at(i)->getEmail() == remetente)
			associados.at(i)->enviarEmail(email);
		
		if (associados.at(i)->getEmail() == destinatario)
			associados.at(i)->receberEmail(email);
	}

	for (unsigned int i = 0; i < gestores.size(); i++)
	{
		if (gestores.at(i)->getEmail() == remetente)
			gestores.at(i)->enviarEmail(email);

		if (gestores.at(i)->getEmail() == destinatario)
			gestores.at(i)->receberEmail(email);
	}
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

	//apagar associado do vetor de associados
	for (unsigned int i = 0; i<associados.size(); i++)
		if (associados.at(i) == associado)
		{
			associados.erase(associados.begin() + i);
			//delete associado;
		}

	//apagar associado dos eventos em que participa
	for (unsigned int i = 0; i < eventos.size(); i++)
	{
		auto planeadores = eventos.at(i)->getPlaneadores();
		auto organizadores = eventos.at(i)->getOrganizadores();
		auto posPlaneador = find(planeadores.begin(), planeadores.end(), associado->getID());
		auto posOrganizador = find(organizadores.begin(), organizadores.end(), associado->getID());

		if (posPlaneador != planeadores.end())
			eventos.at(i)->removePlaneador(associado->getID());

		if (posOrganizador != organizadores.end())
			eventos.at(i)->removeOrganizador(associado->getID());

		if (eventos.at(i)->escolaVerao() == true)   //se esse evento for uma escola de Verao existe a possibilidade de esse 
													  //associado constar da lista de formadores
		{
			auto formadores = eventos.at(i)->getFormadores();
			auto posFormador = find(formadores.begin(), formadores.end(), associado->getID());

			if (posFormador != formadores.end())
				eventos.at(i)->removeFormador(associado->getID());
		}
		
		
	}
}

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

bool Associacao::existeEmail(std::string email) const
{
	//verifica se o email existe e se pertence a um subscriber, contributor ou gestor
	for (unsigned int i = 0; i < associados.size(); i++)
	{
		if (associados.at(i)->getEmail() == email)
		{
			if((associados.at(i)->isContributor()==true) || (associados.at(i)->isSubscriber()==true))
			   return true;
		}
	}

	for (unsigned int i = 0; i < gestores.size(); i++)
	{
		if (gestores.at(i)->getEmail() == email)
			return true;
	}
	return false;
}


void Associacao::organizaEmails()
{
	bool organizado = false;

	for (unsigned int i=0; i<this->emails.size(); i++)
	{
		std::cout << "Iteracao " << i+1 << std::endl;
		for (unsigned int j=0; j<associados.size(); j++)
		{
			if (emails.at(i)->getRemetente() == associados.at(j)->getEmail())
			{
				associados.at(j)->enviarEmail(emails.at(i));
				std::cout << "Fiz push para o vetor de emails enviados de " << associados.at(j)->getNome() << std::endl;
				organizado = true;
			}
			else if (emails.at(i)->getDestinatario() == associados.at(j)->getEmail())
			{
				associados.at(j)->receberEmail(emails.at(i));
				std::cout << "Fiz push para o vetor de emails recebidos de " << associados.at(j)->getNome()<< std::endl;
				organizado = true;
			}
			continue;
		}

		if (!organizado)
			for (unsigned int j = 0; j < gestores.size(); j++)
			{
				if (emails.at(i)->getRemetente() == gestores.at(j)->getEmail())
					gestores.at(j)->enviarEmail(emails.at(i));
				else if (emails.at(i)->getDestinatario()== gestores.at(j)->getEmail())
					gestores.at(j)->receberEmail(emails.at(i));
			}
	}
}


AssociacaoRepetida::AssociacaoRepetida(std::string nome) {
	this->nome = nome;
}

