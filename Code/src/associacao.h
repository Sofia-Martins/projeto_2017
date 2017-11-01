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
#include "evento.h"

class Associacao{
private:
	std::string nome;
	std::string sigla;
	DominioCientifico* dominioAssociacao;
	std::vector<Evento*> eventos;
	std::vector<Email*> emails;
	std::vector<Associado*> associados;
	std::vector<Gestor*> gestores;

public:
	Associacao();
	
	Associacao(std::string nome, std::vector<Evento*> eventos, std::vector<Email*> emails,
			std::vector<Associado*> associados, std::vector<Gestor*> gestores);

	//metodos get
	std::string getNome() const;

	DominioCientifico* getDominio() const {return dominioAssociacao;};
	std::vector<Associado*> getAssociados() const;
	std::vector<Gestor*> getGestores() const;
	std::vector<Email*> getEmails() const;
	std::vector<Evento*> getEventos() const;

	//metodos set
	void setNome(std::string nome);
	void setSigla(std::string sigla);
	void setDominio(DominioCientifico &dominio) {this->dominioAssociacao->setCiencia(dominio.getCiencia());}

	//outros metodos
	void addEmail(Email &email);
	void addAssociado(Associado &associado);
	void addGestor(Gestor &gestor);
	void addEvento(Evento &evento);

};

//excecoes

class AssociacaoRepetida
{
private:
	std::string nome;
public:
	AssociacaoRepetida(std::string nome);
};


#endif
