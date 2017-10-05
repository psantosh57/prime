#include "prime.h"

int prime::number_of_primes(int n) {

	switch (n) {

	case 0 : {

		//cout << "School Method" << endl;

		//_primeArray_1 = new int[_limit];

		int index = -1;

		for (int i = 2; i < _limit; ++i) {

			if (isPrime(i)) {
				
				//cout << i << " is prime!" << endl;
				//_numPrimesArray[0][1] ++;
				_primeArray_1[++index] = i;

			}

		}

		return (index+1);

	}

	case 1: {

		//cout << "Up to prime numbers" << endl;

		//_primeArray_2 = new int[_limit];
		_primeArray_2[0] = 2;
		for (int i = 1; i < _limit; ++i) {

			_primeArray_2[i] = -1;
		}
		
		int index = 0;

		for (int i = 3; i < _limit; ++i) {

			if (isPrime_2(i)) {

				//cout << i << " is prime!" << endl;
				//_numPrimesArray[0][1] ++;
				_primeArray_2[++index] = i;

			}

		}


		return (index+1);

	}
	case 2: {

		//cout << "Sieve of Eratosthenes" << endl;
		int* tempArray = new int[_limit];
		tempArray[0] = -1;
		tempArray[1] = -1;
		for (int i = 2; i < _limit; ++i) {
			tempArray[i] = i;

		}

		int index = 0;
		int count = 0;
		int arrayCnt = 0;

		for (int i = 2; i < _limit; ++i) {

			strikeOutMultiples(tempArray, i);
		}

		for (int i = 0; i < _limit; ++i) {

			if (tempArray[i] != -1) {

				arrayCnt++;
			}
		}

		//_primeArray_3 = new int[arrayCnt];




		for (int k = 0; k < _limit; ++k) {

			if (tempArray[k] != -1) {

				//count++;
				_primeArray_3[index] = tempArray[k];
				index++;
				//cout << _primeArray_3[k] << endl;
			}
		}



		delete[] tempArray;
		return arrayCnt;

	}

		
	}

}

bool prime::isPrime(int n) {

	for (int i = 2; i <= sqrt(n); ++i) {
		
		_numSteps++;
		
		if (n % i == 0) {

			return false;
		}

	}

	return true;

}

void prime::allocate() {

	_primeArray_1 = new int[_limit];
	_primeArray_2 = new int[_limit];
	_primeArray_3 = new int[_limit];
}

void prime::release() {

	delete[] _primeArray_1;
	delete[] _primeArray_2;
	delete[] _primeArray_3;

}

int prime::get_prime_number(int algoType, int index) {

	switch (algoType) {

	case 0: {

		return _primeArray_1[index];

	}

	case 1: {

		return _primeArray_2[index];
	}

	case 2: {

		return _primeArray_3[index];

	}

	}

}

bool prime::isPrime_2(int n) {

	int index = 0;
	while (_primeArray_2[index] != -1 && index < _limit) {

		if (n % _primeArray_2[index] == 0) {

			return false;

		}

		index++;

	}

	return true;
}

void prime::strikeOutMultiples(int* temp, int n) {

	int index = n+n;
	while (index < _limit) {

		if (temp[index] != -1) {
			temp[index] = -1;
		}
		
		index += n;

	}
	

}