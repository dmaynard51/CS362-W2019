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
    int i;
    
    for (i = 10; i >= 0; i--)
    {
        gstate.supplyCount[province] = i;
        if (i > 0)
        {
            printf("Expected Game should not be over: 0 Actual: %i\n", isGameOver(&gstate));
        }
        else
        {
            printf("Expected game should be over: 1 Actual: %i\n", isGameOver(&gstate));
        }
    }
    
    printf("PASS!\n");
 
    return 0;
    
}
