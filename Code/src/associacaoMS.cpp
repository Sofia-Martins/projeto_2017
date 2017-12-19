/*
* associacaoMS.cpp
*
*  Created on: 18/10/2017
*      Author: luisa
*/

#include "associacaoMS.h"


//declaracao de algumas funcoes

bool hasChar(std::string &string);
void eliminateSpaces(std::string &string);
void getString(std::string &string, const std::string question);
void getNumber(unsigned int &number, const std::string &question);
void clearScreen(); 

//variaveis globais
std::string retornoMenu = "/";

/*------------------------------------------- menu 1 ---------------------------------------------*/
void AssociacaoMS::menuBemVindo()
{
	//inicializar a associacao
	this->associacao = new Associacao();


	clearScreen(); //apagar conteudo do ecra

	std::cout << "---- BEM-VINDO AO GESTOR DE ASSOCIACOES CIENTIFICAS! ----\n\n";
	std::cout << "1. Criar associacao\n";
	std::cout << "2. Aceder a uma associacao ja existente\n\n";

	this->menuBemVindoSelecao();

}

void AssociacaoMS::menuBemVindoSelecao()
{

	unsigned int numeroOpcao = 0;

	do
	{
		getNumber(numeroOpcao, "Opcao: ");

		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuTermino();
		}

	} while (!((numeroOpcao == 1) || (numeroOpcao == 2)));

	if (numeroOpcao == 2)
		this->menuFicheiroAssociacoes();
	else if (numeroOpcao == 1)
		this->menuCriaAssociacao();

}
/*------------------------------------------- menu 2.2 -------------------------------------------*/

void AssociacaoMS::menuFicheiroAssociacoes() {
	clearScreen(); //apagar conteudo do ecra
	std::cout << "---- ESCOLHER FICHEIRO DAS ASSSOCIACOES ----\n\n";
	menuFicheiroAssociacoesSelecao(); //invocacao do metodo
}

void AssociacaoMS::menuFicheiroAssociacoesSelecao() {

	std::string nomeFicheiro;
	std::ifstream streamAssociacoes;

	do {
		getString(nomeFicheiro, "Por favor introduza o nome do ficheiro das associacoes (sem .txt): ");
		if (std::cin.eof())
		{
			std::cin.clear();
			menuBemVindo(); //se o utilizador inseriu CTRL+D
		}


		nomeFicheiro = nomeFicheiro + ".txt";
		std::cout << nomeFicheiro << "\n\n";
		streamAssociacoes.open(nomeFicheiro);
	} while (streamAssociacoes.fail());

	//se o ficheiro existir
	ficheiroAssociacoes = nomeFicheiro;
	lerAssociacoes();

	this->menuAssociacoes(); //selecionar associacao
}

void AssociacaoMS::lerAssociacoes()
{
	this->associacoes.clear();
	std::ifstream streamAssociacoes;
	std::string linhaFicheiro, siglaAssociacao, nomeAssociacao;
	streamAssociacoes.open(ficheiroAssociacoes);
	std::istringstream ssFicheiro;

	while (!streamAssociacoes.eof())
	{
		getline(streamAssociacoes, linhaFicheiro); //linha que tem a sigla e nome da associacao
		std::stringstream ssFicheiro(linhaFicheiro);
		getline(ssFicheiro, siglaAssociacao, ';');
		getline(ssFicheiro, nomeAssociacao);

		if(siglaAssociacao == "" || nomeAssociacao == "")
			break;

		eliminateSpaces(nomeAssociacao);
		eliminateSpaces(siglaAssociacao);

		//acrescentar a sigla e nome da associacao ao vetor associacoes
		associacoes.push_back(std::pair<std::string, std::string>(siglaAssociacao, nomeAssociacao));
	}

	streamAssociacoes.close();
}

/*------------------------------------------- menu 2.1 -------------------------------------------*/
void AssociacaoMS::menuAbrirFicheiroAssociacoes(std::string & nomeFicheiroAssociacoes) {

	std::string nomeFicheiro;
	std::ifstream streamAssociacoes;

	do {
		getString(nomeFicheiro, "Por favor introduza o nome do ficheiro das associacoes (sem .txt): ");
		if (std::cin.eof())
		{
			std::cin.clear();
			menuBemVindo(); //se o utilizador inseriu CTRL+D
		}

		nomeFicheiro = nomeFicheiro + ".txt";
		streamAssociacoes.open(nomeFicheiro);
	} while (streamAssociacoes.fail());

	//se o ficheiro existir
	ficheiroAssociacoes = nomeFicheiro;
	lerAssociacoes();
	std::cout << nomeFicheiro << "\n\n";

	nomeFicheiroAssociacoes = nomeFicheiro;

	streamAssociacoes.close();

}

void AssociacaoMS::menuCriaAssociacao() {

	std::string nomeFicheiroAssociacoes;

	clearScreen(); //apagar conteudo do ecra
	this->menuAbrirFicheiroAssociacoes(nomeFicheiroAssociacoes);

	clearScreen(); //apagar conteudo do ecra
	std::cout << "-------------- CRIAR ASSOCIACAO --------------\n\n";
	std::string nomeAssociacao, siglaAssociacao;
	bool encontrou = false;

	do {
		encontrou = false;

		getString(nomeAssociacao, "Nome: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuFicheiroAssociacoes();

		}
		getString(siglaAssociacao, "Sigla: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuFicheiroAssociacoes();
		}

		std::transform(siglaAssociacao.begin(), siglaAssociacao.end(),
				siglaAssociacao.begin(), ::tolower); //converter sigla para letras minusculas

		for (unsigned int i = 0; i < associacoes.size(); i++) {
			if (siglaAssociacao == associacoes.at(i).first) {
				encontrou = true;
				std::cout
						<< "A sigla '"<<siglaAssociacao<<"' esta a ser utilizada por outra associacao, por favor tente novamente."
						<< std::endl << std::endl;
			}

			if (nomeAssociacao == associacoes.at(i).second) {
				encontrou = true;
				std::cout << "A associacao já existe! " << std::endl
						<< std::endl;

			}
		}

	} while(encontrou);

	associacoes.push_back(std::pair<std::string, std::string>(siglaAssociacao, nomeAssociacao));

	this->enviarNovaAssociacaoFicheiro(nomeFicheiroAssociacoes);
	this->criaFicheirosNovaAssociacao(siglaAssociacao);
	this->criaGestor(siglaAssociacao,true,0);
}

void AssociacaoMS::enviarNovaAssociacaoFicheiro(std::string & nomeFicheiroAssociacoes) {

	std::ofstream streamAssociacoes;
	streamAssociacoes.open(nomeFicheiroAssociacoes);

	if (streamAssociacoes.is_open())
	{
		if (associacoes.size() > 1)

			for (unsigned int i = 0; i < associacoes.size(); i++)
			{
				if (i!=(associacoes.size()-1))
					streamAssociacoes << associacoes.at(i).first << ";" << associacoes.at(i).second << std::endl;
				else streamAssociacoes << associacoes.at(i).first << ";" << associacoes.at(i).second;
			}
		else streamAssociacoes << associacoes.at(0).first << ";" << associacoes.at(0).second;
	}

	else std::cout << "Falha ao abrir ficheiro de destino" << std::endl;
}

void AssociacaoMS::criaFicheirosNovaAssociacao(std::string siglaAssociacao){
	std::ofstream streamAssociados(siglaAssociacao + "_associados.txt");
	std::ofstream streamConferencias(siglaAssociacao+"_conferencias.txt");
	std::ofstream streamDominios(siglaAssociacao+"_dominios.txt");
	std::ofstream streamEmails(siglaAssociacao+"_emails.txt");
	std::ofstream streamEscolaVerao(siglaAssociacao+"_escolaVerao.txt");
}

void AssociacaoMS::criaGestor(std::string siglaAssociacao, bool criaAssociacao, int idMenu){
	clearScreen(); //apagar conteudo do ecra
	std::cout << "---------------- CRIAR GESTOR --------------\n\n";
	std::string nome;
	unsigned int id = this->associacao->incIdAssociados();
	std::string password;
	std::string enderecoEmail;

	do
	{
		if (std::cin.eof()) std::cin.clear();
		getString(nome, "Nome: ");
	} while (std::cin.eof() && criaAssociacao);

	if (std::cin.eof())
	{
		std::cin.clear();
		if (!criaAssociacao)
			this->menuSessaoGestor(idMenu);
	}

	do
	{
		if (std::cin.eof()) std::cin.clear();
		getString(password, "Password: ");
	} while (std::cin.eof() && criaAssociacao);

	if (std::cin.eof())
	{
		std::cin.clear();
		if (!criaAssociacao)
			this->menuSessaoGestor(idMenu);
	}

	Gestor* gestor = new Gestor(nome, password, siglaAssociacao,id);
	this->associacao->addGestor(*gestor);

	std::cout << "ID atribuido: " << gestor->getID() << std::endl;
	std::cout << "Email: " << gestor->getEnderecoEmail() << std::endl << std::endl;

	std::string nomeFicheiroGestores = siglaAssociacao+"_gestores.txt";

	this->enviarNovoGestorFicheiro(nomeFicheiroGestores);

	std::cout << std::endl<< "Pressione ENTER para continuar... " << std::endl;

	if (std::cin.get())
	{
		if (std::cin.eof()) std::cin.clear();
		if (!criaAssociacao)
			this->menuSessaoGestor(idMenu);
		else
			this->menuAssociacoes();
	}
	

}

void AssociacaoMS::enviarNovoGestorFicheiro(std::string & nomeFicheiroGestores) {
	std::ofstream streamGestores;
	streamGestores.open(nomeFicheiroGestores);

	if (streamGestores.is_open())
	{
		auto gestores = associacao->getGestores();

		for (unsigned int i = 0; i <gestores.size(); i++)
		{
			streamGestores << gestores.at(i)->getNome() << "; "
				<< gestores.at(i)->getID() << "; "
				<< gestores.at(i)->getPassword() << "; "
				<< gestores.at(i)->getEnderecoEmail();

			if(i!=(gestores.size()-1))
				streamGestores<< std::endl;
		}

	}

	else std::cout << "Falha ao abrir ficheiro de destino" << std::endl;
}

