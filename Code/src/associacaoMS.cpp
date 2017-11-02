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
std::string retornoMenu="/";

/*------------------------------------------- menu 1 -------------------------------------------*/
void AssociacaoMS::menuBemVindo()
{
	clearScreen(); //apagar conteudo do ecra

	std::cout<<"---- BEM-VINDO AO GESTOR DE ASSOCIACOES CIENTIFICAS! ----\n\n";
	std::cout <<"1. Criar associacao\n";
	std::cout <<"2. Aceder a uma associacao ja existente\n\n";

	this->menuBemVindoSelecao();

}

void AssociacaoMS::menuBemVindoSelecao()
{

	std::cout<<"menu bem vindo selecao\n";
	unsigned int numeroOpcao=0;

	do
	{
		getNumber(numeroOpcao,"Opcao: ");

		if(std::cin.eof())
			this->menuTermino();

	}while(!((numeroOpcao==1) || (numeroOpcao==2)));

	if(numeroOpcao==1)
		this->menuCriaAssociacao();

	if(numeroOpcao==2)
		this->menuFicheiroAssociacoes();
	//else: invoca o menu para criar uma associacao
}


/*------------------------------------------- opcao 1 -------------------------------------------*/


void AssociacaoMS::menuAbrirFicheiroAssociacoes(std::string & nomeFicheiroAssociacoes) {

	std::string nomeFicheiro;
	std::ifstream streamAssociacoes;

	do {
		getString(nomeFicheiro,"Por favor introduza o nome do ficheiro das associacoes (sem .txt): ");
		if (std::cin.eof())
		{
			std::cin.clear();
			menuBemVindo(); //se o utilizador inseriu CTRL+D
		}
		std::cout << nomeFicheiro << "\n\n";

		nomeFicheiro = nomeFicheiro + ".txt";
		streamAssociacoes.open(nomeFicheiro);
		if(streamAssociacoes.is_open())
			std::cout << "Open!\n\n";
	} while (streamAssociacoes.fail());

	//se o ficheiro existir
	ficheiroAssociacoes = nomeFicheiro;
	lerAssociacoes(nomeFicheiro);

	nomeFicheiroAssociacoes = nomeFicheiro;

}

void AssociacaoMS::menuCriaAssociacao(){

	std::string nomeFicheiroAssociacoes;

	clearScreen(); //apagar conteudo do ecra
	this->menuAbrirFicheiroAssociacoes(nomeFicheiroAssociacoes);


	clearScreen(); //apagar conteudo do ecra
	std::cout<<"-------------- CRIAR ASSOCIACAO --------------\n\n";
	std::string nomeAssociacao, siglaAssociacao;

	getString(nomeAssociacao, "Nome: ");
	getString(siglaAssociacao, "Sigla: ");

	associacoes.push_back(std::pair<std::string,std::string>(siglaAssociacao,nomeAssociacao));

	this->enviarNovaAssociacaoFicheiro(nomeFicheiroAssociacoes);
}

void AssociacaoMS::enviarNovaAssociacaoFicheiro(std::string & nomeFicheiroAssociacoes){
	std::ofstream streamAssociacoes;
	streamAssociacoes.open(nomeFicheiroAssociacoes);

	if(streamAssociacoes.is_open())
	{
		for(unsigned int i=0; i<associacoes.size(); i++)
			streamAssociacoes << associacoes.at(i).first << ";" << associacoes.at(i).second << std::endl;
	}
	else std::cout << "Falha ao abrir ficheiro de destino" << std::endl;

	menuBemVindo();
}

/*------------------------------------------- opcao 2 -------------------------------------------*/

void AssociacaoMS::menuFicheiroAssociacoes() {
	clearScreen(); //apagar conteudo do ecra
	std::cout<<"---- ESCOLHER FICHEIRO DAS ASSSOCIACOES ----\n\n";
	menuFicheiroAssociacoesSelecao(); //invocacao do metodo
}

void AssociacaoMS::menuFicheiroAssociacoesSelecao() {

	std::string nomeFicheiro;
	std::ifstream streamAssociacoes;

	do {
		getString(nomeFicheiro,"Por favor introduza o nome do ficheiro das associacoes (sem .txt): ");
		if (std::cin.eof())
		{
			std::cin.clear();
			menuBemVindo(); //se o utilizador inseriu CTRL+D
		}
		std::cout << nomeFicheiro << "\n\n";

		nomeFicheiro = nomeFicheiro + ".txt";
		streamAssociacoes.open(nomeFicheiro);
		if(streamAssociacoes.is_open())
			std::cout << "Open!\n\n";
	} while (streamAssociacoes.fail());

	//se o ficheiro existir
	ficheiroAssociacoes = nomeFicheiro;
	lerAssociacoes(nomeFicheiro);

	this->menuAssociacoes(); //selecionar associacao
}

