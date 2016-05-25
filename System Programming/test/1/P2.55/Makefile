all: show-bytes

show-bytes: show-bytes.o
	gcc -W -Wall -o show-bytes show-bytes.o 

show-bytes.o: show-bytes.c
	gcc -W -Wall -c -o show-bytes.o show-bytes.c
clean:
	rm -rf *.o show-bytes