/*------------------------------------------- menu 3 -------------------------------------------*/
void AssociacaoMS::menuAssociacoes() {
	clearScreen();
	unsigned int opcao = 0;
	bool valido;
	std::cout << "---- ESCOLHER ASSOCIACAO ----\n\n";

	for (unsigned int i = 0; i < associacoes.size(); i++)
		std::cout << i + 1 << ". " << associacoes.at(i).second << std::endl;

	do
	{

		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuFicheiroAssociacoes();
		}
		if (opcao > associacoes.size())
			valido = false;
		else valido = true;

	} while (!valido);


	//atualizar nome da associacao
	associacao->setNome(associacoes.at(opcao - 1).second);

	//atualizar sigla da associacao
	associacao->setSigla(associacoes.at(opcao - 1).first);

	//atualizar nomes dos ficheiros da associacaoMS
	ficheiroAssociados = associacoes.at(opcao - 1).first + "_associados.txt";
	ficheiroConferencias = associacoes.at(opcao - 1).first + "_conferencias.txt";
	ficheiroDominios = associacoes.at(opcao - 1).first + "_dominios.txt";
	ficheiroEmails = associacoes.at(opcao - 1).first + "_emails.txt";
	ficheiroEscolasVerao = associacoes.at(opcao - 1).first + "_escolaVerao.txt";
	ficheiroGestores = associacoes.at(opcao - 1).first + "_gestores.txt";

	//ler ficheiros
	this->associacao->setEventos({});
	this->associacao->setID(0);
	lerAssociados();
	lerDominios();
	lerEmails();
	lerConferencias();
	lerEscolasVerao();
	lerGestores();


	//proximo menu
	this->menuLogin();

/*
	//ao sair da associacao atual, atualiza informacao dos ficheiros
	enviarDominios();
	enviarAssociados();
	//envarEmails();
	enviarConferencias();
	enviarEscolasVerao();

	this->menuAssociacoes();
*/
}

void AssociacaoMS::lerDominios() {

	std::ifstream dac; //Dominios e Areas Cientificas
	dac.open(ficheiroDominios);
	bool primeiraLeitura = true;
	this->associacao->setDominio(NULL);

	DominioCientifico* dominio = new DominioCientifico();
	char carater;
	std::string cienciaS, areaCientificaS, subAreaS;
	Ciencia* ciencia = NULL;
	AreaCientifica* area = NULL;
	SubAreaCientifica* subArea = NULL;

	dac.get(carater);
	while (!dac.eof())
	{
		if (primeiraLeitura)
		{
			primeiraLeitura = false;
		}
		else
			dac.get(carater);

		if (carater == '@')
		{
			getline(dac, cienciaS);
			if(cienciaS == "")
				break;
			eliminateSpaces(cienciaS);
			ciencia = new Ciencia(cienciaS);
			dominio->addCiencia(ciencia);
		}
		else if (carater == '#')
		{
			getline(dac, areaCientificaS);
			if(areaCientificaS == "" )
				break;
			eliminateSpaces(areaCientificaS);
			area = new AreaCientifica(areaCientificaS);
			ciencia->addAreaCientifica(area);
		}
		else if (carater == '*')
		{
			getline(dac, subAreaS);
			if(subAreaS == "" )
				break;
			eliminateSpaces(subAreaS);
			subArea = new SubAreaCientifica(subAreaS);
			area->addSubAreaCientifica(subArea);
		}	
	}

	this->associacao->setDominio(dominio);
	dac.close();
}

void AssociacaoMS::lerAssociados() {

	std::ifstream streamAssociados;
	streamAssociados.open(ficheiroAssociados);
	bool primeiraLeitura = true;
	char carater;
	this->associacao->setAssociados({});

	std::string linhaFicheiro, nome, ID, password, instituicao, emDiaString, atraso, email, tema, subareas;

	streamAssociados.get(carater);
	while (!streamAssociados.eof()) {
		if (primeiraLeitura)
		{
			streamAssociados.putback(carater);
			primeiraLeitura = false;
		}
		getline(streamAssociados, linhaFicheiro);
		std::stringstream input(linhaFicheiro);
		getline(input, nome, ',');
		getline(input, ID, ',');
		getline(input, password, ',');
		getline(input, instituicao, ',');
		getline(input, emDiaString, ',');
		getline(input, atraso, ',');
		getline(input, email, ';');
		getline(input, tema, ';');
		getline(input, subareas);

		/*
		if(nome == "")
			break;

		if(subareas == "")
			break;
*/

		eliminateSpaces(nome);
		eliminateSpaces(ID);
		eliminateSpaces(password);
		eliminateSpaces(instituicao);
		eliminateSpaces(emDiaString);
		eliminateSpaces(atraso);
		eliminateSpaces(email);
		if (tema != "")
		{
			eliminateSpaces(tema);
		}
		if (subareas != "")
		{
			eliminateSpaces(subareas);
		}

		bool emDia;
		if (emDiaString == "sim")
			emDia = true;
		else emDia = false;

		Cota *cota = new Cota(emDia, std::stoul(atraso));
		Associado *a1;

		if (emDia)
			a1 = new Contributor(nome, std::stoul(ID), password, instituicao, cota, email);
		else if (std::stoul(atraso) < 5)
			a1 = new Subscriber(nome, std::stoul(ID), password, instituicao, cota, email);
		else
			a1 = new Associado(nome, std::stoul(ID),password, instituicao, cota, email);


		//guardar temas de eventos
		std::istringstream ssEventos(tema);
		std::vector<std::string> v_eventos;
		if (tema != "")
		{
			while (!ssEventos.eof())
			{
				std::string evento;
				getline(ssEventos, evento, ',');
				eliminateSpaces(evento);
				v_eventos.push_back(evento);
			}
		}
		a1->setEventos(v_eventos);


		//guardar subareas de interesse
		std::istringstream ssSubAreas(subareas);
		std::vector<std::string> v_subareas;
		if (subareas != "")
		{
			while (!ssSubAreas.eof())
			{
				std::string subArea;
				getline(ssSubAreas, subArea, ',');
				eliminateSpaces(subArea);
				v_subareas.push_back(subArea);
			}
		}
		a1->setAreasInteresse(v_subareas);
		associacao->addAssociado(*a1);
		if (std::stoul(ID) >= this->associacao->getID()) this->associacao->setID(std::stoul(ID));
	}
}

void AssociacaoMS::lerEmails()
{
	bool primeiraLeitura = true;
	char carater;
	this->associacao->setEmails({});
	//abrir ficheiro
	std::ifstream in;
	in.open(ficheiroEmails);
	std::string remetente, destinatario, conteudo;

	in.get(carater);
	//extrair informação do ficheiro
	while (!in.eof())
	{
		if (primeiraLeitura)
		{
			in.putback(carater);
			primeiraLeitura = false;
		}
		getline(in, remetente, ',');
		getline(in, destinatario, ',');
		getline(in, conteudo);
		if(remetente == "")
			break;
		eliminateSpaces(remetente);
		eliminateSpaces(destinatario);
		eliminateSpaces(conteudo);
		Email* email = new Email(remetente, destinatario, conteudo);
		associacao->addEmail(email);
	}

	in.close();
}

void AssociacaoMS::lerConferencias()
{
	std::ifstream in;
	in.open(ficheiroConferencias);
	bool primeiraLeitura = true;
	char carater;

	in.get(carater);
	while (!in.eof())
	{
		if (primeiraLeitura)
		{
			in.putback(carater);
			primeiraLeitura = false;
		}
		//buscar planeadores
		std::vector<unsigned int> vetorPlaneadores;
		std::string ID=""; //id do planeador
		std::string planeadores="";
		getline(in, planeadores, ';');
		std::istringstream ssPlaneadores(planeadores);

		if(planeadores == "")
			break;

		while (!ssPlaneadores.eof())
		{
			getline(ssPlaneadores, ID, ',');
			vetorPlaneadores.push_back(std::stoi(ID)); //adiciona o id ao vetor de planeadores
		}

		//buscar organizadores
		std::vector<unsigned int> vetorOrganizadores;
		std::string organizadores;
		getline(in, organizadores, ';');
		std::istringstream ssOrganizadores(organizadores);

		while (!ssOrganizadores.eof())
		{
			getline(ssOrganizadores, ID, ',');
			vetorOrganizadores.push_back(std::stoi(ID)); //adiciona o ID ao vetor de organizadores
		}

		//buscar local
		std::string local;
		getline(in, local, ';');
		eliminateSpaces(local);

		//buscar tema
		std::string tema;
		getline(in, tema, ';');
		if(tema == "")
			break;
		eliminateSpaces(tema);

		//buscar data
		std::string data, dia, mes, ano, hora, minuto;
		getline(in, data, ';');
		std::istringstream ssData(data);

		getline(ssData, dia, ',');
		getline(ssData, mes, ',');
		getline(ssData, ano, ',');
		getline(ssData, hora, ',');
		getline(ssData, minuto);
		if(dia == "")
			break;
		eliminateSpaces(dia);
		eliminateSpaces(mes);
		eliminateSpaces(ano);
		eliminateSpaces(hora);
		eliminateSpaces(minuto);

		Data dataEvento(std::stoul(dia), std::stoul(mes), std::stoul(ano), std::stoul(hora), std::stoul(minuto));

		//buscar apoio da associacao (true/false)
		std::string apoioAssociacao;
		bool apoioB;
		getline(in, apoioAssociacao, ';');
		eliminateSpaces(apoioAssociacao);
		(apoioAssociacao == "0") ? apoioB = false : apoioB = true;

		//buscar tipo de apoio
		std::string tipoApoio;
		getline(in, tipoApoio, ';');

		if(tipoApoio != "")
			eliminateSpaces(tipoApoio);

		Apoio apoio(apoioB, tipoApoio);

		//buscar numero de participantes
		std::string numeroParticipantes;
		getline(in, numeroParticipantes);
		eliminateSpaces(numeroParticipantes);
		unsigned int nParticipantes = std::stoul(numeroParticipantes);

		//criar conferencia
		Evento* evento = new Conferencia(vetorPlaneadores, vetorOrganizadores, local, tema, dataEvento, apoio, nParticipantes);
		this->associacao->addEvento(*evento);
	}

	in.close();
}

