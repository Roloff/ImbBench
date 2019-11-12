#include<stdio.h>
#include<stdlib.h>

void Merge(long lVetor[], unsigned long ulSize)
{
  register unsigned long i; /*contador*/
  register unsigned long j; /*contador*/
  unsigned long k;      /* XXX */
  long *plVetor;      /*vetor auxiliar*/
  unsigned long ulMeio  = ulSize / 2;
    
  /* Tenta alocar memoria para o buffer temporario,
   * se nao conseguir, retorna erro para o sistema
   */
  if(NULL == (plVetor = (long *)malloc((ulSize) *sizeof(long))))
    exit(1);

  /* Usei a metodologia de mergesort proposta no livro: "Algorithms in C"
   * do autor Robert Sedgewick. Como ele propoe a copia de metade do
   * vetor em dois for diferentes, acredito que fique interessante para o
   * OpenMP
   */
  for (i = 0, j = 0; j < ulMeio; ++i, ++j)
    plVetor[i] = lVetor[j];
  
  for (i = ulSize-1, j = ulMeio; j < ulSize; --i, ++j)
    plVetor[i] = lVetor[j];   

  j = 0;
  k = ulSize-1;
  for(i=0;i<=ulSize-1;i++)
    if (plVetor[j] <= plVetor[k])
      lVetor[i] = plVetor[j++];
    else
      lVetor[i] = plVetor[k--];

  /* Libera a memoria alocada para o buffer temporario
   */
  free(plVetor);
}

void MergeSort(long lVetor[], unsigned long ulSize)
{
  if(1 < ulSize)
  {
    /*Meio do vetor*/
    unsigned long ulMeio  = ulSize / 2;
    
    /*Executa recursao*/
    MergeSort(lVetor, ulMeio); /*Inicio ate o meio*/
    MergeSort(lVetor+ulMeio, ulSize-ulMeio); /*Meio ate o fim*/
    
    /*Faz o Merge dos dois segmentos*/
    Merge(lVetor, ulSize);
  }
}
