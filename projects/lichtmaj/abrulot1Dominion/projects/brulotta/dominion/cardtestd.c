/**********************************************************************************
 * Author: Adam Brulotte
 * Class: CS362 W2018
 * Assignment: 3
 * Name cardtest1.c
 * Description:  Unit test that will test the functionality of the smithy dominion
 * 		card.
 **********************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//define variable to hold the card under test
#define TESTCARD "smithy"

int main()
{
	//set variables
	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;
	int i, j, k;
	int numPlayers = 2;
	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		 sea_hag, tribute, smithy, council_room};
	int gameSeed = 1000;
	int curPlayer = 0;

	//make instances of the game
	struct gameState game, test;

	//initialize game
	initializeGame(numPlayers, cards, gameSeed, &game);

	//copy game state to test state for comparisons
	memcpy(&test, &game, sizeof(struct gameState));

	printf("\n\t\t--- Testing Card: %s ---\n\n", TESTCARD);
}
