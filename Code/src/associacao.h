/*
* associacao.h
*
*  Created on: 17/10/2017
*      Author: luisa
*/

#ifndef ASSOCIACAO_H_
#define ASSOCIACAO_H_

#include <string>
#include <vector>
#include <algorithm>
#include "dominioCientifico.h"
#include "email.h"
#include "associado.h"
#include "gestor.h"
#include "evento.h"

class Associacao {
private:
	/**
	 * @brief Nome da associação científica
	 */
	std::string nome;
	/**
	 * @brief Sigla da associação científica
	 */
	std::string sigla;
	/**
	 * @brief Domínio científico da associação (conjunto de ciências da associação)
	 */
	DominioCientifico* dominioAssociacao;
	/**
	 * @brief Vetor de eventos criados pelos associados
	 */
	std::vector<Evento*> eventos;
	/**
	 * @brief Vetor de emails partilhados entre associados e gestores
	 */
	std::vector<Email*> emails;
	/**
	 * @brief Vetor de associados (subscribers, contributors, e associados sem outro estatuto)
	 */
	std::vector<Associado*> associados;
	/**
	 * @brief Vetor de gestores da associação
	 */
	std::vector<Gestor*> gestores;
	/**
	 * @brief ID do próximo gestor ou associado que for adicionado à associação
	 */
	unsigned int id;  //id do associado/gestor seguinte da associacao

public:
	/**
	 * @brief Construtor da classe associacao sem parametros
	 *
	 * Inicializa os paramentros vazios
	 *
	 * @return void
	 */
	Associacao();
	/**
	 * @brief Construtor da classe associacao
	 * @param nome Define o nome da associacao
	 * @param eventos Define o vetor de eventos
	 * @param emails Define o vetor de emails
	 * @param associados Define o vetor de associados
	 * @param gestores Define o vetor de gestores
	 * @return void
	 */
	Associacao(std::string nome, std::vector<Evento*> eventos, std::vector<Email*> emails,
		std::vector<Associado*> associados, std::vector<Gestor*> gestores);
	/**
	 * @brief Retorna valor do atributo nome
	 * @return String nome
	 */
	std::string getNome() const;
	/**
	 * @brief Retorna valor do atributo sigla
	 * @return String sigla
	 */
	std::string getSigla() const;
	/**
	 * @brief Retorna gestor de ID id
	 * @param id ID do gestor pedido
	 * @return Gestor gestor
	 */
	Gestor* getGestor(int id) const;
	/**
	 * @brief Retorna valor do atributo dominioAssociacao
	 * @return DominioCientifico dominioAssociacao
	 */
	DominioCientifico* getDominio() const { return dominioAssociacao; }
	/**
	 * @brief Retorna valor do vetor associados
	 * @return Vector associados
	 */
	std::vector<Associado*> getAssociados() const;
	/**
	 * @brief Retorna valor do vetor gestores
	 * @return Vector gestores
	 */
	std::vector<Gestor*> getGestores() const;
	/**
	 * @brief Retorna valor do vetor emails
	 * @return Vector emails
	 */
	std::vector<Email*> getEmails() const;
	/**
	 * @brief Retorna valor do vetor eventos
	 * @return Vector eventos
	 */
	std::vector<Evento*> getEventos() const;
	/**
	 * @brief Retorna valor do ID do associado
	 * @return Atributo id
	 */
	unsigned int getID() const;
	/**
	 * @brief Altera nome da associacao
	 * @param nome Especifica novo valor do nome
	 * @return void
	 */
	void setNome(std::string nome);
	/**
	 * @brief Altera sigla da associacao
	 * @param sigla Especifica novo valor da sigla
	 * @return void
	 */
	void setSigla(std::string sigla);
	/**
	 * @brief Altera nome do dominio da associacao
	 * @param dominio Especifica novo valor do dominio cientifico
	 * @return void
	 */
	void setDominio(DominioCientifico* dominio);
	/**
	 * @brief Altera id inicial para a associacao
	 * @param id Especifica novo valor do id
	 * @return void
	 */
	void setID(unsigned int id);
	/**
	 * @brief Altera vetor de emails da associacao
	 * @param emails Especifica novo valor do emails
	 * @return void
	 */
	void setEmails(std::vector<Email*> emails);
	/**
	 * @brief Altera vetor de associados da associacao
	 * @param associados Especifica novo valor do associadps
	 * @return void
	 */
	void setAssociados(std::vector<Associado*> associados);
	/**
	 * @brief Altera vetor de gestores da associacao
	 * @param gestores Especifica novo valor do gestores
	 * @return void
	 */
	void setGestores(std::vector<Gestor*> gestores);
	/**
	 * @brief Altera vetor de eventos da associacao
	 * @param eventos Especifica novo valor do eventos
	 * @return void
	 */
	void setEventos(std::vector<Evento*> eventos);
	/**
	 * @brief Adiciona email ao vetor de emails
	 * @param email Especifica email a adicionar
	 * @return void
	 */
	void addEmail(Email* email);
	/**
	 * @brief Adiciona associado ao vetor de associados
	 * @param associado Especifica associado a adicionar
	 * @return void
	 */
	void addAssociado(Associado &associado);
	/**
	 * @brief Apaga associado do vetor de associados
	 * @param associado Especifica associado a apagar
	 * @return void
	 */
	void eraseAssociado(Associado* associado);
	/**
	 * @brief Adiciona gestor ao vetor de gestores
	 * @param gestor Especifica gestor a adicionar
	 * @return void
	 */
	void addGestor(Gestor &gestor);
	/**
	 * @brief Adiciona evento ao vetor de eventos
	 * @param evento Especifica evento a adicionar
	 * @return void
	 */
	void addEvento(Evento &evento);
	/**
	 * @brief Incrementa id dos associados e devolve id seguinte
	 *
	 * @return Atributo id
	 */
	unsigned int incIdAssociados();
	/**
	 * @brief Imprime os eventos de um associado na consola
	 * @param associado Especifica associado do qual imprimir os eventos
	 * @return void
	 */
	void showEventos(Associado* associado) const;
	/**
	 * @brief Imprime os associados na consola com excecao dos de ID id, caso o ignorarAssociado seja true e devolve vetor sem esses associados
	 * @param id Especifica id dos associados a ignorar
	 * @param ignorarAssociados Valida o ignorar
	 * @return Vector IDs
	 */
	std::vector<unsigned int> showAssociados(unsigned int id, bool ignorarAssociado) const; //mostra todos os associados exceto aquele que tem o id 'id' (se ignorarAssociado==true)
	/**
	 * @brief Imprime os contributers na consola
	 * @return void
	 */
	void showContributors() const;
	/**
	 * @brief Imprime os subscribers na consola
	 * @return void
	 */
	void showSubscribers() const;
	/**
	 * @brief Imprime os gestores na consola
	 * @return void
	 */
	void showGestores() const;
	/**
	 * @brief Imprime os interesses dos associados na consola
	 * @return void
	 */
	void showInteressesOutrosAssociados() const;
	/**
	 * @brief Verifica se o email recebido como string existe no vetor emails
	 * @param email Especifica email a procurar
	 * @return Atributo bool
	 */
	bool existeEmail(std::string email) const;
	/**
	 * @brief Atribui os emails aos respetivos remetentes e destinatarios
	 * @return void
	 */
	void organizaEmails();
	/**
	 * @brief Imprime os interesses de um associado na consola
	 * @param associado Especifica o associado para imprimir os interesses
	 * @return void
	 */
	void showInteressesAssociado(Associado* associado) const;
};



class AssociacaoRepetida
{
private:
	/**
	 * @brief Nome da associação que se repete
	 */
	std::string nome;
public:
	/**
	 * @brief Construtor da classe associacao repetida
	 * @param nome Especifica o nome da associação que se repete
	 * @return void
	 */
	AssociacaoRepetida(std::string nome);
};


#endif
