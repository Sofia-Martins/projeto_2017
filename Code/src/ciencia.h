/*
 * ciencia.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */


#ifndef CODE_SRC_CIENCIA_H_
#define CODE_SRC_CIENCIA_H_

/////////////////////////////
#include "areaCientifica.h"
/////////////////////////////

class Ciencia
{

private:
	std::string nomeCiencia;
	std::vector<AreaCientifica*> areas;
public:
	//construtor
	Ciencia(std::string nomeCiencia);

	//metodos set
	void setNomeCiencia(std::string nomeCiencia);

	//metodos get
	std::string getNomeCiencia() const;
};




#endif /* CODE_SRC_CIENCIA_H_ */
