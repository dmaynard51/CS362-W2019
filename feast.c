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
int discardCountFail;
int buyFail;
int passFail;
int coinIncrease;
int coinIncreaseFails = 0;


void checkSmithy(int p1, struct gameState *gstate)
{
    //create gamestates
    struct gameState previousGameState;
    //previous game state
    memcpy(&previousGameState, gstate, sizeof(struct gameState));
    //memcpy(&pre,post,sizeof(struct gameState));

    
    int temphand[MAX_HAND];
    int drawntreasure = 0;
    int bonus = 0;
    
    int i;
    int treasureCard = rand() % 20;
    
    //use card
    int useCard = 0;
    gstate->supplyCount[treasureCard] = 10;
    useCard = cardEffect(feast,treasureCard,0,0,gstate,0,&bonus);
    
    
    
    
    //holds our newDrawCount after we used the smithy card
    int newDrawCount = gstate->handCount[p1];
    int correctDrawCount = previousGameState.handCount[p1] + 3;
    
    
    //manually increase handCount
    int oldDrawCount = drawCard(p1,&previousGameState);
    int oldDrawCount1 = drawCard(p1,&previousGameState);
    int oldDrawCount2 = drawCard(p1,&previousGameState);
    
    
 //   printf("\n correct draw count is: %i\n", correctDrawCount);
   // printf("\n new draw count is: %i\n", newDrawCount);
   
    
    if (newDrawCount != correctDrawCount)
    {
        countIncreaseFail++;
    }
    
    //check discards
    
    //call discard on previouState
    int callDraw = discardCard(0, p1, &previousGameState, 0);
    
    //check new hand count
    int newHand = gstate->handCount[p1];
    //check correct hand count
    int correctHand = previousGameState.handCount[p1];
    
    
    //int correctDiscard = previousGameState.discardCard[p1];
    
    //printf("\n correct discard count is: %i\n", correctHand);
   // printf("\n new discard count is: %i\n", newHand);
    

    if (correctHand != newHand)
    {
        discardCountFail++;
    }
    
    //printf("%i\n", getCost(treasureCard));
    //printf("%i\n", gstate->coins);
    
    
    if (gstate->coins < treasureCard)
    {
        buyFail++;
    }
    else
    {
        passFail++;
    }
    
    if (gstate->coins == 5)
    {
        coinIncrease++;
    }    
    else
    {
        coinIncreaseFails++;
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
    playerNumber = rand() % MAX_PLAYERS-1;
    int treasureNumber = 0;
    
    
    
    struct gameState g1;
    //set up deckcount
    //set the deck count of this player
    g1.deckCount[playerNumber] = rand() % MAX_HAND;
    
    g1.handCount[playerNumber] = 0;
    g1.whoseTurn = playerNumber;
    
    //randomize discard count
    g1.discardCount[playerNumber] = MAX_DECK;
    //call the function
    checkSmithy(playerNumber, &g1);
    }
    
    
    printf("** Total Buy FAILS: %i **\n", buyFail);
    
    
    printf("** Total Buy PASS: %i **\n", passFail);
    
    printf("** Coin increase PASS: %i **\n", coinIncrease);
    printf("** Coin increase FAILS: %i **\n", coinIncreaseFails);
    
    
    return 0;
}