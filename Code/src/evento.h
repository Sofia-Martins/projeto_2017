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
	std::vector<int> planeadores;
	std::vector<int> organizadores;
	std::string local;
	std::string tema;
	Data data;
	Apoio apoioEvento;

public:
	// Construtor
	Evento(std::vector <int> planeadores, std::vector<int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento);

	// Metodos get

	std::vector<int> getPlaneadores() const;
	std::vector<int> getOrganizadores() const;
	std::string getLocal() const;
	std::string getTema() const;
	virtual std::vector<int> getFormadores() const { return {}; }

	// Metodos set

	void setLocal(std::string local);
	void setTema(std::string tema);

	// Outros metodos

	virtual void show() const;
	void addPlaneador(int planeador);
	void addOrganizador(int organizador);
	void removePlaneador(int planeador);
	void removeOrganizador(int organizador);
	virtual void removeFormador(int formador) {}
	virtual bool escolaVerao() { return false;}

};


////////////////////////////////////////////// CONFERENCIA ////////////////////////////////////////////////////////////////////////


class Conferencia : public Evento {

private:
	unsigned int numeroParticipantes;

public:
	// Construtor
	Conferencia(std::vector<int> planeadores, std::vector<int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento, unsigned int numeroParticipantes);

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
	std::vector <int> formadores;

public:
	//Construtor
	EscolaVerao(std::vector <int> planeadores,
		std::vector<int> organizadores,
		std::string local,
		std::string tema,
		Data data,
		Apoio apoioEvento,
		std::vector<int> formadores);

	// Metodos get
	std::vector<int> getFormadores() const;

	// Outros metodos
	void show() const;
	void addFormador(int formador);
	void removeFormador(int formador);
	bool escolaVerao() { return true; }
};


#endif