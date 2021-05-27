#ifndef MYLAB2_LINKEDLIST_H
#define MYLAB2_LINKEDLIST_H

#include "../Exceptions/Exceptions.h"
#include "../dependencies.h"

template <class T>
class LinkedList
{
protected:
    using m_Element = struct m_Element {
        T data;
        struct m_Element* next;
        struct m_Element* prev;
    };

    m_Element* m_head;
    m_Element* m_tail;
    int m_size;
public:
    explicit LinkedList();
    explicit LinkedList(T* items, int size);
    LinkedList(const LinkedList<T>& another);

    LinkedList<T>& operator= (const LinkedList<T>& another);
    LinkedList<T>& operator= (LinkedList<T>* another);

    ~LinkedList();

    int getSize() const;

    T getItem(int index) const;
    T getFirst() const;
    T getLast() const;
    T reduce(T (*function)(const T& previousValue, const T& currentValue)) const;

    LinkedList<T>& clear();
    LinkedList<T>& append(const T& item);
    LinkedList<T>& prepend(const T& item);
    LinkedList<T>& remove(int index);
    LinkedList<T>& insert(int index, const T& item);
    LinkedList<T>* concat(const LinkedList<T>& list) const;
    LinkedList<T>* getSubList(int startIndex, int endIndex) const;
    LinkedList<T>* map(T (*function)(const T& item)) const;
    LinkedList<T>* filter(bool (*function)(const T& item)) const;

    T& operator[] (int index);

};


#include "LinkedList.inl"

#endif
