/************************************************************************
 * Author: Adam Brulotte
 * Class: CS362 W2018
 * Assignment: 4
 * Name: randomtestcard1.c
 * Description: Random tester for the dominion card Council Room.  
 * **********************************************************************/

#include "dominion.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <math.h>
#include <time.h>



//define variable to hold the card under test
#define TESTCARD "council_room"

int testCard(int curPlayer, struct gameState *control)
{
	//variables
	int cardEff;	
	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;

	//create instance of the game state to test
	struct gameState test;

	//copy parameter gamestate to test gamestate
	memcpy(&test, control, sizeof(struct gameState));

	

	//call cardEffect with the chosen card
	cardEff = cardEffect(TESTCARD, choice1, choice2, choice3, &test, 
		handPos, &bonus);	
}



int main()
{
	//seed the random test generator
	SelectStream(3);
	PutSeed(4);
	//variables
	int i, j, k, player;
	int numTests = 100000;

	//make instances of the game
	struct gameState Game, control;
	
	//loop to run interations of the tests
	for(i = 0; i < numTests; i++)
	{
		//fill the game state with random bytes
		for(j = 0; j , sizeof(struct gameState); j++)
		{
			((char*)&Game[j] = floor(Random() * 256);
		}
		
		//set "good" values for important variables
		player = floor(Random() * MAX_PLAYERS);
		Game.deckCount[player] = floor(Random() * MAX_DECK);
		Game.discardCount[player] = floor(Random() * MAX_DECK);
		Game.handCount[player] = floor(Random() * MAX_HAND);
	}	

	

	

	


















	return 0;
}
