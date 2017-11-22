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
#include <iostream>
#include <algorithm>             // std::binary_search
#include "subAreaCientifica.h"
////////////////////////

class AreaCientifica
{
private:
	std::string nomeArea;
	std::vector<SubAreaCientifica*> subAreas;

public:
	//construtor
	/*
	 * @brief Construtor sem parâmetros da classe AreaCientifica
	 *
	 * Coloca o nomeArea igual a string vazia
	 *
	 */
	AreaCientifica(){nomeArea = {};};
	/*
	 * @brief Construtor da classe AreaCientifica
	 * @param nomeArea Define nome da area
	 * @return void
	 */
	AreaCientifica(std::string nomeArea);


	//metodos set
	/*
	 * @brief Altera nome da area cientifica
	 * @param nomeArea Especifica novo valor do nome da area
	 * @return void
	 */
	void setNomeAreaCientifica(std::string nomeArea);

	//metodos get
	/*
	 * @brief Retorna valor do atributo nomeArea
	 * @return String nomeArea
	 */
	std::string getNomeAreaCientifica() const;
	/*
	 * @brief Retorna vetor com as sub areas
	 * @return Vector subAreas
	 */
	std::vector<SubAreaCientifica*> getsubAreas() const {return subAreas;};


	//outros metodos
	/*
	 * @brief Adiciona uma sub area cientifica ao vetor de sub areas
	 * @param subArea sub area a adicionar
	 * @return void
	 */
	void addSubAreaCientifica(SubAreaCientifica* subArea);
	/*
	 * @brief Imprime a area cientifica na consola
	 * @return void
	 */
	void show(unsigned int i, unsigned int j) const;

	//friends
	friend class Associacao;

};

//excecoes

class SubAreaCientificaRepetida
{
private:
	SubAreaCientifica* subArea;
public:
	/*
	 * @brief Construtor da excecao lancada por sub area repetida
	 * @param subArea Especifica a sub area repetida
	 * @return void
	 */
	SubAreaCientificaRepetida(SubAreaCientifica* subArea);
};




#endif
