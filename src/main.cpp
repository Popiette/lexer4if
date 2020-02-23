#include <iostream>

#include "lexer.h"
#include "Automate.h"

int main(int argc, char ** argv) {
   string chaine;
   if(argc > 1)
		   chaine = string(argv[1]);
   else
		   chaine = string("(1+34)*123");
   Automate a(chaine);
   a.analyse();
   return 0;
}

