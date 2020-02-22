/******************************************************************
Créé le : 21 février 2020
par : pierre
e-mail :
******************************************************************/


//-------------- Interface de la classe <Etat> (fichier Etat.h) ---------------------
#if ! defined ( ETAT_H )
#define ETAT_H

#include <string>

#include "symbole.h"
#include "Automate.h"
//-------------- Interfaces utilisées -----------------------------
//-------------- Constantes ---------------------------------------
//-------------- Types --------------------------------------------

//-----------------------------------------------------------------
//Rôle de la classe <Etat>:
//
//-----------------------------------------------------------------

class Etat
{
	public:
		//----- Methodes publiques -----
		void print() const;
		virtual bool transition(Automate & automate, Symbole * s) = 0;
		//---- Surchage d'opérateurs ----
		//--- Constructeurs - Destructeurs ---
		
		protected:
		//----- Methodes protégées -----
		//----- Attributs protégés -----

};
//------------ Autres définitions dépendantes de Etat ----------

class Etat0 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat1 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat2 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat3 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat4 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat5 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat6 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat7 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat8 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat9 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

class Etat10 : public Etat
{
	public:
		// ----- Methode surchargée -----	
		virtual bool transition(Automate & automate, Symbole * s);
};

#endif // ! defined ( ETAT_H )
