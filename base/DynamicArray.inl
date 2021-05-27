template <typename T>
DynamicArray<T>::DynamicArray()
{
    m_size = 0;
    m_data = new T[0];
}

template <typename T>
DynamicArray<T>::DynamicArray(int size)
{
    if (size < 0) throw (Exceptions(ExceptionConsts::INVALID_SIZE));
    m_size = size;
    m_data = new T[size] {0};
}

template <typename T>
DynamicArray<T>::DynamicArray(T* items, int count) : DynamicArray(count) {
    if (count < 0) throw (Exceptions(ExceptionConsts::INVALID_COUNT));
    for (int i = 0; i < count; i++) {
        m_data[i] = items[i];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& another)
    : m_size(another.getSize())
{
    m_data = new T[m_size];

    for (int i = 0; i < m_size; i++) {
        m_data[i] = another.getItem(i);
    }
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& another) {
    resize(another.getSize());
    for (int i = 0; i < another.getSize(); i++) {
        setItem(i, another.getItem(i));
    }
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= (DynamicArray<T>* another) {
    resize(another->getSize());
    for (int i = 0; i < another->getSize(); i++) {
        setItem(i, another->getItem(i));
    }
    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    if (m_data)
        delete[] m_data;
}

template <typename T>
T DynamicArray<T>::getItem(int index) const {
    if (index < 0 || index >= m_size)
        throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));
    return m_data[index];
}

template <typename T>
int DynamicArray<T>::getSize() const{
    return m_size;
}

template <typename T>
T DynamicArray<T>::getFirst() const{
    return m_data[0];
}

template <typename T>
T DynamicArray<T>::getLast() const{
    return m_data[m_size - 1];
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::clear() {
    if (m_data)
        delete[] m_data;
    m_size = 0;
    return *this;
}


template <typename T>
DynamicArray<T>& DynamicArray<T>::setItem(int index, T item) {
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));
    m_data[index] = item;

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::resize(int size) {
    if (size < 0) throw(Exceptions(ExceptionConsts::INVALID_SIZE));

    if (getSize() == size) return *this;

    T* tmp= new T[size];
    if (size < m_size)
        for (int i = 0; i < size; i++)
            tmp[i] = m_data[i];
    else if (size > m_size) {
        for (int i = 0; i < getSize(); i++)
            tmp[i] = m_data[i];
        for (int i = getSize(); i < size; i++)
            tmp[i] = T(0);
    }
    delete[] m_data;

    m_size = size;
    m_data = tmp;

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::push(T item) {
    T* tmp = new T[m_size + 1];

    for (int i = 0; i < m_size; i++)
        tmp[i] = m_data[i];

    tmp[m_size++] = item;
    delete[] m_data;
    m_data = tmp;

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::pop() {
    if (m_size == 0) throw(Exceptions(ExceptionConsts::INVALID_POP));
    resize(--m_size);

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::unshift(T item) {
    T* tmp = new T[++m_size];
    tmp[0] = item;

    for (int i = 1; i < m_size; i++)
        tmp[i] = m_data[i-1];

    delete[] m_data;
    m_data = tmp;

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::shift() {

    if (m_size == 0) throw(Exceptions(ExceptionConsts::INVALID_SHIFT));

    T* tmp = new T[--m_size];

    for (int i = m_size; i > 0; i--)
        tmp[i - 1] = m_data[i];

    delete[] m_data;
    m_data = tmp;

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::remove(int index) {
    if (m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));

    T* tmp = new T[m_size - 1];

    for (int i = 0; i < index; i++)
        tmp[i] = m_data[i];
    for (int i = index + 1; i < m_size; i++)
        tmp[i - 1] = m_data[i];

    delete[] m_data;
    m_size--;
    m_data = tmp;

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::insert(int index, const T& item) {
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));

    T* tmp = new T[m_size + 1];

    for (int i = 0; i < index; i++)
        tmp[i] = m_data[i];
    tmp[index] = item;
    for (int i = index + 1; i < m_size + 1; i++)
        tmp[i] = m_data[i - 1];

    delete[] m_data;
    m_size++;
    m_data = tmp;
    return *this;
}

template <typename T>
DynamicArray<T>* DynamicArray<T>::map(T (*function)(const T& item)) const{
    DynamicArray* tmp = new DynamicArray<T>(m_size);

    for (int i = 0; i < m_size; i++)
        tmp->m_data[i] = function(m_data[i]);

    return tmp;
};

template <typename T>
T DynamicArray<T>::reduce(T (*function)(const T& previousValue, const T& currentValue)) const{
    if (m_size < 2) throw (Exceptions(ExceptionConsts::EMPTY_ARRAY));
    T result = m_data[0];
    for (int i = 1; i < m_size; i++)
        result = function(result, m_data[i]);
    return result;
}

template <typename T>
DynamicArray<T>* DynamicArray<T>::filter(bool (*function)(const T& item)) const {
    DynamicArray<T>* result = new DynamicArray<T>();
    T tmp;
    for (int i = 0; i < m_size; i++) {
        tmp = getItem(i);
        if (function(tmp))
            result->push(tmp);
    }
    return result;
}


template <typename T>
DynamicArray<T>* DynamicArray<T>::concat(const DynamicArray<T>& array) const {
    DynamicArray<T>* result = new DynamicArray(*this);
    for (int i = 0; i < array.getSize(); i++)
        result->push(array.getItem(i));

    return result;
}

template <typename T>
DynamicArray<T>* DynamicArray<T>::getSubList(int startIndex, int endIndex) const {
    if(m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_ARRAY));
    if( (startIndex < 0 || startIndex >= m_size) && (endIndex < startIndex || endIndex >= m_size) )
        throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));;
    DynamicArray<T>* result = new DynamicArray<T>();
    for (int i = startIndex; i <= endIndex; i++)
        (*result).push(getItem(i));

    return result;
}


// Operators

template <typename T>
std::ostream& operator<< (std::ostream& out, const DynamicArray<T>& arr) {
    out << "[";
    for (int i = 0; i < arr.getSize() - 1; i++) {
        out << arr.getItem(i) << ", ";
    }
    if (arr.getSize() > 0)
        out << arr.getItem(arr.getSize() - 1);
    out << "]";
    return out;
}

template <typename T>
T& DynamicArray<T>::operator[] (const int index)
{
    if (m_size == 0) throw (Exceptions(ExceptionConsts::EMPTY_ARRAY));
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));
    return m_data[index];
}

