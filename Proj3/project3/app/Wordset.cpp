#include "Wordset.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include "math.h"

const int BASE_TO_USE = 41; 
const double LOAD_LIMIT = 0.27;


// returns s, as a number in the given base, mod the given modulus
int hashFunction(std::string s, int base, int mod)
{
	unsigned int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int temp = s[i]-'a';
		for (int j = 0; j < s.size()-i-1; j++)
		{
			temp = temp * base;
		}
		result += temp % mod;
	}
	int result_t = result % mod;
	return result_t;
}

bool isPrime(int n)
	{
		if(n % 2 == 0)
			return false;
		
		for(int i = 3; i <= sqrt(n); i += 2)
		{
			if(n % i == 0)
				return false;
		}
		return true;
	}

int nextPrime(int x)
{
	int new_doble = 2 * x + 1;
	if(isPrime(new_doble)) return new_doble;
	while(isPrime(new_doble) == false){
		new_doble++;
	}
	
	return new_doble;
}


WordSet::WordSet()
{
	table = new std::string[13];
	size = 13;
	capacity = 0;
	//count = 0;
}

WordSet::~WordSet()
{
	delete[] table;
}

void WordSet::insert(std::string s)
{
	//check whether distinct or not
	//if (contains(s) == false) count++;


	//normal insert
	int bucket = hashFunction(s, BASE_TO_USE, size);
	int i = 0;
	while(table[bucket] != ""){
		if(table[bucket] == s){
			capacity--;
			break;
		}
		i++;
		bucket = (hashFunction(s, BASE_TO_USE, size) + i*i) % size;
	}
	table[bucket] = s;
	//count++;
	capacity++;
	
	double capacity_d = capacity;
	double size_d = size;
	double check = capacity_d/size_d;

	//Resizing
	if (check > LOAD_LIMIT)
	{
		int newSize = nextPrime(size);
		int j = 0;

		std::string* newTable = new std::string[newSize];
		for (int i = 0; i < size; i++)
		{
			if (table[i] != "")
			{
				bucket = hashFunction(table[i], BASE_TO_USE, newSize);
				while (newTable[bucket] != "")
				{
					j++;
					bucket = (hashFunction(s, BASE_TO_USE, size) + j*j) % newSize;
				}
				newTable[bucket] = table[i];
			}
		}
		size = newSize;
		delete[] table;
		table = newTable;
	}

}


bool WordSet::contains(std::string s) const
{
	
	for(int i = 0; i < capacity; i++){
		if (table[(hashFunction(s, BASE_TO_USE, size) + i * i) % size] == s){
			return true;
		}
		else if(table[(hashFunction(s, BASE_TO_USE, size) + i * i) % size] == ""){
			return false;
		}
		
	}
	
	return false;
}

// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return capacity;
}

// return how large the underlying array is.
int WordSet::getCapacity() const
{
	return size;
}