void AssociacaoMS::lerEscolasVerao()
{
	std::ifstream in;
	in.open(ficheiroEscolasVerao);
	bool primeiraLeitura = true;
	char carater;

	in.get(carater);
	while (!in.eof())
	{
		if (primeiraLeitura)
		{
			in.putback(carater);
			primeiraLeitura = false;
		}
		//buscar planeadores
		std::vector<unsigned int> vetorPlaneadores;
		std::string ID; //id do planeador
		std::string planeadores;
		getline(in, planeadores, ';');
		std::istringstream ssPlaneadores(planeadores);

		if(planeadores == "")
			break;

		while (!ssPlaneadores.eof())
		{
			getline(ssPlaneadores, ID, ',');
			vetorPlaneadores.push_back(stoi(ID)); //adiciona o id ao vetor de planeadores
		}

		//buscar organizadores
		std::vector<unsigned int> vetorOrganizadores;
		std::string organizadores;
		getline(in, organizadores, ';');
		std::istringstream ssOrganizadores(organizadores);

		while (!ssOrganizadores.eof())
		{
			getline(ssOrganizadores, ID, ',');
			vetorOrganizadores.push_back(stoi(ID)); //adiciona o ID ao vetor de organizadores
		}

		//buscar local
		std::string local;
		getline(in, local, ';');
		eliminateSpaces(local);

		//buscar tema
		std::string tema;
		getline(in, tema, ';');
		eliminateSpaces(tema);

		//buscar data
		std::string data, dia, mes, ano, hora, minuto;
		getline(in, data, ';');
		std::istringstream ssData(data);

		getline(ssData, dia, ',');
		getline(ssData, mes, ',');
		getline(ssData, ano, ',');
		getline(ssData, hora, ',');
		getline(ssData, minuto);
		if(dia == "")
			break;
		eliminateSpaces(dia);
		eliminateSpaces(mes);
		eliminateSpaces(ano);
		eliminateSpaces(hora);
		eliminateSpaces(minuto);

		Data dataEvento(stoul(dia), stoul(mes), stoul(ano), stoul(hora), stoul(minuto));

		//buscar apoio da associacao (true/false)
		std::string apoioAssociacao;
		bool apoioB;
		getline(in, apoioAssociacao, ';');
		eliminateSpaces(apoioAssociacao);
		(apoioAssociacao == "0") ? apoioB = false : apoioB = true;

		//buscar tipo de apoio
		std::string tipoApoio;
		getline(in, tipoApoio, ';');

		if(tipoApoio != "")
			eliminateSpaces(tipoApoio);

		Apoio apoio(apoioB, tipoApoio);

		//buscar formadores
		std::vector <unsigned int> vetorFormadores;
		std::string formadoresS;
		getline(in, formadoresS);
		std::istringstream ssFormadores(formadoresS);

		while (!ssFormadores.eof())
		{
			std::string formador;
			getline(ssFormadores, formador, ',');
			eliminateSpaces(formador);
			vetorFormadores.push_back(stoi(formador));
		}

		//criar EscolaVerao
		Evento* evento = new EscolaVerao(vetorPlaneadores, vetorOrganizadores, local, tema, dataEvento, apoio, vetorFormadores);
		this->associacao->addEvento(*evento);
	}
	in.close();
}

void AssociacaoMS::lerGestores()
{
	this->associacao->setGestores({});
	std::ifstream in;
	in.open(ficheiroGestores);
	bool primeiraLeitura = true;
	char carater;

	in.get(carater);
	while (!in.eof())
	{
		if (primeiraLeitura)
		{
			in.putback(carater);
			primeiraLeitura = false;
		}

		std::string nome;
		std::string idS;
		std::string password;
		std::string email;
		unsigned int id;

		//buscar nome do gestor
		getline(in, nome, ';');
		if(nome == "")
			break;
		eliminateSpaces(nome);

		//buscar id do gestor

		in >> id;
		in.ignore(1000, ';');

		/*getline(in, idS, ';');
		if(idS == "")
			break;
		eliminateSpaces(idS);
		id = stoi(idS);*/

		//buscar password do gestor
		getline(in, password, ';');
		if(password == "")
			break;
		eliminateSpaces(password);

		//buscar endereço de email do gestor
		getline(in, email);
		if(email == "")
			break;
		eliminateSpaces(email);

		//criar gestor
		Gestor* gestor = new Gestor(nome, id, password, email);
		this->associacao->addGestor(*gestor);
		if (id >= this->associacao->getID())
			this->associacao->setID(id);

	}

	in.close();
}

/*------------------------------------------- menu 4 -------------------------------------------*/
void AssociacaoMS::menuLogin() {
	clearScreen();
	std::cout << "---- LOGIN ----\n\n";
	std::cout << "1. Sign up\n";
	std::cout << "2. Sign in\n";
	std::cout << "3. Sair\n\n";
	unsigned int opcao = 0, id = 0;
	std::string password;

	do
	{
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			enviarDominios();
			enviarAssociados();
			enviarEmails();
			enviarConferencias();
			enviarEscolasVerao();
			enviarGestores();
			this->menuAssociacoes();
		}
	} while (!((opcao == 1) || (opcao == 2) || (opcao == 3) ));

	if (opcao == 1) {
		//cria conta com id automatico
		clearScreen();
		std::cout << "---- SIGN UP ----\n\n";
		this->criaConta();


	}

	if (opcao == 2) {
		//acede a conta da lista associados
		clearScreen();
		std::cout << "---- SIGN IN ----\n\n";
		this->getID(id, password);
		//caso validado acede a menu seguinte. ***Ver funcao getPassword***

	}

	if (opcao == 3){
		//ao sair da associacao atual, atualiza informacao dos ficheiros
		enviarDominios();
		enviarAssociados();
		enviarEmails();
		enviarConferencias();
		enviarEscolasVerao();
		enviarGestores();

		this->menuAssociacoes();
	}
}

void AssociacaoMS::criaConta() {
	std::string nome, password, instituicao, email;
	int ID = associacao->incIdAssociados();

	getString(nome, "Nome: ");
	if (std::cin.eof())
	{
		std::cin.clear();
		this->menuLogin();
	}
	auto associados = this->associacao->getAssociados();
	auto it = associados.begin();

	for(;it!=associados.end();it++)
		if((*it)->getNome() == nome)
			{
			std::cout << "Utilizador ja existente! Tente iniciar sessao! \n\n";
			std::cout << "Pressione ENTER para continuar... " << std::endl;

				if(std::cin.get())
					this->menuLogin();
			}

	getString(password, "Password: ");
	if (std::cin.eof())
	{
		std::cin.clear();
		this->menuLogin();
	}
	getString(instituicao, "Instituicao: ");
	if (std::cin.eof())
	{
		std::cin.clear();
		this->menuLogin();
	}
	email = std::to_string(ID) + "@" + associacao->getSigla() + ".com";

	std::cout << "ID atribuido : " << ID << "\nEmail atribuido : " << email << "\n\n";

	Cota *cota = new Cota(true, 0);

	Contributor *a = new Contributor(nome, ID, password, instituicao, cota, email);

	associacao->addAssociado(*a);

	std::cout << "Pressione ENTER para continuar... " << std::endl;

		if(std::cin.get())
			this->menuLogin();

}

void AssociacaoMS::getID(unsigned int id, std::string pass) {
	bool IDvalido = false;
	bool PassValida = false;
	unsigned int pos = -1;
	do {
		getNumber(id, "ID: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuLogin();
		}

		auto associados = this->associacao->getAssociados();
		auto it = associados.begin();
		Associado* associado = NULL;

		for (;it!=associados.end();it++)
			if ((*it)->getID() == id) //ID valido
			{
				IDvalido = true;
				associado = (*it);
			}

		if (IDvalido)
		{
			do {
					getString(pass, "Password do associado: ");
					if (std::cin.eof())
					{
						std::cin.clear();
						this->menuLogin();
					}
					if(associado->getPassword() == pass)
							PassValida = true;
					if (!PassValida)
						std::cout << "Password invalida!! \n\n";
					else this->menuSessaoAssociado(id);
			} while (!PassValida);

		}

		else {
			//verifica se e gestor
			for(unsigned int i = 0; i < associacao->getGestores().size(); i++ )
				if(associacao->getGestores().at(i)->getID() == id){
					IDvalido = true;
					pos = i;
				}

			if (IDvalido)
			{
				do {
						getString(pass, "Password do gestor: ");
						if (std::cin.eof())
						{
							std::cin.clear();
							this->menuLogin();
						}
						if(associacao->getGestores().at(pos)->getPassword() == pass)
								PassValida = true;
						if (!PassValida)
							std::cout << "Password invalida!! \n\n";
						else this->menuSessaoGestor(id);
				} while (!PassValida);
			}

		}

		if(!IDvalido)
			std::cout << "ID invalido!! \n\n";

	} while (!IDvalido);

}

/*------------------------------------------- menu 5 -------------------------------------------*/
bool procuraAssociado(unsigned int id, Associado* associado)
{
	return associado->getID() == id;
}

