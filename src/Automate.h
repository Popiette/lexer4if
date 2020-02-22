/******************************************************************
Créé le : 21 février 2020
par : pierre
e-mail :
******************************************************************/

//-------------- Interface de la classe <Automate> (fichier Automate.h) ---------------------
#if ! defined ( AUTOMATE_H )
#define AUTOMATE_H

#include <string>
#include <deque>

#include "symbole.h"
#include "lexer.h"
//-------------- Interfaces utilisées -----------------------------
//-------------- Constantes ---------------------------------------
//-------------- Types --------------------------------------------

//-----------------------------------------------------------------
//Rôle de la classe <Automate>:
//
//-----------------------------------------------------------------

class Etat;

class Automate
{
	public:
		//----- Methodes publiques -----
		void reduction(int n, Symbole * s);
		void decalage(Symbole * s, Etat * e);

		// Pop le symbole depuis le haut de la pile
		Symbole * popSymbole();

		// Pop et détruit le symbole !
		void popAndDestroySymbole();

		// Calcule le résultat !
		int analyse();

		//---- Surchage d'opérateurs ----
		//--- Constructeurs - Destructeurs ---
		Automate(std::string expression);
		virtual ~Automate();

	protected:
		//----- Methodes protégées -----
		//----- Attributs protégés -----
		std::string expr;
		std::deque<Etat *> p_etat;
		std::deque<Symbole *> p_sym;
		Lexer * lex;
};
//------------ Autres définitions dépendantes de Automate ----------

#endif // ! defined ( AUTOMATE_H )
