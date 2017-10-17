/*
 * areaCientifica.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_AREACIENTIFICA_H_
#define CODE_SRC_AREACIENTIFICA_H_

////////////////////////
#include <vector>
#include <algorithm>             // std::binary_search
#include "subAreaCientifica.h"
////////////////////////

class AreaCientifica
{
private:
	std::string nomeArea;
	std::string siglaArea;
	std::vector<SubAreaCientifica*> subAreas;

public:
	//construtor
	AreaCientifica(std::string nomeArea,std::string siglaArea);

	//metodos set
	void setNomeAreaCientifica(std::string nomeArea);
	void setSiglaAreaCientifica(std::string siglaArea);

	//metodos get
	std::string getNomeAreaCientifica() const;
	std::string getSiglaAreaCientifica() const;


	//outros metodos
	void addSubAreaCientifica(SubAreaCientifica* &subArea);

};

//excecoes

class SubAreaCientificaRepetida
{
private:
	SubAreaCientifica* subArea;
public:
	SubAreaCientificaRepetida(SubAreaCientifica* subArea);
};




#endif /* CODE_SRC_AREACIENTIFICA_H_ */