void AssociacaoMS::menuSessaoGestor(unsigned int id){
	clearScreen(); //apagar conteudo do ecra

	Gestor* gestor = NULL;
	for (unsigned int i = 0; i < this->associacao->getGestores().size(); i++)
	{
		if (this->associacao->getGestores().at(i)->getID() == id)
		{
			gestor = this->associacao->getGestores().at(i);
		}
	}

	std::cout << "Bem vindo " << gestor->getNome() << "!" << std::endl << std::endl;

	std::cout << "_________________ O MEU ESPACO _________________\n\n";
	std::cout << " 1. Informacoes da minha conta\n";
	std::cout << " 2. Modificar a minha conta\n";
	std::cout << " 3. Apagar a minha conta\n";
	std::cout << " 4. Emails recebidos\n";
	std::cout << " 5. Emails enviados\n\n";

	std::cout << "_________________ ESPACO GESTOR ________________\n\n";
	std::cout << " 6. Criar um novo gestor\n";
	std::cout << " 7. Modificar conta de um associado\n";
	std::cout << " 8. Apagar associado\n";
	std::cout << " 9. Apoiar evento\n"; 
	std::cout << "10. Enviar email\n";
	std::cout << "11. Lista de associados\n";
	std::cout << "12. Terminar Sessao\n\n";


	unsigned int opcao = 0;
	do
	{
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuLogin();
		}
	} while (!((opcao == 1) || (opcao == 2) || (opcao == 3) ||
			(opcao == 4) || (opcao == 5) || (opcao == 6) || (opcao == 7) || (opcao == 8) || (opcao == 9) || (opcao==10) || (opcao==11)));

	if (opcao == 1) {
		clearScreen();
		for (unsigned int i = 0; i < this->associacao->getGestores().size(); i++)
			if (this->associacao->getGestores().at(i)->getID() == id)
				this->associacao->getGestores().at(i)->show();
		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof())
			{
				std::cin.clear();
			}
		}
		this->menuSessaoGestor(id);
	}

	else if (opcao == 7)
		this->alteraAssociado(id);
	else if (opcao == 3)
		this->apagaGestor(id);
	else if (opcao == 8)
		this->apagaAssociado(id);
	else if (opcao == 11)
		visualizaAssociados(id);
	else if (opcao == 10) {

		this->envioEmail(gestor);
		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof())
			{
				std::cin.clear();
			}
		}
		this->menuSessaoGestor(id);
	}
	else if (opcao == 6)
		this->criaGestor(associacao->getSigla(), false, id);
	else if (opcao == 12)
	{
		this->menuLogin();
	}
	else if (opcao == 2)
		this->alteraGestor(gestor);
	else if (opcao == 9)
		this->apoiarEvento(id);
	else if (opcao == 4)
	{
		this->visualizaEmailsRecebidos(gestor);
		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof())
			{
				std::cin.clear();
			}
		}
		this->menuSessaoGestor(id);
	}
	else if (opcao == 5)
	{
		this->visualizaEmailsEnviados(gestor);
		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof())
			{
				std::cin.clear();
			}
		}
		this->menuSessaoGestor(id);
	}


}

void AssociacaoMS::visualizaAssociados(unsigned int id)
{
	clearScreen();
	this->associacao->showAssociadosCategoria();

	std::cout << "Pressione ENTER para continuar... " << std::endl;

	if (std::cin.get())
	{
		if (std::cin.eof())
		{
			std::cin.clear();
		}
	}
	this->menuSessaoGestor(id);
}

void AssociacaoMS::apoiarEvento(unsigned int id) {
	clearScreen();
	std::vector<std::pair<Evento*,int>> eventosSemApoio;
	int numeroEvento = 1;
	std::cout << "Eventos sem apoio da associacao\n\n";
	for (unsigned int i = 0; i < associacao->getEventos().size(); i++)
		if (!associacao->getEventos().at(i)->getApoioEvento().getApoioAssociacao())
		{
			std::cout << "Evento numero " << numeroEvento << " \nNome : "
				<< associacao->getEventos().at(i)->getTema() << " \nLocal : "
				<< associacao->getEventos().at(i)->getLocal() << "\n\n";
			numeroEvento++;
			eventosSemApoio.push_back(std::pair<Evento*,int>(associacao->getEventos().at(i),i));
		}

	unsigned int opcao;
	std::string tipoApoio;
	do {
		getNumber(opcao, "Indique o numero do evento que pretende dar apoio : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(id);
		}

		if ((opcao - 1) >= eventosSemApoio.size()) {
			std::cout << "Evento inexistente...\n\n";
			continue;
		}

		getString(tipoApoio, "\nIndique o tipo de apoio : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(id);
		}
		Apoio a(true,tipoApoio);
		associacao->getEventos().at(eventosSemApoio.at(opcao-1).second)->setApoio(a);

		std::cout << "\nEvento alterado com sucesso!\n\n";

		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof()) std::cin.clear();
			this->menuSessaoGestor(id);
		}

	} while (opcao >= associacao->getEventos().size());


}

void AssociacaoMS::alteraGestor(Gestor* gestor) {

	std::string nome, pass;
	clearScreen();

	std::cout << "O que deseja alterar ? \n\n";
	std::cout << "1. Nome \n" << "2. Password \n\n";

	unsigned int opcao = 0;
	do {
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(gestor->getID());
		}
	} while (!((opcao == 1) || (opcao == 2)));

	if (opcao == 1) {
		std::cout << "Nome Atual : " << gestor->getNome();
		do
		{
			getString(nome, "\nNovo Nome : ");
			if (std::cin.eof())
			{
				std::cin.clear();
				this->menuSessaoGestor(gestor->getID());
			}
			if (nome == gestor->getNome())
			{
				std::cout << "Manteve o mesmo nome! Por favor insira outro\n\n";
			}
		} while (nome == gestor->getNome());
		gestor->setNome(nome);
		std::cout << "Nome alterado com sucesso!\n\n";

	} else if (opcao == 2) {
		std::cout << "Password Atual : " << gestor->getPassword();
		do
		{
			getString(pass, "\nNova Password : ");
			if (std::cin.eof())
			{
				std::cin.clear();
				this->menuSessaoGestor(gestor->getID());
			}
			if (pass == gestor->getPassword())
			{
				std::cout << "Manteve a mesma password! Por favor insira outra\n\n";
			}
		} while (pass == gestor->getPassword());
		gestor->setPassword(pass);
		std::cout << "Password alterada com sucesso!\n\n";
	}

	std::cout << "Pressione ENTER para continuar... " << std::endl;

	if (std::cin.get())
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(gestor->getID());
		}
		this->menuSessaoGestor(gestor->getID());
	}

}

void AssociacaoMS::menuSessaoAssociado(unsigned int id)
{
	auto associados = this->associacao->getAssociados();
	auto it = associados.begin();
	Associado* associado = NULL;
	unsigned int pos;

	//procura o associado

	for (;it!=associados.end();it++)
	{
		if ((*it)->getID() == id)
			associado = (*it);
	}

	//verifica que tipo de associado é (contributor, subscriber, ou simplesmente um associado)
	if (associado->getCota()->getEmDia() == true)
		this->menuSessaoContributor(associado);


	else if (associado->getCota()->getAtraso() < 5)
		this->menuSessaoSubscriber(associado);
	else
		this->menuSessaoOther(associado);


}

void AssociacaoMS::menuSessaoContributor(Associado* associado)
{
	clearScreen();
	std::cout << "Bem vindo " << associado->getNome() << "!" << std::endl << std::endl;

	std::cout << "_________________ O MEU ESPACO _________________\n\n";
	std::cout << " 1. Informacoes da minha conta\n";
	std::cout << " 2. Modificar a minha conta\n";
	std::cout << " 3. Apagar a minha conta\n";
	std::cout << " 4. Os meus interesses cientificos\n";
	std::cout << " 5. Adicionar subarea cientifica de interesse\n\n";

	std::cout << "_______________ ESPACO ASSOCIACAO ______________\n\n";
	std::cout << " 6. Eventos nos quais eu participo\n";
	std::cout << " 7. Emails Recebidos\n";
	std::cout << " 8. Emails Enviados\n";
	std::cout << " 9. Areas e subareas cientificas dos restantes associados\n";
	std::cout << "10. Enviar email\n";
	std::cout << "11. Criar evento\n";
	std::cout << "12. Terminar Sessao\n\n";

	/* ---- variaveis ---- */
	unsigned int opcao;
	do
	{
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuLogin();
		}

	} while ((opcao < 0) || (opcao > 12));

	//encaminhamento para cada uma das opcoes do menu
	switch (opcao)
	{
	case 1:
		clearScreen();
		associado->show();
		break;

	case 2:
		clearScreen();
		modificarConta(associado);
		break;

	case 3:
		clearScreen();
		associacao->eraseAssociado(associado,true);
		std::cout << "Conta eliminada com sucesso...\n\n";
		std::cout << "Pressione ENTER para continuar... " << std::endl;
		if (std::cin.get())
		{
			if (std::cin.eof()) std::cin.clear();
			this->menuLogin();
		}

	case 4:
		clearScreen();
		associacao->showInteressesAssociado(associado);
		break;

	case 5:
		clearScreen();
		this->addSubareaCientificaInteresse(associado);
		break;

	case 6:
		clearScreen();
		associacao->showEventos(associado);
		break;

	case 7:
		clearScreen();
		this->visualizaEmailsRecebidos(associado);
		break;

	case 8:
		clearScreen();
		this->visualizaEmailsEnviados(associado);
		break;

	case 9:
		clearScreen();
		this->associacao->showInteressesOutrosAssociados();
		break;

	case 10:
		clearScreen(); //apagar conteudo do ecra
		this->envioEmail(associado);
		break;

	case 11:
		clearScreen();
		this->criarEvento(associado);
		break;

	case 12:
		clearScreen();
		this->menuLogin();
		break;
	}

	std::cout << "\n\nPressione ENTER para continuar... " << std::endl;

	if (std::cin.get())
	{
		if (std::cin.eof()) std::cin.clear();
		this->menuSessaoContributor(associado);
	}
}

