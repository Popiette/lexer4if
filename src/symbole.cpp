#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal() const
{
	return (ident <= 4); 
}

// === Classe Entier ===
void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::getValeur() const
{
	return valeur;
}
