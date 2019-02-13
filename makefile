all: main.c engine.h
	gcc main.c
	
run:
	./a.out

clean:
	rm a.out
