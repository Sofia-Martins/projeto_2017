/*
* associacaoMS.h
*
*  Created on: 17/10/2017
*      Author: luisa
*/

#ifndef ASSOCIACAOMS_H_
#define ASSOCIACAOMS_H_


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <climits>
#include <utility>  //std::pair
#include <algorithm>
#include <iomanip>
#include "associacao.h"
#include "associado.h"
#include "areaCientifica.h"
#include "dominioCientifico.h"
#include "subAreaCientifica.h"


class AssociacaoMS {
private:
	/**
	 * @brief Associação a ser gerida pelo objeto do tipo AssociacaoMS
	 */
	Associacao* associacao;
	/**
	 * @brief Nome do ficheiro que contém o nome e sigla de todas as associações criadas
	 */
	std::string ficheiroAssociacoes;
	/**
	 * @brief Nome do ficheiro que contém todos os associados da associação a ser gerida
	 */
	std::string ficheiroAssociados;
	/**
	 * @brief Nome do ficheiro que contém a informação sobre todas as conferências da associação a ser gerida
	 */
	std::string ficheiroConferencias;
	/**
	 * @brief Nome do ficheiro que contém o domínio científico da associação a ser gerida
	 */
	std::string ficheiroDominios;
	/**
	 * @brief Nome do ficheiro que contém todos os emails da associação a ser gerida
	 */
	std::string ficheiroEmails;
	/**
	 * @brief Nome do ficheiro que contém a informação sobre todas as escolas de verão da associação a ser gerida
	 */
	std::string ficheiroEscolasVerao;
	/**
	 * @brief Nome do ficheiro que contém todos os gestores da associação a ser gerida
	 */
	std::string ficheiroGestores;
	/**
	 * @brief Vetor que contém informações sobre todas as associações contidas no ficheiroAssociacoes
	 *
	 * Os pares são do tipo (sigla da associação,nome da associação)
	 */
	std::vector<std::pair<std::string, std::string > > associacoes;

public:

