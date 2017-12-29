/*
* evento.h
*
*  Created on: 17/10/2017
*      Author: Tiago Rodrigues
*/

#ifndef EVENTO_H_
#define EVENTO_H_

#include "associado.h"
#include "data.h"
#include "apoio.h"
#include <string>
#include <vector>


///////////////////////////////////////////////// EVENTO //////////////////////////////////////////////////////////////////////////

class Evento {

private:
	std::vector<unsigned int> planeadores;
	std::vector<unsigned int> organizadores;
	std::string local;
	std::string tema;
	Data data;
	Apoio apoioEvento;

protected:
	int numContributers;
	int numSubscribers;

public:
	// Construtor
	/**
	 * @brief Construtor com parâmetros
	 * @param planeadores Vetor com os planeadores do evento
	 * @param organizadores Vetor com os organizadores do evento
	 * @param local Especifica local do evento
	 * @param tema Especifica tema do evento
	 * @param data Especifica data do evento
	 * @param apoioEvento Especifica se o evento e apoiado ou nao
	 */
	Evento(std::vector <unsigned int> planeadores, std::vector<unsigned int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento);

	// Metodos get
	/**
	 * @brief Retorna valor do atributo planeadores
	 * @return Valor do atributo planeadores
	 */
	std::vector<unsigned int> getPlaneadores() const;
	/**
	 * @brief Retorna valor do atributo organizadores
	 * @return Valor do atributo organizadores
	 */
	std::vector<unsigned int> getOrganizadores() const;
	/**
	 * @brief Retorna valor do atributo local
	 * @return Valor do atributo local
	 */
	std::string getLocal() const;
	/**
	 * @brief Retorna valor do atributo tema
	 * @return Valor do atributo tema
	 */
	std::string getTema() const;
	/**
	 * @brief Retorna valor do atributo data
	 * @return Valor do atributo data
	 */
	Data getData() const;
	/**
	 * @brief Funcao virtual para o retorno dos atributo formadores, na sub class escola de verao
	 * @return Valor do atributo nomeSubArea
	 */
	virtual std::vector<unsigned int> getFormadores() const { return {}; }
	/**
	 * @brief Retorna valor do atributo apoioEvento
	 * @return Valor do atributo apoioEvento
	 */
	Apoio getApoioEvento() const;


	// Metodos set
	/**
	 * @brief Atribui valor do argumento ao atributo local
	 * @param local Valor que será atribuído ao atributo local
	 * @return void
	 */
	void setLocal(std::string local);
	/**
	 * @brief Atribui valor do argumento ao atributo tema
	 * @param tema Valor que será atribuído ao atributo tema
	 * @return void
	 */
	void setTema(std::string tema);
	/**
	 * @brief Atribui valor do argumento ao atributo apoioEvento
	 * @param apoio Valor que será atribuído ao atributo apoioEvento
	 * @return void
	 */
	void setApoio(Apoio apoio);


	// Outros metodos

	/**
	 * @brief Funcao virtual para imprimir cada um dos tipos de eventos
	 */
	virtual void show() const;
	/**
	 * @brief Adiciona o planeador especificado ao atributo planeadores
	 * @param planeador Especifica planeador a adicionar
	 * @return void
	 */
	void addPlaneador(unsigned int planeador);
	/**
	 * @brief Adiciona o organizador especificado ao atributo organizadores
	 * @param organizador Especifica organizador a adicionar
	 * @return void
	 */
	void addOrganizador(unsigned int organizador);
	/**
	 * @brief Remove o planeador especificado do atributo planeadores
	 * @param planeador Especifica planeador a remover
	 * @return void
	 */
	void removePlaneador(unsigned int planeador);
	/**
	 * @brief Remove o organizador especificado do atributo organizadores
	 * @param organizador Especifica organizador a remover
	 * @return void
	 */
	void removeOrganizador(unsigned int organizador);
	/**
	 * @brief Funcao virtual para obter numero de participantes de cada tipo de evento
	 */
	virtual unsigned int getNumeroParticipantes() const { return 0; }
	/**
	 * @brief Funcao virtual para remover formador da sub class escola de verao
	 */
	virtual void removeFormador(unsigned int formador) {}
	/**
	 * @brief Funcao virtual para verificar o tipo de evento
	 */
	virtual bool escolaVerao() { return false;}
	/**
	 * @brief Atribui valor do argumento ao atributo numContributers
	 * @param num Valor que será atribuído ao atributo numContributers
	 * @return void
	 */
	void setNumContributers(int num) { numContributers = num; }
	/**
	 * @brief Atribui valor do argumento ao atributo numSubscribers
	 * @param num Valor que será atribuído ao atributo numSubscribers
	 * @return void
	 */
	void setNumSubscribers(int num) { numSubscribers = num; }



};


////////////////////////////////////////////// CONFERENCIA ////////////////////////////////////////////////////////////////////////


