BENCHMARK=imb
BINDIR	= bin
SRCDIR = src
CLINK	= mpicc
CLINKFLAGS = -O3


PROGRAM  = $(BINDIR)/$(BENCHMARK)
CCOMPILE = $(CLINK) -c $(CLINKFLAGS)


OBJSO = ${SRCDIR}/*.o
OBJSC = ${SRCDIR}/*.c

${PROGRAM}: ${OBJSO}
	${CLINK} ${CLINKFLAGS} -o ${PROGRAM} ${OBJSC}


${SRCDIR}/%.o: ${SRCDIR}/%.c
	cd ${SRCDIR}; ${CCOMPILE} *.c

clean:
	rm -f ${SRCDIR}/*.o
	rm -f ${BINDIR}/imb