void AssociacaoMS::lerAssociacoes(std::string ficheiroAssociacoes)
{
	std::ifstream streamAssociacoes;
	std::string linhaFicheiro, siglaAssociacao, nomeAssociacao;
	streamAssociacoes.open(ficheiroAssociacoes);
	std::istringstream ssFicheiro;

	while(!streamAssociacoes.eof())
	{
		getline(streamAssociacoes,linhaFicheiro); //linha que tem a sigla e nome da associacao
		std::stringstream ssFicheiro(linhaFicheiro);
		getline(ssFicheiro,siglaAssociacao,';');
		getline(ssFicheiro,nomeAssociacao);
		//eliminateSpaces(nomeAssociacao);
		//eliminateSpaces(siglaAssociacao);

		//acrescentar a sigla e nome da associacao ao vetor associacoes
		associacoes.push_back(std::pair<std::string,std::string>(siglaAssociacao,nomeAssociacao));
	}


}

void AssociacaoMS::menuAssociacoes(){
	unsigned int opcao = 0, i= 0;
	bool valido;
	std::cout <<"---- ESCOLHER ASSOCIACAO ----\n\n";

	for(i ; i < associacoes.size(); i++)
		std::cout << i+1 << ". " << associacoes[i].first;

	do
	{
		getNumber(opcao,"Opcao: ");
		if(opcao > associacoes.size())
			valido = false;
		else valido = true;

		if(std::cin.eof())
			this->menuTermino();
	}while(!valido);

	Associacao ac1(associacoes[opcao - 1].second); //criar associacao
	ficheiroAssociados = associacoes[opcao - 1].first + "_associados.txt"; //Confirmar q é o second!
	ficheiroConferencias = associacoes[opcao - 1].first + "_conferencias.txt";
	ficheiroDominios = associacoes[opcao - 1].first + "_dominios.txt";
	ficheiroEmails = associacoes[opcao - 1].first + "_emails.txt";
	ficheiroEscolasVerao = associacoes[opcao - 1].first + "_escolaVerao.txt";
	ficheiroGestores = associacoes[opcao - 1].first + "_gestores.txt";

	//ler ficheiros...
	DominioCientifico  DC = lerDominios(ficheiroDominios);
	lerAssociados(ac1, ficheiroAssociados, &DC);

	ac1.setDominio(&DC);
	this->menuLogin(ac1);

}

DominioCientifico AssociacaoMS::lerDominios(std::string ficheiroDominios){
	std::ifstream dac; //Dominios e Areas Cientificas
	dac.open(ficheiroDominios);
	char carater;
	std::string ciencia, areaCientifica, subArea;
	DominioCientifico dominioCientifico;

	dac >> carater;
	Ciencia c;
	AreaCientifica ac;
	SubAreaCientifica sac;

	do
	{

		if (carater == '@')
		{
			if(c.getNomeCiencia() != "")
				dominioCientifico.addCiencia(&c);

			getline(dac, ciencia);
			dac >> carater;
			c.setNomeCiencia(ciencia);

			if (carater == '#')
			{
				getline(dac, areaCientifica);
				dac >> carater;
				ac.setNomeAreaCientifica(areaCientifica);

				while (carater == '*')
				{
					getline(dac, subArea);
					dac >> carater;
					std::string sigla = subArea.substr(subArea.length()-7, subArea.length() - 1);
					sac.setNomeSubAreaCientifica(subArea);
					sac.setSiglaSubAreaCientifica(sigla);

					ac.addSubAreaCientifica(&sac);
				}
				c.addAreaCientifica(&ac);
			}
			else { dac.ignore(1000, '\n'); }
		}

		else
		{
			if (carater == '#')
			{
				getline(dac, areaCientifica);
				dac >> carater;
				AreaCientifica ac(areaCientifica);

				while (carater == '*')
				{
					getline(dac, subArea);
					dac >> carater;
					std::string sigla = subArea.substr(subArea.length()-7, subArea.length() - 1);
					SubAreaCientifica sac(subArea, sigla);

					ac.addSubAreaCientifica(&sac);
				}

				c.addAreaCientifica(&ac);
			}
			else { dac.ignore(1000, '\n'); }
		}


	} while (!dac.eof());

	//teste para confirmar que funciona
/*
	std::ofstream teste;
	teste.open("teste.txt");

		for (int i = 0; i < dominioCientifico.getCiencia().size(); i++)
		{
			teste << "@" << dominioCientifico.getCiencia().at(i) << std::endl;
			for (int j = 0; j < dominioCientifico.getCiencia().at(i)->getAreas().size(); j++)
			{
				teste << "#" << dominioCientifico.getCiencia().at(i)->getAreas().at(j) << std::endl;
				for (int k = 0; k < dominioCientifico.getCiencia().at(i)->getAreas().at(j)->getsubAreas().size(); k++)
				{
					teste << "*" << dominioCientifico.getCiencia().at(i)->getAreas().at(j)->getsubAreas().at(k) << std::endl;
				}

				teste << std::endl;
			}

			teste << std::endl;
		}

*/

	return dominioCientifico;
}

