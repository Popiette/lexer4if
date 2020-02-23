#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

	  // Return false if the symbol is an expression.
	  bool isTerminal() const;

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v, Identificateurs id = INT) : Symbole(id), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
	  int getValeur() const;

   protected:
      int valeur;
};
