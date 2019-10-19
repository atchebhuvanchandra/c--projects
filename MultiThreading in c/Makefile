#declare the variable
CC = gcc

all:	et_crt	para_mm ep_crt

et_crt:	et.o timing.o
	$(CC) -pthread et.o timing.o -o et_crt

et.o:	et.c
	$(CC) -c et.c -o et.o

timing.o:	timing.c
	$(CC) -c timing.c -o timing.o
para_mm:	para_mm.o timing.o
	$(CC) -pthread para_mm.o timing.o -o para_mm
para_mm.o:	para_mm.c
	$(CC) -c para_mm.c -o para_mm.o
ep_crt:	ep.o timing.o
	$(CC) ep.o timing.o -o ep_crt 
ep.o:	ep.c
	$(CC) -c ep.c -o ep.o

clean:
	rm -rf *o et_crt
