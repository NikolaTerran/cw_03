all: main.o matrix.o line.o util.o random.o engine.h
	gcc main.o matrix.o line.o util.o random.o

main.o: main.c engine.h
	gcc -c main.c

matrix.o: matrix.c engine.h
	gcc -c matrix.c

util.o: util.c engine.h
	gcc -c util.c

line.o: line.c engine.h
	gcc -c line.c
	
random.o: random.c engine.h
	gcc -c random.c

run:
	./a.out

clean:
	rm *.o
