/*
* email.h
*
*  Created on: 14/10/2017
*      Author: sofia
*/


#ifndef CODE_SRC_EMAIL_H_
#define CODE_SRC_EMAIL_H_

///////////////////
#include<string>
//////////////////


class Email
{
private:
	std::string remetente;  //email do remetente
	std::string destinatario;  //email do destinatario
	std::string conteudo;

public:
	//construtor
	Email(std::string remetente, std::string destinatario, std::string conteudo);

	//metodos set
	void setRemetente(std::string remetente);
	void setDestinatario(std::string destinatario);
	void setConteudo(std::string conteudo);

	//metodos get
	std::string getRemetente() const;
	std::string getDestinatario() const;
	std::string getConteudo() const;
};




#endif /* CODE_SRC_EMAIL_H_ */