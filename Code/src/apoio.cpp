/*
 * apoio.cpp
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#include "apoio.h"



	//Construtor
	Apoio::Apoio(){
		this->apoioAssociacao = false;
		this->verba = 0;
	}
	Apoio::Apoio (bool apoioAssociacao, std::string tipoApoio, unsigned int verba)
	{
		this->apoioAssociacao=apoioAssociacao;
		this->tipoApoio=tipoApoio;
		this->verba = verba;
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


	//outros metodos
	void Apoio::show() const
	{
		if (apoioAssociacao)
		{
			std::cout << "    Evento apoiado " << std::endl;
			std::cout << "    Tipo de apoio: " << tipoApoio << std::endl;
			std::cout << "    Verba para o evento: " << verba << std::endl;
		}
		else
			std::cout << "    Evento nao apoiado " << std::endl;
	}
