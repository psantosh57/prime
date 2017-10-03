#pragma once

#include "../util/util.h"

#ifndef PRIME_H
#define PRIME_H

class prime {

public:

	prime(const int n, const int maxNum) : _algo(n), _limit(maxNum), _numPrimesArray{ {0,0}, {1,0},{2,0} }, _stepArray{ { 0,0 },{ 1,0 },{ 2,0 } }, _numSteps(0), _primeArray_1(0), _primeArray_2(0), _primeArray_3(0) {

		cout << "In prime constructor" << endl;
			
	}

	~prime() {

		release();
	}

	int number_of_primes(int n);
	int get_prime_number(int algoType, int index);
	void release();

private:

	int _algo;
	int _limit;
	int* _primeArray_1;
	int* _primeArray_2;
	int* _primeArray_3;
	int _numSteps;

	int _stepArray [3][2];
	int _numPrimesArray [3][2]; 

	
	bool isPrime(int n);
	bool isPrime_2(int n);
	void strikeOutMultiples(int* temp, int n);



};



#endif