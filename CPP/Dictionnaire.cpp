/*
 * Dictionnaire.cpp
 *
 *  Created on: 11 déc. 2018
 *      Author: Thomas
 */

#include "../H/Dictionnaire.h"

using namespace std ;

/**
 * Constructeur de la classe dictionnaire
 * Là ou on va créer la map contenant tous les mot que l'on veut
 */
Dictionnaire::Dictionnaire()
{
	for(int i = 0 ; i < 9 ; i++)
	{
		this->m[i] = map<string, int>() ;
	}

	this->createTable() ;
}

/**
 * Permet d'ajouter un mot a la map donnée en argument
 */
void Dictionnaire::ajouter(map<string, int>& m, string mot)
{
	m[mot] = 0 ;
}

/**
 * Affiche la map avec tous les mots
 */
void Dictionnaire::display()
{
	for(int i = 0 ; i < 9 ; i++)
	{
		cout << i << " : " ;

		map<string,int>::iterator it ;
		for(it=m[i].begin() ; it!=m[i].end() ; ++it)
		{
			cout << it->first << " => " << it->second << '\n';
		}

		cout << endl ;
	}
}

/**
 * Permet de créer la table de la manière suivante :
 * 0 = tous les mot d'1 lettres ;
 * 1 = tous les mot de 2 lettres ; (etc..)
 *
 * A chaque indice on va ajouter une map<string, int> contenant tous les mot, cela permet
 * de faciliter la recherche
 */
void Dictionnaire::createTable()
{
	fstream fichier ;
	//le chemin ou se trouve mon dico, faudra penser à le modifier
	fichier.open("C:\\Users\\Thomas\\Desktop\\Jeux java\\Dico\\Ressources\\dico.mots", ios::in) ;

	if(fichier)
	{
		cout << "Création des maps !!! " << endl ;
		string tmp = "" ;
		while(!fichier.eof())
		{
			fichier >> tmp ;

			if(tmp.size() < 9)
			{
				this->ajouter(m[tmp.size()-1], tmp) ;
			}
		}

		fichier.close() ;
	}
	else
	{
		cout << "Pas de fichier" << endl ;
	}
}

/**
 * On va rechercher si le mot contenue dans la map et le bon
 * renvoi true s'il le contient
 */
bool Dictionnaire::rechercher(map<string, int> myMap, string mot)
{
	if(myMap.find(mot) != myMap.end())
	{
		return true ;
	}

	return false ;
}

/**
 * Permet d'obtenir la map contenant tous les mot de la taille i
 */
map<string, int> Dictionnaire::getMap(int i)
{
	return this->m[i] ;
}
