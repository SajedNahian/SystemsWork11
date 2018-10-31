all: main.o
	gcc -o out main.o

main.o: main.c
	gcc -c main.c

clean:
	rm out
	rm *.o

run: 
	./out