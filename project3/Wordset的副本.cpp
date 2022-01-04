#include "Wordset.hpp"
#include <string>

const int BASE_TO_USE = 41; 
const double LOAD_LIMIT = 0.27;


// returns s, as a number in the given base, mod the given modulus
int hashFunction(std::string s, int base, int mod)
{
	int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int temp = s[i]-'a';
		for (int j = 0; j < s.size()-i-1; j++)
		{
			temp = temp * base;
		}
		result += temp;
	}

	return result % mod;
}

bool isPrime(int n)
	{
		if(n % 2 == 0)
			return false;
		
		for(int i = 3; i <= sqrt(n); i += 2)
		{
			if(n % i == 0)
				return 0;
		}
		return 1;
	}

int nextPrime(int x){
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
	for (int i = 0; i < 13; i++)
	{
		table[i] = "999";
	}
	size = 13;
	capacity = 0;
}

WordSet::~WordSet()
{
	delete[] table;
}

void WordSet::insert(std::string s)
{
	//normal insert
	int bucket = hashFunction(s, BASE_TO_USE, size);
	int i = 0;
	bucket = bucket % size;
	//if (table[bucket] != "999"){ // 这儿逻辑有些问题 应该是现在这样 之前是 while table[bucket] == '999' 这样会一直跑下去  应该是不是999的话代表被占了那就接着去跑 i+1
	while (table[bucket] != "999")
		{
			i++;
			bucket = (bucket + i*i) % size;
		}
	//}
	
	
	table[bucket] = s;
	capacity++;


	//Resizing
	if (capacity/size > LOAD_LIMIT)
	{
		int newSize = nextPrime(2 * size);
		int j = 0;

		std::string* newTable = new std::string[newSize];
		for (int i = 0; i < size; i++)
		{
			if (table[i] != "999") // 这儿的逻辑好像有同样的问题 现在是改好的
			{
				bucket = hashFunction(table[i], BASE_TO_USE, newSize);
				bucket = bucket % size;
				while (newTable[bucket] != "999")
				{
					j++;
					bucket = (bucket + j*j) % newSize;
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
	int bucket = hashFunction(s, BASE_TO_USE, size);
	for(int i = 0; i < capacity; i++){
		if (table[(bucket + i * i) % size] == s) return true;
	}
	
	return false;  // stub, not correct.
}

// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return BASE_TO_USE + LOAD_LIMIT; // this is not the right answer. 
}

// return how large the underlying array is.
int WordSet::getCapacity() const
{
	return 1729; // that isn't even a prime number!
}
