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
int treasurefail = 0;


void checkTreasure(int p1, struct gameState *gstate)
{
    //create gamestates
    struct gameState previousGameState;
    memcpy(&previousGameState, gstate, sizeof(struct gameState));
    //memcpy(&pre,post,sizeof(struct gameState));
    //variables for the treasure to compare
    int oldTreasure = 0;
    int verifyTreasure = 0;
    int newTreasure = 0;
    
    int temphand[MAX_HAND];
    int drawntreasure = 0;
    int bonus = 0;
    int drawnCard = 0;
    
    int i;
    int temphandIter = 0;
    int treasureCard;
    
    //use card
    int useCard = 0;
    useCard = cardEffect(adventurer,0,0,0,gstate,0,&bonus);
    
    //treasure on our own
    
    for (i = 0; i < gstate->handCount[p1]; i++) {
        treasureCard = gstate->hand[p1][i];
        if (treasureCard == copper || treasureCard == silver || treasureCard == gold) {
            treasureCount = treasureCount + 1;
        }
    }
    
    while (verifyTreasure < 2)
    {
        //draw card    
        drawnCard = drawCard(p1, &previousGameState);
        //
        treasureCard = previousGameState.hand[p1][previousGameState.handCount[p1] - 1];
        if (treasureCard ==copper || treasureCard ==silver || treasureCard ==gold) {
            //increment treasure
            verifyTreasure++;
           // previousGameState.handCount[p1]--;
        }
        else
        {
            temphand[temphandIter] = drawnCard;
            previousGameState.handCount[p1]--;
            temphandIter++;
        }
    }
    
    
   // printf("\n new treasure count is: %i\n", treasureCount);
    /*previousGameState.hand[p1][0] = copper;
    previousGameState.hand[p1][1] = copper;
    previousGameState.hand[p1][2] = copper;
    previousGameState.handCount[p1] += 2;*/

    


    for (i = 0; i < previousGameState.handCount[p1]; i++) {
        treasureCard = previousGameState.hand[p1][i];
        if (treasureCard == copper || treasureCard == silver || treasureCard == gold) {
            oldTreasure = oldTreasure + 1;
        }
    }    
    
   // printf("treasure %i  actual treasure %i", oldTreasure, treasureCount);
    
    //printf("\n old treasure count is: %i\n", oldTreasure);
    
    if (oldTreasure != treasureCount)
    {
        treasurefail++;
    }
    
    
}

int main () {
    srand(time(NULL));
    int i;
    int playerNumber;
    int testNumber = 100;
    int n;
    for (n = 0; n < testNumber; n++)
    {
    playerNumber = rand() % MAX_PLAYERS;
    int treasureNumber = 0;
    
    
    
    struct gameState g1;
    //set up deckcount
    g1.deckCount[playerNumber] = rand() % MAX_HAND;
    //set up treasure
    treasureNumber = rand() % g1.deckCount[playerNumber];
    //randomize the treasure type
    for (i = 0; i < treasureNumber; i++)
    {
        g1.deck[playerNumber][i] = treasureArray[rand() % 3-1];
    }
    
    g1.handCount[playerNumber] = 0;
    g1.whoseTurn = playerNumber;
    g1.discardCount[playerNumber] = 0;
    
    
    
    //set player count to max
    
    
    
    //int playerCount = MAX_PLAYERS;
    
    
    
    //call the function
    checkTreasure(playerNumber, &g1);
    }
    printf("Total fails out of %i is: %i", testNumber, treasurefail);
    
    return 0;
}