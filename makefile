# Andre Ambrosio Boechat

COMP = gcc

# Usar o -g para mais detalhes do valgrind
FLAGS = -std=c99 -pedantic

ARQS =		Main.o\
		Quicksort.o\
		Leitura.o\
		
	
EXE = quicksort 

INPUT = teste1.txt


.c.o	:
	$(COMP) $(FLAGS) -c -o $@ $<


all:	$(ARQS)
	$(COMP) $(FLAGS) $(ARQS) -o $(EXE)
	
run:
	./$(EXE) $(INPUT)
	
clean:
	rm -f $(EXE) *.o
	
cleanall:
	rm -f $(EXE) *.o *~
	
mem:
	valgrind --leak-check=yes --show-reachable=yes ./$(EXE) $(INPUT)
