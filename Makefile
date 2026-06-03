test: main.o structs.o ritchie.o
	gcc main.o structs.o ritchie.o -o test

main.o: main.c structs.h
	gcc -c -g main.c

structs.o: structs.c structs.h ritchie.h
	gcc -c -g structs.c

ritchie.o: ritchie.c ritchie.h
	gcc -c -g ritchie.c

clean:
	rm -f *.o test

