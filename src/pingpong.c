#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define INT 0
#define DOUBLE 1

void pingpong(int numloops, int rank, int size)
{
	double t1, t2, time;
	int i, dest, source, count, tag = 1;
	char outmsg = 'x', inmsg = 'e';

	MPI_Status Stat;

	if (rank == 0) 
	{
	   	for(i = 0; i < numloops; i++)
	   	{
			dest = 1;
			source = 1;
			MPI_Send(&outmsg, 1, MPI_CHAR, dest, 0, MPI_COMM_WORLD);
			MPI_Recv(&inmsg, 1, MPI_CHAR, source, 1, MPI_COMM_WORLD, &Stat);

			MPI_Get_count(&Stat, MPI_CHAR, &count);
       		printf("Task %d: Received %d char(s) from task %d with tag %d.\n",
       			rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);
		}
	} 
	else if (rank == 1) 
	{
		for(i = 0; i < numloops; i++)
		{
			dest = 0;
			source = 0;
			MPI_Recv(&inmsg, 1, MPI_CHAR, source, 0, MPI_COMM_WORLD, &Stat);
			MPI_Send(&outmsg, 1, MPI_CHAR, dest, 1, MPI_COMM_WORLD);

			MPI_Get_count(&Stat, MPI_CHAR, &count);
      		printf("Task %d: Received %d char(s) from task %d with tag %d.\n",
       			rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);
		}
	}
}