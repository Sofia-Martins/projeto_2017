/*
 * dominioCientifico.h
 *
 *  Created on: 15/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_DOMINIOCIENTIFICO_H_
#define CODE_SRC_DOMINIOCIENTIFICO_H_

/////////////////////////
#include <map>
#include <iostream>
#include <algorithm>             // std::binary_search
#include "ciencia.h"
////////////////////////

class DominioCientifico
{

private:
	/**
	 * @brief Vetor de apontadores para ciências (que compõem o domínio científico)
	 */
	std::vector<Ciencia*> ciencias;

public:
	/**
	 * @brief Construtor da classe DominioCientifico
	 */
	DominioCientifico(){ciencias = {};}
	/**
	 * @brief Permite adicionar ao atributo ciencias um apontador para uma nova ciência
	 * @param ciencia Apontador para a ciência que se pretende adicionar ao domínio científico
	 */
	void addCiencia(Ciencia* ciencia);
	/**
	 * @brief Retorna vetor de ciências que compõem o domínio científico
	 * @return Vetor de apontadores para ciências (cópia do atributo ciencias)
	 */
	std::vector<Ciencia*> getCiencia() const;
	/**
	 * @brief Atribui novo valor ao atributo ciencias
	 * @param ciencias Novo valor do atributo ciencias
	 * @return void
	 */
	void setCiencia(std::vector<Ciencia*> ciencias) {this->ciencias = ciencias;}
	/**
	 * @brief Imprime na consola o domínio científico
	 */
	void show() const;
	/**
	*@brief Organiza vetor de ciências
	*@return void
	*/
	void sortCiencias();
    /**
     * @brief Class amiga Associacao
     * @relates Associacao
     */
	friend class Associacao;
};


class CienciaRepetida
{
private:
	/**
	 * @brief Apontador para a ciência que se repete
	 */
	Ciencia* ciencia;
public:
	/**
	 * @brief Construtor da excecao lançada perante uma ciência repetida
	 * @param ciencia Especifica a ciência repetida
	 */
	CienciaRepetida(Ciencia* ciencia);
};

/**
*@brief Função que compara duas ciências e que serve como função de comparação no algoritmo sort
*@param a1 Apontador para a primeira ciência
*@param a2 Apontador para a segunda ciência
*@return bool Retorna 'true' se o nome da ciência 's1' vier antes do nome da ciência 's2' (ordenação alfabética)
*/
bool comparaCiencias(const Ciencia* c1, const Ciencia* c2);

#endif /* CODE_SRC_DOMINIOCIENTIFICO_H_ */
