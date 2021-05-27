template <typename T>
LinkedListSequence<T>::LinkedListSequence()
    : m_list( new LinkedList<T>() ) {}

template <typename T>
LinkedListSequence<T>::LinkedListSequence(int size)
        : m_list( new LinkedList<T>(size) ) {}

template<class T>
LinkedListSequence<T>::LinkedListSequence(T* items, int size)
    : m_list( new LinkedList<T>(items, size) ) {};

template <typename T>
LinkedListSequence<T>::LinkedListSequence(const LinkedListSequence<T>& another)
    : m_list( new LinkedList<T>(*another.m_list) ) {};

template <typename T>
LinkedListSequence<T>::LinkedListSequence(const LinkedList<T>& list) : m_list( new LinkedList<T>(list) ) {}

template <typename T>
LinkedListSequence<T>& LinkedListSequence<T>::operator= (const LinkedListSequence<T>& another) {
    m_list = new LinkedList<T>(*another.m_list);
}

template <typename T>
LinkedListSequence<T>& LinkedListSequence<T>::operator= (LinkedListSequence<T>* another) {
    m_list = new LinkedList<T>(*another->m_list);
}



template <typename T>
LinkedListSequence<T>::~LinkedListSequence() {
    delete m_list;
}

template <typename T>
T LinkedListSequence<T>::getItem(int index) const {
    return m_list->getItem(index);
}

template <typename T>
int LinkedListSequence<T>::getSize() const {
    return m_list->getSize();
}

template <typename T>
T LinkedListSequence<T>::getFirst() const {
    return m_list->getFirst();
}

template <typename T>
T LinkedListSequence<T>::getLast() const {
    return m_list->getLast();
}

template <typename T>
Sequence<T>& LinkedListSequence<T>::insert(int index, const T& item) {
    m_list->insert(index, item);
    return *this;
}

template <typename T>
Sequence<T>& LinkedListSequence<T>::remove(int index) {
    m_list->remove(index);
    return *this;
}

template <typename T>
Sequence<T>& LinkedListSequence<T>::append(const T& item) {
    m_list->append(item);
    return *this;
}

template <typename T>
Sequence<T>& LinkedListSequence<T>::prepend(const T& item) {
    m_list->prepend(item);
    return *this;
}

template <typename T>
Sequence<T>& LinkedListSequence<T>::clear() {
    m_list->clear();
    return *this;
}

template <typename T>
LinkedListSequence<T>* LinkedListSequence<T>::map(T (*function)(const T& item)) {
    LinkedList<T>* tmp = m_list->map(function);
    LinkedListSequence<T>* result = new LinkedListSequence<T>(*tmp);
    delete tmp;
    return result;
}

template <typename T>
LinkedListSequence<T>* LinkedListSequence<T>::filter(bool (*function)(const T& item)) {
    LinkedList<T>* tmp = m_list->filter(function);
    LinkedListSequence<T>* result = new LinkedListSequence<T>(*tmp);
    delete tmp;
    return result;
}

template <typename T>
LinkedListSequence<T>* LinkedListSequence<T>::getSubSequence(int startIndex, int endIndex) const {
    LinkedList<T>* tmp = m_list->getSubList(startIndex, endIndex);
    LinkedListSequence<T>* result = new LinkedListSequence<T>(*tmp);
    delete tmp;
    return result;
}

template <typename T>
LinkedListSequence<T>* LinkedListSequence<T>::concat(Sequence<T>& sequence) const {
    LinkedListSequence<T>* result = new LinkedListSequence<T>(*this);
    for (int i = 0; i < sequence.getSize(); i++) {
        result->append(sequence.getItem(i));
    }
    return result;
}

template <typename T>
T LinkedListSequence<T>::reduce(T (*function)(const T& previousValue, const T& currentValue)) {
    return m_list->reduce(function);
}


//
//  Ops
//

template <typename T>
std::ostream& operator<< (std::ostream &out, const LinkedListSequence<T>& list) {
    out << "<";
    for (int i = 0; i < list.getSize() - 1; i++) {
        out << list.getItem(i) << ", ";
    }
    if (list.getSize() > 0)
        out << list.getItem(list.getSize() - 1);
    out << ">";
    return out;
}

template <typename T>
T& LinkedListSequence<T>::operator[] (int index) {
    return (*m_list)[index];
}


