/*
 * data.h
 *
 *  Created on: 17/10/2017
 *      Author: Tiago Rodrigues
 */

#ifndef DATA_H_
#define DATA_H_

#include <string>
#include<iostream>


class Data
{

private:
	unsigned int dia;
	unsigned int mes;
	int ano;
	unsigned int hora;
	unsigned int minuto;

public:

	/*
	 * @brief Construtor sem parâmetros da classe Data
	 *
	 * Coloca todos os atributos da classe Data a 0
	 *
	 */
	Data();
	/*
	 * @brief Construtor da classe Data
	 * @param dia Dia da data
	 * @param mes Mes da data
	 * @param ano Ano da data
	 * @param hora Hora da data
	 * @param minuto Minuto da data
	 */
	Data(unsigned int dia, unsigned int mes, int ano, unsigned int hora, unsigned int minuto);
	/*
	 * @brief Atribui valor ao atributo dia
	 * @param dia Especifica novo valor do atributo dia
	 * @return void
	 */
	void setDia (unsigned int dia);
	/*
	 * @brief Atribui valor ao atributo mes
	 * @param mes Especifica novo valor do atributo mes
	 * @return void
	 */
	void setMes (unsigned int mes);
	/*
	 * @brief Atribui valor ao atributo ano
	 * @param ano Especifica novo valor do atributo ano
	 * @return void
	 */
	void setAno (int ano);
	/*
	 * @brief Atribui valor ao atributo hora
	 * @param hora Especifica novo valor do atributo hora
	 * @return void
	 */
	void setHora (unsigned int hora);
	/*
	 * @brief Atribui valor ao atributo minuto
	 * @param minuto Especifica novo valor do atributo minuto
	 * @return void
	 */
	void setMinuto (unsigned int minuto);
	/*
	 * @brief Retorna a data em formato textual
	 * @return String data
	 */
	std::string getData() const;
	/*
	 * @brief Retorna valor do atributo dia
	 * @return Atributo dia
	 */
	unsigned int getDia () const;
	/*
	 * @brief Retorna valor do atributo mes
	 * @return Atributo mes
	 */
	unsigned int getMes () const;
	/*
	 * @brief Retorna valor do atributo ano
	 * @return Atributo ano
	 */
	unsigned int getAno () const;
	/*
	 * @brief Retorna valor do atributo hora
	 * @return Atributo hora
	 */
	unsigned int getHora () const;
	/*
	 * @brief Retorna valor do atributo minuto
	 * @return Atributo minuto
	 */
	unsigned int getMinuto () const;
	/*
	 * @brief Imprime a data na consola
	 * @return void
	 */
	void show() const;

};


#endif
