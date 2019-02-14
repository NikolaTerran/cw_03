all: main.o matrix.o engine.h
	gcc main.o matrix.o 

main.o: main.c engine.h
	gcc -c main.c

matrix.o: matrix.c engine.h
	gcc -c matrix.c

run:
	./a.out

clean:
	rm *.o
