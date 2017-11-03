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
void getID(Associacao &ac1, unsigned int id, std::string pass);
void getPassword(Associacao &ac1, std::string pass);
void criaConta(Associacao &ac1);

//variaveis globais
std::string retornoMenu = "/";

/*------------------------------------------- menu 1 -------------------------------------------*/
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

	std::cout << "menu bem vindo selecao\n";
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
/*------------------------------------------- menu 2.1 -------------------------------------------*/

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
		std::cout << nomeFicheiro;
		streamAssociacoes.open(nomeFicheiro);
		if (streamAssociacoes.is_open())
			std::cout << "Open!\n\n";
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
		eliminateSpaces(nomeAssociacao);
		eliminateSpaces(siglaAssociacao);

		//acrescentar a sigla e nome da associacao ao vetor associacoes
		associacoes.push_back(std::pair<std::string, std::string>(siglaAssociacao, nomeAssociacao));
	}

	streamAssociacoes.close();
}

/*------------------------------------------- menu 2.2 -------------------------------------------*/
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
		std::cout << nomeFicheiro << "\n\n";

		nomeFicheiro = nomeFicheiro + ".txt";
		streamAssociacoes.open(nomeFicheiro);
		if (streamAssociacoes.is_open())
			std::cout << "Open!\n\n";
	} while (streamAssociacoes.fail());

	//se o ficheiro existir
	ficheiroAssociacoes = nomeFicheiro;
	lerAssociacoes();

	nomeFicheiroAssociacoes = nomeFicheiro;

}

void AssociacaoMS::menuCriaAssociacao() {

	std::string nomeFicheiroAssociacoes;

	clearScreen(); //apagar conteudo do ecra
	this->menuAbrirFicheiroAssociacoes(nomeFicheiroAssociacoes);


	clearScreen(); //apagar conteudo do ecra
	std::cout << "-------------- CRIAR ASSOCIACAO --------------\n\n";
	std::string nomeAssociacao, siglaAssociacao;

	getString(nomeAssociacao, "Nome: ");
	getString(siglaAssociacao, "Sigla: ");

	associacoes.push_back(std::pair<std::string, std::string>(siglaAssociacao, nomeAssociacao));

	this->enviarNovaAssociacaoFicheiro(nomeFicheiroAssociacoes);
}

void AssociacaoMS::enviarNovaAssociacaoFicheiro(std::string & nomeFicheiroAssociacoes) {
	std::ofstream streamAssociacoes;
	streamAssociacoes.open(nomeFicheiroAssociacoes);

	if (streamAssociacoes.is_open())
	{
		for (unsigned int i = 0; i<associacoes.size(); i++)
			streamAssociacoes << associacoes.at(i).first << ";" << associacoes.at(i).second << std::endl;
	}
	else std::cout << "Falha ao abrir ficheiro de destino" << std::endl;

	menuBemVindo();
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
	ficheiroAssociados = associacoes.at(opcao - 1).first + "_associados.txt"; //Confirmar q é o second!
	ficheiroConferencias = associacoes.at(opcao - 1).first + "_conferencias.txt";
	ficheiroDominios = associacoes.at(opcao - 1).first + "_dominios.txt";
	ficheiroEmails = associacoes.at(opcao - 1).first + "_emails.txt";
	ficheiroEscolasVerao = associacoes.at(opcao - 1).first + "_escolaVerao.txt";
	ficheiroGestores = associacoes.at(opcao - 1).first + "_gestores.txt";

	//ler ficheiros
	lerDominios();
	//lerAssociados(ficheiroAssociados);
	lerEmails();
	lerConferencias();
	lerEscolasVerao();
	lerGestores();

	//proximo menu
	//this->menuLogin(ac1);

}
void AssociacaoMS::lerDominios() {

	std::ifstream dac; //Dominios e Areas Cientificas
	dac.open(ficheiroDominios);

	DominioCientifico* dominio = new DominioCientifico();
	char carater;
	std::string cienciaS, areaCientificaS, subAreaS;
	Ciencia* ciencia = NULL;
	AreaCientifica* area = NULL;
	SubAreaCientifica* subArea = NULL;

	while (!dac.eof())
	{
		dac.get(carater);

		if (carater == '@')
		{
			getline(dac, cienciaS);
			eliminateSpaces(cienciaS);
			ciencia = new Ciencia(cienciaS);
			dominio->addCiencia(ciencia);
		}
		else if (carater == '#')
		{
			getline(dac, areaCientificaS);
			eliminateSpaces(areaCientificaS);
			area = new AreaCientifica(areaCientificaS);
			ciencia->addAreaCientifica(area);
		}
		else if (carater == '*')
		{
			getline(dac, subAreaS);
			eliminateSpaces(subAreaS);
			subArea = new SubAreaCientifica(subAreaS);
			area->addSubAreaCientifica(subArea);
		}	
	}

	this->associacao->setDominio(dominio);
	dac.close();
}

