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

