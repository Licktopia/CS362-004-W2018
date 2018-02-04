/* -----------------------------------------------------------------------
 * BUYCARD
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int testsPassed = 0;
    int testsFailed = 0;
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount, toState;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING buyCard():\n");
#if (NOISY_TEST == 1)
                printf("Test buying a mine when there are enough coins, numbuys, and supply count.\n", p);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.coins = 6;
                G.numBuys = 1;
                G.supplyCount[mine] = 2;
                int rValue = buyCard(k[4], &G);

#if (NOISY_TEST == 1)
                printf("Return value is %d, expected %d\n", rValue, 0);
                printf("G.supplyCount[mine] = %d, expected = %d\n", G.supplyCount[mine], 1);
              
#endif
                if(rValue == 0){
                    testsPassed++;
                } else {
                    testsFailed++;
                }
                if(G.supplyCount[mine] == 1){
                    testsPassed++;
                } 
                else{
                    testsFailed++;
                }
#if (NOISY_TEST == 1)
                printf("Test buying a mine when there aren't enough coins.\n", p);
#endif
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.coins = 4;
                G.numBuys = 1;
                G.supplyCount[mine] = 2;
                rValue = buyCard(k[4], &G);

#if (NOISY_TEST == 1)
                printf("Return value is %d, expected %d\n", rValue, -1);
                printf("G.supplyCount[mine] = %d, expected = %d\n", G.supplyCount[mine], 2);
              
#endif
                if(rValue == -1){
                    testsPassed++;
                } else {
                    testsFailed++;
                }
                if(G.supplyCount[mine] == 2){
                    testsPassed++;
                } 
                else{
                    testsFailed++;
                }
#if (NOISY_TEST == 1)
                printf("Test buying a mine when there aren't buys, .\n", p);
#endif
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.coins = 5;
                G.numBuys = 0;
                G.supplyCount[mine] = 2;
                rValue = buyCard(k[4], &G);

#if (NOISY_TEST == 1)
                printf("Return value is %d, expected %d\n", rValue, -1);
                printf("G.supplyCount[mine] = %d, expected = %d\n", G.supplyCount[mine], 2);
              
#endif
                if(rValue == -1){
                    testsPassed++;
                } else {
                    testsFailed++;
                }
                if(G.supplyCount[mine] == 2){
                    testsPassed++;
                } 
                else{
                    testsFailed++;
                }
#if (NOISY_TEST == 1)
                printf("Test buying a mine when there aren't mines left.\n", p);
#endif
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.coins = 5;
                G.numBuys = 1;
                G.supplyCount[mine] = 0;
                rValue = buyCard(k[4], &G);

#if (NOISY_TEST == 1)
                printf("Return value is %d, expected %d\n", rValue, -1);
                printf("G.supplyCount[mine] = %d, expected = %d\n", G.supplyCount[mine], 0);
              
#endif
                if(rValue == -1){
                    testsPassed++;
                } else {
                    testsFailed++;
                }
                if(G.supplyCount[mine] == 0){
                    testsPassed++;
                } 
                else{
                    testsFailed++;
                }

    printf("Tests passed: %d\n",testsPassed);
    printf("Tests failed: %d\n",testsFailed);
    return 0;
}