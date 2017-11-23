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
	/**
	 * @brief Remetente do email
	 */
	std::string remetente;
	/**
	 * @brief Destinatário do email
	 */
	std::string destinatario;
	/**
	 * @brief Conteúdo textual do email
	 */
	std::string conteudo;

public:
	/**
	 * @brief Construtor da classe
	 * @param remetente Remetente do novo email
	 * @param destinatario Destinatário do novo email
	 * @param conteudo Conteúdo textual do novo email
	 */
	Email(std::string remetente, std::string destinatario, std::string conteudo);
	/**
	 * @brief Atribui novo valor ao atributo remetente
	 * @param remetente Novo valor do atributo remetente
	 * @return void
	 */
	void setRemetente(std::string remetente);
	/**
	 * @brief Atribui novo valor ao atributo destinatario
	 * @param destinatario Novo valor do atributo destinatario
	 * @return void
	 */
	void setDestinatario(std::string destinatario);
	/**
	 * @brief Atribui novo valor ao atributo conteudo
	 * @param conteudo Novo valor do atributo conteudo
	 * @return void
	 */
	void setConteudo(std::string conteudo);
	/**
	 * @brief Retorna valor do atributo remetente
	 * @return Valor do atributo remetente
	 */
	std::string getRemetente() const;
	/**
	 * @brief Retorna valor do atributo destinatario
	 * @return Valor do atributo destinatario
	 */
	std::string getDestinatario() const;
	/**
	 * @brief Retorna valor do atributo conteudo
	 * @return Valor do atributo conteudo
	 */
	std::string getConteudo() const;
};

#endif /* CODE_SRC_EMAIL_H_ */
