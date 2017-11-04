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
	static unsigned int idGestor;
public:
	//construtor
	Gestor(std::string nome,unsigned int id,std::string password,std::string enderecoEmail); //ler gestor do ficheiro
	Gestor(std::string nome, std::string password, std::string siglaAssociacao); //criar gestor de raiz

	//metodos set
	void setNome(std::string nome);
	void setID (unsigned int id);
	void setPassword(std::string password);
	void setEnderecoEmail(std::string enderecoEmail);

	//metodos get
	std::string getNome() const;
	unsigned int getID() const;
	std::string getPassword() const;
	std::string getEnderecoEmail() const;

};

#endif
