/*
 * Attribut.h
 *
 *  Created on: 11 déc. 2018
 *      Author: Thomas
 */
#include "Dictionnaire.h"


#ifndef ATTRIBUT_H_
#define ATTRIBUT_H_

class Attribut
{
	char* mot ;
	std::string motOrdreAlpha ;
	std::string motTrouve ;
	Dictionnaire d ;

	public:
		Attribut(char* m, int taille);
		//virtual ~Attribut();
		std::string trier(char* m, int n) ;
		std::string find(std::string m, int taille) ;
		std::string enleverLettre(std::string m, int taille, int indice) ;
};

#endif /* ATTRIBUT_H_ */
