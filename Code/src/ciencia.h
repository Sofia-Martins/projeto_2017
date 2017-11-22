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
	std::string nomeCiencia;
	std::vector<AreaCientifica*> areas;
public:
	//construtor
	/*
	 * @brief Construtor da ciencia sem parametros
	 *
	 * Inicializa o nomeCiencia com a string vazia
	 *
	 * @return void
	 */
	Ciencia(){nomeCiencia = "";};
	/*
	 * @brief Construtor da classe ciencia
	 * @param nomeCiencia Define o nome da ciencia
	 * @return void
	 */
	Ciencia(std::string nomeCiencia);

	//metodos set
	/*
	 * @brief Altera nome da ciencia
	 * @param nomeCiencia Especifica novo valor do nome da ciencia
	 * @return void
	 */
	void setNomeCiencia(std::string nomeCiencia);

	//metodos get
	/*
	 * @brief Retorna valor do atributo nomeCiencia
	 * @return String nomeCiencia
	 */
	std::string getNomeCiencia() const;
	/*
	 * @brief Retorna vetor de areas da ciencia
	 * @return Vector areas
	 */
	std::vector<AreaCientifica*> getAreas() const{return areas;};

	//outros metodos
	/*
	 * @brief Adiciona uma area cientifica ao vetor de areas
	 * @param area area a adicionar
	 * @return void
	 */
	void addAreaCientifica(AreaCientifica* area);
	/*
	 * @brief Imprime a ciencia na consola
	 * @return void
	 */
	void show(unsigned int i) const;

	//friends
	friend class Associacao;
};

//excecoes

class AreaCientificaRepetida
{


private:
	AreaCientifica* area;
public:
	/*
	 * @brief Construtor da area cientifica repetida
	 * @param area Especifica a area cientifica repetida
	 * @return void
	 */
	AreaCientificaRepetida(AreaCientifica* area);
};



#endif /* CODE_SRC_CIENCIA_H_ */
