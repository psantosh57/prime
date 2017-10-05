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
	const int n[] = { 10,100,1000,10000,100000,1000000 };
	const int num_prime[] = { 4,25, 168, 1229,9592,78498 };
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
			
			/*
			if (j) {
				/* make sure you have computed same prime numbers in every algorithm */
			/*
				for (int k = 0; k < p.number_of_primes(0); ++k) {
					int p1 = p.get_prime_number(0, k);
					int p2 = p.get_prime_number(j, k);
					assert(p1 == p2);
				}
			}
			*/
			
		}


		cout << "-----------------------------------------------------" << endl;
	}
	cout << "You are GrEat. All Tests Passed\n";
}


/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
	//test();
	

	prime p(0, 10);
	int i = p.number_of_primes(0);
	cout << "Num of primes are " << i << endl;
	cout << "Num of steps are " << p.number_of_steps(0) << endl;


#if 0
	cout << "Primes are " << endl;
	for (int k = 0; k < p.number_of_primes(2); ++k) {
		int p1 = p.get_prime_number(2, k);
		cout << p1 << " ";
		//int p2 = p.get_prime_number(j, k);
		//assert(p1 == p2);
	}



	prime p(0, 10000);
	//int i = p.number_of_primes(1);
	//double ans = p.sqrt2(9);
	//cout << "Ans = " << ans << endl;

#endif // 0
	return 0;
}