#include "PrimePrinter.h"
#include <iostream>
#include <iomanip>

void PrimePrinter::print(){
    int* primes;    

    Generator generator(numberOfPrimes, ordmax);
    Printer printer(numberOfPrimes, linesPerPage, columns);

    primes = generator.GeneratePrime();
    printer.printPage(primes);
}

int* Generator::GeneratePrime() {
    int* primes = new int[generatorNumberOfPrimes + 1];
    primes[1] = 2;
    int* multiples = new int[generatorOrdmax + 1];

    while (primeIndex < generatorNumberOfPrimes) {
        do {
            candidate += 2;
            if (candidate == square) {
                ord++;
                square = primes[ord] * primes[ord];
                multiples[ord - 1] = candidate;
            }
            N = 2;
            possiblyPrime = true;
            while (N < ord && possiblyPrime) {
                while (multiples[N] < candidate)
                    multiples[N] += primes[N] + primes[N];
                if (multiples[N] == candidate)
                    possiblyPrime = false;
                N++;
            }
        } while (!possiblyPrime);
        primeIndex++;
        primes[primeIndex] = candidate;
    }

    return primes;
}

void Printer::printPage(int* primes) {
    while (pageoffset <= numberOfPrimes) {
        printHeader();
        printPrime(primes);
        pagenumber++;
        pageoffset += linesPerPage * columns;
    }
}

void Printer::printHeader(){
    std::cout << "The First ";
    std::cout << numberOfPrimes;
    std::cout << " Prime Numbers === Page ";        
    std::cout << pagenumber << std::endl;
    std::cout << std::endl;
}

void Printer::printPrime(int* primes){
    for (int rowoffset = pageoffset; rowoffset <= pageoffset + linesPerPage - 1; rowoffset++) {
        for (int column = 0; column <= columns - 1; column++)
            if (rowoffset + column * linesPerPage <= numberOfPrimes)
                std::cout << std::setw(10) << std::right << primes[rowoffset + column * linesPerPage];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


