/*******************************************************************************************
Créé le : 21 février 2020
par : pierre
e-mail :
*******************************************************************************************/

//------------- Realisation de la classe <Etat> ( fichier Etat.cpp ) -----------------

//------------- Include système ------------------------------------------------------------


//------------- Include personnel ----------------------------------------------------------
#include "Etat.h"

//------------- Constantes -----------------------------------------------------------------


//------------- Methodes publiques ---------------------------------------------------------
// Fonctions de transitions des etats.
bool Etat0::transition(Automate & automate, Symbole * s)
{
	switch (*s)
	{
		case INT:
				automate.decalage(s, new Etat3);
				break;
		case OPENPAR:
				automate.decalage(s, new Etat2);
				break;
		case EXPRESSION:
				automate.decalage(s, new Etat1);
				break;
		default:
				// TODO : gerer les cas d'erreurs !
				break;
	}
	return false;
}

bool Etat1::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS:
				automate.decalage(s, new Etat4);
				break;
		case MULT:
				automate.decalage(s, new Etat5);
				break;
		case FIN:
				delete s;
				return true;
				
		default:
				break;

	}
	return false;
}

bool Etat2::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case INT:
				automate.decalage(s, new Etat3);
				break;
		case OPENPAR:
				automate.decalage(s, new Etat2);
				break;
		case EXPRESSION:
				automate.decalage(s, new Etat6);
				break;
		default:
				break;
	}
	return false;
}

bool Etat3::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		default:
				Entier * val = (Entier *) automate.popSymbole();
				Entier * e = new Entier(val->getValeur(), EXPRESSION);
				delete val;
				automate.reduction(1, e);
				break;
	}
	return false;
}

bool Etat4::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case INT:
				automate.decalage(s, new Etat3);
				break;
		case OPENPAR:
				automate.decalage(s, new Etat2);
				break;
		case EXPRESSION:
				automate.decalage(s, new Etat7);
				break;
		default:
				break;
	}

	return false;
}

bool Etat5::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case INT:
				automate.decalage(s, new Etat3);
				break;
		case OPENPAR:
				automate.decalage(s, new Etat2);
				break;
		case EXPRESSION:
				automate.decalage(s, new Etat8);
				break;
		default:
				break;
	}
	return false;
}

bool Etat6::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS:
				automate.decalage(s, new Etat4);
				break;
		case MULT:
				automate.decalage(s, new Etat5);
				break;
		case CLOSEPAR:
				automate.decalage(s, new Etat9);
				break;
		default:
				break;

	}
	return false;
}

bool Etat7::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case MULT:
				automate.decalage(s, new Etat5);
				break;

		default:
				Entier * a;
			   	Entier * b; 
				Entier * resultat;
				a = (Entier *) automate.popSymbole();
				automate.popAndDestroySymbole();
				b = (Entier *) automate.popSymbole();
				resultat = new Entier(a->getValeur() + b->getValeur(), EXPRESSION);
				delete a;
				delete b;
				automate.reduction(3,resultat);
				break;
	}
	return false;
}

bool Etat8::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		default:
				Entier * a;
				Entier * b;
				Entier * resultat;
				a = (Entier *) automate.popSymbole();
				automate.popAndDestroySymbole();
				b = (Entier *) automate.popSymbole();
				resultat = new Entier(a->getValeur() * b->getValeur(), EXPRESSION);
				delete a;
				delete b;
				automate.reduction(3, resultat);
				break;
	}
	return false;
}

bool Etat9::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		default:
				Entier * entier;
				Entier * expression;
				automate.popAndDestroySymbole();
				entier = (Entier *) automate.popSymbole();
				automate.popAndDestroySymbole();

				expression = new Entier(entier->getValeur(), EXPRESSION);
				delete entier;
				automate.reduction(3, expression);
	}
	return false;
}
//------------- Surcharge d'opérateurs -----------------------------------------------------

//------------- Constructeurs - Destructeur ------------------------------------------------

//------------- Methodes protégées ---------------------------------------------------------
