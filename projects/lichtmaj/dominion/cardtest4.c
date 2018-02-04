/*
 * cardtest4.c
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

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
	int beforeTreasure = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	for(i = 0; i < G.handCount[thisPlayer]; i++){
  		if (G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold){
    		beforeTreasure++;
  		}
	}

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("Adventurer: Reveal cards in deck until 2 treasure cards are revealed and discard the rest\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	int afterTreasure = 0;
	for(i = 0; i < G.handCount[thisPlayer]; i++){
  		if (G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold){
    		afterTreasure++;
  		}
	}

	newCards = 2;
	newActions =0;
	
	printf("Test 1 Correct number of cards in deck: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 2);
	printf("Test 2 The turn has not changed: whose turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn);
	printf("Test 3 Actions are one fewer: num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions - 1);
	printf("Test 4 Treasure in hand has increased by 2: after treasure = %d, expected = %d\n", afterTreasure, beforeTreasure + 2);
	
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
	if(testG.numActions == G.numActions - 1){
		testsPassed++;
	}else{
		testsFailed++;
	}
	
	

	printf("Tests passed: %d\n",testsPassed);
    printf("Tests failed: %d\n",testsFailed);


	return 0;
}

