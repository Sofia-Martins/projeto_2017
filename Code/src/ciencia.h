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
#include <iostream>
#include <algorithm>  
/////////////////////////////


class Ciencia
{

private:
	/**
	 * @brief Nome da ciência
	 */
	std::string nomeCiencia;
	/**
	 * @brief Vetor de apontadores para as áreas cinetíficas que compõem a ciência
	 */
	std::vector<AreaCientifica*> areas;
public:
	/**
	 * @brief Construtor sem parâmetros da ciência
	 *
	 * Inicializa o atributo nomeCiencia com a string vazia
	 */
	Ciencia(){nomeCiencia = "";};
	/**
	 * @brief Construtor com parâmetros da classe Ciencia
	 * @param nomeCiencia Define o valor do atributo nomeCiencia
	 */
	Ciencia(std::string nomeCiencia);
	/**
	 * @brief Altera nome da ciência
	 * @param nomeCiencia Especifica novo valor do atributo nomeCiencia
	 * @return void
	 */
	void setNomeCiencia(std::string nomeCiencia);
	/**
	 * @brief Retorna valor do atributo nomeCiencia
	 * @return String nomeCiencia
	 */
	std::string getNomeCiencia() const;
	/**
	 * @brief Retorna vetor de areas da ciencia
	 * @return Vector areas
	 */
	std::vector<AreaCientifica*> getAreas() const{return areas;};
	/**
	 * @brief Adiciona uma area cientifica ao vetor de areas
	 * @param area area a adicionar
	 * @return void
	 */
	void addAreaCientifica(AreaCientifica* area);
	/**
	 * @brief Imprime a ciencia na consola
	 * @return void
	 */
	void show(unsigned int i) const;
	/**
	*@brief Organiza vetor de áreas científicas
	*@return void
	*/
	void sortAreas();

	friend class Associacao;
};



class AreaCientificaRepetida
{
private:
	/**
     * @brief Apontador para a área científica que se repete
     */
	AreaCientifica* area;
public:
	/**
	 * @brief Construtor da area cientifica repetida
	 * @param area Especifica a area cientifica repetida
	 * @return void
	 */
	AreaCientificaRepetida(AreaCientifica* area);
};

/**
*@brief Função que compara duas áreas e que serve como função de comparação no algoritmo sort
*@param a1 Apontador para a primeira área
*@param a2 Apontador para a segunda área
*@return bool Retorna 'true' se o nome da área 's1' vier antes do nome da área 's2' (ordenação alfabética)
*/
bool comparaAreas(const AreaCientifica* a1, const AreaCientifica* a2);


#endif /* CODE_SRC_CIENCIA_H_ */
