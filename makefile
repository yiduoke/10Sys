all: signals.c
	gcc signals.c

clean:
	rm *~
	rm a.out

run: all
	./a.out