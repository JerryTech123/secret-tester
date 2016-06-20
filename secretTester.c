#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generatePrimes.h"
#include "constants.h"
#include "secret.h"

int main (int argc, char *argv[]){
	int numEntered; 			//the integer entered from the command line
	int primesFound; 			//the number of primes that were found between 1 and the user-entered number
	int i;
	int j;
	int secretX_Y; 				//will hold the results of secret(x+y)
	int secretX;				//will hold the results of secret(x)
	int secretY;				//will hold the results of secret(y)
	int primes[PRIMES] = {0}; 	//the array that will contain the list of primes found between 1 and the user-entered number
	
	//We are specifically looking for the case where 2 arguments are given:
	//the program name and the number against which to test secret()
	//If the argument list is too long (>2) or too short (<2), we alert the user as to what went wrong
    if(argc == 2){
		
		for(i = 0; i < strlen(argv[1]); i++){
			
			//make sure that the user gave us an integer, and if the user did not, tell them what went wrong
			if(!isdigit(argv[1][i])){
				printf("Number entered is not a positive integer.\n");
				return 0;
			}
		}
		
		numEntered = atoi(argv[1]);
		
		if(numEntered > LIMIT){
			printf("%d exceeds the input limit of %d\n", numEntered, LIMIT);
			return 0;
		}
		if(numEntered < 4){
			printf("In order to have at least 2 primes to test against, the number entered must be greater than 3\n");
			return 0;
		}
		//collect the prime numbers between 1 and numEntered
		primesFound = generatePrimes(numEntered,primes);
		//printf("%d primes were found\n", primesFound);
		printf("Testing Secret()...\n", primesFound);
	} else if(argc > 2){
		printf("Too many arguments entered. I was expecting a single integer.\n");
		return 0;
	} else if(argc < 2){
		printf("No number was entered!\n");
		return 0;
	}
	
	//for every combination of the primes found, test secret(x+y) = secret(x) + secret(y)
	//if we find that the test fails once, we can stop testing
	//if every combination is tested and all of the tests pass, then we can conclude that secret()
	//is additive for all primes less than the number entered from the command line
	for(i = 0; i < primesFound - 2; i++){
		for(j = i + 1; j < primesFound - 1; j++){
		
			//printf("testing %d against %d\n",primes[i],primes[j]);
		
			secretX_Y = secret(primes[i] + primes[j]);
			secretX = secret(primes[i]);
			secretY = secret(primes[j]);
			
			if(secretX_Y != (secretX + secretY)){
				printf("secret() is not additive for all primes less than the number entered from the command line");
				return 0;
			}
		}
	}
	
	//If program execution reaches this point, then all of our tests against secret() have passed
	printf("secret() is additive for all primes less than the number entered from the command line");
	
	//printf("%d arguments were entered\n", argc);
    //printf("You entered the number %d\n", numEntered);

	

	
    return 0;
} 