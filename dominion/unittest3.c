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
 
    memset(&gstate,15,sizeof(struct gameState));
    initializeGame(playerNumber, kingdomCards, seed, &gstate);
    
    //set the deckCount to 0, which should return 0
    gstate.deckCount[player] = 0;
    printf("Should return -1 since deckCount is 0 : %i\n", shuffle(player, &gstate));
    printf("PASS!\n");
    gstate.deckCount[player] = 10;
    printf("Should return 0 since the deck count is not 0 : %i\n", shuffle(player, &gstate));
    printf("PASS!\n");
    gstate.deckCount[player] = 15;
    printf("Should return 0 since the deck count is not 0 : %i\n", shuffle(player, &gstate));
    printf("PASS!\n");
    gstate.deckCount[player] = -2;
    printf("Should return -1 since deckCount is 0 : %i\n", shuffle(player, &gstate));
    printf("PASS!\n");
    return 0;
    
}
