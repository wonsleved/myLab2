#ifndef MYLAB2_SEQUENCE_H
#define MYLAB2_SEQUENCE_H

#include <cstdlib>
#include <utility>


template<typename T>
class Sequence {
public:
//    virtual ~Sequence() = 0;

    virtual T getItem(int index) const = 0;
    virtual T getFirst() const = 0;
    virtual T getLast() const = 0;

    virtual int getSize() const = 0;

    virtual Sequence<T>& insert(int index, const T& item) = 0;
    virtual Sequence<T>& remove(int index) = 0;
    virtual Sequence<T>& append(const T& item) = 0;
    virtual Sequence<T>& prepend(const T& item) = 0;
    virtual Sequence<T>& clear() = 0;

    virtual Sequence<T>* map(T (*function)(const T& item)) = 0;
    virtual Sequence<T>* filter(bool (*function)(const T& item)) = 0;
    virtual Sequence<T>* getSubSequence(int startIndex, int endIndex) const = 0;
    virtual Sequence<T>* concat(Sequence<T>& sequence) const = 0;

    virtual T reduce(T (*function)(const T& previousValue, const T& currentValue)) = 0;

    virtual T& operator[] (int index) = 0;
};

#endif