void AssociacaoMS::menuSessaoSubscriber(Associado* associado)  //para completar
{
	clearScreen();
		std::cout << "Bem vindo " << associado->getNome() << "!" << std::endl << std::endl;

		std::cout << "_________________ O MEU ESPACO _________________\n\n";
		std::cout << " 1. Informacoes da minha conta\n";
		std::cout << " 2. Modificar a minha conta\n";
		std::cout << " 3. Apagar a minha conta\n";
		std::cout << " 4. Os meus interesses cientificos\n";
		std::cout << " 5. Adicionar subarea cientifica de interesse\n\n";

		std::cout << "_______________ ESPACO ASSOCIACAO ______________\n\n";
		std::cout << " 6. Eventos nos quais eu participo\n";
		std::cout << " 7. Emails Recebidos\n";
		std::cout << " 8. Areas e subareas cientificas dos restantes associados\n";
		std::cout << " 9. Criar evento\n";
		std::cout << "10. Terminar Sessao\n\n";

		/* ---- variaveis ---- */
		unsigned int opcao;
		do
		{
			getNumber(opcao, "Opcao: ");
			if (std::cin.eof())
			{
				std::cin.clear();
				this->menuLogin();
			}

		} while ((opcao < 0) || (opcao > 10));

		//encaminhamento para cada uma das opcoes do menu
		switch (opcao)
		{
		case 1:
			clearScreen();
			associado->show();
			break;

		case 2:
			clearScreen();
			modificarConta(associado);
			break;

		case 3:
			clearScreen();
			associacao->eraseAssociado(associado,true);
			std::cout << "Conta eliminada com sucesso...\n\n";
			std::cout << "Pressione ENTER para continuar... " << std::endl;
			if (std::cin.get())
			{
				if (std::cin.eof()) std::cin.clear();
				this->menuLogin();
			}

		case 4:
			clearScreen();
			associacao->showInteressesAssociado(associado);
			break;

		case 5:
			clearScreen();
			this->addSubareaCientificaInteresse(associado);
			break;

		case 6:
			clearScreen();
			associacao->showEventos(associado);
			break;

		case 7:
			clearScreen();
			this->visualizaEmailsRecebidos(associado);
			break;

		case 8:
			clearScreen();
			this->associacao->showInteressesOutrosAssociados();
			break;

		case 9:
			clearScreen();
			this->criarEvento(associado);
			break;

		case 10:
			clearScreen();
			this->menuLogin();
			break;
		}

		std::cout << "\n\nPressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof()) std::cin.clear();
			this->menuSessaoSubscriber(associado);
		}
}

void AssociacaoMS::menuSessaoOther(Associado * associado){

	clearScreen();
		std::cout << "Bem vindo " << associado->getNome() << "!" << std::endl << std::endl;

		std::cout << "_________________ O MEU ESPACO _________________\n\n";
		std::cout << " 1. Informacoes da minha conta\n";
		std::cout << " 2. Modificar a minha conta\n";
		std::cout << " 3. Apagar a minha conta\n";
		std::cout << " 4. Os meus interesses cientificos\n";
		std::cout << " 5. Adicionar subarea cientifica de interesse\n\n";

		std::cout << "_______________ ESPACO ASSOCIACAO ______________\n\n";
		std::cout << " 6. Eventos nos quais eu participo\n";
		std::cout << " 7. Areas e subareas cientificas dos restantes associados\n";
		std::cout << " 8. Terminar Sessao\n\n";

		/* ---- variaveis ---- */
		unsigned int opcao;
		do
		{
			getNumber(opcao, "Opcao: ");
			if (std::cin.eof())
			{
				std::cin.clear();
				this->menuLogin();
			}

		} while ((opcao < 0) || (opcao > 8));

		//encaminhamento para cada uma das opcoes do menu
		switch (opcao)
		{
		case 1:
			clearScreen();
			associado->show();
			break;

		case 2:
			clearScreen();
			modificarConta(associado);
			break;

		case 3:
			clearScreen();
			associacao->eraseAssociado(associado,true);
			std::cout << "Conta eliminada com sucesso...\n\n";
			std::cout << "Pressione ENTER para continuar... " << std::endl;
			if (std::cin.get())
			{
				if (std::cin.eof()) std::cin.clear();
				this->menuLogin();
			}

		case 4:
			clearScreen();
			associacao->showInteressesAssociado(associado);
			break;

		case 5:
			clearScreen();
			this->addSubareaCientificaInteresse(associado);
			break;

		case 6:
			clearScreen();
			associacao->showEventos(associado);
			break;

		case 7:
			clearScreen();
			this->associacao->showInteressesOutrosAssociados();
			break;

		case 8:
			clearScreen();
			this->menuLogin();
			break;
		}

		std::cout << "\n\nPressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof()) std::cin.clear();
			this->menuSessaoOther(associado);
		}
}

void AssociacaoMS::modificarConta(Associado* associado) {

	std::string nome, pass;

	std::cout << "O que deseja alterar ? \n\n";
	std::cout << "1) Nome \n" << "2) Password \n\n";

	unsigned int opcao = 0;
	do {
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
				this->menuSessaoSubscriber(associado);
			else
				this->menuSessaoOther(associado);
		}
	} while (!((opcao == 1) || (opcao == 2)));

	if (opcao == 1) {
		std::cout << "Nome Atual : " << associado->getNome();
		getString(nome, "\nNovo Nome : ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
				this->menuSessaoSubscriber(associado);
			else
				this->menuSessaoOther(associado);
		}
		associado->setNome(nome);
		std::cout << "Nome alterado com sucesso!\n\n";

	} else if (opcao == 2) {
		std::cout << "Password Atual : " << associado->getPassword();
		getString(pass, "\nNova Password : ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
				this->menuSessaoSubscriber(associado);
			else
				this->menuSessaoOther(associado);
		}
		associado->setPassword(pass);
		std::cout << "Password alterada com sucesso!\n\n";
	}

	std::cout << "Pressione ENTER para continuar... " << std::endl;

	if (std::cin.get())
	{
		if (std::cin.eof())
		{
			std::cin.clear();
		}
		if (associado->isContributor())
			this->menuSessaoContributor(associado);
		else if (associado->isSubscriber())
			this->menuSessaoSubscriber(associado);
		else
			this->menuSessaoOther(associado);
	}

}

