/*
* evento.h
*
*  Created on: 17/10/2017
*      Author: Tiago Rodrigues
*/

#ifndef EVENTO_H_
#define EVENTO_H_

#include "associado.h"
#include "data.h"
#include "apoio.h"
#include <string>
#include <vector>


///////////////////////////////////////////////// EVENTO //////////////////////////////////////////////////////////////////////////

class Evento {

private:
	std::vector<unsigned int> planeadores;
	std::vector<unsigned int> organizadores;
	std::string local;
	std::string tema;
	Data data;
	Apoio apoioEvento;

public:
	// Construtor
	Evento(std::vector <unsigned int> planeadores, std::vector<unsigned int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento);

	// Metodos get

	std::vector<unsigned int> getPlaneadores() const;
	std::vector<unsigned int> getOrganizadores() const;
	std::string getLocal() const;
	std::string getTema() const;
	Data getData() const;
	virtual std::vector<unsigned int> getFormadores() const { return {}; }
	Apoio getApoioEvento() const;



	// Metodos set

	void setLocal(std::string local);
	void setTema(std::string tema);

	// Outros metodos

	virtual void show() const;
	void addPlaneador(unsigned int planeador);
	void addOrganizador(unsigned int organizador);
	void removePlaneador(unsigned int planeador);
	void removeOrganizador(unsigned int organizador);
	virtual unsigned int getNumeroParticipantes() const {}
	virtual void removeFormador(unsigned int formador) {}
	virtual bool escolaVerao() { return false;}

};


////////////////////////////////////////////// CONFERENCIA ////////////////////////////////////////////////////////////////////////


class Conferencia : public Evento {

private:
	unsigned int numeroParticipantes;

public:
	// Construtor
	Conferencia(std::vector<unsigned int> planeadores, std::vector<unsigned int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento, unsigned int numeroParticipantes);

	// Metodos get
	unsigned int getNumeroParticipantes() const;

	// Metodos set
	void setNumeroParticipantes(unsigned int numeroParticipantes);

	//outros metodos
	void show() const;
	bool escolaVerao() { return false; }
};


////////////////////////////////////////////// ESCOLA DE VERAO ////////////////////////////////////////////////////////////////////


class EscolaVerao : public Evento {

private:
	std::vector <unsigned int> formadores;

public:
	//Construtor
	EscolaVerao(std::vector <unsigned int> planeadores,
		std::vector<unsigned int> organizadores,
		std::string local,
		std::string tema,
		Data data,
		Apoio apoioEvento,
		std::vector<unsigned int> formadores);

	// Metodos get
	std::vector<unsigned int> getFormadores() const;

	// Outros metodos
	void show() const;
	void addFormador(unsigned int formador);
	void removeFormador(unsigned int formador);
	bool escolaVerao() { return true; }
};


#endif