void AssociacaoMS::lerAssociados(Associacao &ac1, std::string ficheiroAssociados, DominioCientifico *dominio){
	std::ifstream streamAssociados;
	streamAssociados.open(ficheiroAssociados);
	std::string linhaFicheiro, nome, password, instituicao, emDiaString, email, tema, subareas;
	unsigned int ID, atraso;

	while(!streamAssociados.eof()){
		getline(streamAssociados, linhaFicheiro);
		std::stringstream input(linhaFicheiro);
		getline(input,nome,','); //eliminateSpaces(nome);
		input >> ID;
		input.ignore(1000, ',');
		//getline(input,ID,',');
		getline(input,password,','); //eliminateSpaces(password);
		getline(input,instituicao,','); //eliminateSpaces(instituicao);
		getline(input,emDiaString,','); //eliminateSpaces(emDiaString);
		input >> atraso;
		input.ignore(1000, ',');
		//getline(input,atraso,',');
		getline(input,email,';'); //eliminateSpaces(email);
		getline(input,tema,';'); //eliminateSpaces(tema);
		getline(input,subareas); //eliminateSpaces(subareas);



		bool emDia;
		if(emDiaString == "sim")
			emDia = true;
		else emDia = false;

		Cota *cota = new Cota(emDia, atraso);
		Associado *a1 = new Associado(nome, ID, password, instituicao, cota, email);

		if(emDia)
			Contributor a1();
		else if (atraso < 5)
			Subscriber a1();


		//guardar temas de eventos
		std::vector<std::string> v_eventos;

		while (tema.find(",") != tema.npos)
		{
			int p1 = tema.find_first_of(","); // posicao da vírgula
			v_eventos.push_back(tema.substr(1, p1 - 1));
			tema = tema.substr(p1 + 1);

		}

		a1->setEventos(v_eventos);



		//guardar subareas de interesse
		std::vector<std::string> v_subareas;

		while (subareas.find(",") != subareas.npos)
		{
			int p1 = subareas.find_first_of(","); // posicao da vírgula
			v_subareas.push_back(subareas.substr(1, p1 - 1));
			subareas = subareas.substr(p1 + 1);

		}

		a1->setAreasInteresse(v_subareas);


		ac1.addAssociado(*a1);


	}

}

void AssociacaoMS::menuLogin(Associacao &ac1){
	std::cout <<"---- LOGIN ----\n\n";
	std::cout <<"1. Sign up\n";
	std::cout <<"2. Sign in\n";
	unsigned int opcao=0, id = 0;
	std::string password;

	std::cout << "Hello!\n\n";

	do
	{
		getNumber(opcao,"Opcao: ");
		if(std::cin.eof())
			this->menuTermino();
	}while(!((opcao==1) || (opcao==2)));

	if(opcao == 1){
		//cria conta com id automatico
		std::cout <<"---- SIGN UP ----\n\n";
		criaConta(ac1);

	}

	if(opcao == 2){
		//acede a conta da lista associados
		std::cout <<"---- SIGN IN ----\n\n";
		getID(ac1, id, password);
		//caso validado acede a menu seguinte. ***Ver funcao getPassword***

	}
}

void criaConta(Associacao &ac1){
	std::string nome, password, instituicao, email;
	int ID = ac1.incIdAssociado() ; //falta ordernar vetor!!!!!

	getString(nome, "Nome: ");
	getString(password, "Password: ");
	getString(instituicao, "Instituicao: ");
	getString(email, "Endereco de email: ");

	Cota *cota = new Cota(true,0);

	Contributor *a = new Contributor(nome, ID, password, instituicao, cota, email);

	ac1.getAssociados().push_back(a);

}

/*------------------------------------------- menu final -------------------------------------------*/
void AssociacaoMS::menuTermino()
{
	clearScreen(); //apagar conteudo do ecra
	std::cout<<"Obrigada pela visita! Ate `a proxima! :-D\n\n";
	sleep(5);
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

void clearScreen() //pode (e deve) ser procurado um metodo melhor!!!
  {
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  }

//ACABARRR!!!!!!!
void getID(Associacao &ac1, unsigned int id, std::string pass){
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

void getPassword(Associacao &ac1, std::string pass){
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
