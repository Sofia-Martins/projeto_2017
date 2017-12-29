/*
* associacao.cpp
*
*  Created on: 17/10/2017
*      Author: luisa
*/


#include "associacao.h"

Associacao::Associacao() {

	this->dominioAssociacao = NULL;
	this->eventos = {};
	this->emails = {};
	this->associados = {};
	this->gestores = {};
	this->id = 0;
}


Associacao::Associacao(std::string nome, std::vector<Evento*> eventos,
	std::vector<Email*> emails, std::set<Associado*, AssociadoCmp> associados, std::vector<Gestor*> gestores) {
	this->dominioAssociacao = NULL;
	this->nome = nome;
	this->eventos = eventos;
	this->emails = emails;
	this->associados = associados;
	this->gestores = gestores;
	this->id = 0;
}


//metodos get
std::string Associacao::getNome() const {
	return this->nome;
}

std::string Associacao::getSigla() const
{
	return this->sigla;
}

std::vector<Email*> Associacao::getEmails() const {
	return this->emails;
}

bool equalGestor(Gestor* g1, Gestor* g2)
{
	return (g1->getID() == g2->getID());
}

HashTabAssociados Associacao::getApenasAssociados() const{
	return this->apenasAssociados;
}

/*
Gestor* Associacao::getGestor(int id) const
{
	Gestor* temp = new Gestor("", id, "", ""); //nome, id, password, email
	auto it = find_if(this->gestores.begin(), this->gestores.end(), temp,equalGestor);
	if()
}
*/
std::set<Associado*, AssociadoCmp>  Associacao::getAssociados() const {
	return this->associados;
}

std::vector<Gestor*> Associacao::getGestores() const {
	return this->gestores;
}

std::vector<Evento*> Associacao::getEventos() const {
	return this->eventos;
}
unsigned int Associacao::getID() const { return this->id; }

//metodos set
void Associacao::setNome(std::string nome) {
	this->nome = nome;
}

void Associacao::setSigla(std::string sigla)
{
	this->sigla = sigla;
}

void Associacao::setDominio(DominioCientifico* dominio)
{
	this->dominioAssociacao = dominio;
}
void Associacao::setID(unsigned int id)
{
	this->id = id;
}

void Associacao::setEventos(std::vector<Evento*> eventos) { this->eventos = eventos; }
void Associacao::setEmails(std::vector<Email*> emails) { this->emails = emails; }
void Associacao::setAssociados(std::set<Associado*, AssociadoCmp> associados) { this->associados = associados; }
void Associacao::setGestores(std::vector<Gestor*> gestores) { this->gestores = gestores; }


//outros metodos

void Associacao::showContributors() const
{
	std::cout << "--- CONTRIBUTORS ---" << std::endl;

	auto it = this->associados.begin();
	for (;it!=associados.end();it++)
	{
		auto associado = *it;

		if (associado->isContributor() == true)
		{
			std::cout << "ID: " << associado->getID() << std::endl;
			std::cout << "Instituicao: " << associado->getInstituicao() << std::endl;
			std::cout << "Nome: " << associado->getNome() << std::endl;
			std::cout << "Email: " << associado->getEmail() << std::endl << std::endl;
		}
	}
}

void Associacao::showSubscribers() const
{
	std::cout << "--- SUBSCRIBERS ---" << std::endl;
	auto it = this->associados.begin();
	for (;it!=associados.end();it++)
	{
		auto associado = *it;

		if (associado->isSubscriber() == true)
		{
			std::cout << "ID: " << associado->getID() << std::endl;
			std::cout << "Instituicao: " << associado->getInstituicao() << std::endl;
			std::cout << "Nome: " << associado->getNome() << std::endl;
			std::cout << "Email: " << associado->getEmail() << std::endl << std::endl;
		}
	}
}

