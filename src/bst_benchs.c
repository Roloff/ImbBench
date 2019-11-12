#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "bst_benchs.h"
#include "bst.h"


/* Definir DEBUG para ligar alguns prints de debug
 */
#define DEBUG
#define TAM_BST 102400
#define CHUNK_BST 100
#define MAX_PROC 1024

//Colocar isso em um Defines.h
#define CPU 10
#define MEMORY 20
#define IO 30
#define NETWORK 40

#define BALANCED 100
#define LINEAR 200
#define AMDAHL 300
#define TWO_LEVEL 400
#define FOUR_LEVEL 500
#define EIGHT_LEVEL 600

void bst_bench_insert(int iLoad)
{
  struct bst_node *root = NULL; 

  root = bst_insert(root, iLoad/2); 

  for (int i=0;i<iLoad;i++)
  {
    bst_insert(root, i); 
  }
}

int mem_bst_bench(int MPI_Rank, int MPI_Size, int Pattern)
{
    switch (Pattern)
    {
        case BALANCED:
          bst_bench_insert(TAM_BST);
        break;
        
        case LINEAR:
        {
          // CHUNK_BST = menor matriz
          // MAX_PROC = quantidade max processos que o benchmark suporta: 1024
          // MPI_Size = quantidade de processos na execução
          int iLoad = CHUNK_BST * (MPI_Rank+1) * (MAX_PROC / MPI_Size);

          printf("My Rank is: %d and I will execute %d loops\n", MPI_Rank, iLoad);

          bst_bench_insert(iLoad);
        }
        break;

        case AMDAHL:
        {
          int iLoad = TAM_BST/4;

          if(MPI_Rank == 0)
            bst_bench_insert(TAM_BST);
          else
            bst_bench_insert(iLoad);
        }        
        break;

        case TWO_LEVEL:
        {
          int iLoad = TAM_BST/32;

          if(MPI_Rank % 2 == 1)
            bst_bench_insert(iLoad*32);
          else if(MPI_Rank % 2 == 0) 
            bst_bench_insert(iLoad*23);
        }
        break;
        
        case FOUR_LEVEL:
        {
          int iLoad = TAM_BST/32;

          if(MPI_Rank % 4 == 3)
            bst_bench_insert(iLoad*32);
          else if(MPI_Rank % 4 == 2) 
            bst_bench_insert(iLoad*27);
          else if(MPI_Rank % 4 == 1) 
            bst_bench_insert(iLoad*23);
          else if(MPI_Rank % 4 == 0)
           bst_bench_insert(iLoad*17);
        }
        break;

        case EIGHT_LEVEL:
        {
          int iLoad = TAM_BST/32;

          if(MPI_Rank % 8 == 7)
            bst_bench_insert(iLoad*32);
          else if(MPI_Rank % 8 == 6) 
            bst_bench_insert(iLoad*29);
          else if(MPI_Rank % 8 == 5) 
            bst_bench_insert(iLoad*27);
          else if(MPI_Rank % 8 == 4)
           bst_bench_insert(iLoad*25);
          else if(MPI_Rank % 8 == 3)
            bst_bench_insert(iLoad*23);
          else if(MPI_Rank % 8 == 2) 
            bst_bench_insert(iLoad*19);
          else if(MPI_Rank % 8 == 1) 
            bst_bench_insert(iLoad*17);
          else if(MPI_Rank % 8 == 0)
           bst_bench_insert(iLoad*12);
        }
        break;

        default:
        break;
    }

  return 0;
}
