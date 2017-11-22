/*
 * cota.h
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#ifndef CODE_SRC_COTA_H_
#define CODE_SRC_COTA_H_

class Cota
{
private:
	bool emDia;
	unsigned int atraso;

public:
	/**
	 * @brief Construtor da classe Cota
	 * @param emDia True se a cota do associado está em dia, False em caso contrário
	 * @param atraso Atraso (em anos) de pagamento da cota. 0 se a cota está em dia.
	 */
	Cota(bool emDia,unsigned int atraso);
	/**
	 * @brief Atribui valor ao atributo emDia
	 * @param emDia True se a cota do associado está em dia, False em caso contrário
	 * @return void
	 */
	void setEmDia(bool emDia);
	/**
	 * @brief Atribui valor ao atributo atraso
	 * @param atraso Atraso (em anos) de pagamento da cota.
	 * @return void
	 */
	void setAtraso(unsigned int atraso);
	/**
	 * @brief Retorna valor do atributo emDia
	 * @return Retorna True se a cota está em dia e False em caso contrário
	 */
	bool getEmDia() const;
	/**
	 * @brief Retorna valor do atributo atraso
	 * @return Retorna o atraso (em anos) de pagamento da cota.
	 */
	unsigned int getAtraso() const;

};

#endif
