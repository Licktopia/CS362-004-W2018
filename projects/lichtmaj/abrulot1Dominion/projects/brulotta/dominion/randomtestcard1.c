/*
 * randomtestcard1.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h> 
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"


int testsPassed = 0;
int testsFailed = 0;

void myAssert(int passOrFail, char *nameOfTest){
	if (passOrFail > 0){
	  	printf("TEST: %s PASSED\n", nameOfTest);
	    testsPassed++;
  	}
    else{
	    printf("TEST: %s FAILED\n", nameOfTest);
	    testsFailed++;
  	}
}


int main() {
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2; 
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
	  sea_hag, tribute, smithy, council_room};
	srand(time(NULL));
	int newActions = 2;

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	printf("Village: Draw one card plus 2 actions\n");

	for (i = 0; i < 500; i++){
	    //randomize number of players and starting player
	    numPlayers = rand() % 2 + 2; 
	    thisPlayer = rand() % numPlayers;
	    seed = rand();
	    //initialize game
	    initializeGame(numPlayers, k, seed, &G); 
	    memcpy(&testG, &G, sizeof(struct gameState)); 
	    //randomize deck count, discard count, handcount, hand position
	    G.deckCount[thisPlayer] = rand() % MAX_DECK;
	    G.discardCount[thisPlayer] = rand() % MAX_DECK;
	    G.handCount[thisPlayer] = rand() % MAX_HAND;
	    handpos = rand() % G.handCount[thisPlayer]; 
	    G.hand[thisPlayer][handpos] = village;
	    printf("NumPlayers: %d This Player: %d Deckcount: %d Discardcound: %d Handcount %d Handpos %d\n", numPlayers, thisPlayer, G.deckCount[thisPlayer], G.discardCount[thisPlayer], G.handCount[thisPlayer], handpos);
	    //play card
	    cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);


	    printf("Test 1 Correct number of cards in deck: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	    printf("Test 2 New hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	    printf("Test 3 The turn has not changed: whose turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn);
	    printf("Test 4 Actions are one fewer: num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions + 1);
	    
	    myAssert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1, "+0 Cards in Deck");
	    myAssert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1, "+0 Cards in Hand");
	    myAssert(testG.whoseTurn == G.whoseTurn, "Turn hasn't changed");
	    myAssert(testG.numActions == G.numActions + newActions - 1, "+1 actions left after playing card");
	    
    }
  return 0;
}