void Associacao::showGestores() const
{
	std::cout << "--- GESTORES ---" << std::endl;
	for (unsigned int i = 0; i < gestores.size(); i++)
	{
			auto gestor = gestores.at(i);

			std::cout << "ID: " << gestor->getID() << std::endl;
			std::cout << "Nome: " << gestor->getNome() << std::endl;
			std::cout << "Email: " << gestor->getEmail() << std::endl << std::endl;
		}
}
unsigned int Associacao::incIdAssociados(){
	//auto id_disponivel = this->id;
	id++;
	return id;
}
void Associacao::showInteressesOutrosAssociados() const
{
	//fun��o que mostra os interesses cientificos de todos os associados, exceto do associado com o ID id

	typedef std::vector<std::pair< unsigned int, std::string >> vetorInfo; //vetor de informa��es dos associados
																		  //cada elemento do vetor � um par que cont�m
																		  //o id do associado e o respetivo nome

	typedef	std::vector<std::pair<std::string, vetorInfo>> subAreasAssociados; //vetor que cont�m a correspond�ncia entre
																			  //as sub�reas e os associados que partilham interesse por essa
																			  //mesma sub�rea

	subAreasAssociados interesses;

	// Primeiro passo - Inicializar a subArea de cada par 
	auto ciencias = this->dominioAssociacao->ciencias;

	for (unsigned int i = 0; i < ciencias.size(); i++)
	{
		auto cienciaAtual = ciencias.at(i);
		auto areas = cienciaAtual->areas;

		for (unsigned int j = 0; j < areas.size(); j++)
		{
			auto areaAtual = areas.at(j);
			auto subAreas = areaAtual->subAreas;

			for (unsigned int k = 0; k < subAreas.size(); k++)
			{
				std::pair<std::string, vetorInfo> pair;
				pair.first = subAreas.at(k)->getNomeSubAreaCientifica();
				interesses.push_back(pair);  //adicionar o par ao vetor 'interesses'
			}
		}
	}

	// Segundo passo - Adicionar os associados ao vetor 'interesses'
	
	auto it = associados.begin();
	for (;it!=associados.end();it++)
	{
		auto associadoAtual = *it;

	

			std::vector<std::string> interessesAssociado = associadoAtual->getAreasInteresse();

			std::pair< unsigned int, std::string > infoAssociado;  //criar info do associado
			infoAssociado.first = associadoAtual->getID();
			infoAssociado.second = associadoAtual->getNome();

			//percorrer o vetor de subAreas de interesse do associado
			for (unsigned int j = 0; j < interessesAssociado.size(); j++)
			{

				//percorrer o vetor de interesses dos associados de modo a adicionar o associado atual � respetiva categoria
				for (unsigned int k = 0; k < interesses.size(); k++)
				{
					if (interesses.at(k).first == interessesAssociado.at(j))
					{
						interesses.at(k).second.push_back(infoAssociado); //adiciona o associado ao vetor
					}
				}
			
		}

	}

	unsigned int posicaoInteresses = 0; //posicao no vetor 'interesses'


		//mostrar os interesses dos associados
		for (unsigned int i = 0; i < ciencias.size(); i++)
		{
			auto areas = ciencias.at(i)->areas;
			std::cout << "|" << i + 1 << "| " << ciencias.at(i)->getNomeCiencia() << "\n";


			for (unsigned int j = 0; j < areas.size(); j++)
			{
				auto subAreas = areas.at(j)->subAreas;
				std::cout << "  |" << i + 1 << "." << j + 1 << "| " << areas.at(j)->getNomeAreaCientifica() << "\n";

				for (unsigned int k = 0; k < subAreas.size(); k++)
				{
					std::cout << "    |" << i + 1 << "." << j + 1 << "." << k + 1 << "| " << subAreas.at(k)->getNomeSubAreaCientifica() << "\n";
					vetorInfo associadosAtuais = interesses.at(posicaoInteresses).second;
					posicaoInteresses++;
					for (unsigned int m = 0; m < associadosAtuais.size(); m++)
					{
						//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						//SetConsoleTextAttribute(hConsole, 10);
						std::cout << "             " << std::setw(15)<<associadosAtuais.at(m).second << " (ID " << associadosAtuais.at(m).first << ")" << std::endl;
						//SetConsoleTextAttribute(hConsole, 7);
						
					}
				}
			}
		}
	
}


void Associacao::addEmail(Email* email) {

	auto remetente = email->getRemetente();
	auto destinatario = email->getDestinatario();
	emails.push_back(email);

	auto it = associados.begin();
	for (;it!=associados.end();it++)
	{
		auto associadoAtual = *it;

		if (associadoAtual->getEmail() == remetente)
			associadoAtual->enviarEmail(email);
		
		if (associadoAtual->getEmail() == destinatario)
			associadoAtual->receberEmail(email);
	}

	for (unsigned int i = 0; i < gestores.size(); i++)
	{
		if (gestores.at(i)->getEmail() == remetente)
			gestores.at(i)->enviarEmail(email);

		if (gestores.at(i)->getEmail() == destinatario)
			gestores.at(i)->receberEmail(email);
	}
}

void Associacao::addAssociado(Associado &associado) {
	associados.insert(&associado);
}

void Associacao::addApenasAssociado(Associado associado) {
	apenasAssociados.insert(associado);
}

void Associacao::eraseApenasAssociado(Associado associado) {
	apenasAssociados.erase(associado);
}

void Associacao::addGestor(Gestor &gestor) {
	gestores.push_back(&gestor);
}

