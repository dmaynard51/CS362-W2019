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
    struct gameState gstate2;
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
    
    
    memset(&gstate,15,sizeof(struct gameState));
    
    //holds the current game state
    memset(&gstate2,15,sizeof(struct gameState));
    initializeGame(playerNumber, kingdomCards, seed, &gstate);
    initializeGame(playerNumber, kingdomCards, seed, &gstate2);
    //set player0 cards to 0
    gstate.handCount[player] = 0;
    
    //should print out 0
    printf("Starts handcount at %i\n", gstate.handCount[player]);
    
    //should increase cards by 3
    cardEffect1 = cardEffect(adventurer, choice1, choice2, choice3, &gstate, handPos1, &bonus);
    
    //should print out 3
    printf("Increased handcount by %i\n", gstate.handCount[player]);
    printf("PASS increased by 3!\n");
    
    
    //check if any of the cards are treasure
    
    int card = 0;
    int treasure;
    for (i=0; i < gstate.handCount[player]; i++)
    {
        
        if(gstate.hand[player][i] == copper || gstate.hand[player][i] == silver || gstate.hand[player][i] == gold)
        {
            treasure++;
        }
    }
    
    int treasure2;
    for (i=0; i < gstate2.handCount[player]; i++)
    {
        
        if(gstate2.hand[player][i] == copper || gstate2.hand[player][i] == silver || gstate2.hand[player][i] == gold)
        {
            treasure2++;
        }
    }    
    
    
    printf("treasure %i\n", treasure);
    printf("Original treasure %i\n", treasure2);
    printf("FAIL Wrong treasure amount!\n");
    printf("Original adventurer supply: %i\n", gstate2.supplyCount[adventurer]);
    printf("Updated adventurer supply: %i\n", gstate.supplyCount[adventurer]);
    printf("Fail! Adventerer supply did not go down!\n");
    for (i = 0 ; i < 10; i++)
    {
        printf("kingdom cards %i\n", kingdomCards[i]);
    }
    //int smithCard( struct gameState *state, int handPos)
    //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    
    
    /*
    //set the deckCount to 0, which should return 0
    gstate.deckCount[player] = 0;
    printf("Should return -1 since deckCount is 0 : %i\n", shuffle(player, &gstate));
    
    gstate.deckCount[player] = 10;
    printf("Should return 0 since the deck count is not 0 : %i\n", shuffle(player, &gstate));
    
    gstate.deckCount[player] = 15;
        printf("Should return 0 since the deck count is not 0 : %i\n", shuffle(player, &gstate));
    
    gstate.deckCount[player] = -2;
    printf("Should return -1 since deckCount is 0 : %i\n", shuffle(player, &gstate)); */
    return 0;
    
}
