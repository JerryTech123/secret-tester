#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int generatePrimes(int num, int primes[PRIMES]){
    int i,j;
	int numPrimesFound = 0;
	int *numbers;
	numbers = malloc(1000000 * sizeof(int));

	//make sure that malloc worked
	if(numbers != 0){
		
		/*fill the array with natural numbers*/
		 for (i = 0; i < num - 2; i++){
			 numbers[i] = i + 2;
			 printf("%d added to numbers array\n",numbers[i]);
		 }

		// /*sieve the non-primes*/
		 for (i = 0; i < num-2; i++){
			 if (numbers[i] != -1){
				 for (j = 2*numbers[i] - 2; j < num; j += numbers[i])
					 numbers[j]=-1;
			 }
		 }

		// /*transfer the primes to their own array*/
		 j = 0;
		 for (i = 0;i < (num-2) && j < PRIMES;i++){
			 if (numbers[i] != -1){
				 primes[j++] = numbers[i];
				 numPrimesFound++;
			 }
		 }

		// /*print*/
		 for (i = 0; i < numPrimesFound; i++){
			 printf("%d\n",primes[i]);
		 }

		 free(numbers);
		 return numPrimesFound;
	}
	
	return 0;
}
