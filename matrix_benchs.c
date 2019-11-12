#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "matrix.h"

#define INT 0
#define DOUBLE 1
#define MAX_PROC 1024
#define MAX_LOAD 1024
#define MIN_LOAD 1

void matrix_bench(int type, int size)
{
	switch(type)
    {
        case INT:
       		int_matrix(size,size);
	    break;

	    case DOUBLE:
	       	double_matrix(size,size);
       	break;
    }
}

void balanced(int type)
{
    matrix_bench(type,MAX_LOAD);
}

void twolevels(int type, int num, int den, int rank)
{
	int iLoad = MAX_LOAD/16;

    if(rank % 2 == 1)
        matrix_bench(type,iLoad*16);
    else
        matrix_bench(type,iLoad*13);
}

void fourlevels(int type, int rank)
{
	int iLoad = MAX_LOAD/16;

	if(rank % 4 == 3)
        matrix_bench(type,iLoad*16);
    else if(rank % 4 == 2) 
    	matrix_bench(type,iLoad*14);
   	else if(rank % 4 == 1) 
    	matrix_bench(type,iLoad*12);
    else if(rank % 4 == 0)
    	matrix_bench(type,iLoad*10);
  
}

void eightlevels(int type, int rank)
{
	int iLoad = MAX_LOAD/16;

	if(rank % 8 == 7)
		matrix_bench(type,iLoad*16);
	else if(rank % 8 == 6)
		matrix_bench(type,iLoad*15);
	else if(rank % 8 == 5)
		matrix_bench(type,iLoad*14);
	else if(rank % 8 == 4)
		matrix_bench(type,iLoad*13);
	else if(rank % 8 == 3)
        matrix_bench(type,iLoad*12);
   	else if(rank % 8 == 2) 
    	matrix_bench(type,iLoad*11);
   	else if(rank % 8 == 1) 
    	matrix_bench(type,iLoad*10);
    else if(rank % 8 == 0)
    	matrix_bench(type,iLoad*9);
}

void linear(int type, int rank, int size)
{
    // MIN_LOAD = menor matriz
    // MAX_PROC = quantidade max processos que o benchmark suporta: 1024
    // size = quantidade de processos na execução
    int iTotal = MIN_LOAD * (rank+1) * (MAX_PROC / size);

    printf("My Rank is: %d and I will execute %d loops\n", rank, iTotal);

    matrix_bench(type,iTotal);
}

void amdahl(int type, int rank)
{
	int iLoad = (MAX_LOAD/4) * 3;

	if(rank == 0)
		matrix_bench(type,MAX_LOAD);
	else
		matrix_bench(type,iLoad);
}

void teste(int type,int rank)
{
	int iLoad = MAX_LOAD/16;

	if(rank % 16 == 15)
		matrix_bench(type,iLoad*16);
	else if(rank % 16 == 14)
		matrix_bench(type,iLoad*15);
	else if(rank % 16 == 13)
		matrix_bench(type,iLoad*14);
	else if(rank % 16 == 12)
		matrix_bench(type,iLoad*13);
	else if(rank % 16 == 11)
        	matrix_bench(type,iLoad*12);
   	else if(rank % 16 == 10) 
    		matrix_bench(type,iLoad*11);
   	else if(rank % 16 == 9) 
    		matrix_bench(type,iLoad*10);
    else if(rank % 16 == 8)
    		matrix_bench(type,iLoad*9);
	else if(rank % 16 == 7)
		matrix_bench(type,iLoad*8);
	else if(rank % 16 == 6)
		matrix_bench(type,iLoad*7);
	else if(rank % 16 == 5)
		matrix_bench(type,iLoad*6);
	else if(rank % 16 == 4)
		matrix_bench(type,iLoad*5);
	else if(rank % 16 == 3)
        matrix_bench(type,iLoad*4);
   	else if(rank % 16 == 2) 
    	matrix_bench(type,iLoad*3);
   	else if(rank % 16 == 1) 
    	matrix_bench(type,iLoad*2);
    else if(rank % 16 == 0)
    	matrix_bench(type,iLoad);
}





