	/**
	 *@return void
	 *Menu que permite aceder às seguintes opções: criar uma associação e aceder a uma associação já existente
	 */
	void menuBemVindo();
	/**
	 *Função que permite detetar a opção selecionada no menuBemVindo
	 *@return void
	 */
	void menuBemVindoSelecao();
	/**
	 *Menu no qual o utilizador especifica o nome do ficheiro que contém as informações sobre todas as associações
	 *@param nomeFicheiroAssociacoes Nome do ficheiro que contém a informação sobre todas as associações criadas
	 *@return void
	 */
	void menuAbrirFicheiroAssociacoes(std::string & nomeFicheiroAssociacoes);
	/**
	 *Menu que permite ao utilizador criar uma associação (especificando o seu nome e sigla)
	 *@return void
	 */
	void menuCriaAssociacao();
	/**
	 *Função que atualiza o ficheiro das associações com as informações da associação criada
	 *@param nomeFicheiroAssociacoes Nome do ficheiro a ser atualizado
	 *@return void
	 */
	void enviarNovaAssociacaoFicheiro(std::string & nomeFicheiroAssociacoes);
	/**
	 *@brief Função que cria um novo gestor da associação (a associacao corresponde ao atributo 'associacao' da classe AssociacaoMS)
	 *@param siglaAssociacao Sigla da nova associação
	 *@param criaAssociacao Especifica se está a ser criada uma associação (nessa situação o gestor criado será o primeiro dessa associação)
	 *@param idMenu ID do gestor a ser criado. Será utilizado para invocar o menu do gestor.
	 *@return void
	 */
	void criaGestor (std::string siglaAssociacao,bool criaAssociacao, int idMenu);
	/**
	 * @param siglaAssociacao Sigla da nova associação
	 * @brief Função que cria os ficheiros que irão conter toda a informação sobre a nova associação
	 * @return void
	 */
	void criaFicheirosNovaAssociacao(std::string siglaAssociacao);
	/**
	 * @param nomeFicheiroGestores Nome do ficheiro dos gestores da associação
	 * @brief Função que envia a informação sobre um gestor para o ficheiro de gestores da associação
	 * @return void
	 */
	void enviarNovoGestorFicheiro(std::string & nomeFicheiroGestores);
	/**
	 * @brief Menu onde o utilizador especifica o nome do ficheiro que contém a informação sobre todas as associações
	 * @return void
	 */
	void menuFicheiroAssociacoes();
	/**
	 * @brief Menu onde é obtida a resposta do utilizador. Atualiza atributo ficheiroAssociacoes da classe AssociacaoMS.
	 * @return void
	 */
	void menuFicheiroAssociacoesSelecao();
	/**
	 * @brief Função que atualiza atributo associacoes da classe AssociacaoMS
	 * Faz leitura do ficheiro 'ficheiroAssociacoes' e guarda as informações daí obtidas no vetor associacoes
	 * @return void
	 */
	void lerAssociacoes();
	/**
	 * @brief Menu onde o utilizador escolhe a associação a que pertence
	 * @return void
	 */
	void menuAssociacoes();
	/**
	 * @brief Função que atualiza atributo dominioAssociacao da associação a ser gerida, com as informações obtidas do ficheiro ficheiroDominios
	 * @return void
	 */
	void lerDominios();
	/**
	 * @brief Função que atualiza atributo associados da associação a ser gerida, com as informações obtidas do ficheiro ficheiroAssociados
	 * @return void
	 */
	void lerAssociados();
	/**
	 * @brief Função que atualiza atributo emails da associação a ser gerida, com as informações obtidas do ficheiro ficheiroEmails
	 * @return void
	 */
	void lerEmails();
	/**
	 * Função que atualiza atributo eventos da associação a ser gerida, adicionando as informações obtidas do ficheiro ficheiroConferencias
	 * @return void
	 */
	void lerConferencias();
	/**
	 * Função que atualiza atributo eventos da associação a ser gerida, adicionando as informações obtidas do ficheiro ficheiroEscolasVerao
	 * @return void
	 */
	void lerEscolasVerao();
	/**
	 * Função que atualiza atributo gestores da associação a ser  gerida, com as informações obtidas do ficheiro ficheiroGestores
	 * @return void
	 */
	void lerGestores();
	/**
	 * Função que atualiza o ficheiro contendo a informação do domínio científico da associação a ser gerida. O ficheiro atualizado
	 * é o ficheiro de nome ficheiroDominios
	 * @return void
	 */
	void enviarDominios() const;
	/**
	 * Função que atualiza o ficheiro contendo a informação dos associados da associação a ser gerida. O ficheiro atualizado
	 * é o ficheiro de nome ficheiroAssociados
	 * @return void
	 */
	void enviarAssociados() const;
	/**
	 * Função que atualiza o ficheiro contendo a informação dos emails da associação a ser gerida. O ficheiro atualizado
	 * é o ficheiro de nome ficheiroEmails
	 *  @return void
	 */
	void enviarEmails() const;
	/**
	 * Função que atualiza o ficheiro contendo a informação das conferências da associação a ser gerida. O ficheiro atualizado
	 * é o ficheiro de nome ficheiroConferencias
	 * @return void
	 */
	void enviarConferencias() const;
	/**
	 * Função que atualiza ficheiro contendo a informação das escolas de verão da associação a ser gerida. O ficheiro atualizado
	 * é o ficheiro de nome ficheiroEscolasVerao
	 * @return void
	 */
	void enviarEscolasVerao() const;
	/**
	 *Menu no qual o utilizador especifica a tarefa que deseja efetuar: 'sign up', 'sign in' ou 'sair'
	 *@return void
	 */
	void menuLogin();
	/**
	 * @param id ID do utilizador
	 * @param pass Password do utilizador
	 * Função que verifica a validade dos parâmetros 'id' e 'password' fornecidos pelo utilizador aquando da operação 'sign in'
	 * @return void
	 */
	void getID(unsigned int id, std::string pass);
	/**
	 *
	 * Função que permite ao utilizador criar uma nova conta dentro da associação que está a ser gerida
	 * @return void
	 */
	void criaConta();
	/**
	 * @param id ID do gestor que efetuou o login
	 * Menu apresentado a um gestor da associação (logo após o login). O menu contém as opções: "Informacoes da minha conta",
	 * "Modificar a minha conta", "Apagar a minha conta", "Criar um novo gestor", "Modificar conta de um associado",
	 * "Apagar associado", "Apoiar evento", "Enviar email", "Terminar Sessao".
	 * A função reencaminha o utilizador para cada um dos menus respetivos.
	 *
	 * @return void
	 */
	void menuSessaoGestor(unsigned int id);
	/**
	 * @brief Função que verifica o tipo de associado com o ID 'id' e que reencaminha o associado('subscriber', 'contributor' ou associado sem outro estatuto) para o menu respetivo
	 * @param id ID do associado que efetuou o login
	 * @return void
	 */
	void menuSessaoAssociado(unsigned int id);
	/**
	 * @param associado Apontador para o associado que efetuou login (associado do tipo 'contributor')
	 * Menu apresentado a um 'contributor' da associação (logo após o login). O menu contém as opções: "Informacoes da minha conta",
	 * "Modificar a minha conta", "Apagar a minha conta", "Os meus interesses cientificos", "Adicionar subarea cientifica de interesse",
	 * "Eventos nos quais eu participo", "Emails Recebidos", "Emails Enviados", "Areas e subareas cientificas dos restantes associados",
	 * "Enviar email", "Criar evento", "Terminar Sessao".
	 *  A função reencaminha o utilizador para cada um dos menus respetivos.
	 * @return void
	 *
	 */
	void menuSessaoContributor(Associado* associado);
	/**
	 * @param associado Apontador para o associado que efetuou login
	 * @brief Função que permite ao associado modificar o seu perfil
	 * @return void
	 */
	void modificarConta(Associado* associado);
	/**
	 *@param associado Apontador para o associado que efetuou login (associado do tipo 'subscriber')
	 *Menu apresentado a um 'subscriber' da associação (logo após o login). O menu contém as opções: "Informacoes da minha conta",
	 *"Modificar a minha conta", "Apagar a minha conta", "Os meus interesses cientificos", "Adicionar subarea cientifica de interesse",
	 *"Eventos nos quais eu participo", "Emails Recebidos", " Areas e subareas cientificas dos restantes associados",
	 *"Criar evento", "Terminar Sessao".
	 *A função reencaminha o utilizador para cada um dos menus respetivos.
	 *
	 *@return void
	 */
	void menuSessaoSubscriber(Associado* associado);
	/**
	 * @param associado Apontador para o associado que efetuou login (associado sem outro estatuto)
	 * Menu apresentado a um associado (sem outro estatuto) da associação (logo após o login). O menu contém as opções: "Informacoes da minha conta",
	 * "Modificar a minha conta", "Apagar a minha conta", "Os meus interesses cientificos", "Adicionar subarea cientifica de interesse",
	 * "Eventos nos quais eu participo", "Areas e subareas cientificas dos restantes associados", "Terminar Sessao".
	 * A função reencaminha o utilizador para cada um dos menus respetivos.
	 *
	 * @return void
	 */
	void menuSessaoOther(Associado* associado);
	/**
	 * @param id ID do evento que passa a ser apoiado pela associação a ser gerida
	 * Função que permite atualizar o atributo 'apoio' de um evento da associação
	 * @return void
	 */
	void apoiarEvento(unsigned int id);
	/**
	 * @param gestor Gestor a ser alterado
	 * Função que permite a modificação do perfil de um gestor da associação
	 * @return void
	 */
	void alteraGestor(Gestor* gestor);
	/**
	 * @param id ID do associado cujo perfil será alterado
	 * Função que permite a modificação do perfil de um associado da associação
	 * @return void
	 */
	void alteraAssociado(unsigned int id);
	/**
	 * @param id ID do gestor que será apagado
	 * Função que permite apagar um gestor da associação
	 * @return void
	 */
	void apagaGestor(unsigned int id);
	/**
	 * @param id ID do gestor que será apagado
	 * Função que permite apagar um associado da associação
	 */
	void apagaAssociado(unsigned int id);
	/**
	 * @param associado Apontador para um utilizador ('contributor', 'subscriber', associado sem outro estatuto, ou 'gestor')
	 * Função que permite a um associado ou gestor enviar um email
	 * Atualiza conteúdo do atributo 'emails' da associação a ser gerida
	 * @return void
	 */
	template <class T> void envioEmail(T* associado);
	/**
	 * @param associado Apontador para um associado ('contributor', 'subscriber', associado sem outro estatuto)
	 * Função que imprime no ecrã os emails recebidos pelo associado especificado como argumento
	 * @return void
	 */
	template <class T> void visualizaEmailsRecebidos(T* associado);
	/**
	 * @param associado Apontador para um associado ('contributor', 'subscriber', associado sem outro estatuto)
	 * Função que imprime no ecrã os emails enviados pelo associado especificado como argumento
	 * @return void
	 */
	template <class T> void visualizaEmailsEnviados(T* associado);
	/**
	 * @param associado Apontador para um associado ('contributor', 'subscriber', associado sem outro estatuto)
	 * Função que permite adicionar uma sub-área científica ao conjunto de sub-áreas científicas de interesse do associado especificado como argumento
	 * @return void
	 */
	template <class T> void addSubareaCientificaInteresse (T* associado);
	/**
	 * @param associado Apontador para um associado ('contributor', 'subscriber', associado sem outro estatuto)
	 * Função que permite ao associado especificado como argumento adicionar um novo evento à associação
	 * @return void
	 */
	template <class T> void criarEvento(T* associado);
	/**
	 * Menu apresentado ao utilizador aquando do fecho da consola
	 * @return void
	 */
	void menuTermino();




};



#endif /* ASSOCIACAOMS_H_ */
