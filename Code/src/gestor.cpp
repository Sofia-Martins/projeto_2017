/*
 * gestor.cpp
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#include "gestor.h"

//inicializacao da variavel static


//construtores
Gestor::Gestor(std::string nome,unsigned int id,std::string password,std::string enderecoEmail)
{
	this->nome=nome;
	this->id = id;
	this->password=password;
	this->enderecoEmail=enderecoEmail;
}
Gestor::Gestor(std::string nome, std::string password,std::string siglaAssociacao,unsigned int id)
{
	this->nome = nome;
	this->password = password;
	this->id = id;
	this->enderecoEmail = std::to_string(this->id) + "@" + siglaAssociacao + ".com";
}

//metodos set
void Gestor::setNome(std::string nome)
{
	this->nome=nome;
}
void Gestor::setID (unsigned int id)
{
	this->id=id;
}
void Gestor::setPassword(std::string password)
{
	this->password=password;
}
void Gestor::setEnderecoEmail(std::string enderecoEmail)
{
	this->enderecoEmail=enderecoEmail;
}

//metodos get
std::string Gestor::getNome() const
{
	return nome;
}
unsigned int Gestor::getID() const
{
	return id;
}
std::string Gestor::getPassword() const
{
	return password;
}
std::string Gestor::getEnderecoEmail() const
{
	return enderecoEmail;
}
std::vector<Email*> Gestor::getEmailsRecebidos() {
	return this->emailsRecebidos;
}
std::vector<Email*> Gestor::getEmailsEnviados() {
	return this->emailsEnviados;
}
void Gestor::enviarEmail(Email &email) {
	this->emailsEnviados.push_back(&email);
}
void Gestor::receberEmail(Email &email) {
	this->emailsRecebidos.push_back(&email);
}

void Gestor::show() const
{
	std::cout << "|1| INFORMACOES GERAIS " << std::endl;
	std::cout << " | ID: " << this->id << std::endl;
	std::cout << " | Nome: " << this->nome << std::endl;
	std::cout << " | Password: " <<  this->password << std::endl;
	std::cout << " | Endereco de email: " <<this->enderecoEmail << std::endl << std::endl;

}