template <class T> 
void AssociacaoMS::criarEvento(T* associado)
{
	std::cout << "----------- CRIAR EVENTO -----------\n\n";

	/* ----- Variaveis ----- */
	unsigned int opcao;
	bool conferencia = false;  //indica se o evento é uma conferencia (se nao o for, será uma escola de verao)
	std::vector<unsigned int> planeadores;   //id's dos planeadores
	std::vector<unsigned int> organizadores; //id's dos organizadores
	std::vector<unsigned int> associados; //id's dos associados
	std::string tema;  //tema do evento
	std::string local; //local do evento
	unsigned int contador = 1;  //contador do numero de planeadores do evento
	unsigned int numeroParticipantes; //numero de participantes da conferencia
	std::vector<unsigned int> formadores; //id's dos formadores da escola de Verao
	bool temaNovo = true; //verificar se ja existe tema com mesmo nome

	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
	unsigned int hora;
	unsigned int minuto;
	/* ------- Passo 1 - Escolher tipo de evento --------*/

	std::cout << "PASSO 1: Escolher tipo de evento\n";
	std::cout << "   1 - Conferencia\n";
	std::cout << "   2 - Escola de Verao\n\n";

	do
	{
		getNumber(opcao, "Opcao: ");

		if (std::cin.eof())
		{
			std::cin.clear();
			
			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
				this->menuSessaoSubscriber(associado);
			else
				this->menuSessaoOther(associado);
				
		}
	} while ((opcao != 1) && (opcao != 2));

	if (opcao == 1)
		conferencia = true;

	/* ------- Passo 2 - Escolher planeadores do evento --------*/
	clearScreen();
	std::cout << "PASSO 2: Escolher planeadores do evento\n";
	std::cout << "   Instrucoes:\n   - Escolha mais 2 associados para planearem o evento.\n";
	std::cout << "   - Quando terminar insira 0\n";
	std::cout << "   - Listam-se aqui os associados disponiveis:\n\n";
	associados = this->associacao->showAssociados(associado->getID(),true); //id's dos associados (exceto do associado atual)
	std::cout << "\n\n";
	planeadores.push_back(associado->getID());
	do
	{
		do
		{
			getNumber(opcao, "Planeador: ");

			if (std::cin.eof())
			{
				std::cin.clear();

				if (associado->isContributor())
					this->menuSessaoContributor(associado);
				else if (associado->isSubscriber())
				    this->menuSessaoSubscriber(associado);
				else
				    this->menuSessaoOther(associado);
				
			}
			if (opcao == 0)
				break;
		} while ((opcao > (this->associacao->getAssociados().size() - 1)) || (find(planeadores.begin(), planeadores.end(), associados.at(opcao-1)) != planeadores.end()));
		//repete enquanto a opcao for invalida (o associado nao existe ou ja foi escolhido)

		if (opcao != 0)
		{
			std::cout << "Planeador " << opcao << " selecionado com sucesso\n\n";
			planeadores.push_back(associados.at(opcao-1));
			contador++;
		}
		else
		{
			if (contador < 3)
			{
				std::cout << "Precisa de pelo menos 3 planeadores (nos quais voce esta incluido)\n\n";
				opcao = 1;
			}
		}
	} while (opcao != 0);

	organizadores = planeadores; //os planeadores tambem sao organizadores do evento

    /* ------- Passo 3 - Escolher organizadores do evento --------*/
	clearScreen();
	std::cout << "PASSO 3: Escolher organizadores do evento\n";
	std::cout << "   Instrucoes:\n   - Escolha os organizadores do evento.\n";
	std::cout << "   - Nao se esqueca que os planeadores do evento sao tambem seus organizadores\n";
	std::cout << "   - Quando terminar insira 0\n";
	std::cout << "   - Listam-se aqui os associados disponiveis:\n\n";

	this->associacao->showAssociados(associado->getID(),true);
	std::cout << "\n";

	std::cout << "   - ID's dos planeadores do evento: ";
	for (int i = 0; i < planeadores.size(); i++)
	{
		if (i ==( planeadores.size() - 1))
			std::cout << planeadores.at(i) << std::endl << std::endl;
		else 
		    std::cout << planeadores.at(i)<<", ";
	}
	do
	{
		do
		{
			getNumber(opcao, "Organizador: ");

			if (std::cin.eof())
			{
				std::cin.clear();

				if (associado->isContributor())
					this->menuSessaoContributor(associado);
				else if (associado->isSubscriber())
				    this->menuSessaoSubscriber(associado);
				else
				    this->menuSessaoOther(associado);
				 
			}
			if (opcao == 0)
				break;

			if ((opcao <= (this->associacao->getAssociados().size() - 1)) && (find(organizadores.begin(), organizadores.end(), associados.at(opcao - 1)) != organizadores.end())) //o organizador ja foi escolhido
			{
				std::cout << "O organizador " << opcao << " ja foi selecionado\n\n";
			}
		} while ((opcao > (this->associacao->getAssociados().size() - 1)) || (find(organizadores.begin(), organizadores.end(), associados.at(opcao - 1)) != organizadores.end()));
		//repete enquanto a opcao for invalida (o associado nao existe ou ja foi escolhido)

		if (opcao != 0)
		{
			std::cout << "Organizador " << opcao << " selecionado com sucesso\n\n";
			organizadores.push_back(associados.at(opcao - 1));
		}
	} while (opcao != 0);

	/* ------- Passo 4 - Escolher tema do evento --------*/
	clearScreen();
	std::cout << "PASSO 4: Escolher tema do evento\n\n";

	do{
		temaNovo = true;
		getString(tema, "Tema do evento: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
				this->menuSessaoSubscriber(associado);
			else
				this->menuSessaoOther(associado);
		}
		for(unsigned int i = 0; i < associacao->getEventos().size();i++)
			if(associacao->getEventos().at(i)->getTema() == tema)
				temaNovo = false;


	}while(!temaNovo);

	if (std::cin.eof())
	{
		std::cin.clear();

		if (associado->isContributor())
			this->menuSessaoContributor(associado);
		else if (associado->isSubscriber())
		    this->menuSessaoSubscriber(associado);
		else
		    this->menuSessaoOther(associado);
	}

	eliminateSpaces(tema);

	/* ------- Passo 5 - Escolher local do evento --------*/
	clearScreen();
	std::cout << "PASSO 5: Escolher local do evento\n\n";
	getString(local, "Local do evento: ");

	if (std::cin.eof())
	{
		std::cin.clear();

		if (associado->isContributor())
			this->menuSessaoContributor(associado);
		else if (associado->isSubscriber())
		    this->menuSessaoSubscriber(associado);
		else
		    this->menuSessaoOther(associado);
	}

	eliminateSpaces(local);

	/* ------- Passo 6 - Escolher data do evento --------*/
	clearScreen();
	std::cout << "PASSO 6: Escolher data do evento\n\n";

	
	getNumber(ano, "Ano: ");
	if (std::cin.eof())
	{
		std::cin.clear();

		if (associado->isContributor())
			this->menuSessaoContributor(associado);
		else if (associado->isSubscriber())
	     	this->menuSessaoSubscriber(associado);
		else
		    this->menuSessaoOther(associado);
	}

	do
	{
		getNumber(mes, "Mes: ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
			    this->menuSessaoSubscriber(associado);
			else
			    this->menuSessaoOther(associado);
		}

	}while ((mes == 0) || (mes > 12));

	bool diaValido = false;
	do
	{
		getNumber(dia, "Dia: ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
			    this->menuSessaoSubscriber(associado);
			else
			    this->menuSessaoOther(associado);
		}

		switch (mes)
		{
		case 11:
			if (dia <= 30)
				diaValido = true;
			break;
		case 4:
			if (dia <= 30)
				diaValido = true;
			break;
		case 6:
			if (dia <= 30)
				diaValido = true;
			break;
		case 9:
			if (dia <= 30)
				diaValido = true;
			break;
		case 2:
			if (dia <= 29)
				diaValido = true;
			break;
		default:
			if (dia <= 31)
				diaValido = true;
			break;
		}

		if (!diaValido)
			std::cout << "Numero de dias incompativel com o mes apontado\n";
	} while (!diaValido);

	do
	{
		getNumber(hora, "Hora: ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
			    this->menuSessaoSubscriber(associado);
			else
			    this->menuSessaoOther(associado);
		}

	} while (hora > 24);

	do
	{
		getNumber(minuto, "Minuto: ");
		if (std::cin.eof())
		{
			std::cin.clear();

			if (associado->isContributor())
				this->menuSessaoContributor(associado);
			else if (associado->isSubscriber())
			    this->menuSessaoSubscriber(associado);
			else
			    this->menuSessaoOther(associado);
		}

	} while (minuto>=60);

	Data data(dia,mes,ano,hora,minuto); //data do evento

	/* ------- Passo 7 - Paramtros proprios da conferencia/escola de verao --------*/

	if (conferencia) //se for uma conferencia
	{
		clearScreen();
		std::cout << "PASSO 7: Estimativa do numero de participantes da conferencia\n\n";

		do
		{
			getNumber(numeroParticipantes, "Numero de participantes: ");
			if (std::cin.eof())
			{
				std::cin.clear();

				if (associado->isContributor())
					this->menuSessaoContributor(associado);
				else if (associado->isSubscriber())
				    this->menuSessaoSubscriber(associado);
				else
				    this->menuSessaoOther(associado);
			}

			if (numeroParticipantes == 0)
				std::cout << "A conferencia deve ter pelo menos 1 participante\n\n";
		} while (numeroParticipantes == 0);

	}
	else //se for uma escola de verao
	{

		clearScreen();
		std::cout << "PASSO 7: Formadores da escola de Verao\n\n";
		std::cout << "   Instrucoes:\n   - Escolha os formadores da escola de verao.\n";
		std::cout << "   - Quando terminar insira 0\n";
		std::cout << "   - Listam-se aqui os associados disponiveis:\n\n";
		associados=this->associacao->showAssociados(associado->getID(),false);
		std::cout << "\n";

		do
		{
			do
			{
				getNumber(opcao, "Formador: ");

				if (std::cin.eof())
				{
					std::cin.clear();

					if (associado->isContributor())
						this->menuSessaoContributor(associado);
					else if (associado->isSubscriber())
					    this->menuSessaoSubscriber(associado);
					else
					    this->menuSessaoOther(associado);
					
				}

				if (opcao == 0)
					break;
			} while ((opcao > (this->associacao->getAssociados().size())) || (find(formadores.begin(), formadores.end(), associados.at(opcao - 1)) != formadores.end()));

			if (opcao != 0)
			{
				formadores.push_back(associados.at(opcao - 1));
				std::cout << "Formador adicionado com sucesso!\n\n";
			}
			else
			{
				if (formadores.size() == 0)
				{
					std::cout << "Deve escolher pelo menos 1 formador\n\n";
					opcao = 1;
				}
			}
		} while (opcao != 0);
	}

	/* ------- Passo 8 - Criar evento e adicionar ao vetor de eventos da associacao --------*/
    Apoio apoio; //ao ser criado o evento este nao é apoiado
	Evento* evento;

	if (conferencia)
	{
		evento = new Conferencia(planeadores, organizadores, local, tema, data, apoio, numeroParticipantes);
	} 
	else
	{
		evento = new EscolaVerao(planeadores, organizadores, local, tema, data, apoio, formadores);
	}

	this->associacao->addEvento(*evento);
	auto grupo_associados = this->associacao->getAssociados();
	auto it = grupo_associados.begin();
	for (;it!=grupo_associados.end();it++)
	{
		auto id = (*it)->getID();
		auto planeador = find(planeadores.begin(), planeadores.end(), id);
		auto organizador = find(organizadores.begin(), organizadores.end(), id);
		auto formador = find(formadores.begin(), formadores.end(), id);

		if ((planeador != planeadores.end()) || (organizador != organizadores.end()) || (formador != formadores.end()))
		{
			auto associadoEvento = (*it);
			associadoEvento->addEvento(tema);
		}

		if ((*it)->getID());
	}
	clearScreen();
	std::cout << "Evento adicionado com sucesso! \n\n";

}

