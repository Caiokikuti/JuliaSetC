TP: *.c
	mpicc -o julia_paralelo.o julia_paralelo.c
	gcc -o visualization_paralelo.o points_paralelo.c -lGL -lGLU -lglut -lfreeimage
	gcc -o julia_sequencial.o julia_sequencial.c
	gcc -o visualization_sequencial.o points_sequencial.c -lGL -lGLU -lglut -lfreeimage
