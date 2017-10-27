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
void clearScreen(); //pode (e deve) ser procurado um método melhor!!!
void getID(Associacao *ac1, unsigned int id, std::string pass);
void getPassword(Associacao *ac1, std::string pass);

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

	if(numeroOpcao==2)
		this->menuFicheiroAssociacoes();
	//else: invoca o menu para criar uma associacao

}
/*------------------------------------------- menu 2 -------------------------------------------*/

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
		nomeFicheiro = nomeFicheiro + ".txt";
		streamAssociacoes.open(nomeFicheiro);
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
		std::istringstream ssFicheiro(linhaFicheiro);
		getline(ssFicheiro,siglaAssociacao,';');
		getline(ssFicheiro,nomeAssociacao);
		eliminateSpaces(nomeAssociacao);
		eliminateSpaces(siglaAssociacao);

		//acrescentar a sigla e nome da associacao ao vetor associacoes
		associacoes.push_back(std::pair<std::string,std::string>(siglaAssociacao,nomeAssociacao));
	}


	for(int i=0;i<associacoes.size();i++)
	{
		using namespace std;
		cout <<"Nome da associacao: "<<associacoes.at(i).first<<"\n";
		cout <<"Sigla da associacao: "<<associacoes.at(i).second<<"\n\n";
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

	Associacao ac1(associacoes[opcao - 1].first, {}, {}, {}, {} ); //criar associacao
	ficheiroAssociados = associacoes[opcao - 1].second + "_associados.txt"; //Confirmar q é o second!
	ficheiroConferencias = associacoes[opcao - 1].second + "_conferencias.txt";
	ficheiroDominios = associacoes[opcao - 1].second + "_dominios.txt";
	ficheiroEmails = associacoes[opcao - 1].second + "_emails.txt";
	ficheiroEscolasVerao = associacoes[opcao - 1].second + "_escolaVerao.txt";
	ficheiroGestores = associacoes[opcao - 1].second + "_gestores.txt";

	//ler ficheiros...
	DominioCientifico  DC = lerDominios(ficheiroDominios);
	lerAssociados(&ac1, ficheiroAssociados, DC);

	this->menuLogin(&ac1);
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

void AssociacaoMS::lerAssociados(Associacao *ac1, std::string ficheiroAssociados, DominioCientifico dominio){
	std::ifstream streamAssociados;
	streamAssociados.open(ficheiroAssociados);
	std::string linhaFicheiro, nome, ID, password, instituicao, emDia, atraso, email, tema, subareas;


	while(!streamAssociados.eof()){
		getline(streamAssociados, linhaFicheiro);
		std::stringstream input(linhaFicheiro);
		getline(input,nome,','); eliminateSpaces(nome);
		getline(input,ID,','); eliminateSpaces(ID);
		getline(input,password,','); eliminateSpaces(password);
		getline(input,instituicao,','); eliminateSpaces(instituicao);
		getline(input,emDia,','); eliminateSpaces(emDia);
		getline(input,atraso,','); eliminateSpaces(atraso);
		getline(input,email,';'); eliminateSpaces(email);
		getline(input,tema,';'); eliminateSpaces(tema);
		getline(input,subareas); eliminateSpaces(subareas);

		//verificar dominio, tema, subareas
		Associado a1;


		//verificar o funcionamento
		if(emDia == "sim")
			Contributor a1 = (nome, std::stoul(ID), password, instituicao,
					dominio, Cota(emDia,stoul(atraso)), email);
		else if (stoul(atraso) < 5)
			Subscriber a1 = (nome, std::stoul(ID), password, instituicao,
					dominio, Cota(emDia,stoul(atraso)), email);
		else a1 = Associado(nome, std::stoul(ID), password, instituicao,
				dominio, Cota(emDia,stoul(atraso)), email);

		//guardar temas de eventos
		std::vector<std::string> v_eventos;
		do
		{
			int p1 = tema.find_first_of(","); // posicao da vírgula
			v_eventos.push_back(tema.substr(1, p1 - 1));
			tema = tema.substr(p1 + 1);

		} while (tema.find_first_of(",") != tema.size() - 1);

		a1.setEventos(v_eventos);


		//guardar subareas de interesse
		std::vector<std::string> v_subareas;
		do
		{
			int p1 = subareas.find_first_of(","); // posicao da vírgula
			v_subareas.push_back(subareas.substr(1, p1 - 1));
			subareas = subareas.substr(p1 + 1);

		} while (subareas.find_first_of(",") != subareas.size() - 1);

		a1.setAreasInteresse(v_subareas);


		ac1->addAssociado(a1);

	}

}

void AssociacaoMS::menuLogin(Associacao *ac1){
	std::cout <<"---- LOGIN ----\n\n";
	std::cout <<"1. Sign up\n";
	std::cout <<"2. Sign in\n";
	unsigned int opcao=0, id = 0;
	std::string password;

	do
	{
		getNumber(opcao,"Opcao: ");
		if(std::cin.eof())
			this->menuTermino();
	}while(!((opcao==1) || (opcao==2)));

	if(opcao == 1){
		//cria conta com id automatico
	}

	if(opcao == 2){
		//acede a conta da lista associados
		std::cout <<"---- SIGN IN ----\n\n";
		getID(ac1, id, password);
		//caso validado acede a menu seguinte. ***Ver funcao getPassword***

	}
}

/*------------------------------------------- menu final -------------------------------------------*/
void AssociacaoMS::menuTermino()
{
	clearScreen(); //apagar conteudo do ecra
	std::cout<<"Obrigada pela visita! Ate `a proxima! :-D\n\n";
	sleep(5);
	exit(0);

}

/*
 void AssociacaoMS::menu(){

 std::ifstream fAssociados, fDominios, fEventos, fGestores, fEmails; // ?
 std::string input;
 bool validFile;

 std::cout << "Bem-Vindo à APIC!\n\n";

 do{
 //pedir ficheiros
 std::cout <<"Ficheiro de associados: ";
 std::cin >> input;
 fAssociados.open(input + ".txt");

 std::cout <<"Ficheiro de dominios cientificos: ";
 std::cin >> input;
 fDominios.open(input + ".txt");

 std::cout <<"Ficheiro de eventos: ";
 std::cin >> input;
 fEventos.open(input + ".txt");

 std::cout <<"Ficheiro de gestores: ";
 std::cin >> input;
 fGestores.open(input + ".txt");

 std::cout <<"Ficheiro de emails: ";
 std::cin >> input;
 fEmails.open(input + ".txt");

 //se file associados nao existe
 if(fAssociados.fail()){
 validFile = false;
 std::cout << "Parece que a associacao esta um pouco vazia! \n Pretende criar um gestor ? (Yes/No) \n";
 std::cin >> input;
 switch(input){
 case "Yes":
 //criar gestor
 validFile = true;
 break;
 case "No" :
 std::cin.clear();
 break; //volta a pedir file
 }
 }

 }while(!validFile);
 }
 */

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

void clearScreen() //pode (e deve) ser procurado um método melhor!!!
  {
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  }

//ACABARRR!!!!!!!
void getID(Associacao *ac1, unsigned int id, std::string pass){
	bool IDvalido = false;
	do {
		getNumber(id, "ID: ");

		for (int i = 0; i < ac1->getAssociados().size(); i++)
			if (ac1->getAssociados().at(i)->getID() == id) //ID valido
				IDvalido = true;
		if (IDvalido)
			getPassword(ac1, pass);
		else
			std::cout << "ID invalido!! \n\n";
	} while (!IDvalido);

}

void getPassword(Associacao *ac1, std::string pass){
	bool PassValida = false;
	do {
		getString(pass, "Password: ");
		for (int i = 0; i < ac1->getAssociados().size(); i++)
			if (ac1->getAssociados().at(i)->getPassword() == pass) //pass valido
				PassValida = true;
		if (!PassValida)
			std::cout << "Password invalid<!! \n\n";
		//else acede a menu seguinte!!!
	} while (!PassValida);
}
