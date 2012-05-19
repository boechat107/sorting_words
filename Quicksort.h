#ifndef __QUICKSORT_H
#define __QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort(char* words[], long int begin, long int end, int key);

void Partitioner(char* words[], long int* begin, long int* end, int key, long int* a, long int* b, long int* c, long int* d);

void Change_position(char* vector[],int a,int b);

long int Select_pivo(char* words[],long int begin,long int end,int key);

void InsertionSort(char* words[],long int begin,long int end);

//int Is_smaller_equal(char a, char b);

#endif

