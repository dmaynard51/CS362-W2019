#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>




// runs the tests
int main () {
    
    //create kingdom cards
    int randomNumber = 1000;
    int kingdomCards[10] = {adventurer, council_room, 
    feast, gardens, mine, remodel, smithy, village, 
    treasure_map, outpost};
    int seed = 1500;
    int playerNumber = 2;
    struct gameState gstate;
    int initGame;
    initGame = initializeGame(playerNumber, kingdomCards, randomNumber,  &gstate);

    printf("smithy : %i\n", smithy);
    int handCount;
    int bonus = 0;
    
    printf("Printing out the costs from 0-10 of each card");
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%i\n", getCost(i));
    }
    
    //prints the what the cost is, and then the number of each card. 
    //Should be in the same order as above.
    printf("Curse should be 0 %i\n ",curse );
    printf("Estate should be 2 %i\n",estate );
    printf("Duchy should be 5 %i\n",duchy );
    printf("Province should be 8 %i\n",province );
    printf("Coppyer should be 0 %i\n",copper );
    printf("Silver should be 3 %i\n",silver );
    printf("Gold should be 6 %i\n",gold );
    printf("Adventurer should be 6 %i\n",adventurer );
    printf("Councilroom should be 5 %i\n",council_room );
    printf("Feast should be 4 %i\n",feast );
    
    printf("PASS! Costs match up!\n");
    return 0;
    
}