void Associacao::addEvento(Evento &evento)
{
	eventos.push_back(&evento);

	if(!evento.getApoioEvento().getApoioAssociacao())
		pedidos.push(&evento);
}

void Associacao::eraseAssociado(Associado* associado, bool apagaEventos){

	//apagar associado do vetor de associados
	this->associados.erase(associado);

	//apagar associado dos eventos em que participa
	if (!apagaEventos)
		return;

	for (unsigned int i = 0; i < eventos.size(); i++)
	{
		auto planeadores = eventos.at(i)->getPlaneadores();
		auto organizadores = eventos.at(i)->getOrganizadores();
		auto posPlaneador = find(planeadores.begin(), planeadores.end(), associado->getID());
		auto posOrganizador = find(organizadores.begin(), organizadores.end(), associado->getID());

		if (posPlaneador != planeadores.end())
			eventos.at(i)->removePlaneador(associado->getID());

		if (eventos.at(i)->getPlaneadores().size() < 3) //os eventos têm de ter no mínimo 3 planeadores
		{
			eventos.erase(eventos.begin() + i);
			i--;
		}
		else
		{

			if (posOrganizador != organizadores.end())
				eventos.at(i)->removeOrganizador(associado->getID());

			if (eventos.at(i)->escolaVerao() == true)   //se esse evento for uma escola de Verao existe a possibilidade de esse 
														  //associado constar da lista de formadores
			{
				auto formadores = eventos.at(i)->getFormadores();
				auto posFormador = find(formadores.begin(), formadores.end(), associado->getID());

				if (posFormador != formadores.end())
					eventos.at(i)->removeFormador(associado->getID());
			}
		}
		
		
	}
}

void Associacao::showEventos(Associado* associado) const
{
	for (unsigned int i = 0; i < eventos.size(); i++)
	{
		auto evento = eventos.at(i);
		auto planeadores = evento->getPlaneadores();
		auto organizadores = evento->getOrganizadores();

		if (find(planeadores.begin(), planeadores.end(), associado->getID()) !=planeadores.end()) //se encontrou esse associado
		{
			evento->show();
			std::cout << std::endl;
		}
		else
		{
			if (find(organizadores.begin(), organizadores.end(), associado->getID()) != organizadores.end())
			{
				evento->show();
				std::cout << std::endl;
			}
		}
	}
}

bool Associacao::existeEmail(std::string email) const
{
	//verifica se o email existe e se pertence a um subscriber, contributor ou gestor
	auto it = associados.begin();
	for (;it!=associados.end();it++)
	{
		if ((*it)->getEmail() == email)
		{
			if(((*it)->isContributor()==true) || ((*it)->isSubscriber()==true))
			   return true;
		}
	}

	for (unsigned int i = 0; i < gestores.size(); i++)
	{
		if (gestores.at(i)->getEmail() == email)
			return true;
	}
	return false;
}

/*
void Associacao::organizaEmails()
{
	bool organizado = false;

	for (unsigned int i=0; i<this->emails.size(); i++)
	{
		std::cout << "Iteracao " << i+1 << std::endl;
		for (unsigned int j=0; j<associados.size(); j++)
		{
			if (emails.at(i)->getRemetente() == associados.at(j)->getEmail())
			{
				associados.at(j)->enviarEmail(emails.at(i));
				std::cout << "Fiz push para o vetor de emails enviados de " << associados.at(j)->getNome() << std::endl;
				organizado = true;
			}
			else if (emails.at(i)->getDestinatario() == associados.at(j)->getEmail())
			{
				associados.at(j)->receberEmail(emails.at(i));
				std::cout << "Fiz push para o vetor de emails recebidos de " << associados.at(j)->getNome()<< std::endl;
				organizado = true;
			}
			continue;
		}

		if (!organizado)
			for (unsigned int j = 0; j < gestores.size(); j++)
			{
				if (emails.at(i)->getRemetente() == gestores.at(j)->getEmail())
					gestores.at(j)->enviarEmail(emails.at(i));
				else if (emails.at(i)->getDestinatario()== gestores.at(j)->getEmail())
					gestores.at(j)->receberEmail(emails.at(i));
			}
	}
}
*/

