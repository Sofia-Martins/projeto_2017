/*
 * associacao.h
 *
 *  Created on: 17/10/2017
 *      Author: luisa
 */

#ifndef ASSOCIACAO_H_
#define ASSOCIACAO_H_

#include <string>
#include <vector>
#include "dominioCientifico.h"
#include "email.h"
#include "associado.h"
#include "gestor.h"

class Associacao{
private:
	std::string nome;
	//DominioCientifico* dominioAssociacao;
	//std::vector<Evento*> eventos;
	std::vector<Email*> emails;
	std::vector<Associado*> associados;
	std::vector<Gestor*> gestores;

public:
	//metodos get
	std::string getNome();
	//DominioCientifico getDominio();
	std::vector getEmails();
	std::vector getAssociados();
	std::vector getGestores();

	//metodos set
	void setNome(std::string nome);
	//void setDominio(DominioCientifico dominio);

	//other metodos
	void addEmail(Email email);
	void addAssociado(Associado associado);
	void addGestor(Gestor gestor);

};

//excecoes

class AssociacaoRepetida
{
private:
	std::string nome();
public:
	AssociacaoRepetida(std::string nome);
};


#endif /* ASSOCIACAO_H_ */
