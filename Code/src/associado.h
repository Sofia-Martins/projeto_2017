/*
* associado.h
*
*  Created on: 17/10/2017
*      Author: luisa
*/

#ifndef ASSOCIADO_H_
#define ASSOCIADO_H_

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "cota.h"
#include "email.h"
#include "dominioCientifico.h"

class Associado {
private:
	int ID;
	std::string nome;
	std::string password;
	std::string instituicao;

	Cota* cota;
	std::string enderecoEmail;
	std::vector<std::string> eventos;
	std::vector<std::string> areasInteresse;

public:
	/**
	 * @brief Construtor sem parâmetros
	 *
	 * Atribui 'string vazia' aos atributos
	 */
	Associado();
	/**
	 * @brief Construtor com parâmetros
	 * @param nome Especifica nome do associado
	 * @param ID Especifica id do associado
	 * @param password Especifica password do associado
	 * @param instituicao Especifica instituicao do associado
	 * @param cota Especifica cota do associado
	 * @param enderecoEmail Especifica email do associado
	 */
	Associado(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail);
	/**
	 * @brief Funcao virtual para verificar se e contributer
	 * @return false
	 */
	virtual bool isContributor() { return false; }
	/**
	 * @brief Funcao virtual para verificar se e subscriber
	 * @return false
	 */
	virtual bool isSubscriber() { return false; }


	//metodos get
	/**
	 * @brief Retorna valor do atributo ID
	 * @return Valor do atributo ID
	 */
	int getID() const;
	/**
	 * @brief Retorna valor do atributo nome
	 * @return Valor do atributo nome
	 */
	std::string getNome() const;
	/**
	 * @brief Retorna valor do atributo instituicao
	 * @return Valor do atributo instituicao
	 */
	std::string getInstituicao() const;
	/**
	 * @brief Retorna valor do atributo password
	 * @return Valor do atributo password
	 */
	std::string getPassword() const { return this->password; };
	/**
	 * @brief Retorna valor do atributo areasInteresse
	 * @return Valor do atributo areasInteresse
	 */
	std::vector<std::string> getAreasInteresse() const;
	/**
	 * @brief Retorna valor do atributo eventos
	 * @return Valor do atributo eventos
	 */
	std::vector<std::string> getEventos() const { return eventos; }
	/**
	 * @brief Retorna valor do atributo cota
	 * @return Valor do atributo cota
	 */
	Cota* getCota() const;
	/**
	 * @brief Retorna valor do atributo enderecoEmail
	 * @return Valor do atributo enderecoEmail
	 */
	std::string getEmail() const;
	/**
	 * @brief Funcao virtual para emails recebidos
	 */
	virtual std::vector<Email*> getEmailsRecebidos() {
		return{};
	}
	/**
	 * @brief Funcao virtual para emails enviados
	 */
	virtual std::vector<Email*> getEmailsEnviados() {
		return{};
	}

	/**
	 * @brief Funcao virtual para enviar emails
	 */
	virtual void enviarEmail(Email* email) {};
	/**
	 * @brief Funcao virtual para receber emails
	 */
	virtual void receberEmail(Email* email) {};

	//metodos set
	/**
	 * @brief Atribui valor do argumento ao atributo nome
	 * @param nome Valor que será atribuído ao atributo nome
	 * @return void
	 */
	void setNome(std::string nome);
	/**
	 * @brief Atribui valor do argumento ao atributo password
	 * @param pass Valor que será atribuído ao atributo password
	 * @return void
	 */
	void setPassword(std::string pass);
	/**
	 * @brief Atribui valor do argumento ao atributo instituicao
	 * @param instituicao Valor que será atribuído ao atributo instituicao
	 * @return void
	 */
	void setInstituicao(std::string instituicao);
	/**
	 * @brief Atribui valor do argumento ao atributo cota
	 * @param cota Valor que será atribuído ao atributo cota
	 * @return void
	 */
	void setCota(Cota *cota) {
		this->cota->setAtraso(cota->getAtraso());
		this->cota->setEmDia(cota->getEmDia());
	}
	/**
	 * @brief Atribui valor do argumento ao atributo enderecoEmail
	 * @param email Valor que será atribuído ao atributo enderecoEmail
	 * @return void
	 */
	void setEmail(std::string email);
	/**
	 * @brief Atribui valor do argumento ao atributo eventos
	 * @param eventos Valor que será atribuído ao atributo eventos
	 * @return void
	 */
	void setEventos(std::vector<std::string> eventos) { this->eventos = eventos; }
	/**
	 * @brief Atribui valor do argumento ao atributo areasInteresse
	 * @param areasInteresse Valor que será atribuído ao atributo areasInteresse
	 * @return void
	 */
	void setAreasInteresse(std::vector<std::string> areasInteresse) { this->areasInteresse=areasInteresse; }
	/**
	 * @brief Adiciona um evento ao atributo eventos
	 * @param tema Especifica nome do tema
	 * @return void
	 */
	void addEvento(std::string tema) { eventos.push_back(tema); }
	//operators
	/**
	 * @brief Overloading do operador de menor
	 * @param a Associado a comparar
	 * @return true caso o parametro seja maior
	 */
	bool operator < (const Associado & a) const{
		return (ID < a.ID);
	}

