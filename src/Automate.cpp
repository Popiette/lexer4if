/*******************************************************************************************
Créé le : 21 février 2020
par : pierre
e-mail :
*******************************************************************************************/

//------------- Realisation de la classe <Automate> ( fichier Automate.cpp ) -----------------

//------------- Include système ------------------------------------------------------------
#include <iostream>

//------------- Include personnel ----------------------------------------------------------
#include "Automate.h"
#include "Etat.h"

using namespace std;

//------------- Constantes -----------------------------------------------------------------


//------------- Methodes publiques ---------------------------------------------------------

void Automate::reduction(int n, Symbole * s)
{
	for(int i = 0; i < n; i++)
	{
		delete(p_etat.back());
		p_etat.pop_back();
	}
	p_etat.back()->transition(*this, s);
}

void Automate::decalage(Symbole * s, Etat * e)
{
	p_etat.push_back(e);
	p_sym.push_back(s);
	if(s->isTerminal())
	{
		lex->Avancer();
	}

}

Symbole * Automate::popSymbole()
{
	Symbole * s =  p_sym.back();
	p_sym.pop_back();
	return s;
}

void Automate::popAndDestroySymbole()
{
	delete(p_sym.back());
	p_sym.pop_back();
}

int Automate::analyse(){

	bool accept = false;
	while(!accept)
	{
			accept = p_etat.back()->transition(*this, lex->Consulter());
	}

	cout << "OK !" << endl;

	return 0;
}

//------------- Surcharge d'opérateurs -----------------------------------------------------

//------------- Constructeurs - Destructeur ------------------------------------------------

Automate::Automate(string expression)
		: expr(expression)
{
	lex = new Lexer(expression);
	p_etat.push_back(new Etat0);
}

Automate::~Automate()
{

}

//------------- Methodes protégées ---------------------------------------------------------
