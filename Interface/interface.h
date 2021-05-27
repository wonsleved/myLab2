#ifndef MYLAB2_INTERFACE_H
#define MYLAB2_INTERFACE_H

#include "../Polynomial/Polynomial.h"
#include "cassert"

#include "../tests/DynamicArrayTest.h"
#include "../tests/DynamicArraySequenceTest.h"
#include "../tests/LinkedListTest.h"
#include "../tests/LinkedListSequence.h"
#include "../tests/PolynomialTest.h"




int getInt();
int getInt(int up);
int getInt(int down, int up);

double getDouble();
std::complex<int> getComplex();

std::ostream& operator << (std::ostream& out, std::complex<int> num);

void printPolynomial(
        int item,
        DynamicArraySequence<Polynomial<int>>& polInt,
        DynamicArraySequence<Polynomial<double>>& polDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>>& polComp
);

void printArray(
        int item,
        Polynomial<int> polInt,
        Polynomial<double> polDouble,
        Polynomial<std::complex<int>> polComp
);

void polynomialDelete(
        int item,
        DynamicArraySequence<Polynomial<int>>* polynomialInt,
        DynamicArraySequence<Polynomial<double>>* polynomialDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>>* polynomialComp
);

template<class T>
void printTypePol(DynamicArraySequence<Polynomial<T>>* polynomial);

template<class T>
void printSimple(DynamicArraySequence<Polynomial<T>>* polynomial);

template<class T>
void arrayTypePrint(Polynomial<T>& polynomial);

template<class T>
Polynomial<T> polynomialTypeRead(int count);

template<class T>
void deleteTypePolynomial(DynamicArraySequence<Polynomial<T>>* polynomial);

void testFunction();

void interface();

int getType();

void polynomialRead(
        int item,
        DynamicArraySequence<Polynomial<int>>* polynomialInt,
        DynamicArraySequence<Polynomial<double>>* polynomialDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>>* polynomialComp
);

void polynomialOperations(
        int item,
        DynamicArraySequence<Polynomial<int>>* polynomialInt,
        DynamicArraySequence<Polynomial<double>>* polynomialDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>>* polynomialComp
);

template<class T>
void polynomialTypeOperations(DynamicArraySequence<Polynomial<T>>* polynomials);


#include "interface.inl"

#endif