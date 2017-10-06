#include "prime.h"

int prime::number_of_primes(int n) {

		switch (n) {

		case 0: {

			if (!_called[n]) {
				
				_called[n] = true;

				int index = -1;

				for (int i = 2; i < _limit; ++i) {

					if (isPrime(n, i)) {

						_primeArray_1[++index] = i;
						_numPrimes[n]++;

					}

				}

				return (index + 1);

			}
			else {

				return _numPrimes[n];
			}

		}

		case 1: {

			if (!_called[n]) {

				_called[n] = true;

				_primeArray_2[0] = 2;

				int index = 0;

				for (int i = 3; i < _limit; ++i) {

					if (isPrime_2(n, i)) {
						_primeArray_2[++index] = i;
						_numPrimes[n]++;

					}

				}


				return (index + 1);

			}
			else {

				return _numPrimes[n];
			}

		}
		case 2: {

			if (!_called[n]) {

				_called[n] = true;

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

					strikeOutMultiples(tempArray, i, n);
				}

				for (int i = 0; i < _limit; ++i) {

					if (tempArray[i] != -1) {

						arrayCnt++;
						_numPrimes[n]++;
					}
				}

				for (int k = 0; k < _limit; ++k) {

					if (tempArray[k] != -1) {
						
						_primeArray_3[index] = tempArray[k];
						index++;						
					}
				}

				delete[] tempArray;
				return arrayCnt;

			}
			else {

				return _numPrimes[n];
			}

		}
				
	}


}

bool prime::isPrime(int algo, int n) {

	int sqrt = sqrt2(n);

	for (int i = 2; i <= sqrt; ++i) {
		_numSteps[algo]++;
		
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
	_numSteps = new int[_algo];
	_numPrimes = new int[_algo];
	_called = new bool[_algo];
	for (int i = 0; i < _algo; ++i) {
		_called[i] = false;
		_numPrimes[i] = 0;
		_numSteps[i] = 0;
	}
}

void prime::release() {

	delete[] _primeArray_1;
	delete[] _primeArray_2;
	delete[] _primeArray_3;
	delete[] _numSteps;
	delete[] _numPrimes;
	delete[] _called;


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

bool prime::isPrime_2(int algo, int n) {

	int index = 0;
	int sqrt = sqrt2(n);
	while (_primeArray_2[index] <= sqrt) {
		_numSteps[algo]++;
		if (n % _primeArray_2[index] == 0) {

			return false;

		}

		index++;

	}

	return true;
}

void prime::strikeOutMultiples(int* temp, int n, int algo) {

	int index = n+n;
	while (index < _limit) {

		if (temp[index] != -1) {
			temp[index] = -1;
			_numSteps[algo]++;
		}
		
		index += n;

	}
	

}

int prime::sqrt2(int n) {

	long low = 1;
	long high = n;
	long long ans = 0;

	long long mid = (high + low) / 2;

	if (mid*mid == n) {

		return mid;
	}
	else {

		while (low <= high) {

			mid = low + (high - low) / 2;

			if (mid*mid == n) {

				return mid;
			} 
			else if (mid*mid < n) {

				low = mid+1;
				ans = mid;
			}
			else if (mid*mid > n) {

				high = mid-1;
			}
			
		}

		return ans;

	}

}


int prime::number_of_steps(int algoType) {

	return _numSteps[algoType];
}
