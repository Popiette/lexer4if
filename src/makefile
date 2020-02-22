cppFiles=lexer.cpp symbole.cpp Automate.cpp Etat.cpp main.cpp

binDir=bin/
_objFiles=dir_lexer.o dir_symbole.o dir_Automate.o dir_Etat.o dir_main.o
objFiles=$(subst dir_,$(binDir),$(_objFiles))

executable=main

$(executable) : $(objFiles)
	g++ -o $(executable) -g -Wall $(objFiles)

$(binDir)%.o : %.cpp
	g++ -o $@ -g -Wall -c $<

clean : 
	rm -rf $(objFiles) $(executable)
