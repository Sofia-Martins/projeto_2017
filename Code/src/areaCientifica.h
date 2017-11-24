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
	/**
	 *@brief Nome da área cientifica
	 */
	std::string nomeArea;
	/**
	 * @brief Vetor de sub-áreas cientificas da área cientifica
	 */
	std::vector<SubAreaCientifica*> subAreas;

public:
	/**
	 * @brief Construtor sem parâmetros da classe AreaCientifica
	 *
	 * Coloca o nomeArea igual a string vazia
	 *
	 */
	AreaCientifica(){nomeArea = {};};
	/**
	 * @brief Construtor da classe AreaCientifica
	 * @param nomeArea Define nome da area
	 * @return void
	 */
	AreaCientifica(std::string nomeArea);
	/**
	 * @brief Altera nome da area cientifica
	 * @param nomeArea Especifica novo valor do nome da area
	 * @return void
	 */
	void setNomeAreaCientifica(std::string nomeArea);
	/**
	 * @brief Retorna valor do atributo nomeArea
	 * @return String nomeArea
	 */
	std::string getNomeAreaCientifica() const;
	/**
	 * @brief Retorna vetor com as sub areas
	 * @return Vector subAreas
	 */
	std::vector<SubAreaCientifica*> getsubAreas() const {return subAreas;};
	/**
	 * @brief Adiciona uma sub area cientifica ao vetor de sub areas
	 * @param subArea sub area a adicionar
	 * @return void
	 */
	void addSubAreaCientifica(SubAreaCientifica* subArea);
	/**
	 * @brief Imprime a area cientifica na consola
	 * @return void
	 */
	void show(unsigned int i, unsigned int j) const;
	/**
	*@brief Organiza vetor de subáreas
	*@return void
	*/
	void sortSubAreas();

	friend class Associacao;

};


class SubAreaCientificaRepetida
{
private:
	/**
	 * @brief Apontador para a sub-área que se repete
	 */
	SubAreaCientifica* subArea;
public:
	/**
	 * @brief Construtor da excecao lançada perante uma sub área repetida
	 * @param subArea Especifica a sub área repetida
	 */
	SubAreaCientificaRepetida(SubAreaCientifica* subArea);
};

/**
*@brief Função que compara duas subáreas e que serve como função de comparação no algoritmo sort
*@param a1 Apontador para a primeira subárea
*@param a2 Apontador para a segunda subárea
*@return bool Retorna 'true' se o nome da subárea 's1' vier antes do nome da subárea 's2' (ordenação alfabética)
*/
bool comparaSubAreas(const SubAreaCientifica* s1, const SubAreaCientifica* s2);


#endif
