#include "prime.h"

void prime::number_of_primes(int n) {

	switch (n) {

	case 0 : {

		cout << "School Method" << endl;

		int primeArray[4] = { 0 };
		int index = 0;

		for (int i = 2; i < _limit; ++i) {

			if (isPrime(i)) {
				
				cout << i << " is prime!" << endl;
				primeArray[index] = i;
				index++;				

			}

		}

		for (int i = 0; i < 4; ++i) {

			cout << primeArray[i] << endl;
		}

	}

	case 1: {

		cout << "Up to prime numbers" << endl;
	}
	case 2: {

		cout << "Sieve of Eratosthenes" << endl;

	}

		
	}

}

bool prime::isPrime(int n) {

	for (int i = 2; i <= sqrt(n); ++i) {

		if (n % i == 0) {

			return false;
		}

	}

	return true;

}