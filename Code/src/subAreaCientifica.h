/*
 * subAreaCientifica.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_SUBAREACIENTIFICA_H_
#define CODE_SRC_SUBAREACIENTIFICA_H_

/////////////////////////////
#include "areaCientifica.h"
/////////////////////////////

class SubAreaCientifica
{
private:
	std::string nomeSubArea;
	std::string siglaSubArea;

public:
	//construtor
	SubAreaCientifica(std::string nomeSubArea,std::string siglaSubArea);

	//metodos set
	void setNomeSubAreaCientifica(std::string nomeSubArea);
	void setSiglaSubAreaCientifica(std::string siglaSubArea);

	//metodos get
	std::string getNomeSubAreaCientifica() const;
	std::string getSiglaSubAreaCientifica() const;
};



#endif /* CODE_SRC_SUBAREACIENTIFICA_H_ */
