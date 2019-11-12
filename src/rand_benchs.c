#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "sort_benchs.h"
#include "mergesort.h"


/* Definir DEBUG para ligar alguns prints de debug
 */
#define DEBUG
#define TAM_VETOR 100000000 /*1048576*/

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

int cpu_rand_bench(int rank, int Pattern)
{

//  long *lVetor;
//  unsigned long ulSize = TAM_VETOR;
//
//  lVetor = malloc(ulSize * sizeof(long)); 
//
//  if (!lVetor)
//  {
//    printf("ERROR: Allocate the buffer\n");
//
//    return -1;
//  }
//
//  PreencheVetor(lVetor, ulSize);

//  int i = 0;
//  for(i=0;i<ulSize;i++)
//    printf("%ld\n", lVetor[i]);


    switch (Pattern)
    {
        case BALANCED:
        {
          int i;

          for(i=0;i<320000000;i++)
          {

            int r = rand();
          }
        }
        break;
        
        case LINEAR:
        {
          int i = 0;
          int iTotal = 10000000 * (rank+1);
    
          for(i=0;i<iTotal;i++)
          {
            int r = rand();
          }
        }
        break;

        case AMDAHL:
        {
          if(rank==0)
          {
            int i;

            for(i=0;i<320000000;i++)
            {
              int r = rand();
            }
          }
          else
          {
            int i;
            for(i=0;i<80000000;i++)
            {
              int r = rand();
            }
          }
        }
        break;

        case TWO_LEVEL:
        {
          if(rank % 2 == 1)
          {
            int i;
            for(i=0;i<320000000;i++)
            {
              int r = rand();
            }
          }
          else
          {
            int i;
            for(i=0;i<160000000;i++)
            {
              int r = rand();
            }
          }
        }
        break;
        
        case FOUR_LEVEL:
        {
          if(rank % 4 == 3)
          {
              int i;
              for(i=0;i<320000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 4 == 2)
          {
              int i;
              for(i=0;i<240000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 4 == 1)
          {
              int i;
              for(i=0;i<160000000;i++)
              {
                  int r = rand();
              }
          }
          else
          {
            int i;
            for(i=0;i<80000000;i++)
              {
                int r = rand();
              }
          }        
        }
        break;

        case EIGHT_LEVEL:
        {
          if(rank % 8 == 7)
          {
              int i;
              for(i=0;i<320000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 6)
          {
              int i;
              for(i=0;i<280000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 5)
          {
              int i;
              for(i=0;i<240000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 4)
          {
              int i;
              for(i=0;i<200000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 3)
          {
              int i;
              for(i=0;i<160000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 2)
          {
              int i;
              for(i=0;i<120000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 1)
          {
              int i;
              for(i=0;i<80000000;i++)
              {
                  int r = rand();
              }
          }
          else if(rank % 8 == 0)
          {
              int i;
              for(i=0;i<40000000;i++)
              {
                  int r = rand();
              }
          }
        }
        break;

        default:
        break;
    }

#if 0

#ifdef DEBUG
  unsigned long i = 0;
  struct timeval Inicio;
  struct timeval Fim;

  printf("DEBUG: Tamanho do vetor: %ld\n", ulSize);

  printf("DEBUG: Vetor Original: ");
  for(i = 0;i<ulSize;i++)
    if(i==ulSize-1)
      printf("%ld\n", lVetor[i]);
    else
      printf("%ld,", lVetor[i]);

  gettimeofday(&Inicio, NULL);
#endif

  MergeSort(lVetor, ulSize);

#ifdef DEBUG
  gettimeofday(&Fim, NULL);
  
  printf("Tempo de execucao: %ld ms\n",
    (((Fim.tv_sec - Inicio.tv_sec)*1000) +
    ((Fim.tv_usec - Inicio.tv_usec)/1000)));

  printf("DEBUG: Vetor ordenado: ");
  for(i = 0;i<ulSize;i++)
    if(i==ulSize-1)
      printf("%ld\n", lVetor[i]);
    else
      printf("%ld,", lVetor[i]);
#endif

#endif

  return 0;
}