	//outros metodos
	/**
	 * @brief Imprime a a informacao do associado na consola
	 */
	void show() const;
	/**
	 * @brief Adiciona valor do argumento ao atributo areasInteresse
	 * @param areasInteresse Valor que será adicionado ao atributo areasInteresse
	 * @return void
	 */
	void addSubAreaInteresse(std::string subArea);

};

class AssociadoRepetido {
private:
	std::string nome;

public:
	/**
	 * @brief Construtor da excecao lançada perante um associado repetido
	 * @param nome Especifica o nome do associado repetido
	 */
	AssociadoRepetido(std::string nome);
};

//subclasse Contributor
class Contributor : public Associado {

	std::vector<Email*> emailsRecebidos;
	std::vector<Email*> emailsEnviados;
public:
	/**
	 * @brief Verifica se e contributor
	 * @return true
	 */
	bool isContributor() { return true; }

	//construtor sem emails
	/**
	 * @brief Construtor com parâmetros mas sem atributos dos emails
	 * @param nome Especifica nome do associado
	 * @param ID Especifica id do associado
	 * @param password Especifica password do associado
	 * @param instituicao Especifica instituicao do associado
	 * @param cota Especifica cota do associado
	 * @param enderecoEmail Especifica email do associado
	 */
	Contributor(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail);
	/**
	 * @brief Construtor com parâmetros
	 * @param nome Especifica nome do associado
	 * @param ID Especifica id do associado
	 * @param password Especifica password do associado
	 * @param instituicao Especifica instituicao do associado
	 * @param cota Especifica cota do associado
	 * @param enderecoEmail Especifica email do associado
	 * @param emailsRecebidos Especifica vetor de emails recebidos
	 * @param emailsEnviados Especifica vetor de emails enviados
	 */
	Contributor(std::string nome, int ID, std::string password, std::string instituicao,
		Cota* cota, std::string enderecoEmail, std::vector<Email*> emailsRecebidos, std::vector<Email*> emailsEnviados);

	//metodos get
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

	//metodos other
	/**
	 * @brief Adiciona email ao atributo emailsEnviados
	 * @param email Valor a adicionar ao atributo emailsEnviados
	 */
	void enviarEmail(Email* email);
	/**
	 * @brief Adiciona email ao atributo emailsRecebidos
	 * @param email Valor a adicionar ao atributo emailsRecebidos
	 */
	void receberEmail(Email* email);
};

class Subscriber : public Associado {
	std::vector<Email*> emailsRecebidos = {};
public:
	bool isSubscriber() { return true; }
	//construtor sem emails
	/**
	 * @brief Construtor com parâmetros mas sem os emails
	 * @param nome Especifica nome do associado
	 * @param ID Especifica id do associado
	 * @param password Especifica password do associado
	 * @param instituicao Especifica instituicao do associado
	 * @param cota Especifica cota do associado
	 * @param enderecoEmail Especifica email do associado
	 */
	Subscriber(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail);
	/**
	 * @brief Construtor com parâmetros
	 * @param nome Especifica nome do associado
	 * @param ID Especifica id do associado
	 * @param password Especifica password do associado
	 * @param instituicao Especifica instituicao do associado
	 * @param cota Especifica cota do associado
	 * @param enderecoEmail Especifica email do associado
	 * @param emailsRecebidos Especifica vetor de emails recebidos
	 */
	Subscriber(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail, std::vector<Email*> emailsRecebidos);

	//metodos get
	/**
	 * @brief Retorna valor do atributo emailsRecebidos
	 * @return Valor do atributo emailsRecebidos
	 */
	std::vector<Email*> getEmailsRecebidos();


	//metodos other
	/**
	 * @brief Adiciona email ao atributo emailsRecebidos
	 * @param email Valor a adicionar ao atributo emailsRecebidos
	 */
	void receberEmail(Email* email);
};



#endif
