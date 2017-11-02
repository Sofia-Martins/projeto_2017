/*
 * gestor.cpp
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#include "gestor.h"


//construtor
Gestor::Gestor(std::string nome,unsigned int id,std::string password,std::string enderecoEmail)
{
	this->nome=nome;
	this->id=id;
	this->password=password;
	this->enderecoEmail=enderecoEmail;
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


