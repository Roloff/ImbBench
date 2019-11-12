#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <unistd.h>
#include <string.h>
#include "matrix.h"
#include "matrix_benchs.h"
#include "sort_benchs.h"
#include "bst_benchs.h"
#include "rand_benchs.h"
#include "pingpong.h"


#define INT 0
#define DOUBLE 1

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


int main(int argc, char** argv)
{
    int size, rank, type = -1;

    int Test, Pattern;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    srand(time(NULL));
    clock_t begin = clock();

    //TODO: Usar um parser decente

    /* select the test */
    if (strcmp(argv[1], "CPU") == 0) 
        Test = CPU;
    else if (strcmp(argv[1], "Memory") == 0)
        Test = MEMORY;
    else if (strcmp(argv[1], "IO") == 0)
        Test = IO;
    else if (strcmp(argv[1], "Network") == 0)
        Test = NETWORK;
    else if (strcmp(argv[1], "Help") == 0)
        printf("Sorry, not written yet.\n");
    else /* error */
    {
        printf("ERROR: Incorrect Test selection.\n");
        printf("ERROR: Options are: \"CPU\", \"Memory\", \"IO\", \"Network\" or \"Help\".\n");

        MPI_Finalize();
        return 0;
    }

    /* select the pattern */
    if (strcmp(argv[2], "Balanced") == 0) 
        Pattern = BALANCED;
    else if (strcmp(argv[2], "Linear") == 0)
        Pattern = LINEAR;
    else if (strcmp(argv[2], "Amdahl") == 0)
        Pattern = AMDAHL;
    else if (strcmp(argv[2], "2Level") == 0)
        Pattern = TWO_LEVEL;
    else if (strcmp(argv[2], "4Level") == 0)
        Pattern = FOUR_LEVEL;
    else if (strcmp(argv[2], "8Level") == 0)
        Pattern = EIGHT_LEVEL;
    else if (strcmp(argv[2], "Help") == 0)
        printf("Sorry, not written yet.\n");
    else /* error */
    {
        printf("ERROR: Incorrect Pattern selection.\n");
        printf("ERROR: Options are: \"Balanced\", \"Linear\", \"Amdahl\", \"2Level\", \"4Level\", \"8Level\" or \"Help\".\n");

        MPI_Finalize();
        return 0;
    }

    switch (Test)
    {
        case CPU:
            if (argc != 4)
            {
                printf("ERROR: Incorrect number of parameters.\n");

                MPI_Finalize();
                return 0;
            }
            else if (strcmp(argv[3], "Rand") == 0)
            {
                if (cpu_rand_bench(rank, Pattern) != 0)
                {
                    printf("ERROR: In process rank: %d\n", rank);

                    MPI_Finalize();
                    return 0;
                }
            }
            else if (strcmp(argv[3], "Help") == 0)
                printf("Sorry, not written yet.\n");
            else /* error */
            {
                printf("ERROR: Incorrect microbenchmark selected.\n");
                printf("ERROR: Options are: \"Rand\".\n");

                MPI_Finalize();
                return 0;
            }            
        break;
        
        case MEMORY:
            if (argc != 4)
            {
                printf("ERROR: Incorrect number of parameters.\n");

                MPI_Finalize();
                return 0;
            }
            else if (strcmp(argv[3], "Sort") == 0)
            {
                if (mem_sort_bench(rank, Pattern) != 0)
                {
                    printf("ERROR: In process rank: %d\n", rank);

                    MPI_Finalize();
                    return 0;
                }
            }
            else if (strcmp(argv[3], "BST") == 0)
            {
                if (mem_bst_bench(rank, size, Pattern) != 0)
                {
                    printf("ERROR: In process rank: %d\n", rank);

                    MPI_Finalize();
                    return 0;
                }
            }
            else if (strcmp(argv[3], "Help") == 0)
                printf("Sorry, not written yet.\n");
            else /* error */
            {
                printf("ERROR: Incorrect microbenchmark selected.\n");
                printf("ERROR: Options are: \"Sort\" or \"BST\".\n");

                MPI_Finalize();
                return 0;
            }
        break;

        case IO:
        break;

        case NETWORK:
        break;
        
        default:
        break;
    }



//   /////////////////////////////////////////////
//   // Balanced
//       if(strcmp(argv[1],"balanced") == 0)
//       { 
//      		balanced(type);
//       }
//   /////////////////////////////////////////////
//   // 2 Levels
//       else if(strcmp(argv[1],"2levels") == 0)
//       {
//      		int num = atoi(argv[3]);
//      		int den = atoi(argv[4]);

//      		twolevels(type,num,den,rank);
//       }
//   /////////////////////////////////////////////
//   // 4 Levels
//       else if(strcmp(argv[1],"4levels") == 0)
//       {
//          	fourlevels(type,rank);
//       }
//   /////////////////////////////////////////////
//   // 8 Levels
//       else if(strcmp(argv[1],"8levels") == 0)
//       {
//           eightlevels(type,rank);
//       }
//   /////////////////////////////////////////////
//   // Linear
//       else if(strcmp(argv[1],"linear") == 0)
//       {
//       	linear(type,rank,size);
//       }
//   /////////////////////////////////////////////
//   // AMDAHL
//       else if(strcmp(argv[1],"amdahl") == 0)
//       {
//           amdahl(type,rank);
//       }
//   /////////////////////////////////////////////
//  	// PING PONG
//   	else if(strcmp(argv[1],"pingpong") == 0)
//   	{
//   		int numloops = atoi(argv[3]);

//   		if (size != 2) 
//			{
//   			printf("ERROR: Incorrect number of tasks.\n");
//   			MPI_Finalize();
//           	return 0;
// 			}
// 			else
//           	pingpong(numloops, rank, size);
//   	}
//   /////////////////////////////////////////////
//       else if(strcmp(argv[1],"teste") == 0)
//       {
//           teste(type,rank);
//       }
//   /////////////////////////////////////////////
//       else
//       {
//           printf("ERROR: Wrong second parameter.\n");
//           MPI_Finalize();
//           return 0;
//       }
//   }

    clock_t end_process = clock();
	double time_spent_process = (double)(end_process - begin) / CLOCKS_PER_SEC;

	printf("My Rank is: %d and I took %0.4f seconds\n", rank, time_spent_process);

    MPI_Finalize();
    return (EXIT_SUCCESS);
}