template <typename T>
DynamicArraySequence<T>::DynamicArraySequence()
        : m_array( new DynamicArray<T>() ) {}

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence(int size)
        : m_array( new DynamicArray<T>(size) ) {}

template<class T>
DynamicArraySequence<T>::DynamicArraySequence(T* items, int size)
        : m_array( new DynamicArray<T>(items, size) ) {};

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence(const DynamicArraySequence<T>& another)
        : m_array( new DynamicArray<T>(*another.m_array) ) {};

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence(const DynamicArray<T>& array) : m_array( new DynamicArray<T>(array) ) {}

template <typename T>
DynamicArraySequence<T>& DynamicArraySequence<T>::operator= (const DynamicArraySequence<T>& another) {
    m_array = new DynamicArray<T>(*another.m_array);
    return *this;
}

template <typename T>
DynamicArraySequence<T>& DynamicArraySequence<T>::operator= (DynamicArraySequence<T>* another) {
    m_array = new DynamicArray<T>(*another->m_array);
}

template <typename T>
DynamicArraySequence<T>::~DynamicArraySequence() {
    delete m_array;
}

template <typename T>
T DynamicArraySequence<T>::getItem(int index) const {
    return m_array->getItem(index);
}

template <typename T>
int DynamicArraySequence<T>::getSize() const {
    return m_array->getSize();
}

template <typename T>
T DynamicArraySequence<T>::getFirst() const {
    return m_array->getFirst();
}

template <typename T>
T DynamicArraySequence<T>::getLast() const {
    return m_array->getLast();
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::insert(int index, const T& item) {
    m_array->insert(index, item);
    return *this;
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::remove(int index) {
    m_array->remove(index);
    return *this;
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::append(const T& item) {
    m_array->push(item);
    return *this;
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::prepend(const T& item) {
    m_array->unshift(item);
    return *this;
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::clear() {
    m_array->clear();
    return *this;
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::pop() {
    m_array->pop();
    return *this;
}

template <typename T>
Sequence<T>& DynamicArraySequence<T>::shift() {
    m_array->shift();
    return *this;
}

template <typename T>
DynamicArraySequence<T>* DynamicArraySequence<T>::map(T (*function)(const T& item)) {
    DynamicArray<T>* tmp = m_array->map(function);
    DynamicArraySequence<T>* result = new DynamicArraySequence<T>(*tmp);
    delete tmp;
    return result;
}

template <typename T>
DynamicArraySequence<T>* DynamicArraySequence<T>::filter(bool (*function)(const T& item)) {
    DynamicArray<T>* tmp = m_array->filter(function);
    DynamicArraySequence<T>* result = new DynamicArraySequence<T>(*tmp);
    delete tmp;
    return result;
}

template <typename T>
DynamicArraySequence<T>* DynamicArraySequence<T>::getSubSequence(int startIndex, int endIndex) const {
    DynamicArray<T>* tmp = m_array->getSubList(startIndex, endIndex);
    DynamicArraySequence<T>* result = new DynamicArraySequence<T>(*tmp);
    delete tmp;
    return result;
}

template <typename T>
DynamicArraySequence<T>* DynamicArraySequence<T>::concat(Sequence<T>& sequence) const {
    DynamicArraySequence<T>* result = new DynamicArraySequence<T>(*this);
    for (int i = 0; i < sequence.getSize(); i++) {
        result->append(sequence.getItem(i));
    }
    return result;
}

template <typename T>
T DynamicArraySequence<T>::reduce(T (*function)(const T& previousValue, const T& currentValue)) {
    return m_array->reduce(function);
}


//
//  Ops
//

template <typename T>
std::ostream& operator<< (std::ostream &out, const DynamicArraySequence<T>& array) {
    out << "[";
    for (int i = 0; i < array.getSize() - 1; i++) {
        out << array.getItem(i) << ", ";
    }
    if (array.getSize() > 0)
        out << array.getItem(array.getSize() - 1);
    out << "]";
    return out;
}

template <typename T>
T& DynamicArraySequence<T>::operator[] (int index) {
    return (*m_array)[index];
}


