/*
 * subAreaCientifica.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_SUBAREACIENTIFICA_H_
#define CODE_SRC_SUBAREACIENTIFICA_H_

///////////////////
#include <string>
#include <iostream>
///////////////////

class SubAreaCientifica
{
private:
	std::string nomeSubArea;

public:
	//construtor
	SubAreaCientifica() { nomeSubArea = ""; }
	SubAreaCientifica(std::string nomeSubArea);

	//metodos set
	void setNomeSubAreaCientifica(std::string nomeSubArea);
	

	//metodos get
	std::string getNomeSubAreaCientifica() const;

	//outros metodos
	void show() const;
	
};



#endif /* CODE_SRC_SUBAREACIENTIFICA_H_ */
