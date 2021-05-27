#ifndef MYLAB2_LINKEDLISTSEQUENCE_H
#define MYLAB2_LINKEDLISTSEQUENCE_H

#include "Sequence.h"
#include "../base/LinkedList.h"

template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T>* m_list;
public:
    LinkedListSequence();
    LinkedListSequence(int size);
    LinkedListSequence(T* items, int size);
    LinkedListSequence(const LinkedListSequence<T>& another);
    LinkedListSequence(const LinkedList<T>& list);

    LinkedListSequence<T>& operator= (const LinkedListSequence<T>& another);
    LinkedListSequence<T>& operator= (LinkedListSequence<T>* another);

    ~LinkedListSequence();

    virtual int getSize() const;
    virtual T getItem(int index) const;
    virtual T getFirst() const;
    virtual T getLast() const;

    virtual Sequence<T>& insert(int index, const T& item);
    virtual Sequence<T>& remove(int index);
    virtual Sequence<T>& append(const T& item);
    virtual Sequence<T>& prepend(const T& item);
    virtual Sequence<T>& clear();

    virtual LinkedListSequence<T>* map(T (*function)(const T& item));
    virtual LinkedListSequence<T>* filter(bool (*function)(const T& item));
    virtual LinkedListSequence<T>* getSubSequence(int startIndex, int endIndex) const;
    virtual LinkedListSequence<T>* concat(Sequence<T>& sequence) const;

    virtual T reduce(T (*function)(const T& previousValue, const T& currentValue));

    virtual T& operator[] (int index);
};


#include "LinkedListSequence.inl"

#endif
