/*
 * cota.h
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#ifndef CODE_COTA_H_
#define CODE_COTA_H_

class Cota
{
private:
	bool emDia;
	unsigned int atraso;

public:
	//construtor
	Cota(bool emDia,unsigned int atraso);

	//métodos set
	void setEmDia(bool emDia);
	void setAtraso(unsigned int atraso);

	//métodos get
	bool getEmDia() const;
	unsigned int getAtraso() const;

};

#endif /* CODE_COTA_H_ */
