/*
 * Dictionnaire.h
 *
 *  Created on: 11 déc. 2018
 *      Author: Thomas
 */

#include <iterator>
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <string>


#ifndef DICTIONNAIRE_H_
#define DICTIONNAIRE_H_

class Dictionnaire
{
	std::map<int, std::map<std::string, int> > m ;

	public:
		Dictionnaire();
		//virtual ~Dictionnaire();
		void ajouter(std::map<std::string, int>& m, std::string mot) ;
		void createTable() ;
		void display() ;
		bool rechercher(std::map<std::string, int> myMap, std::string m) ;
		std::map<std::string, int> getMap(int i) ;
};

#endif
