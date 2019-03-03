#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#include <assert.h>

int shuffleCount = 0;
int treasureCount = 0;
int treasureArray[3] = {copper, silver, gold};
int countIncreaseFail = 0;


void checkTreasure(int p1, struct gameState *gstate)
{
    //create gamestates
    struct gameState previousGameState;
    memcpy(&previousGameState, gstate, sizeof(struct gameState));
    //memcpy(&pre,post,sizeof(struct gameState));
    //variables for the treasure to compare
    int oldTreasure = 0;
    int newTreasure = 0;
    
    int temphand[MAX_HAND];
    int drawntreasure = 0;
    int bonus = 0;
    
    int i;
    int treasureCard;
    
    //use card
    int useCard = 0;
    
    
    useCard = cardEffect(council_room,0,0,0,gstate,0,&bonus);
    
    
    
    
    //holds the new handCount after council_room was called
    int newDrawCount = gstate->handCount[p1];
    
    int oldDrawCount = previousGameState.handCount[p1] + 4; 
    
    
    printf("\n old draw count is: %i\n", oldDrawCount);
    printf("\n new draw count is: %i\n", newDrawCount);
   
    
    if (newDrawCount != oldDrawCount)
    {
        countIncreaseFail++;
    }
}

int main () {
    srand(time(NULL));
    int i;
    
    int playerNumber;
    int testNumber = 50;
    
    
    int n;
    
    for (n = 0; n < testNumber; n++)
    {
        
    //randomize playerNumber
    playerNumber = rand() % MAX_PLAYERS;
    int treasureNumber = 0;
    
    
    
    struct gameState g1;
    //set up deckcount
    //set the deck count of this player
    g1.deckCount[playerNumber] = rand() % MAX_HAND;
    //set up treasure
    treasureNumber = rand() % g1.deckCount[playerNumber];
    //randomize the treasure type
    for (i = 0; i < treasureNumber; i++)
    {
        g1.deck[playerNumber][i] = treasureArray[rand() % treasureNumber];
    }
    
    g1.handCount[playerNumber] = 0;
    g1.whoseTurn = playerNumber;
    g1.discardCount[playerNumber] = 0;
    
    
    
    //set player count to max
    
    
    
    //int playerCount = MAX_PLAYERS;
    
    
    
    //call the function
    checkTreasure(playerNumber, &g1);
    }
    
    
    if (countIncreaseFail > 0){
    printf("Total fails: %i\n", countIncreaseFail);
    }
    return 0;
}