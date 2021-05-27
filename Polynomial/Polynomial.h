#ifndef MYLAB2_POLYNOMIAL_H
#define MYLAB2_POLYNOMIAL_H

#include "../Sequence/DynamicArraySequence.h"

template<class T>
class Polynomial {
private:
    DynamicArraySequence<T>* data;
    static T pow(int power, T value);

public:
    Polynomial();
    Polynomial(int size);
    Polynomial(const Polynomial<T>& polynomial);

    Polynomial<T> &operator = (const Polynomial<T>& polynomial);
    Polynomial<T> &operator = (Polynomial<T>* polynomial);

    ~Polynomial();

    T getItem(int index) const;
    int getSize() const;

    Polynomial<T>& setItem(int index, T item);

    Polynomial<T>& add(const Polynomial<T>& another);
    Polynomial<T>& sub(const Polynomial<T>& another);
    Polynomial<T>& multiplyByScalar(T scalar);
    Polynomial<T>& multiply(const Polynomial<T>& another);
    T value(T value);

    Polynomial<T>& operator +   (const Polynomial<T>& pol);
    Polynomial<T>& operator +=  (const Polynomial<T>& pol);
    Polynomial<T>& operator -   (const Polynomial<T>& pol);
    Polynomial<T>& operator -=  (const Polynomial<T>& pol);
    Polynomial<T>& operator *   (const Polynomial<T>& pol);
    Polynomial<T>& operator *=  (const Polynomial<T>& pol);
};


#include "Polynomial.inl"


#endif
