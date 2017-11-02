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
#include "cota.h"
#include "email.h"
#include "dominioCientifico.h"



class Associado {
private:
	int ID;
	std::string nome;
	std::string password;
	std::string instituicao;
	DominioCientifico* dominio;
	Cota* cota;
	std::string enderecoEmail;
	std::vector<std::string> eventos = {};
	std::vector<std::string> areasInteresse = {};

public:
	Associado();
	Associado(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail);

	//metodos get
	int getID() const;
	std::string getNome() const;
	std::string getInstituicao() const;
	std::string getPassword() const { return this->password; };
	//DominioCientifico getDominio() const;
	//Cota getCota() const;
	std::string getEmail() const;

	//metodos set
	void setNome(std::string nome);
	void setPassword(std::string pass);
	void setInstituicao(std::string instituicao);
	//void setDominio(DominioCientifico *dominio){this->dominio->setCiencia(dominio->getCiencia());}
	void setCota(Cota *cota) {
		this->cota->setAtraso(cota->getAtraso());
		this->cota->setEmDia(cota->getEmDia());
	}
	void setEmail(std::string email);
	void setEventos(std::vector<std::string> eventos) { this->eventos = eventos; }
	void setAreasInteresse(std::vector<std::string> areasInteresse) { this->areasInteresse; }

	//operators
	const Associado & operator= (const Associado & a);

};

class AssociadoRepetido {
private:
	std::string nome;

public:
	AssociadoRepetido(std::string nome);
};

//subclasse Contributor
class Contributor : public Associado {

	std::vector<Email*> emailsRecebidos = {};
	std::vector<Email*> emailsEnviados = {};
public:
	//construtor sem emails
	Contributor(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail);
	Contributor(std::string nome, int ID, std::string password, std::string instituicao,
		Cota* cota, std::string enderecoEmail, std::vector<Email*> emailsRecebidos, std::vector<Email*> emailsEnviados);

	//metodos get
	std::vector<Email*> getEmailsRecebidos();
	std::vector<Email*> getEmailsEnviados();

	//metodos other
	void enviarEmail(Email &email);
	void receberEmail(Email &email);
};

class Subscriber : public Associado {
	std::vector<Email*> emailsRecebidos = {};
public:
	//construtor sem emails
	Subscriber(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail);
	Subscriber(std::string nome, int ID, std::string password, std::string instituicao, Cota* cota, std::string enderecoEmail, std::vector<Email*> emailsRecebidos);

	//metodos get
	std::vector<Email*> getEmailsRecebidos();

	//metodos other
	void receberEmail(Email &email);
};



#endif