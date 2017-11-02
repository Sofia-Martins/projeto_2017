/*
 * email.cpp
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#include "email.h"

//construtor
/*Email::Email(Associado* remetente,Associado* destinatario, string conteudo)
{
	this->remetente=remetente;
	this->destinatario->destinatario;
	this->conteudo=conteudo;
}*/

//metodos set
/*void Email::setRemetente(Associado* remetente)
{
	this->remetente=remetente;
}*/
/*void Email::setDestinatario(Associado* destinatario)
{
	this->destinatario=destinatario;
}*/
void Email::setConteudo(std::string conteudo)
{
	this->conteudo=conteudo;
}

//metodos get
/*Associado* Email::getRemetente() const
{
	return remetente;
}*/
/*Associado* Email::getDestinatario() const
{
	return destinatario;
}*/
std::string Email::getConteudo() const
{
	return conteudo;
}


