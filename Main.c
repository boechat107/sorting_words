#include <stdio.h>
#include <time.h>
#include "Quicksort.h"
#include "Leitura.h"

int main(int argc, char* argv[]){
	
	char** words;
	long int length;
	float time,time_sec;
	if( argc != 2){
		printf("Numero de parametros incorreto! Passe apenas o nome do arquivo a ser lido.\n\n");
		exit(1);
	}
	
	words = Read_input(argv[1],&length);printf("numero de linhas: %d\n",length);

	time = clock();
	Sort(words,0,length-1,0);
	time = clock() - time;
	time_sec = time/CLOCKS_PER_SEC;

	printf("Tempo de ordenacao: %f\n\n",time_sec);
	//Print_words(words,0,length-1);
	Delete_words(words,length);
	return 0;
}	

