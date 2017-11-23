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


#endif /* CODE_SRC_DOMINIOCIENTIFICO_H_ */
