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

class Evento{

private:
	std::vector<Associado*> planeadores;
	std::vector<Associado*> organizadores;
	std::string local;
	std::string tema;
	Data data;
	Apoio apoioEvento;

public:
	// Construtor
	Evento(std::vector <Associado*> planeadores, std::string local, std::string tema, Data data, Apoio apoioEvento);

	// Metodos get

	std::vector<Associado*> getPlaneadores () const;
	std::vector<Associado*> getOrganizadores() const;
	std::string getLocal() const;
	std::string getTema() const;

	// Metodos set

	void setLocal(std::string local);
	void setTema(std::string tema);

	// Outros metodos

	void addPlaneador (Associado* planeador);
	void addOrganizador (Associado* organizador);
	void removePlaneador (Associado* planeador);
	void removeOrganizador (Associado* organizador);

};


////////////////////////////////////////////// CONFERENCIA ////////////////////////////////////////////////////////////////////////


class Conferencia: public Evento {

private:
	unsigned int numeroParticipantes;

public:
	// Construtor
	Conferencia(std::vector<Associado*> planeadores, std::string local, std::string tema, Data data, Apoio apoioEvento, unsigned int numeroParticipantes);

	// Metodos get
	unsigned int getNumeroParticipantes() const;

	// Metodos set
	void setNumeroParticipantes(unsigned int numeroParticipantes);
};


////////////////////////////////////////////// ESCOLA DE VERAO ////////////////////////////////////////////////////////////////////


class EscolaVerao: public Evento {

private:
	std::vector <Associado*> formadores;

public:
	//Construtor
	EscolaVerao(std::vector <Associado*> planeadores,
			std::string local,
			std::string tema,
			Data data,
			Apoio apoioEvento,
			std::vector<Associado*> formadores);

	// Metodos get
	std::vector<Associado*> getFormadores () const;

	// Outros metodos
	void addFormador (Associado* formador);
	void removeFormador (Associado* formador);
};


#endif
