/*
* email.cpp
*
*  Created on : 14 / 10 / 2017
* Author : sofia
*/

#include "email.h"

//construtor
Email::Email(std::string remetente, std::string destinatario, std::string conteudo)
{
	this->remetente = remetente;
	this->destinatario = destinatario;
	this->conteudo = conteudo;
}

//metodos set
void Email::setRemetente(std::string remetente)
{
	this->remetente = remetente;
}
void Email::setDestinatario(std::string destinatario)
{
	this->destinatario = destinatario;
}
void Email::setConteudo(std::string conteudo)
{
	this->conteudo = conteudo;
}

//metodos get
std::string Email::getRemetente() const
{
	return remetente;
}
std::string Email::getDestinatario() const
{
	return destinatario;
}
std::string Email::getConteudo() const
{
	return conteudo;
}

