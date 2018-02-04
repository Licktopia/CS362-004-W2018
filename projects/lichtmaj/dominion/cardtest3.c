/*
 * cardtest3.c
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Great Hall"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int newActions = 0;
    int shuffledCards = 0;
    int testsPassed = 0;
    int testsFailed = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("Great Hall: Draw one card plus 1 action\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 1;
	newActions = 1;
	printf("Test 1: hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("Test 2: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
	printf("Test 3: whose turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn);
	printf("Test 4: num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions - 1);
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded){
		testsPassed++;
	}else{
		testsFailed++;
	}
	if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards){
		testsPassed++;
	}else{
		testsFailed++;
	}
	if(testG.whoseTurn == G.whoseTurn){
		testsPassed++;
	}else{
		testsFailed++;
	}
	if(testG.numActions == G.numActions - 1){
		testsPassed++;
	}else{
		testsFailed++;
	}
	
	

	printf("Tests passed: %d\n",testsPassed);
    printf("Tests failed: %d\n",testsFailed);


	return 0;
}

