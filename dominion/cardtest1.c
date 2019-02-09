#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>




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
    int handCount;
    int i;
    int bonus = 1;
    int player = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos1 = 0;

    
    int cardEffect1;
    
    
    
    //holds the current game state
    memset(&gstate,15,sizeof(struct gameState));
    initializeGame(playerNumber, kingdomCards, seed, &gstate);
    
    //set player0 cards to 0
    gstate.handCount[player] = 0;
    
    //should print out 0
    printf("Starting handcount at %i\n", gstate.handCount[player]);
    
    //should increase cards by 2
    cardEffect1 = cardEffect(smithy, choice1, choice2, choice3, &gstate, handPos1, &bonus);
    printf("Checking increased handcount.\n");
    //should print out 2
    printf("Hand count increased by %i\n", gstate.handCount[player]);
    printf("FAIL, expected handcount to be 3!\n");
    return 0;
    
}
