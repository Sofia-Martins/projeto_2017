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
	std::vector <Associado*> planeadores;
	std::vector <Associado*> organizadores;
	std::string local;
	std::string tema;
	Data data;
	Apoio apoioEvento;

public:
	//Construtor
	Evento(std::vector <Associado*> planeadores, std::string local, std::string tema, Data data, Apoio apoioEvento);

};


////////////////////////////////////////////// CONFERENCIA ////////////////////////////////////////////////////////////////////////


class Conferencia: public Evento {

private:
	unsigned int numeroParticipantes;

public:
	//Construtor
	Conferencia(std::vector <Associado*> planeadores, std::string local, std::string tema, Data data, Apoio apoioEvento, unsigned int numeroParticipantes);
};


////////////////////////////////////////////// ESCOLA DE VERAO ////////////////////////////////////////////////////////////////////


class EscolaVerao: public Evento {

private:
	std::vector <Associado*> formadores;

public:
	//Construtor
	EscolaVerao(std::vector <Associado*> planeadores, std::string local, std::string tema, Data data, Apoio apoioEvento, std::vector <Associado*> formadores);
};


#endif /* EVENTO_H_ */
