#ifndef __LEITURA_H
#define __LEITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** Read_input(char* file_name,long int* length);

void Print_words(char** words,long int begin,long int end);

void Delete_words( char* words[], long int length);

#endif
