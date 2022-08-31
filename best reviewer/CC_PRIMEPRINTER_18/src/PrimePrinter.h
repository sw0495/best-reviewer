#ifndef _PRIMEPRINTER_H_
#define _PRIMEPRINTER_H_

#include <iostream>

class PrimePrinter{
	const int numberOfPrimes = 1000;
	const int ordmax = 30;
    const int linesPerPage = 50;
    const int columns = 4;

public:
	void print(); 
};

class Generator{
	int* prime;
	int* multiples;
	int generatorNumberOfPrimes;
	int generatorOrdmax;
	int candidate = 1;
    int primeIndex = 1;
    bool possiblyPrime;
    int ord = 2;
    int square = 9;
    int N = 0;

public:
    Generator(){		
	}
    Generator(int numberOfPrimes, int ordmax)
	:generatorNumberOfPrimes(numberOfPrimes)
	,generatorOrdmax(ordmax)
	,candidate(1)
    ,primeIndex(1)
    ,ord(2)
    ,square(9)
    ,N(0){	
	prime = new int[numberOfPrimes + 1];	
	multiples = new int[ordmax + 1];
	}

	~Generator(){
	delete[] prime;	
	delete[] multiples;
	}
	int* GeneratePrime();
};

class Printer{
	int numberOfPrimes;
	int linesPerPage;
	int columns;
    int pagenumber;
    int pageoffset;
public:
    Printer(){
	}
    Printer(int printerNumberOfPrimes, int printerLinesPerPage, int printerColumns)
	:numberOfPrimes(printerNumberOfPrimes)
	,linesPerPage(printerLinesPerPage)
	,columns(printerColumns)
	,pagenumber(1)
	,pageoffset(1){
	}	
	void printPage(int* primes);	
	void printHeader();
	void printPrime(int* primes);
};

#endif      // _PRIMEPRINTER_H_
