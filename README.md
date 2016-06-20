# secret-tester
secret-tester is a command line tool that tests a secret function for additivity across all primes between 1 and a user-entered number.

To compile secret-tester, first ensure that the GNU compiler has been correctly installed on your computer. Then, download the source files
from the repository, navigate to the download directory via a cmd line tool and enter the following command:

gcc -o SecretTester.exe secretTester.c secret.c generatePrimes.c

To run a test against the secret function, enter the following command from the directory where secret-tester was compiled:

SecretTester "num"

where "num" is a positive integer. The largest number that can be tested is 1,000,000. This number can be changed by changing the LIMIT
constant in constants.h, but care should be taken to ensure that the PRIMES constant is changed as well as PRIMES is the maximum number of
prime numbers that will be used in the test. If LIMIT is changed, PRIMES should be increased to the number of prime numbers expected to be
found for the given value of LIMIT.

secret.c contains two secret functions that can be used in secretTester. Edit secret.c and uncomment the desired secret function
that you want to test, but be sure that one and only one secret function exists (is not commented) at one time. To test your own secret
function, overwrite the code in secret.c with the implementation of your own secret function. The compile command above must be executed
again any time the secret function is changed, and the secret function *must* match the following form:

int secret(int num)

The code that generates the list of primes (generatePrimes.c) used in the test is derived from code found at:

http://www.programminglogic.com/the-sieve-of-eratosthenes-implemented-in-c/

and has been modified to fit the needs of this application.
