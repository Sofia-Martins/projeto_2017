/*
 * apoio.cpp
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#include "apoio.h"


	//Construtor
	Apoio::Apoio (bool ApoioAssociacao, std::string tipoApoio)
	{
		this->apoioAssociacao=ApoioAssociacao;
		this->tipoApoio=tipoApoio;
	}


	//Metodos Set

	void Apoio::setApoioAssociacao(bool apoioAssociacao)
	{
		this->apoioAssociacao=apoioAssociacao;
	}

	void Apoio::setTipoApoio(std::string tipoApoio)
	{
		this->tipoApoio=tipoApoio;
	}


	//Metodos Get

	bool Apoio::getApoioAssociacao() const
	{
		return apoioAssociacao;
	}

	std::string Apoio::getTipoApoio() const
	{
		return tipoApoio;
	}

