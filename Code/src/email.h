/*
 * email.h
 *
 *  Created on: 14/10/2017
 *      Author: sofia
 */

#include<string>




#ifndef CODE_SRC_EMAIL_H_
#define CODE_SRC_EMAIL_H_


class Email
{
private:
	//Associado* remetente;
	//Associado* destinatario;
	std::string conteudo;

public:
	//construtor
	//Email(Associado* remetente,Associado* destinatario, string conteudo);

	//metodos set
	//void setRemetente(Associado* remetente);
	//void setDestinatario(Associado* destinatario);
	void setConteudo(std::string conteudo);

	//metodos get
	//Associado* getRemetente() const;
	//Associado* getDestinatario() const;
	std::string getConteudo() const;
};




#endif /* CODE_SRC_EMAIL_H_ */
