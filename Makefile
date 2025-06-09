all : metoa


client.o : client.c
	gcc -o client.o -c client.c
taxi.o : taxi.c 
	gcc -o taxi.o -c taxi.c
itineraire.o : itineraire.c 
	gcc -o itineraire.o -c itineraire.c 
main.o : main.c 
	gcc -o main.o -c main.c
metoa : client.o taxi.o itineraire.o main.o
	gcc -o metoa client.o taxi.o itineraire.o main.o


