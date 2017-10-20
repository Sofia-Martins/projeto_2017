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
void getNumber(uint &number, const std::string &question);

//menu 1
void AssociacaoMS::menuFicheiroAssociacoes() {
	std::cout<<"---- BEM-VINDO AO GESTOR DE ASSOCIACOES CIENTIFICAS! ----\n\n";
	menuFicheiroAssociacoesSelection(); //invocacao do metodo
}
void AssociacaoMS::menuFicheiroAssociacoesSelection() {

	std::string nomeFicheiro;
	std::ifstream streamAssociacoes;

	do {
		getString(nomeFicheiro,"Por favor introduza o nome do ficheiro das associacoes (sem .txt): ");
		if (std::cin.eof())
			return; //se o utilizador inseriu CTRL+Z
		nomeFicheiro += ".txt";
		streamAssociacoes.open(nomeFicheiro);
	} while (streamAssociacoes.fail());

	//se o ficheiro existir
	ficheiroAssociacoes = nomeFicheiro;
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
		//acrescentar a sigla e nome da associacao ao vetor associacoes
		associacoes.push_back(std::pair<std::string,std::string>(siglaAssociacao,nomeAssociacao));
	}

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

//funcoes relacionadas com inputs do utilizador
bool hasChar(std::string &string) {
	for (int i = 0; i < (string.length()); i++) {
		if (((string.at(i)) < 48) || (string.at(i) > 57))
			return true;  //if the string has some char
	}

	return false;
}
void eliminateSpaces(std::string &string) {
	for (int i = 0; i < string.length() - 1; i++) {
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
void getNumber(uint &number, const std::string &question) {
	bool valid;

	std::string test;
	std::string number_string;

	std::cout << question;
	std::cin >> test;
	std::getline(std::cin, number_string);
	number_string = test + number_string;
	valid = hasChar(number_string);

	while ((std::cin.fail()) || ((!(std::cin.fail())) && valid)) {
		if (std::cin.eof())
			return;
		std::cin.clear();
		std::cout << question;
		std::cin >> test;
		std::getline(std::cin, number_string);
		number_string = test + number_string;
		valid = hasChar(number_string);
	}

	number = std::stoul(number_string);
}
