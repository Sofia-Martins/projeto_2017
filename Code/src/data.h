/*
 * data.h
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#ifndef DATA_H_
#define DATA_H_

#include <string>


class Data
{

private:
	unsigned int dia;
	unsigned int mes;
	int ano;
	unsigned int hora;
	unsigned int minuto;

public:

	//Construtor
	Data (unsigned int dia, unsigned int mes, int ano, unsigned int hora, unsigned int minuto);

	//Metodos Set
	void setDia (unsigned int dia);
	void setMes (unsigned int mes);
	void setAno (int ano);
	void setHora (unsigned int hora);
	void setMinuto (unsigned int minuto);

	//Metodos Get
	std::string getData() const;
	unsigned int getDia () const;
	unsigned int getMes () const;
	unsigned int getAno () const;
	unsigned int getHora () const;
	unsigned int getMinuto () const;

};


#endif /* DATA_H_ */
