imb: main.o matrix.o matrix_benchs.o pingpong.o sort_benchs.o mergesort.o bst_benchs.o bst.o
	mpicc main.c matrix.c matrix_benchs.c pingpong.c sort_benchs.c mergesort.c bst_benchs.c bst.c rand_benchs.c -O3 -o imb

main.o: main.c
	mpicc -c -O3 main.c

matrix.o: matrix.c matrix.h
	mpicc -c -O3 matrix.c

matrix_benchs.o: matrix_benchs.c matrix_benchs.h
	mpicc -c -O3 matrix_benchs.c

pingpong.o: pingpong.c pingpong.h
	mpicc -c -O3 pingpong.c

sort_benchs.o: sort_benchs.c sort_benchs.h
	mpicc -c -O3 sort_benchs.c

mergesort.o: mergesort.c mergesort.h
	mpicc -c -O3 mergesort.c

bst_benchs.o: bst_benchs.c bst_benchs.h
	mpicc -c -O3 bst_benchs.c

bst.o: bst.c bst.h
	mpicc -c -O3 bst.c

rand_benchs.o: rand_benchs.c rand_benchs.h
	mpicc -c -O3 rand_benchs.c

clean:
	rm *.o imb
