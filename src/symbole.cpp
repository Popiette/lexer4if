#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal() const
{
	return (ident <= 6); 
}

// === Classe Entier ===
void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
