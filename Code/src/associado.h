/*
 * associado.h
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */

#ifndef ASSOCIADO_H_
#define ASSOCIADO_H_

#include <string>
#include "cota.h"
#include <vector>
#include "dominioCientifico.h"

class Associado{
private:
	bool gestor;
	std::string nome;
	std::string password;
	std::string instituicao;
	DominioCientifico* dominio;
	Cota* cota;
	std::string enderecoEmail;
	//std::vector<>

public:
	//metodos get
	std::string getNome();
	std::string getInstituicao();
	DominioCientifico getDominio();
	Cota getCota;
	std::string getEmail;

	//metodos set
	void setNome(std::string nome);
	void setPassword(std::string pass);
	void setInstituicao(std::string instituicao);
	void setDominio(DominioCientifico dominio);
	void setCota(Cota cota);
	void setEmail(std::string email);

};

class AssociadoRepetido{
private:
	std::string nome;

public:
	AssociadoRepetido(std::string nome);
};

class Contribuidor : public Associado{
public:
	std::vector<Email*> emailsRecebidos;
	std::vector<Email*> emailsEnviados;

	//metodos get
	std::vector<Email*> getEmailsRecebidos();
	std::vector<Email*> getEmailsEnviados();

	//metodos other
	void enviarEmail(Email email);
	void receberEmail(Email email);
};

class Subscriber : public Subscriber{
public:
	std::vector<Email*> emailsRecebidos;

	//metodos get
	std::vector<Email*> getEmailsRecebidos();

	//metodos other
	void receberEmail(Email email);
};



#endif /* ASSOCIADO_H_ */
