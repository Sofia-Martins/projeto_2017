/*
 * associacaoMS.cpp
 *
 *  Created on: 18/10/2017
 *      Author: luisa
 */

#include "associacaoMS.h"
#include <iostream>
#include <fstream>
#include <string>

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


