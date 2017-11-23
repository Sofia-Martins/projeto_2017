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
	/**
		 * @brief Le o gestor do ficheiro de gestores
		 * @param nome Especifica nome do gestor
		 * @param id Especifica id do gestor
		 * @param password Especifica password do gestor
		 * @param enderecoEmail Especifica email do gestor
		 * @return void
		 */
	Gestor(std::string nome,unsigned int id,std::string password,std::string enderecoEmail); //ler gestor do ficheiro
	/**
		 * @brief Construtor do gestor
		 *
		 *	Email e atribuido automaticamente
		 *
		 * @param nome Especifica nome do gestor
		 * @param password Especifica password do gestor
		 * @param siglaAssociacao Especifica associacao do gestor
		 * @param id Especifica id do gestor
		 * @return void
		 */
	Gestor(std::string nome, std::string password, std::string siglaAssociacao,unsigned int id); //criar gestor de raiz

	//metodos set
	/**
	 * @brief Atribui valor do argumento ao atributo nome
	 * @param nome Valor que será atribuído ao atributo nome
	 * @return void
	 */
	void setNome(std::string nome);
	/**
	 * @brief Atribui valor do argumento ao atributo id
	 * @param id Valor que será atribuído ao atributo id
	 * @return void
	 */
	void setID (unsigned int id);
	/**
	 * @brief Atribui valor do argumento ao atributo password
	 * @param password Valor que será atribuído ao atributo password
	 * @return void
	 */
	void setPassword(std::string password);
	/**
	 * @brief Atribui valor do argumento ao atributo enderecoEmail
	 * @param enderecoEmail Valor que será atribuído ao atributo enderecoEmail
	 * @return void
	 */
	void setEnderecoEmail(std::string enderecoEmail);

	//metodos get
	/**
	 * @brief Retorna valor do atributo nome
	 * @return Valor do atributo nome
	 */
	std::string getNome() const;
	/**
	 * @brief Retorna valor do atributo id
	 * @return Valor do atributo id
	 */
	unsigned int getID() const;
	/**
	 * @brief Retorna valor do atributo enderecoEmail
	 * @return Valor do atributo enderecoEmail
	 */
	std::string getEmail() const {return this->enderecoEmail;}
	/**
	 * @brief Retorna valor do atributo password
	 * @return Valor do atributo password
	 */
	std::string getPassword() const;
	/**
	 * @brief Retorna valor do atributo enderecoEmail
	 * @return Valor do atributo enderecoEmail
	 */
	std::string getEnderecoEmail() const;
	/**
	 * @brief Retorna valor do atributo emailsRecebidos
	 * @return Valor do atributo emailsRecebidos
	 */
	std::vector<Email*> getEmailsRecebidos();
	/**
	 * @brief Retorna valor do atributo emailsEnviados
	 * @return Valor do atributo emailsEnviados
	 */
	std::vector<Email*> getEmailsEnviados();

	/**
	 * @brief Adiciona um email ao atributo emailsEnviados
	 * @param email Especifica email a adicionar
	 * @return void
	 */
	void enviarEmail(Email* email);
	/**
	 * @brief Adiciona um email ao atributo emailsRecebidos
	 * @param email Especifica email a adicionar
	 * @return void
	 */
	void receberEmail(Email* email);

	//show
	/**
	 * @brief Imprime na consola os atributos do gestor
	 * @return void
	 */
	void show() const;



};

#endif
