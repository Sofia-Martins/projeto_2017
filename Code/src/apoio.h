/*
 * apoio.h
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#ifndef APOIO_H_
#define APOIO_H_

#include <string>
#include <iostream>


class Apoio
{
private:
	bool apoioAssociacao;
	std::string tipoApoio;
	unsigned int verba;

public:
	/**
	 *@brief Construtor da classe Apoio
	 *@param apoioAssociacao se existe ou nao apoio
	 *@param tipoApoio caso exista, o tipo de apoio, senao string vazia
	 */
	Apoio(bool apoioAssociacao, std::string tipoApoio, unsigned int verba);
	/**
	 *@brief Construtor sem parâmetros da classe Apoio
	 *
	 *Coloca o apoioAssociacao a false, e mantém a string vazia
	 */
	Apoio();
	/**
	 * @brief Muda booleano do apoioAssociacao
	 * @param apoioAssociacao Especifica novo valor do apoioAssociacao
	 * @return void
	 */
	void setApoioAssociacao(bool apoioAssociacao);
	/**
	 * @brief Atribuiu string ao tipo Apoio
	 * @param tipoApoio Especifica novo valor do tipo de apoio
	 * @return void
	 */
	void setTipoApoio(std::string tipoApoio);

	void setVerbaEvento(unsigned int verba) { this->verba = verba; }
	/**
	 * @brief Retorna valor do tipo apoio associacao
	 * @return Bool apoioAssociacao
	 */
	bool getApoioAssociacao() const;
	/**
	 * @brief Retorna string do tipo apoio
	 * @return String tipoApoio
	 */
	std::string getTipoApoio() const;

	unsigned int getVerbaEvento() const { return verba; }
	/**
	 * @brief Imprime o apoio na consola
	 * @return void
	 */
	void show() const;
};

#endif
