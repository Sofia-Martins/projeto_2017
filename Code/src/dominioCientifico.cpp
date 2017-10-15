/*
 * dominioCientifico.cpp
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

/////////////////////////////////
#include "dominioCientifico.h"
////////////////////////////////

// metodos de adicao de Ciencias/AreasCientificas/SubAreasCientificas
void DominioCientifico::addCiencia(const Ciencia &ciencia)
{
	std::vector<Ciencia>::const_iterator inicio=ciencias.begin(); //apontador para a primeira ciencia
	std::vector<Ciencia>::const_iterator fim=ciencias.end(); //apontador para o final do vector ciencias
	bool existeCiencia=binary_search(inicio, fim, ciencia);

	if(existeCiencia)
		throw  CienciaRepetida(&ciencia);
	else
	{   //FALTA ACABAR!!
		//ciencias.push_back(&ciencia);

	}

}
void DominioCientifico::addAreaCientifica(const AreaCientifica &area);
void DominioCientifico::addSubAreaCientifica(const SubAreaCientifica &subArea);
