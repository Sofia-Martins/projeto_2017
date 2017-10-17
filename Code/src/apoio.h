/*
 * apoio.h
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#ifndef APOIO_H_
#define APOIO_H_

#include <string>


class Apoio
{
private:
	bool apoioAssociacao;
	std::string tipoApoio;

public:
	//Construtor
	Apoio (bool ApoioAssociacao, std::string tipoApoio);

	//Metodos Set
	void setApoioAssociacao(bool apoioAssociacao);
	void setTipoApoio(std::string tipoApoio);

	//Metodos Get
	bool getApoioAssociacao() const;
	std::string getTipoApoio() const;
};

#endif /* APOIO_H_ */