/*
void AssociacaoMS::lerAssociados() {

	std::ifstream streamAssociados;
	streamAssociados.open(ficheiroAssociados);

	std::string linhaFicheiro, nome, ID, password, instituicao, emDiaString, atraso, email, tema, subareas;

	while (!streamAssociados.eof()) {
		getline(streamAssociados, linhaFicheiro);
		std::stringstream input(linhaFicheiro);
		getline(input, nome, ','); eliminateSpaces(nome);
		getline(input, ID, ','); eliminateSpaces(ID);
		getline(input, password, ','); eliminateSpaces(password);
		getline(input, instituicao, ','); eliminateSpaces(instituicao);
		getline(input, emDiaString, ','); eliminateSpaces(emDiaString);
		getline(input, atraso, ','); eliminateSpaces(atraso);
		getline(input, email, ';'); eliminateSpaces(email);
		getline(input, tema, ';'); eliminateSpaces(tema);
		getline(input, subareas); eliminateSpaces(subareas);
		bool emDia;
		if (emDiaString == "sim")
			emDia = true;
		else emDia = false;
		Cota *cota = new Cota(emDia, std::stoul(atraso));
		Associado *a1 = new Associado(nome, std::stoul(ID), password, instituicao, cota, email);
		if (emDia)
			Contributor a1();
		else if (std::stoul(atraso) < 5)
			Subscriber a1();
		//guardar temas de eventos
		std::vector<std::string> v_eventos;
		do
		{
			int p1 = tema.find_first_of(","); // posicao da vírgula
			v_eventos.push_back(tema.substr(1, p1 - 1));
			tema = tema.substr(p1 + 1);
		} while (tema.find_first_of(",") != tema.size() - 1);
		a1->setEventos(v_eventos);
		//guardar subareas de interesse
		std::vector<std::string> v_subareas;
		do
		{
			int p1 = subareas.find_first_of(","); // posicao da vírgula
			v_subareas.push_back(subareas.substr(1, p1 - 1));
			subareas = subareas.substr(p1 + 1);
		} while (subareas.find_first_of(",") != subareas.size() - 1);
		a1->setAreasInteresse(v_subareas);
		ac1.addAssociado(*a1);
	}
}
*/

void AssociacaoMS::lerEmails()
{
	//abrir ficheiro
	std::ifstream in;
	in.open(ficheiroEmails);
	std::string remetente, destinatario, conteudo;

	//extrair informação do ficheiro
	while (!in.eof())
	{
		getline(in, remetente, ',');
		getline(in, destinatario, ',');
		getline(in, conteudo);
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

	while (!in.eof())
	{
		//buscar planeadores
		std::vector<int> vetorPlaneadores;
		std::string ID; //id do planeador
		std::string planeadores;
		getline(in, planeadores, ';');
		std::istringstream ssPlaneadores(planeadores);

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

		//buscar numero de participantes
		std::string numeroParticipantes;
		getline(in, numeroParticipantes);
		eliminateSpaces(numeroParticipantes);
		unsigned int nParticipantes = stoul(numeroParticipantes);

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

	while (!in.eof())
	{
		//buscar planeadores
		std::vector<int> vetorPlaneadores;
		std::string ID; //id do planeador
		std::string planeadores;
		getline(in, planeadores, ';');
		std::istringstream ssPlaneadores(planeadores);

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
	std::ifstream in;
	in.open(ficheiroGestores);

	while (!in.eof())
	{
		std::string nome;
		std::string idS;
		std::string password;
		std::string email;
		unsigned int id;

		//buscar nome do gestor
		getline(in, nome, ';');
		eliminateSpaces(nome);

		//buscar id do gestor
		getline(in, idS, ';');
		eliminateSpaces(idS);
		id = stoi(idS);

		//buscar password do gestor
		getline(in, password, ';');
		eliminateSpaces(password);

		//buscar endereço de email do gestor
		getline(in, email);
		eliminateSpaces(email);

		//criar gestor
		Gestor* gestor = new Gestor(nome, id, password, email);
		this->associacao->addGestor(*gestor);
	}
	in.close();
}

/*------------------------------------------- menu 4 -------------------------------------------*/
void AssociacaoMS::menuLogin(Associacao &ac1) {
	std::cout << "---- LOGIN ----\n\n";
	std::cout << "1. Sign up\n";
	std::cout << "2. Sign in\n";
	unsigned int opcao = 0, id = 0;
	std::string password;

	do
	{
		getNumber(opcao, "Opcao: ");
		if (std::cin.eof())
			this->menuTermino();
	} while (!((opcao == 1) || (opcao == 2)));

	if (opcao == 1) {
		//cria conta com id automatico
		std::cout << "---- SIGN UP ----\n\n";
		criaConta(ac1);

	}

	if (opcao == 2) {
		//acede a conta da lista associados
		std::cout << "---- SIGN IN ----\n\n";
		getID(ac1, id, password);
		//caso validado acede a menu seguinte. ***Ver funcao getPassword***

	}
}
void criaConta(Associacao &ac1) {
	std::string nome, password, instituicao, email;
	int ID = ac1.getAssociados().at(ac1.getAssociados().size() - 1)->getID() + 1; //falta ordernar vetor!!!!!

	getString(nome, "Nome: ");
	getString(password, "Password: ");
	getString(instituicao, "Instituicao: ");
	getString(email, "Endereco de email: ");

	Cota *cota = new Cota(true, 0);

	Contributor *a = new Contributor(nome, ID, password, instituicao, cota, email);

	ac1.getAssociados().push_back(a);

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
	system("CLS");
}

//ACABARRR!!!!!!!
void getID(Associacao &ac1, unsigned int id, std::string pass) {
	bool IDvalido = false;
	do {
		getNumber(id, "ID: ");

		for (int i = 0; i < ac1.getAssociados().size(); i++)
			if (ac1.getAssociados().at(i)->getID() == id) //ID valido
				IDvalido = true;
		if (IDvalido)
			getPassword(ac1, pass);
		else
			std::cout << "ID invalido!! \n\n";
	} while (!IDvalido);

}

void getPassword(Associacao &ac1, std::string pass) {
	bool PassValida = false;
	do {
		getString(pass, "Password: ");
		for (int i = 0; i < ac1.getAssociados().size(); i++)
			if (ac1.getAssociados().at(i)->getPassword() == pass) //pass valido
				PassValida = true;
		if (!PassValida)
			std::cout << "Password invalid<!! \n\n";
		//else acede a menu seguinte!!!
	} while (!PassValida);
}