#ifndef MYLAB2_DYNAMICARRAYSEQUENCE_H
#define MYLAB2_DYNAMICARRAYSEQUENCE_H

#include "Sequence.h"
#include "../base/DynamicArray.h"

template <class T>
class DynamicArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* m_array;
public:
    DynamicArraySequence();
    DynamicArraySequence(int size);
    DynamicArraySequence(T* items, int size);
    DynamicArraySequence(const DynamicArraySequence<T>& another);
    DynamicArraySequence(const DynamicArray<T>& array);


    DynamicArraySequence<T>& operator= (const DynamicArraySequence<T>& another);
    DynamicArraySequence<T>& operator= (DynamicArraySequence<T>* another);

    ~DynamicArraySequence();

    virtual int getSize() const;
    virtual T getItem(int index) const;
    virtual T getFirst() const;
    virtual T getLast() const;

    virtual Sequence<T>& insert(int index, const T& item);
    virtual Sequence<T>& remove(int index);
    virtual Sequence<T>& append(const T& item);
    virtual Sequence<T>& prepend(const T& item);
    virtual Sequence<T>& clear();
    Sequence<T>& pop();
    Sequence<T>& shift();

    virtual DynamicArraySequence<T>* map(T (*function)(const T& item));
    virtual DynamicArraySequence<T>* filter(bool (*function)(const T& item));
    virtual DynamicArraySequence<T>* getSubSequence(int startIndex, int endIndex) const;
    virtual DynamicArraySequence<T>* concat(Sequence<T>& sequence) const;

    virtual T reduce(T (*function)(const T& previousValue, const T& currentValue));

    virtual T& operator[] (int index);
};


#include "DynamicArraySequence.inl"

#endif
