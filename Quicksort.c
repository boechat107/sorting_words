#include "Quicksort.h"


//--------------------------------------------------------------------------------------

void Sort(char* words[], long int begin, long int end, int key){

	long int a=0,b=0,c=0,d=0,length;

	length = end - begin + 1;
	if( length <= 30 ){ // numero encontrado por tentativas
		if( length <= 1 )
			return;
		else{
			InsertionSort(words,begin,end);
			return;
		}
	}

	Partitioner(words,&begin,&end,key,&a,&b,&c,&d);

	Sort(words,begin,b,key); // Para os menores
	Sort(words,(b+1),(c-1),(key+1)); // Para os iguais
	Sort(words,c,end,key);  // Para os maiores
}

//--------------------------------------------------------------------------------------

void Partitioner(char* words[], long int* begin, long int* end, int key, long int* a, long int* b, long int* c, long int* d){

	long int i=0,j=0;
	char* pivo;
	
	i = Select_pivo(words,*begin,*end,key);
	pivo = words[i];

	*b = *begin;
	*a = *begin - 1;
	*c = *end;
	*d = *end + 1;
	
	while( *b <= *c){
		// lembrar do limite de key
		// nao ocorre problema com o tamanho da key nesta comparacao porque, quando 
		// a key eh maior que o tamanho da palavra, compara-se o '\0' dessa palavra 
		// com o outro caracter. '\0' eh considerado menor que qualquer caracter.
		// Entao, nunca ocorre um acesso a uma posicao inexistente.
		while( (*b <= *c) && (words[*b][key] <= pivo[key]) ){
			if( words[*b][key] == pivo[key] ){
				*a += 1;
				// troca de posicoes
				Change_position(words,*b,*a);
			}
			*b += 1;
		}
	
		
		while( (*c >= *b) && (words[*c][key] >= pivo[key]) ){
	
			if( words[*c][key] == pivo[key] ){
				*d -= 1;
				// trocar posicoes
				Change_position(words,*c,*d);
			}
			*c -= 1;
		}
		
		if( *c < *b )
			break;
		Change_position(words,*c,*b);
		*b += 1;
		*c -= 1;
	}
	// troca as posicoes dos menores com os iguais
	for(i=*a,j=*b-1; i >= *begin ; i--,j--){// aqui pode melhorar, analiser para lista de palavras quase iguais
		Change_position(words,i,j);
	}
	*b = j;

	// troca as posicoes dos maiores com os iguais
	for(i=*d,j=*c+1; i <= *end ; i++,j++){
		Change_position(words,i,j);
	}
	*c = j;
}



//--------------------------------------------------------------------------------------

// Funcao para troca de posicoes de duas palavras
void Change_position(char* vector[],int a,int b){
	char* aux;

	aux = vector[a];
	vector[a] = vector[b];
	vector[b] = aux;
}

//--------------------------------------------------------------------------------------

// Funcao que seleciona o pivo a ser usado
long int Select_pivo(char* words[],long int begin,long int end,int key){
	long int aux;

	aux = (begin + end)/2;

	if( words[begin][key] > words[end][key] ){
		if( words[begin][key] < words[aux][key] )
			return begin;
		else{
			if( words[end][key] > words[aux][key] )
				return end;
			else
				return aux;
		}
	}
	else{
		if(  words[begin][key] > words[aux][key] )
			return begin;
		else{
			if( words[end][key] < words[aux][key] )
				return end;
			else
				return aux;
		}
	}
}

//-------------------------------------------------------------------------------------

void InsertionSort(char* words[],long int begin,long int end){
	long int i,j;
	char* aux;

	for(j=begin+1; j<=end; j++){

		aux = words[j];
		i = j-1;

		while( (i>=begin)&&(strcmp(words[i],aux)>0) ){
			words[i+1] = words[i];
			i -= 1;
		}
		words[i+1] = aux;
	}
}