class Conferencia : public Evento {

private:
	unsigned int numeroParticipantes;

public:
	// Construtor
	/**
	 * @brief Construtor com parâmetros
	 * @param planeadores Vetor com os planeadores da conferencia
	 * @param organizadores Vetor com os organizadores da conferencia
	 * @param local Especifica local da conferencia
	 * @param tema Especifica tema da conferencia
	 * @param data Especifica data da conferencia
	 * @param apoioEvento Especifica se a conferencia e apoiado ou nao
	 * @param numeroParticipantes Especifica o numero de participantes
	 */
	Conferencia(std::vector<unsigned int> planeadores, std::vector<unsigned int> organizadores, std::string local, std::string tema, Data data, Apoio apoioEvento, unsigned int numeroParticipantes);

	// Metodos get
	/**
	 * @brief Retorna valor do atributo numeroParticipantes
	 * @return Valor do atributo numeroParticipantes
	 */
	unsigned int getNumeroParticipantes() const;

	// Metodos set
	/**
	 * @brief Atribui valor ao atributo numeroParticipantes
	 * @param numeroParticipantes Especifica o valor do atributo numeroParticipantes
	 */
	void setNumeroParticipantes(unsigned int numeroParticipantes);

	//outros metodos
	/**
	 * @brief Imprime a conferencia na consola
	 */
	void show() const;
	/**
	 * @brief Retorna false pois nao e uma escola de verao
	 * @return false
	 */
	bool escolaVerao() { return false; }
	/**
	 * @brief Retorna valor do atributo numContributers
	 * @return Valor do atributo numContributers
	 */
	int getNumContributers() const { return Evento::numContributers; }
	/**
	 * @brief Retorna valor do atributo numSubscribers
	 * @return Valor do atributo numSubscribers
	 */
	int getNumSubscribers() const { return Evento::numSubscribers; }
	/**
	 * @brief Overloading do operador de menor
	 * @param c Conferencia a comparar
	 * @return true caso o parametro seja maior
	 */
	bool operator < (const Conferencia & c) const{

		if (this->getNumContributers() == c.getNumContributers())
			return this->getOrganizadores().size() < c.getOrganizadores().size() || this->getNumSubscribers() < c.getNumSubscribers();
		else return this->getOrganizadores().size() < c.getOrganizadores().size() || this->getNumContributers() < c.getNumContributers();

	}

};


////////////////////////////////////////////// ESCOLA DE VERAO ////////////////////////////////////////////////////////////////////


class EscolaVerao : public Evento {

private:
	std::vector <unsigned int> formadores;

public:
	//Construtor
	/**
	 * @brief Construtor com parâmetros
	 * @param planeadores Vetor com os planeadores da conferencia
	 * @param organizadores Vetor com os organizadores da conferencia
	 * @param local Especifica local da conferencia
	 * @param tema Especifica tema da conferencia
	 * @param data Especifica data da conferencia
	 * @param apoioEvento Especifica se a conferencia e apoiado ou nao
	 * @param formadores Vetor com os formadores da escola de verao
	 */
	EscolaVerao(std::vector <unsigned int> planeadores,
		std::vector<unsigned int> organizadores,
		std::string local,
		std::string tema,
		Data data,
		Apoio apoioEvento,
		std::vector<unsigned int> formadores);

	// Metodos get
	/**
	 * @brief Retorna valor do atributo formadores
	 * @return Valor do atributo formadores
	 */
	std::vector<unsigned int> getFormadores() const;

	// Outros metodos
	/**
	 * @brief Imprime a escola de verao na consola
	 */
	void show() const;
	/**
	 * @brief Adiciona o formador especificado ao atributo formadores
	 * @param formador Especifica formador a adicionar
	 * @return void
	 */
	void addFormador(unsigned int formador);
	/**
	 * @brief Remove o formador especificado do atributo formadores
	 * @param formador Especifica formador a remover
	 * @return void
	 */
	void removeFormador(unsigned int formador);
	/**
	 * @brief Retorna true pois e uma escola de verao
	 * @return true
	 */
	bool escolaVerao() { return true; }
	/**
	 * @brief Retorna valor do atributo numContributers
	 * @return Valor do atributo numContributers
	 */
	int getNumContributers() const { return Evento::numContributers; }
	/**
	 * @brief Retorna valor do atributo numSubscribers
	 * @return Valor do atributo numSubscribers
	 */
	int getNumSubscribers() const { return Evento::numSubscribers; }
	/**
	 * @brief Overloading do operador de menor
	 * @param e Escola de Verao a comparar
	 * @return true caso o parametro seja maior
	 */
	bool operator < (const EscolaVerao & e) const {

		if (this->getNumContributers() == e.getNumContributers())
			return this->getOrganizadores().size() < e.getOrganizadores().size() || this->getNumSubscribers() < e.getNumSubscribers();
		else return this->getOrganizadores().size() < e.getOrganizadores().size() || this->getNumContributers() < e.getNumContributers();

	}


};


#endif
