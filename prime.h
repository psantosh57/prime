#pragma once

#include "../util/util.h"

#ifndef PRIME_H
#define PRIME_H

class prime {

public:

	prime(const int n, const int maxNum): _algo(n), _limit(maxNum) {

		cout << "In prime constructor" << endl;
			
	}

	void number_of_primes(int n);

private:

	int _algo;
	int _limit;
	int _numPrimes;

	
	bool isPrime(int n);



};



#endif