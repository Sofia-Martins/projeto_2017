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
void clearScreen(); //pode (e deve) ser procurado um metodo melhor!!!

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
			this->menuTermino();

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
		getString(siglaAssociacao, "Sigla: ");

		std::transform(siglaAssociacao.begin(), siglaAssociacao.end(),
				siglaAssociacao.begin(), ::tolower); //converter sigla para letras minusculas

		for (unsigned int i = 0; i < associacoes.size(); i++) {
			if (siglaAssociacao == associacoes.at(i).first) {
				encontrou = true;
				std::cout
						<< "A sigla da associacao já esta a ser usada, tente outra! "
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
	unsigned int id = this->associacao->getID();
	std::string password;
	std::string enderecoEmail;

	do
	{
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
	this->associacao->setID(id++);

	std::cout << "ID atribuido: " << gestor->getID() << std::endl;
	std::cout << "Email: " <<gestor->getEnderecoEmail() << std::endl;

	std::cout << this->associacao->getNome();

	std::string nomeFicheiroGestores = siglaAssociacao+"_gestores.txt";

	this->enviarNovoGestorFicheiro(nomeFicheiroGestores);

	std::cout << "Pressione ENTER para continuar... " << std::endl;

	if(std::cin.get())
		this->menuBemVindo();
	

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
		if (opcao > associacoes.size())
			valido = false;
		else valido = true;

		if (std::cin.eof())
		{
			std::cin.clear();
			this->menuFicheiroAssociacoes();
		}
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
			dac.putback(carater);
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

		if(nome == "")
			break;

		eliminateSpaces(nome);
		eliminateSpaces(ID);
		eliminateSpaces(password);
		eliminateSpaces(instituicao);
		eliminateSpaces(emDiaString);
		eliminateSpaces(atraso);
		eliminateSpaces(email);
		eliminateSpaces(tema);
		eliminateSpaces(subareas);

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
		while (!ssEventos.eof())
		{
			std::string evento;
			getline(ssEventos, evento, ',');
			eliminateSpaces(evento);
			v_eventos.push_back(evento);
		}
		a1->setEventos(v_eventos);


		//guardar subareas de interesse
		std::istringstream ssSubAreas(subareas);
		std::vector<std::string> v_subareas;
		while (!ssSubAreas.eof())
		{
			std::string subArea;
			getline(ssSubAreas, subArea, ',');
			eliminateSpaces(subArea);
			v_subareas.push_back(subArea);
		}
		a1->setAreasInteresse(v_subareas);
		associacao->addAssociado(*a1);
		if (std::stoul(ID) >= this->associacao->getID()) this->associacao->setID(std::stoul(ID)+1);
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
		associacao->addEmail(*email);
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
		std::vector<int> vetorPlaneadores;
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
		std::vector<int> vetorOrganizadores;
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
		std::vector<int> vetorPlaneadores;
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
		std::vector<int> vetorOrganizadores;
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
		eliminateSpaces(tipoApoio);

		Apoio apoio(apoioB, tipoApoio);

		//buscar formadores
		std::vector <int> vetorFormadores;
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

		std::cout << "ID: "<< id << std::endl;

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

		std::cout << "3 " << std::endl;

		//buscar endereço de email do gestor
		getline(in, email);
		if(email == "")
			break;
		eliminateSpaces(email);

		//criar gestor
		Gestor* gestor = new Gestor(nome, id, password, email);
		this->associacao->addGestor(*gestor);
		if (id >= this->associacao->getID()) this->associacao->setID(id+1);

	}

	in.close();
}

/*------------------------------------------- menu 4 -------------------------------------------*/
void AssociacaoMS::menuLogin() {
	clearScreen();
	std::cout << "---- LOGIN ----\n\n";
	std::cout << "1. Sign up\n";
	std::cout << "2. Sign in\n";
	unsigned int opcao = 0, id = 0;
	std::string password;

	do
	{
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
			this->menuAssociacoes();
	} while (!((opcao == 1) || (opcao == 2)));

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
}

void AssociacaoMS::criaConta() {
	std::string nome, password, instituicao, email;
	std::sort(associacao->getAssociados().begin(), associacao->getAssociados().end());
	int ID = associacao->getAssociados().at(associacao->getAssociados().size() - 1)->getID() + 1;

	getString(nome, "Nome: ");
	getString(password, "Password: ");
	getString(instituicao, "Instituicao: ");
	getString(email, "Endereco de email: ");

	Cota *cota = new Cota(true, 0);

	Contributor *a = new Contributor(nome, ID, password, instituicao, cota, email);

	associacao->addAssociado(*a);

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
		for (unsigned int i = 0; i < associacao->getAssociados().size(); i++)
			if (associacao->getAssociados().at(i)->getID() == id) //ID valido
				{
				IDvalido = true;
				pos = i;
				}
		if (IDvalido)
		{
			do {
					getString(pass, "Password do associado: ");
					if(associacao->getAssociados().at(pos)->getPassword() == pass)
							PassValida = true;
					if (!PassValida)
					{
						if (std::cin.eof())
							this->menuLogin();
						std::cout << "Password invalida! \n\n";
					}
					else {
						this->menuSessaoAssociado(id);
					}
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
	std::cout << "Bem-Vindo Gestor \n\n";
	std::cout << "1) Criar um novo gestor\n"
		<< "2) Alterar um associado existente \n"
		<< "3) Apaga gestor \n"
		<< "4) Apaga associado \n"
		<< "5) Enviar email \n"
		<< "6) Terminar sessao \n\n";

	unsigned int opcao = 0;
	do
	{
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
			this->menuLogin();
	} while (!((opcao == 1) || (opcao == 2) || (opcao == 3) ||
			(opcao == 4) || (opcao == 5) || (opcao == 6)) );

	if (opcao == 1)
		this->criaGestor(associacao->getSigla(), false, id);
	else if (opcao == 2)
		this->alteraAssociado(id);
	else if (opcao == 3)
		this->apagaGestor(id);
	else if (opcao == 4)
		this->apagaAssociado(id);
	else if (opcao == 5)
		this->envioEmail(id);
	else if (opcao == 6)
		this->menuTermino();

}

void AssociacaoMS::menuSessaoAssociado(unsigned int id)
{
	auto associados = this->associacao->getAssociados();
	Associado* associado = NULL;

	//procura o associado
	for (unsigned int i = 0; i < associados.size(); i++)
	{
		if (associados.at(i)->getID() == id)
			associado = associados.at(i);
	}

	//verifica que tipo de associado é (contributor, subscriber, ou simplesmente um associado)
	if (associado->getCota()->getEmDia() == true)
		this->menuSessaoContributor(associado);
	/*
	else if (associado->getCota()->getAtraso() < 5)
		this->menuSessaoSubscriber(associado);
	else
		this->menuSessaoOther(associado);
	}
	*/

}

void AssociacaoMS::menuSessaoContributor(Associado* associado)
{
	clearScreen();
	std::cout << "Bem vindo " << associado->getNome() << "!" << std::endl << std::endl;

	std::cout << "_________________ O MEU ESPACO _________________\n\n";
	std::cout << "1. Informacoes da minha conta\n";
	std::cout << "2. Modificar a minha conta\n";
	std::cout << "3. Apagar a minha conta\n\n";

	std::cout << "_______________ ESPACO ASSOCIACAO ______________\n\n";
	std::cout << "4. Eventos\n";
	std::cout << "5. Emails\n";
	std::cout << "6. Areas e subareas cientificas dos restantes associados\n";
	std::cout << "7. Enviar email\n";
	std::cout << "8. Adicionar subarea cientifica de interesse\n\n";

	/* ---- variaveis ---- */
	unsigned int opcao;
	do
	{
		if (std::cin.eof())
			this->menuLogin();
		getNumber(opcao, "Opcao: ");
	} while ((opcao < 0) || (opcao > 6));

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

	case 4:
		clearScreen();
		associacao->showEventos(associado);
		break;
	}

	std::cout << "Pressione ENTER para continuar... " << std::endl;

		if(std::cin.get())
			this->menuSessaoContributor(associado);
}


void AssociacaoMS::modificarConta(Associado* associado) {

	std::string nome, pass;

	std::cout << "O que deseja alterar ? \n\n";
	std::cout << "1) Nome \n" << "2) Password \n\n";

	unsigned int opcao = 0;
	do {
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
			this->menuTermino();
	} while (!((opcao == 1) || (opcao == 2)));

	if (opcao == 1) {
		std::cout << "Nome Atual : " << associado->getNome();
		getString(nome, "\nNovo Nome : ");
		associado->setNome(nome);
		std::cout << "Nome alterado com sucesso!\n\n";

	} else if (opcao == 2) {
		std::cout << "Password Atual : " << associado->getPassword();
		getString(pass, "\nNova Password : ");
		associado->setPassword(pass);
		std::cout << "Password alterada com sucesso!\n\n";
	}

	std::cout << "Pressione ENTER para continuar... " << std::endl;

	if (std::cin.get())
		this->menuSessaoContributor(associado);

}

void AssociacaoMS::alteraAssociado(unsigned int id){

	unsigned int ID, atraso;
	int pos = -1;
	std::string nome, pass, emdia;
	bool emdiaBool;

	std::cout << "Associados disponiveis : \n\n";
	std::cout << std::setw(20) << "ID" << std::setw(20) << "Nome" << "\n";
	for(unsigned int i = 0; i < associacao->getAssociados().size(); i++)
		std::cout << std::setw(20) << associacao->getAssociados().at(i)->getID() << std::setw(20) << associacao->getAssociados().at(i)->getNome() << "\n";

	std::cout << "\n";

	do {
		getNumber(ID, "Introduza o ID do associado a alterar : ");
		for (unsigned int i = 0; i < associacao->getAssociados().size(); i++)
			if (associacao->getAssociados().at(i)->getID() == ID)
				pos = i;
		if (pos == -1)
			std::cout << "ID invalido!!\n\n";
	} while (pos == -1);

	std::cout << "O que deseja alterar ? \n\n";
	std::cout << "1) Nome \n" << "2) Password \n" << "3) Cota \n\n";

	unsigned int opcao = 0;
	do {
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
			this->menuTermino();
	} while (!((opcao == 1) || (opcao == 2) || (opcao == 3)));

	if (opcao == 1) {
		std::cout << "Nome Atual : "
			<< associacao->getAssociados().at(pos)->getNome();
		getString(nome, "\nNovo Nome : ");
		associacao->getAssociados().at(pos)->setNome(nome);
		std::cout << "Nome alterado com sucesso!\n\n";

	}
	else if (opcao == 2) {
		std::cout << "Password Atual : "
			<< associacao->getAssociados().at(pos)->getPassword();
		getString(pass, "\nNova Password : ");
		associacao->getAssociados().at(pos)->setPassword(pass);
		std::cout << "Password alterada com sucesso!\n\n";
	}
	else if (opcao == 3) {
		std::cout << "Estado da cota atual : ";
				if(associacao->getAssociados().at(pos)->getCota()->getEmDia())
					std::cout << "Em dia !\n\n";
				else std::cout << "Nao esta em dia, com um atraso de "
						<< associacao->getAssociados().at(pos)->getCota()->getAtraso()
					<< " anos ! \n\n";
		std::cout << "Novo estado da cota : ";
		getString(emdia, "Em dia ? (true/false) ");
		if (emdia == "true")
			emdiaBool = true;
		else
			emdiaBool = false;
		if (!emdiaBool)
			getNumber(atraso, "Atraso (em anos) : ");
		else
			atraso = 0;

		Associado *a1;
		Cota *cota=new Cota(emdiaBool, atraso);
		std::vector<Associado*> temp = associacao->getAssociados();

		if (associacao->getAssociados().at(pos)->getCota()->getEmDia()) //inicialmente como contributor
		{
			if (emdiaBool) //continua
			{

				associacao->getAssociados().at(pos)->setCota(cota);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
			else if (!emdiaBool && atraso < 5) //passa a subscriber
			{
				a1 = new Subscriber(
					associacao->getAssociados().at(pos)->getNome(),
					associacao->getAssociados().at(pos)->getID(),
					associacao->getAssociados().at(pos)->getPassword(),
					associacao->getAssociados().at(pos)->getInstituicao(),
					cota, associacao->getAssociados().at(pos)->getEmail());
				temp.erase(temp.begin() + pos);
				temp.push_back(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";

			}
			else { //passa a so associado
				a1 = new Associado(
					associacao->getAssociados().at(pos)->getNome(),
					associacao->getAssociados().at(pos)->getID(),
					associacao->getAssociados().at(pos)->getPassword(),
					associacao->getAssociados().at(pos)->getInstituicao(),
					cota, associacao->getAssociados().at(pos)->getEmail());
				temp.erase(temp.begin() + pos);
				temp.push_back(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
		}
		else if (associacao->getAssociados().at(pos)->getCota()->getEmDia()
			&& (associacao->getAssociados().at(pos)->getCota()->getAtraso()
				< 5)) //inicialemnte como subscriber
		{
			if (emdiaBool) //passa a contributor
			{
				a1 = new Contributor(
					associacao->getAssociados().at(pos)->getNome(),
					associacao->getAssociados().at(pos)->getID(),
					associacao->getAssociados().at(pos)->getPassword(),
					associacao->getAssociados().at(pos)->getInstituicao(),
					cota, associacao->getAssociados().at(pos)->getEmail());
				temp.erase(temp.begin() + pos);
				temp.push_back(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";

			}
			else if (!emdiaBool && atraso < 5) //continua
			{
				associacao->getAssociados().at(pos)->setCota(cota);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
			else { //passa a so associado
				a1 = new Associado(
					associacao->getAssociados().at(pos)->getNome(),
					associacao->getAssociados().at(pos)->getID(),
					associacao->getAssociados().at(pos)->getPassword(),
					associacao->getAssociados().at(pos)->getInstituicao(),
					cota, associacao->getAssociados().at(pos)->getEmail());
				temp.erase(temp.begin() + pos);
				temp.push_back(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}

		}
		else { //inicialmente como associado
			if (emdiaBool) //passa a contributor
			{
				a1 = new Contributor(
					associacao->getAssociados().at(pos)->getNome(),
					associacao->getAssociados().at(pos)->getID(),
					associacao->getAssociados().at(pos)->getPassword(),
					associacao->getAssociados().at(pos)->getInstituicao(),
					cota, associacao->getAssociados().at(pos)->getEmail());
				temp.erase(temp.begin() + pos);
				temp.push_back(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";

			}
			else if (!emdiaBool && atraso < 5) //passa a subscriber
			{
				a1 = new Subscriber(
					associacao->getAssociados().at(pos)->getNome(),
					associacao->getAssociados().at(pos)->getID(),
					associacao->getAssociados().at(pos)->getPassword(),
					associacao->getAssociados().at(pos)->getInstituicao(),
					cota, associacao->getAssociados().at(pos)->getEmail());
				temp.erase(temp.begin() + pos);
				temp.push_back(a1);
				associacao->setAssociados(temp);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
			else { //continua
				associacao->getAssociados().at(pos)->setCota(cota);
				std::cout << "\nCota alterada com sucesso!\n\n";
			}
		}

		std::cout << "Pressione ENTER para continuar... " << std::endl;

		if(std::cin.get())
			this->menuSessaoGestor(id);

	}
}

void AssociacaoMS::apagaGestor(unsigned int id){
	if (associacao->getGestores().size() == 1)
	{
		std::cout << "Impossivel apagar gestor. So existe um! \n\n";
		std::cout << "Pressione ENTER para continuar... " << std::endl;
		if (std::cin.get())
			this->menuSessaoGestor(id);
	}
	clearScreen(); //apagar conteudo do ecra
	unsigned int ID;
	std::vector<Gestor*> temp = associacao->getGestores();
	getNumber(ID, "Insira o id do gestor a eliminar : ");
	for (unsigned int i = 0; i < associacao->getGestores().size(); i++)
		if (associacao->getGestores().at(i)->getID() == ID)
		{
			temp.erase(temp.begin() + i);
			associacao->setGestores(temp);
			std::cout << "Gestor apagado com sucesso! \n\n";


		}

	std::cout << "Pressione ENTER para continuar... " << std::endl;
	if (std::cin.get())
		this->menuSessaoGestor(id);


}

void AssociacaoMS::apagaAssociado(unsigned int id){
	clearScreen(); //apagar conteudo do ecra
	unsigned int ID;
	std::vector<Associado*> temp = associacao->getAssociados();

	std::cout << "Associados disponiveis : \n\n";
	std::cout << std::setw(20) << "ID" << std::setw(20) << "Nome" << "\n";
	for(unsigned int i = 0; i < associacao->getAssociados().size(); i++)
		std::cout << std::setw(20) << associacao->getAssociados().at(i)->getID() << std::setw(20) << associacao->getAssociados().at(i)->getNome() << "\n";

	std::cout << "\n";

	getNumber(ID, "Insira o id do associado a eliminar : ");
	for (unsigned int i = 0; i < associacao->getAssociados().size(); i++)
		if (associacao->getAssociados().at(i)->getID() == ID)
		{
			temp.erase(temp.begin() + i);
			associacao->setAssociados(temp);
			std::cout << "Associado apagado com sucesso! \n\n";


		}
			std::cout << "Pressione ENTER para continuar... " << std::endl;
			if(std::cin.get())
				this->menuSessaoGestor(id);
}

void AssociacaoMS::envioEmail(unsigned int id){
	clearScreen(); //apagar conteudo do ecra
	int pos = -1;
	std::string dest, corpo = "", temp;
	bool gestor = true, envio = false;
	for (unsigned int i = 0; i < associacao->getAssociados().size(); i++)
		if (associacao->getAssociados().at(i)->getID() == id){
			pos = i;
			gestor = false;
		}

	if(gestor)
		for (unsigned int i = 0; i < associacao->getGestores().size(); i++)
				if (associacao->getGestores().at(i)->getID() == id)
					pos = i;

	std::cout << "Compor nova mensagem \n\n"
			<< "Remetente : " << associacao->getAssociados().at(pos)->getEmail() << "\n";
	getString(dest, "Destinario : ");
	std::cout << "\n\n";
	std::cout << "Corpo Mensagem (Escreva 'ENVIAR' para enviar) : \n";

	while(!envio){
		std::getline(std::cin,temp);
		if(temp == "ENVIAR")
		{
			envio = true;
		}
		corpo += temp;

	}
	std::cout << "\nEnviado!\n";

	std::cout << "Pressione ENTER para continuar... " << std::endl;
	if(std::cin.get())
		this->menuSessaoGestor(id);
}

/*------------------------------------------- menu final -------------------------------------------*/
void AssociacaoMS::menuTermino()
{
	clearScreen(); //apagar conteudo do ecra
	std::cout << "Obrigada pela visita! Ate `a proxima! :-D\n\n";
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
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	//system("CLS");
}