void Associacao::showInteressesAssociado(Associado* associado) const
{
	
	auto interesses = associado->getAreasInteresse();  //vetor de subAreas de interesse do associado (vetor de strings)
	auto ciencias = dominioAssociacao->getCiencia();   //vetor de ciencias da associacao
	DominioCientifico dominioInteresse;
	

	for (unsigned int w = 0; w < interesses.size(); w++)
	{
		auto subAreaInteresseAtual = interesses.at(w);
		SubAreaCientifica* subAreaAdicionar = new SubAreaCientifica(subAreaInteresseAtual);

		for (unsigned int i = 0; i < ciencias.size(); i++)
		{
			auto cienciaAtual = ciencias.at(i);
			auto areas = cienciaAtual->getAreas();

			for (unsigned int j = 0; j < areas.size(); j++)
			{
				auto areaAtual = areas.at(j);
				auto subAreas = areaAtual->getsubAreas();

				for (unsigned int k = 0; k < subAreas.size(); k++)
				{
					if (subAreas.at(k)->getNomeSubAreaCientifica() == subAreaInteresseAtual)  //se encontrar a subArea de interesse no dominio da associacao
					{
						
						try
						{
							auto cienciaAdicionar = new Ciencia(cienciaAtual->getNomeCiencia());
							dominioInteresse.addCiencia(cienciaAdicionar);
						}
						catch (const CienciaRepetida& c)  //se essa ciencia ja pertencer ao dominio de interesse
						{

						}
						
							for (unsigned int l=0;l<dominioInteresse.ciencias.size();l++)
							{
								if (dominioInteresse.ciencias.at(l)->getNomeCiencia() == cienciaAtual->getNomeCiencia())
								{
									try
									{
										auto areaAdicionar = new AreaCientifica(areaAtual->getNomeAreaCientifica());
										dominioInteresse.ciencias.at(l)->addAreaCientifica(areaAdicionar);
									}
									catch (const AreaCientificaRepetida& a)
									{

									}

									for (unsigned int m = 0; m < dominioInteresse.ciencias.at(l)->areas.size(); m++)
									{
										if (dominioInteresse.ciencias.at(l)->areas.at(m)->getNomeAreaCientifica() == areaAtual->getNomeAreaCientifica())
										{
											try
											{
												dominioInteresse.ciencias.at(l)->areas.at(m)->addSubAreaCientifica(subAreaAdicionar);
											}
											catch(const SubAreaCientificaRepetida& s)
											{

											}
										}
									}
								}
							
						}
						
					}
				}
			}
		}
	}

	//mostrar o novo dominio
	dominioInteresse.show();
}

void Associacao::showAssociadosCategoria() const
{
	auto it = this->associados.begin();

	std::cout << "   ID" << "        " << "NOME" << std::endl << std::endl;

	std::cout << "--- CONTRIBUTORS ---------------\n\n";
	
	
	for (; it != associados.end(); it++)
	{
		Associado* associado = (*it);

		if (!(associado->isContributor()))
			break;

		std::cout << std::setw(5) << associado->getID() << "        " << associado->getNome() << std::endl;
	}
	std::cout<<std::endl;

	std::cout << "--- SUBSCRIBERS ----------------\n\n";
	

	for (; it != associados.end(); it++)
	{
		Associado* associado = (*it);

		if (!(associado->isSubscriber()))
			break;

		std::cout << std::setw(5) << associado->getID() <<"        " << associado->getNome() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- OUTROS ASSOCIADOS ----------\n\n";

	for (; it != associados.end(); it++)
	{
		Associado* associado = (*it);

		std::cout << std::setw(5) << associado->getID() << "        " << associado->getNome() << std::endl;
	}
	std::cout<<std::endl;

}

std::vector<unsigned int> Associacao::showAssociados(unsigned int id, bool ignorarAssociado) const
{
	std::vector<unsigned int> IDs;
	unsigned int contador = 1;
	auto it = associados.begin();

	for (;it!=associados.end();it++)
	{
		if (ignorarAssociado)
		{
			if ((*it)->getID() != id)
			{
				std::cout << contador << ". " << (*it)->getNome() << " (ID " << (*it)->getID() << ")\n";
				IDs.push_back((*it)->getID());
				contador++;
			}
		}
		else
		{
			std::cout << contador << ". " << (*it)->getNome() << " (ID " << (*it)->getID() << ")\n";
			IDs.push_back((*it)->getID());
			contador++;
		}
	}

	return IDs;
}

bool comparaAssociados(const Associado* a1, const Associado* a2)
{
	return (a1->getID() < a2->getID());
}

bool comparaGestores(const Gestor* g1, const Gestor* g2)
{
	return (g1->getID() < g2->getID());
}

void Associacao::sortGestores()
{
	sort(gestores.begin(), gestores.end(), comparaGestores);
}

bool comparaEventos(const Evento* e1, const Evento* e2)
{
	return (e1->getTema() < e2->getTema());
}

void Associacao::sortEventos()
{
	sort(eventos.begin(), eventos.end(), comparaEventos);
}

void Associacao::sortDominio()
{
	this->dominioAssociacao->sortCiencias();
}
AssociacaoRepetida::AssociacaoRepetida(std::string nome) {
	this->nome = nome;
}
