kaurIshnoorA1: kaurIshnoorA1.o kaurIshnoorA1Main.o
	gcc -Wall -std=c99 kaurIshnoorA1.o kaurIshnoorA1Main.c -o kaurIshnoorA1 -lm
kaurIshnoorA1.o: kaurIshnoorA1.c givenA1.h
	gcc -Wall -std=c99 -c kaurIshnoorA1.c -lm
kaurIshnoorA1Main.o: kaurIshnoorA1Main.c givenA1.h
	gcc -Wall -std=c99 -c kaurIshnoorA1Main.c
clean:
	rm *.o kaurIshnoorA1
