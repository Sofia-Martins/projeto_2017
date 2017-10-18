/*
 * associado.cpp
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */


#include "associado.h"

//metodos get
std::string Associado::getNome()const{
	return this->nome;
}

std::string  Associado::getInstituicao() const{
	return this->instituicao;
}


std::string Associado::getEmail() const{
	return this->enderecoEmail;
}

//metodos set
void  Associado::setNome(std::string nome){
	this->nome = nome;
}

void  Associado::setPassword(std::string pass){
	this->password = pass;
}

void  Associado::setInstituicao(std::string instituicao){
	this->instituicao = instituicao;
}


void  Associado::setEmail(std::string email){
	this->enderecoEmail = email;
}

//excecao
AssociadoRepetido::AssociadoRepetido(std::string nome){
	this->nome = nome;
}

//subclasse contribuitor

//metodos get
std::vector<Email*> Contributor::getEmailsRecebidos(){
	return this->emailsRecebidos;
}
std::vector<Email*> Contributor::getEmailsEnviados(){
	return this->emailsEnviados;
}

//metodos other
void Contributor::enviarEmail(Email &email){
	this->emailsEnviados.push_back(&email);
}
void Contributor::receberEmail(Email &email){
	this->emailsRecebidos.push_back(&email);
}


//subclasse subscriber

//metodos get
std::vector<Email*> Subscriber::getEmailsRecebidos(){
	return this->emailsRecebidos;
}

//metodos other
void Subscriber::receberEmail(Email &email){
	this->emailsRecebidos.push_back(&email);
}

