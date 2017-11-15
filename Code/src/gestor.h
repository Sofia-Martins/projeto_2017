/*
 * gestor.h
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_GESTOR_H
#define CODE_SRC_GESTOR_H

//////////////////////
#include <string>
#include <vector>
#include <iostream>
#include "email.h"
/////////////////////


class Gestor
{
private:
	std::string nome;
	unsigned int id;
	std::string password;
	std::string enderecoEmail;
	std::vector<Email*> emailsRecebidos;
	std::vector<Email*> emailsEnviados;
public:
	//construtor
	Gestor(std::string nome,unsigned int id,std::string password,std::string enderecoEmail); //ler gestor do ficheiro
	Gestor(std::string nome, std::string password, std::string siglaAssociacao,unsigned int id); //criar gestor de raiz

	//metodos set
	void setNome(std::string nome);
	void setID (unsigned int id);
	void setPassword(std::string password);
	void setEnderecoEmail(std::string enderecoEmail);

	//metodos get
	std::string getNome() const;
	unsigned int getID() const;
	std::string getEmail() const {return this->enderecoEmail;}
	std::string getPassword() const;
	std::string getEnderecoEmail() const;
	std::vector<Email*> getEmailsRecebidos();
	std::vector<Email*> getEmailsEnviados();

	void enviarEmail(Email* email);
	void receberEmail(Email* email);

	//show
	void show() const;



};

#endif
