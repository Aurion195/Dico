/*
 * Attribut.cpp
 *
 *  Created on: 11 déc. 2018
 *      Author: Thomas
 */
#include "../H/Attribut.h"
#include "../CPP/Dictionnaire.cpp"
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std ;

/**
 * Constructeur de la classe Attribut, prend en argument un char* des lettres que l'on veut
 * ainsi que la
 */
Attribut::Attribut(char * m, int taille)
{
	this->mot = m ;
	this->motOrdreAlpha = this->trier(m, taille) ;
	cout << this->motOrdreAlpha << endl ;
	this->motTrouve = this->find(this->motOrdreAlpha, taille) ;
	cout << this->motTrouve << endl ;
}

/**
 * Trie le mot par ordre alphabétique comme demandé dans l'ennoncé
 */
string Attribut::trier(char * m, int n)
{
	vector<char> vec ;

	for(int i = 0 ; i < n ; i++)
		vec.push_back(m[i]) ;

	 sort(vec.begin(), vec.end());

	 string tmp = "" ;

	 for(int i = 0 ; i < n ; i++)
	 {
		 tmp+= vec[i] ;
	 }

	return  tmp ;
}


/**
 * Enleve une lettre du mot, on commence par la 1er et on termine par la fin
 */
string Attribut::enleverLettre(string m, int t, int indice)
{
	vector<char> vec ;

	for(int i = 0 ; i < t ; i++)
	{
		if(i != indice)
			vec.push_back(m[i]) ;
	}

	string tmp = "" ;

	for(int i = 0 ; i < t ; i++)
	{
		tmp+= vec[i] ;
	}

	return  tmp ;

}

/**
 * Regarde si le mot est contenue dans le dictionnaire et son mot le plus long
 * Utilise la fonction rechercher de la classe Dictionnaire (grace au getteur)
 */
string Attribut::find(string m, int t)
{
	if(this->d.rechercher(this->d.getMap(t-1), m))
	{
		cout << "Le mot le plus long avec ces lettres est : " << m << endl ;
		return m ;
	}
	else
	{
		if(t > 1)
		{
			for(int i = 0 ; i < t ; i++)
			{
				string tmp = this->enleverLettre(m, t, i) ;
				if(this->d.rechercher(this->d.getMap(t-2), m))
				{
					cout << "Le mot le plus long est : " << m << endl ;
					return m ;
				}
			}
		}
	}
	
	string tmp = "Pas de mot trouvé" ;
	return (char*)tmp.c_str() ;
}
