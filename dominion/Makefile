CFLAGS=  -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unittestresults: unittest1.c unittest2.c unittest3.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c 
	echo "Unit test 1 results: " >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	
	echo "Unit test 2 results: " >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest2.c >> unittestresults.out	
	
	echo "Unit test 3 results: " >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest3.c >> unittestresults.out	
	
	echo "Card test 1 results: " >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out	
	
	echo "Card test 2 results: " >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out	
	
	echo "Card test 3 results: " >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.c rngs.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out	
	
	echo "Card test 4 results: " >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.c rngs.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out		
	

randomadventerur: randomadventerur.c dominion.c rngs.c 
	gcc -o randomadventerur randomadventerur.c dominion.c rngs.c $(CFLAGS)
	./randomadventerur > randomadventerur.out
	gcov randomadventerur.c >> randomadventerur.out
	
randomcard1: randomcard1.c dominion.c rngs.c 
	gcc -o randomcard1 randomcard1.c dominion.c rngs.c $(CFLAGS)
	./randomcard1 > randomcard1.out
	gcov randomcard1.c >> randomcard1.out
	
randomcard2: randomcard2.c dominion.c rngs.c 
	gcc -o randomcard2 randomcard2.c dominion.c rngs.c $(CFLAGS)	
	./randomcard2 > randomcard2.out
	gcov randomcard2.c >> randomcard2.out	

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 cardtest1 cardtest2 cardtest3 cardtest4 *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
