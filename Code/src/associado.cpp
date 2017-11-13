/*
 * associado.cpp
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */

#include "associado.h"


Associado::Associado(){
	this->ID = 0;
	this->nome = {};
	this->password = {};
	this->instituicao = {};
	this->cota = NULL;
	this->enderecoEmail = {};
}

Associado::Associado(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail) {
	this->ID = ID;
	this->nome = nome;
	this->password = password;
	this->instituicao = instituicao;
	this->cota = cota;
	this->enderecoEmail = enderecoEmail;

}

//metodos get

int Associado::getID() const {
	return this->ID;
}
std::string Associado::getNome() const {
	return this->nome;
}

std::string Associado::getInstituicao() const {
	return this->instituicao;
}

std::string Associado::getEmail() const {
	return this->enderecoEmail;
}

Cota* Associado::getCota() const
{
	return this->cota;
}

//metodos set
void Associado::setNome(std::string nome) {
	this->nome = nome;
}

void Associado::setPassword(std::string pass) {
	this->password = pass;
}

void Associado::setInstituicao(std::string instituicao) {
	this->instituicao = instituicao;
}

void Associado::setEmail(std::string email) {
	this->enderecoEmail = email;
}

//outros metodos
void Associado::show() const
{
	std::cout << "|1| INFORMACOES GERAIS " << std::endl;
	std::cout << " | ID: " << this->ID << std::endl;
	std::cout << " | Nome: " << this->nome << std::endl;
	std::cout << " | Password: " <<  this->password << std::endl;
	std::cout << " | Instituicao: " <<  this->instituicao << std::endl;
	std::cout << " | Endereco de email: " <<this->enderecoEmail << std::endl << std::endl;

	std::cout << "|2| COTA " << std::endl;
	std::cout << " | Atraso: " << this->cota->getAtraso() << " anos" << std::endl << std::endl;

	std::cout << "|3| AREAS DE INTERESSE " << std::endl;
	//this->dominio->show();   Versao correta - completar se tiver tempo - falta inicializar o dominio com o vetor areas de interesse
	for (unsigned int i = 0; i < areasInteresse.size(); i++)
	{
		std::cout << " | "<<areasInteresse.at(i) << std::endl;
	}

}


//excecao
AssociadoRepetido::AssociadoRepetido(std::string nome) {
	this->nome = nome;
}

//subclasse contribuitor

Contributor::Contributor(std::string nome, int ID, std::string password, std::string instituicao,
		Cota* cota, std::string enderecoEmail) : Associado(nome, ID, password, instituicao, cota, enderecoEmail){};

Contributor::Contributor(std::string nome, int ID, std::string password, std::string instituicao,
		Cota* cota, std::string enderecoEmail,
		std::vector<Email*> emailsRecebidos,
		std::vector<Email*> emailsEnviados)
:Associado(nome, ID, password, instituicao, cota, enderecoEmail)
{
	this->emailsRecebidos = emailsRecebidos;
	this->emailsEnviados = emailsEnviados;
}

//metodos get
std::vector<Email*> Contributor::getEmailsRecebidos() {
	return this->emailsRecebidos;
}
std::vector<Email*> Contributor::getEmailsEnviados() {
	return this->emailsEnviados;
}

//metodos other
void Contributor::enviarEmail(Email &email) {
	this->emailsEnviados.push_back(&email);
}
void Contributor::receberEmail(Email &email) {
	this->emailsRecebidos.push_back(&email);
}

//subclasse subscriber

Subscriber::Subscriber(std::string nome, int ID, std::string password, std::string instituicao,
		Cota* cota, std::string enderecoEmail) :Associado(nome, ID, password, instituicao, cota, enderecoEmail){};


Subscriber::Subscriber(std::string nome, int ID, std::string password, std::string instituicao,
		Cota* cota, std::string enderecoEmail,
		std::vector<Email*> emailsRecebidos) :Associado(nome, ID, password, instituicao, cota, enderecoEmail)
{
	this->emailsRecebidos = emailsRecebidos;
}
//metodos get
std::vector<Email*> Subscriber::getEmailsRecebidos() {
	return this->emailsRecebidos;
}

//metodos other
void Subscriber::receberEmail(Email &email) {
	this->emailsRecebidos.push_back(&email);
}

