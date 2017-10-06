#pragma once

#include "../util/util.h"

#ifndef PRIME_H
#define PRIME_H

class prime {

public:

	prime(const int algoType, const int maxNum) : _algo(algoType), _limit(maxNum), _numSteps{ 0 }, _numPrimes{ 0 }, _primeArray_1(0), _primeArray_2(0), _primeArray_3(0), _called{ false } {

		//cout << "In prime constructor" << endl;
		allocate();
			
	}

	~prime() {

		//cout << "In prime destructor" << endl;
		release();
		_called [3] = { false };
	}

	int number_of_primes(int n);
	int number_of_steps(int algoType);
	int get_prime_number(int algoType, int index);
	void release();
	void allocate();
	double sqrt1(double n);
	int sqrt2(int n);

private:

	int _algo;
	int _limit;
	int* _primeArray_1;
	int* _primeArray_2;
	int* _primeArray_3;
	int _numSteps[3];
	int _numPrimes[3];
	bool _called[3];

	bool isPrime(int algo, int n);
	bool isPrime_2(int algo, int n);
	void strikeOutMultiples(int* temp, int n, int algo);



};



#endif