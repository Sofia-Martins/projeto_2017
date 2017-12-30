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
	/**
	 * @brief Nome da sub-área científica
	 */
	std::string nomeSubArea;

public:
	/**
	 * @brief Construtor sem parâmetros
	 *
	 * Atribui 'string vazia' ao atributo nomeSubArea
	 */
	SubAreaCientifica() { nomeSubArea = ""; }
	/**
	 * @brief Construtor com parâmetros
	 * @param nomeSubArea Nome da sub-área científica que se pretende criar
	 */
	SubAreaCientifica(std::string nomeSubArea);
	/**
	 * @brief Atribui valor do argumento ao atributo nomeSubArea
	 * @param nomeSubArea Valor que será atribuído ao atributo nomeSubArea
	 * @return void
	 */
	void setNomeSubAreaCientifica(std::string nomeSubArea);
	/**
	 * @brief Retorna valor do atributo nomeSubArea
	 * @return Valor do atributo nomeSubArea
	 */
	std::string getNomeSubAreaCientifica() const;
	/**
	 * @brief Imprime a sub-área científica na consola
	 */
	void show() const;
    /**
     * @brief Class amiga Associacao
     * @relates Associacao
     */
	friend class Associacao;
	
};



#endif /* CODE_SRC_SUBAREACIENTIFICA_H_ */
