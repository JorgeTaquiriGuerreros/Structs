CC = gcc
CFLAGS = -Wall -Wextra -g

test: main.o structs.o ritchie.o
	$(CC) $(CFLAGS) main.o structs.o ritchie.o -o test

main.o: main.c structs.h
	$(CC) $(CFLAGS) -c main.c

structs.o: structs.c structs.h ritchie.h
	$(CC) $(CFLAGS) -c structs.c

ritchie.o: ritchie.c ritchie.h
	$(CC) $(CFLAGS) -c ritchie.c

run: test
	./test < main.c

clean:
	rm -f *.o test