void AssociacaoMS::alteraAssociado(unsigned int id){

	unsigned int ID, atraso;
	int pos = -1;
	std::string nome, pass, emdia;
	bool emdiaBool;

	clearScreen();
	std::cout << "Associados disponiveis : \n\n";
	std::cout << std::setw(20) << "ID" << std::setw(20) << "Nome" << "\n";
	auto associados = this->associacao->getAssociados();
	auto it = associados.begin();

	for(;it!=associados.end();it++)
		std::cout << std::setw(20) << (*it)->getID() << std::setw(20) << (*it)->getNome() << "\n";

	std::cout << "\n";

	Associado* associado = NULL;

	do {
		getNumber(ID, "Introduza o ID do associado a alterar : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(id);
		}
		
		it = associados.begin();
		for (; it != associados.end(); it++)
		{
			if ((*it)->getID() == ID)
				associado = (*it);
			
		}
		if (associado==NULL)
			std::cout << "ID invalido!!\n\n";
	} while (associado==NULL);

	std::cout << "O que deseja alterar ? \n\n";
	std::cout << "1) Nome \n" << "2) Password \n" << "3) Cota \n\n";

	unsigned int opcao = 0;
	do {
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuTermino();
		}
	} while (!((opcao == 1) || (opcao == 2) || (opcao == 3)));

	if (opcao == 1) {
		std::cout << "Nome Atual : "
			<< associado->getNome();
		getString(nome, "\nNovo Nome : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(id);
		}
		associado->setNome(nome);
		std::cout << "Nome alterado com sucesso!\n\n";
	}
	else if (opcao == 2) {
		std::cout << "Password Atual : "
			<< associado->getPassword();
		getString(pass, "\nNova Password : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(id);
		}
		associado->setPassword(pass);
		std::cout << "Password alterada com sucesso!\n\n";
		this->menuSessaoGestor(id);
	}
	else if (opcao == 3) {
		std::cout << "Estado da cota atual : ";
		if (associado->getCota()->getEmDia())
			std::cout << "Em dia !\n\n";
		else std::cout << "Nao esta em dia, com um atraso de "
			<<associado->getCota()->getAtraso()
			<< " anos ! \n\n";
		std::cout << "Novo estado da cota : ";
		do
		{
			getString(emdia, "Em dia ? (true/false) ");
			if (std::cin.eof())
			{
				std::cin.clear();
				this->menuSessaoGestor(id);
			}
		} while (!((emdia== "true") || (emdia == "false")));
		if (emdia == "true")
			emdiaBool = true;
		else
			emdiaBool = false;
		if (!emdiaBool)
		{
			do
			{
				getNumber(atraso, "Atraso (em anos) : ");
				if (std::cin.eof())
				{
					std::cin.clear();
					this->menuSessaoGestor(id);
				}
				if (atraso == 0)
					std::cout << "Atraso devera ter pelo menos um ano\n\n";
			} while (atraso == 0);
		}
		else
			atraso = 0;

		Associado *a1;
		Cota *cota = new Cota(emdiaBool, atraso);
		auto temp = associacao->getAssociados();
		auto position = temp.find(associado);

		if (associado->getCota()->getEmDia()) //inicialmente como contributor
		{
			if (emdiaBool) //continua
			{

				associado->setCota(cota);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
			else if (!emdiaBool && atraso < 5) //passa a subscriber
			{
				a1 = new Subscriber(
					associado->getNome(),
					associado->getID(),
					associado->getPassword(),
					associado->getInstituicao(),
					cota, associado->getEmail(),
					associado->getEmailsRecebidos());
				this->associacao->eraseAssociado(associado,false);
				this->associacao->addAssociado(*a1);
				//associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";

			}
			else { //passa a so associado
				a1 = new Associado(
					associado->getNome(),
					associado->getID(),
					associado->getPassword(),
					associado->getInstituicao(),
					cota, associado->getEmail());
				temp.erase(position);
				temp.insert(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
		}
		else if (associado->getCota()->getEmDia()
			&& (associado->getCota()->getAtraso()
				< 5)) //inicialemnte como subscriber
		{
			if (emdiaBool) //passa a contributor
			{
				a1 = new Contributor(
					associado->getNome(),
					associado->getID(),
					associado->getPassword(),
					associado->getInstituicao(),
					cota, associado->getEmail());
				temp.erase(position);
				temp.insert(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";

			}
			else if (!emdiaBool && atraso < 5) //continua
			{
				associado->setCota(cota);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
			else { //passa a so associado
				a1 = new Associado(
					associado->getNome(),
					associado->getID(),
					associado->getPassword(),
					associado->getInstituicao(),
					cota, associado->getEmail());
				temp.erase(position);
				temp.insert(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}

		}
		else { //inicialmente como associado
			if (emdiaBool) //passa a contributor
			{
				a1 = new Contributor(
					associado->getNome(),
					associado->getID(),
					associado->getPassword(),
					associado->getInstituicao(),
					cota, associado->getEmail());
				temp.erase(position);
				temp.insert(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";

			}
			else if (!emdiaBool && atraso < 5) //passa a subscriber
			{
				a1 = new Subscriber(
					associado->getNome(),
					associado->getID(),
					associado->getPassword(),
					associado->getInstituicao(),
					cota, associado->getEmail());
				temp.erase(position);
				temp.insert(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
			else { //continua
				associado->setCota(cota);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
		}
	}
		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if (std::cin.get())
		{
			if (std::cin.eof())
				std::cin.clear();
			this->menuSessaoGestor(id);
		}

}

void AssociacaoMS::apagaGestor(unsigned int id){
	clearScreen(); //apagar conteudo do ecra
	if (associacao->getGestores().size() == 1)
	{
		std::cout << "Impossivel apagar a sua conta. Existe um unico gestor da associacao! \n\n";
		std::cout << "Pressione ENTER para continuar... " << std::endl;
		if (std::cin.get())
		{
			if (std::cin.eof()) std::cin.clear();
			this->menuSessaoGestor(id);
		}
	}
	
	std::vector<Gestor*> temp = associacao->getGestores();

	for (unsigned int i = 0; i < associacao->getGestores().size(); i++)
		if (associacao->getGestores().at(i)->getID() == id)
		{
			temp.erase(temp.begin() + i);
			associacao->setGestores(temp);
			std::cout << "A sua conta foi apagada com sucesso! \n\n";
		}

	std::cout << "Pressione ENTER para continuar... " << std::endl;
	if (std::cin.get())
	{
		if (std::cin.eof()) std::cin.clear();
		 
		this->menuLogin();
	}


}

void AssociacaoMS::apagaAssociado(unsigned int id){
	clearScreen(); //apagar conteudo do ecra
	unsigned int ID;
	auto temp = associacao->getAssociados();
	bool existeID = false;

	std::cout << "Associados disponiveis : \n\n";
	std::cout << std::setw(20) << "ID" << std::setw(20) << "Nome" << "\n";
	auto associados = this->associacao->getAssociados();
	std::set<Associado*, AssociadoCmp>::const_iterator it = associados.begin();

	for(;it!=associados.end();it++)
		std::cout << std::setw(20) << (*it)->getID() << std::setw(20) << (*it)->getNome() << "\n";

	std::cout << "\n";

	do
	{
		getNumber(ID, "Insira o id do associado a eliminar : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuSessaoGestor(id);
		}

		it = associados.begin();

		for (; it != associados.end(); it++)
			if ((*it)->getID() == ID)
			{
				existeID = true;
				this->associacao->eraseAssociado(*it,true);
				std::cout << "Associado apagado com sucesso! \n\n";

				std::cout << "Pressione ENTER para continuar... " << std::endl;
				if (std::cin.get())
				{
					if (std::cin.eof()) std::cin.clear();
					this->menuSessaoGestor(id);
				}


			}

	} while (!existeID);
}

template <class T>
void AssociacaoMS::envioEmail(T* associado){
	clearScreen();
	this->associacao->showContributors();
	this->associacao->showSubscribers();
	this->associacao->showGestores();

	std::string dest, corpo = "", temp;
	bool envio = false;

	std::cout << "Compor nova mensagem \n\n"
		<< "Remetente : " << associado->getEmail() << "\n";
	do
	{
		getString(dest, "Destinario (Insira o email) : ");
		if (std::cin.eof())
		{
			std::cin.clear();
			return;
		}
	} while (!(this->associacao->existeEmail(dest)));

	std::cout << "\n\n";
	std::cout << "Corpo Mensagem (Escreva 'ENVIAR' numa nova linha para enviar) : \n";

	while (!envio) {
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cin.clear();
			return;
		}
		if (temp == "ENVIAR")
		{
			envio = true;
			break;
		}
		else
			corpo += temp;
	}


	Email *email = new Email(associado->getEmail(), dest, corpo);
	this->associacao->addEmail(email);

	std::cout << "\nEnviado!\n";

}

template <class T>
void AssociacaoMS::visualizaEmailsRecebidos(T* associado)
{
	unsigned int opcao;

	do {
		clearScreen();
		std::cout << "Caixa de Entrada\n\n";

		for (unsigned int i = 0; i < associado->getEmailsRecebidos().size();i++)
			std::cout << "|" << i + 1 << "|" << std::setw(10) << "De: "	<< associado->getEmailsRecebidos().at(i)->getRemetente() << "   Conteudo: "	<< associado->getEmailsRecebidos().at(i)->getConteudo().substr(0, 20) << "..." << "\n";

		std::cout << "|" << associado->getEmailsRecebidos().size() + 1 << "|" << std::setw(12) << "Voltar";
		std::cout << "\n\n";

		getNumber(opcao, "Indique o numero do email que pretende visualizar: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			return;
		}

		if (opcao == associado->getEmailsRecebidos().size() + 1)
			break;

		if (opcao - 1 >= associado->getEmailsRecebidos().size()) {
			std::cout << "Email inexistente...\n\n";
			continue;
		}

		clearScreen();
		std::cout << "\nRemetente: "
				<< associado->getEmailsRecebidos().at(opcao - 1)->getRemetente()
				<< "\n\n";
		std::cout << "Conteudo: "
				<< associado->getEmailsRecebidos().at(opcao - 1)->getConteudo()
				<< "\n";

		return;

	} while (opcao != associado->getEmailsRecebidos().size() + 1);

}

template <class T>
void AssociacaoMS::visualizaEmailsEnviados(T* associado)
 {

	unsigned int opcao;

	do {
		clearScreen();
		std::cout << "Emails Enviados\n\n";

		for (unsigned int i = 0; i < associado->getEmailsEnviados().size(); i++)
			std::cout << "|" << i + 1 << "|" << std::setw(10) << "Para: "
					<< associado->getEmailsEnviados().at(i)->getDestinatario()
					<< "   Conteudo: "
					<< associado->getEmailsEnviados().at(i)->getConteudo().substr(0, 20) << "..." << "\n";

		std::cout << "|" << associado->getEmailsEnviados().size() + 1 << "|"
				<< std::setw(10) << "Voltar";
		std::cout << "\n\n";

		getNumber(opcao, "Indique o numero do email que pretende visualizar: ");
		if (std::cin.eof())
		{
			std::cin.clear();
			return;
		}

		if (opcao == associado->getEmailsEnviados().size() + 1)
			break;

		if (opcao - 1 >= associado->getEmailsEnviados().size()) {
			std::cout << "Email inexistente...\n\n";
			continue;
		}

		clearScreen();
		std::cout << "\nRemetente: "
				<< associado->getEmailsEnviados().at(opcao - 1)->getRemetente()
				<< "\n\n";
		std::cout << "Conteudo: "
				<< associado->getEmailsEnviados().at(opcao - 1)->getConteudo()
				<< "\n";

		return;

	} while (opcao != associado->getEmailsRecebidos().size() + 1);
}

template <class T>
void AssociacaoMS::addSubareaCientificaInteresse (T* associado){

	std::string chave;
	char lixo;
	bool invalido = true;

unsigned int c, aC, sC;

associacao->getDominio()->show();
std::cout << "\n\n";

do {
	getString(chave, "Introduza a nova subarea cientifica de interesse (x.x.x) : "); // garante que estao no formato x.x.x
	if (std::cin.eof())
	{
		std::cin.clear();
		if (associado->isContributor())
			menuSessaoContributor(associado);
		else if (associado->isSubscriber())
			menuSessaoSubscriber(associado);
		else
			menuSessaoOther(associado);
	}
	std::istringstream codigo(chave);

	codigo >> c >> lixo;
	if (lixo != '.') {
		std::cout << "Formato de entrada inv�lido, tente novamente\n\n";
		continue;
	}
	lixo = ',';
	codigo >> aC >> lixo;
	if (lixo != '.') {
		std::cout << "Formato de entrada inv�lido, tente novamente\n\n";
		continue;
	}
	codigo >> sC;
	invalido = false;

	auto subAreasInteresse = associado->getAreasInteresse();


	if ((!(codigo >> lixo)) && (associacao->getDominio()->getCiencia().size() > c - 1 && associacao->getDominio()->getCiencia().at(c - 1)->getAreas().size() > aC - 1 && associacao->getDominio()->getCiencia().at(c - 1)->getAreas().at(aC - 1)->getsubAreas().size() > sC - 1))
	{
		std::string subAreaParaAdicionar = associacao->getDominio()->getCiencia().at(c - 1)->getAreas().at(aC - 1)->getsubAreas().at(sC - 1)->getNomeSubAreaCientifica();
		if (std::find(subAreasInteresse.begin(), subAreasInteresse.end(), subAreaParaAdicionar) != subAreasInteresse.end()) //se essa subarea j� est� no vetor 
		{
			invalido = true;
			std::cout << "A subarea " << subAreaParaAdicionar << " ja consta das suas sub areas de interesse \n\n";
		}
		else
		{
			associado->addSubAreaInteresse(subAreaParaAdicionar);
			std::cout << "Nova subarea de interesse adicionada com sucesso. ";
		}
	}
	else {
		std::cout << "Falha ao adicionar subarea de interesse, tente novamente\n\n";
		invalido = true;
	}

} while (invalido);

}

void AssociacaoMS::enviarDominios() const
{
	std::ofstream out;
	out.open(this->ficheiroDominios);
	this->associacao->sortDominio();
	auto dominio = this->associacao->getDominio();
	auto ciencias = dominio->getCiencia();

	for (int i = 0; i < ciencias.size(); i++)
	{
		auto nomeCiencia = ciencias.at(i)->getNomeCiencia();
		auto areas = ciencias.at(i)->getAreas();

		if (i == 0)
			out << "@" << nomeCiencia;
		else
			out << "\n@" << nomeCiencia;

		for (int j = 0; j < areas.size(); j++)
		{
			auto nomeArea = areas.at(j)->getNomeAreaCientifica();
			auto subAreas = areas.at(j)->getsubAreas();
			out << "\n" << "#" << nomeArea;

			for (int k = 0; k < subAreas.size(); k++)
			{
				auto nomeSubArea = subAreas.at(k)->getNomeSubAreaCientifica();
				out << "\n" << "*" << nomeSubArea;
			}
		}
	}

	out.close();
}

void AssociacaoMS::enviarAssociados() const
{
	std::ofstream out;
	out.open(this->ficheiroAssociados);

	
	auto associados = this->associacao->getAssociados();
	auto it = associados.begin();

	for (; it != associados.end(); it++)
	{
		auto associado = *it;
		auto nome = associado->getNome();
		auto id = associado->getID();
		auto password = associado->getPassword();
		auto instituicao = associado->getInstituicao();
		std::string emDia;
		if (associado->getCota()->getEmDia() == true)
			emDia = "sim";
		else
			emDia = "nao";
		auto atraso = associado->getCota()->getAtraso();
		auto email = associado->getEmail();
		auto eventos = associado->getEventos();
		auto areas = associado->getAreasInteresse();

		if (it != associados.begin())
		{
			out << "\n";
		}
		out << nome << "," << id << "," << password << "," << instituicao << "," << emDia << "," << atraso << "," << email << ";";

		for (int i = 0; i < eventos.size(); i++)
		{
			if (i != 0)
			{
				out << ",";
			}
			out << eventos.at(i);
		}
		out << ";";
		for (int i = 0; i < areas.size(); i++)
		{
			if (i != 0)
			{
				out << ",";
			}
			out << areas.at(i);
		}
    }
	out.close();
}

void AssociacaoMS::enviarConferencias() const {
	std::ofstream out;
	out.open(this->ficheiroConferencias);
	int numeroConf = 0;

	this->associacao->sortEventos();
	auto eventos = this->associacao->getEventos();

	for (int i = 0; i < eventos.size(); i++) {
		if (!eventos.at(i)->escolaVerao()) {
			if (numeroConf != 0)
			{
				out << "\n";
			}
			else
				numeroConf++;
			for (unsigned int j = 0; j < eventos.at(i)->getPlaneadores().size();
					j++) {
				if (j != 0) {
					out << ",";
				}
				out << eventos.at(i)->getPlaneadores().at(j);
			}
			out << ";";

			for (unsigned int j = 0;
					j < eventos.at(i)->getOrganizadores().size(); j++) {
				if (j != 0) {
					out << ",";
				}
				out << eventos.at(i)->getOrganizadores().at(j);
			}
			out << ";";

			out << eventos.at(i)->getLocal() << ";" << eventos.at(i)->getTema()
					<< ";";

			auto date = eventos.at(i)->getData();

			out << date.getData();
			out << ";";
			if (eventos.at(i)->getApoioEvento().getApoioAssociacao())
				out << "1";
			else
				out << "0";
			out << ";";
			out << eventos.at(i)->getApoioEvento().getTipoApoio();
			out << ";";
			out << eventos.at(i)->getNumeroParticipantes();
			/*
			if(i!=(eventos.size()-1))
			  out << std::endl;
			  */
		}

	}
	out.close();
}

void AssociacaoMS::enviarEscolasVerao() const{
	std::ofstream out;
	out.open(this->ficheiroEscolasVerao);
	int numeroEscola = 0;

	auto eventos = this->associacao->getEventos();

	for (int i = 0; i < eventos.size(); i++)
		{
			if (eventos.at(i)->escolaVerao())
			{
				if (numeroEscola != 0)
				{
					out << "\n";
				}
				else
					numeroEscola++;
				for (unsigned int j = 0; j<eventos.at(i)->getPlaneadores().size(); j++)
				{
					if (j != 0)
					{
						out << ",";
					}
					out << eventos.at(i)->getPlaneadores().at(j);
				}
				out << ";";

				for (unsigned int j = 0; j<eventos.at(i)->getOrganizadores().size(); j++)
				{
					if (j != 0)
					{
						out << ",";
					}
					out << eventos.at(i)->getOrganizadores().at(j);
				}
				out << ";";

				out << eventos.at(i)->getLocal() << ";" << eventos.at(i)->getTema() << ";";

				auto date = eventos.at(i)->getData();

				out << date.getData();
				out << ";";

				if(eventos.at(i)->getApoioEvento().getApoioAssociacao())
				out << "1";
				else out << "0";

				out << ";";
				out << eventos.at(i)->getApoioEvento().getTipoApoio();
				out << ";";

				for (unsigned int j = 0; j<eventos.at(i)->getFormadores().size(); j++)
				{
					if (j != 0)
					{
						out << ",";
					}
					out << eventos.at(i)->getFormadores().at(j);
				}
				//out << std::endl;
			}
		}
	out.close();
}

void AssociacaoMS::enviarEmails() const
{
	std::ofstream out;
	out.open(this->ficheiroEmails);

	auto emails = this->associacao->getEmails();

	for (int i = 0; i < emails.size(); i++)
	{
		auto remetente = emails.at(i)->getRemetente();
		auto destinario = emails.at(i)->getDestinatario();
		auto conteudo = emails.at(i)->getConteudo();

		if (i != 0)
		{
			out << "\n";
		}
		out << remetente << "," << destinario << "," << conteudo;
    }
	out.close();
}

void AssociacaoMS::enviarGestores() const
{
	std::ofstream out;
	out.open(this->ficheiroGestores);

	this->associacao->sortGestores();
	auto gestores = this->associacao->getGestores();

	for (int i = 0; i < gestores.size(); i++)
	{
		auto nome = gestores.at(i)->getNome();
		auto id = gestores.at(i)->getID();
		auto password = gestores.at(i)->getPassword();
		auto email = gestores.at(i)->getEmail();

		if (i != 0) out << "\n";
		out << nome << ";" << id << ";" << password << ";" << email;
	}
	out.close();

}

/*------------------------------------------- menu final -------------------------------------------*/
void AssociacaoMS::menuTermino()
{
	clearScreen(); //apagar conteudo do ecra
	std::cout << "Obrigada pela visita! Ate `a proxima! \n\n";
	//sleep(5);
	exit(0);

}

//funcoes relacionadas com inputs do utilizador ///////////////////////////////////////////
bool hasChar(std::string &string) {
	for (unsigned int i = 0; i < (string.length()); i++) {
		if (((string.at(i)) < 48) || (string.at(i) > 57))
			return true;  //if the string has some char
	}

	return false;
}

void eliminateSpaces(std::string &string) {
	for (unsigned int i = 0; i < string.length() - 1; i++) {
		if ((string.at(i) == ' ') && (string.at(i + 1) == ' ')) {
			string.erase(i, 1); //erases the current space if it's followed by another space
			i = i - 1;
		}
	}

	if (string.at(0) == ' ') {
		string.erase(0, 1);
	}

	if ((string.at(string.length() - 1)) == ' ') {
		string.erase(string.length() - 1, 1);
	}

}

void getString(std::string &string, const std::string question) {
	std::string test;

	std::cout << question;
	test.clear();
	std::cin >> test;    //to test both '\n' and CTRL+Z

	while (std::cin.fail()) //if the input fails
	{
		if (std::cin.eof())
			return;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << question;
		std::cin >> test;
	}
	std::getline(std::cin, string);
	string = test + string;
	eliminateSpaces(string);
}

void getNumber(unsigned int &number, const std::string &question) {
	bool valid;

	std::string test;
	std::string number_string;

	std::cout << question;
	std::cin >> test;
	std::getline(std::cin, number_string);
	number_string = test + number_string;
	valid = hasChar(number_string);

	while ((std::cin.fail()) || ((!(std::cin.fail())) && valid))
	{
		if (std::cin.eof()) return;
		std::cin.clear();
		std::cout << question;
		std::cin >> test;
		std::getline(std::cin, number_string);
		number_string = test + number_string;
		valid = hasChar(number_string);
	}

	number = std::stoul(number_string);
}

void clearScreen() 
{
    system("CLS");
}
