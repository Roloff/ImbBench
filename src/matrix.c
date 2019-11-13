#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <unistd.h>
#include <string.h>
#include "matrix.h"

int** alloc_int_matrix(int nrows, int ncols)
{
	int i;

	int **matrix = malloc(nrows * sizeof(int*));

    for(i = 0; i < ncols; i++)
      matrix[i] = malloc(ncols * sizeof(int));

  	return matrix;
}

double** alloc_double_matrix(int nrows, int ncols)
{
	int i;

	double **matrix = malloc(nrows * sizeof(double*));

    for(i = 0; i < nrows; i++)
      matrix[i] = malloc(ncols * sizeof(double));

  	return matrix;
}

void fill_int_matrix(int **matrix, int nrows, int ncols)
{
    int value = 0; 
    int i = 0, j = 0;
   
    value = rand();

     for (i = 0; i < nrows; i++)
        for (j = 0; j < ncols; j++)
            matrix[i][j] = value;
}

void fill_double_matrix(double **matrix, int nrows, int ncols)
{
    int value = 0; 
    int i = 0, j = 0;
   
    value = rand();

     for (i = 0; i < nrows; i++)
        for (j = 0; j < ncols; j++)
            matrix[i][j] = value;
}

void free_int_matrix(int **matrix, int nrows, int ncols)
{
	int i;

	for(i = 0; i < nrows; i++)
            free((void *)matrix[i]);
    free((void *)matrix);
}

void free_double_matrix(double **matrix, int nrows, int ncols)
{
	int i;

	for(i = 0; i < nrows; i++)
            free((void *)matrix[i]);
    free((void *)matrix);
}

void int_matrix(int nrows, int ncols)
{
	int **mat1_int, **mat2_int, **result_int;
	register unsigned int i, j, k;

	mat1_int = alloc_int_matrix(nrows,ncols);
	mat2_int = alloc_int_matrix(nrows,ncols);
	result_int = alloc_int_matrix(nrows,ncols);

	fill_int_matrix(mat1_int,nrows,ncols);
	fill_int_matrix(mat2_int,nrows,ncols);

	for (i = 0; i < nrows; i++)
		for (j = 0; j < ncols; j++)
		{
			result_int[i][j] = 0;
			    for (k = 0; k < ncols; k++)
			    	result_int[i][j] += mat1_int[i][k]*mat2_int[k][j];
		}

	free_int_matrix(mat1_int,nrows,ncols);
	free_int_matrix(mat2_int,nrows,ncols);
	free_int_matrix(result_int,nrows,ncols);
}

void double_matrix(int nrows, int ncols)
{
	double **mat1_double, **mat2_double, **result_double; 
	register unsigned int i, j, k;

	mat1_double = alloc_double_matrix(nrows,ncols);
	mat2_double = alloc_double_matrix(nrows,ncols);
	result_double = alloc_double_matrix(nrows,ncols);

	fill_double_matrix(mat1_double,nrows,ncols);
	fill_double_matrix(mat2_double,nrows,ncols);

	for (i = 0; i < nrows; i++)
		for (j = 0; j < ncols; j++)
		{
			result_double[i][j] = 0;
			    for (k = 0; k < ncols; k++)
			    	result_double[i][j] += mat1_double[i][k]*mat2_double[k][j];
		}

	free_double_matrix(mat1_double,nrows,ncols);
	free_double_matrix(mat2_double,nrows,ncols);
	free_double_matrix(result_double,nrows,ncols);
}
