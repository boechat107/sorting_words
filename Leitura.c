#include "Leitura.h"

//-----------------------------------------------------------------------------------------

char** Read_input(char* file_name,long int* length){

	FILE* file;
	char** words;
	char word_read[35]; // tamanho maximo de uma palavra
	long int count = 0;
	long int i;
	int eof,size;
	//char lixo;

	file = fopen(file_name,"r");
	if( file == NULL ){
		printf("Erro ao abrir o arquivo de entrada\n\n");
		exit(1);
	}
	
	// contagem do numero de linhas
	while(1){
		eof = fscanf(file,"%s",word_read);
		if( eof == EOF )
			break;

		count++;
	}
//printf("numero de linhas: %d \n\n",count);
	fseek(file,0,SEEK_SET);
	
	if( count == 0 ){
		printf("Arquivo vazio!!\n\n");
		exit(0);
	}
	words = (char**)malloc(count*sizeof(char*));
	
	for(i=0; i<count ; i++){
		fscanf(file,"%s",word_read);
		size = strlen(word_read);
		if( size == 0 )
			continue;
		
		words[i] = (char*)malloc((size+1)*sizeof(char));
		strcpy(words[i],word_read);
		word_read[0] = '\0';
	}

	fclose(file);
	*length = count;
	return words;
}

//----------------------------------------------------------------------------------------------

void Print_words(char** words,long int begin,long int end){
	long int i;

	for(i=begin; i<=end;i++)
		printf("%s\n",words[i]);
}

//---------------------------------------------------------------------------------------------

void Delete_words(char* words[], long int length){
	long int i;

	for(i=0; i<length; i++)
		free(words[i]);

	free(words);
}
	
