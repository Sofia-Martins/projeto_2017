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
void getID(Associacao *ac1, unsigned int id, std::string pass);
void getPassword(Associacao *ac1, std::string pass);

//variaveis globais
std::string retornoMenu="/";

/*------------------------------------------- menu 1 -------------------------------------------*/

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

void clearScreen() //pode (e deve) ser procurado um metodo melhor!!!
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
