/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: primetest.cpp
compile: g++ prime.cpp primetest.cpp
==27185== All heap blocks were freed -- no leaks are possible
-----------------------------------------------------------------*/
#include "prime.h"
#include "vld.h"

/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/

void test() {
	const char* alg_name[] = { "School Method", "Up to prime numbers", "Sieve of Eratosthenes" };
	const int NUM_ALGORITHM = sizeof(alg_name) / sizeof(char *);
	const int n[] = { 10,100,1000,10000,100000,1000000, 10000000 };
	const int num_prime[] = { 4,25, 168, 1229,9592,78498, 664579 };
	int k1 = sizeof(n) / sizeof(int);
	int k2 = sizeof(num_prime) / sizeof(int);
	assert(k1 == k2);
	for (int i = 0; i < k1; ++i) {
		prime p(NUM_ALGORITHM, n[i]);
		for (int j = 0; j < NUM_ALGORITHM; ++j) {
			assert(num_prime[i] == p.number_of_primes(j));
			cout << "n = " << n[i] << " ";
			cout << "Algorithm = " << alg_name[j] << " ";
			cout << "Number of primes = " << p.number_of_primes(j) << " ";
			cout << "Number of steps = " << p.number_of_steps(j) << endl;
			
			if (j) {
				/* make sure you have computed same prime numbers in every algorithm */
			
				for (int k = 0; k < p.number_of_primes(0); ++k) {
					int p1 = p.get_prime_number(0, k);	
					int p2 = p.get_prime_number(j, k);
					assert(p1 == p2);
				}
			}			
				
		}


		cout << "-----------------------------------------------------" << endl;
	}
	cout << "You are GrEat. All Tests Passed\n";
}


/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
	test();

#if 0
	prime p(0, 100000);
	int i = p.number_of_primes(0);
	cout << "Ans = " << i << endl;


	
	int i = p.sqrt1(100000);
	int j = p.sqrt2(100000);
	cout << "Method 1 = " << i << " method 2 = " << j << endl;
	//int i = p.number_of_primes(0);
	//int j = p.number_of_primes(0);
	//cout << "Num of primes are " << i << endl;
	//cout << "Num of steps are " << p.number_of_steps(0) << endl;


	prime p(0, 100000);
	cout << "Primes are " << endl;
	for (int k = 0; k < p.number_of_primes(2); ++k) {
		int p1 = p.get_prime_number(2, k);
		cout << p1 << " ";
		//int p2 = p.get_prime_number(j, k);
		//assert(p1 == p2);
	}

 


	prime p(0, 100000);
	int i = p.number_of_primes(0);
	//double ans = p.sqrt2(144);
	cout << "Ans = " << i << endl;



	const int n[] = { 10,100,1000,10000,100000,1000000,10000000 };
	int k1 = sizeof(n) / sizeof(int);
	for (int i = 0; i < k1; ++i) {
		prime p(3, n[i]);
		for (int j = 0; j < 3; ++j) {
			/* make sure you have computed same prime numbers in every algorithm */

			for (int k = 0; k < p.number_of_primes(0); ++k) {
				//cout << "Calculating primes for " << n[i] << endl;
				//int p1 = p.get_prime_number(0, k);
				//int p2 = p.get_prime_number(j, k);
				//assert(p1 == p2);
			}
		}
	}
	

#endif
	return 0;
}