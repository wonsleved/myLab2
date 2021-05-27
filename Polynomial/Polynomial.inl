template <typename T>
T Polynomial<T>::pow(int power, T value) {
    T result = 1;
    for (int i = 0; i < power; i ++){
        result *= value;
    }
    return result;
}


template <typename T>
Polynomial<T>::Polynomial() : data( new DynamicArraySequence<T>() ) {}

template <typename T>
Polynomial<T>::Polynomial(int size) : data( new DynamicArraySequence<T>(size) ) {}

template <typename T>
Polynomial<T>::Polynomial(const Polynomial<T>& polynomial) : data( new DynamicArraySequence<T>(*polynomial.data) ) {}

template <typename T>
Polynomial<T>& Polynomial<T>::operator= (const Polynomial<T>& polynomial) {
    data = new DynamicArraySequence<T>(*polynomial.data);
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator= (Polynomial<T>* polynomial) {
    *data = *polynomial->data;
    return *this;
}

template <typename T>
Polynomial<T>::~Polynomial() {
    delete data;
}

template <typename T>
T Polynomial<T>::getItem(int index) const {
    return data->getItem(index);
}

template <typename T>
int Polynomial<T>::getSize() const {
    return data->getSize();
}

template <typename T>
Polynomial<T>& Polynomial<T>::setItem(int index, T item) {
    if (index < 0 || index > data->getSize()) return *this; // Exception
    (*data)[index] = item;
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::add(const Polynomial<T>& another) {
    if (another.getSize() <= 0) throw Exceptions(ExceptionConsts::EMPTY_POL);
    int q;
    int max_len;
    int min_len;
    if (this->getSize() > another.getSize()) {
        max_len = this->getSize();
        q = 1;
        min_len = another.getSize();
    }
    else {
        max_len = another.getSize();
        q = 0;
        min_len = this->getSize();
    }

    Polynomial<T> newPolynomial;

    for (int i = 0; i < min_len; i++){
        newPolynomial.data->append(this->data->getItem(i) + another.data->getItem(i));
    }
    for ( int i = min_len; i < max_len; i++) {
        if (q == 0) {
            newPolynomial.data->append(another.data->getItem(i));
        } else {
            newPolynomial.data->append(this->data->getItem(i));
        }
    }
    *data = *newPolynomial.data;
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::sub(const Polynomial<T>& another) {
    if (another.getSize() <= 0) throw Exceptions(ExceptionConsts::EMPTY_POL);
    int q;
    int max_len;
    int min_len;
    if (this->getSize() > another.getSize()) {
        max_len = this->getSize();
        q = 1;
        min_len = another.getSize();
    }
    else{
        max_len = another.getSize();
        q = 0;
        min_len = this->getSize();
    }
    Polynomial<T> NewPol;
    for (int i = 0; i < min_len; i++){
        NewPol.data->append((this->data->getItem(i) - another.data->getItem(i)));
    }
    for ( int i = min_len; i < max_len; i++){
        if (q == 0){
            NewPol.data->append(-1 * another.data->getItem(i));
        }
        else {
            NewPol.data->append(this->data->getItem(i));
        }
    }
    *data = *NewPol.data;
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::multiplyByScalar(T scalar){

    Polynomial<T> NewPol;
    for (int i = 0; i < this->getSize(); i++){
        NewPol.data->append(this->data->getItem(i) * scalar);
    }
    *this->data = *NewPol.data;
    return *this;
}

template <typename T>
T Polynomial<T>::value(T value) {
    if (this->getSize() <= 0) throw Exceptions(ExceptionConsts::EMPTY_POL);
    T result = this->data->getItem(0);

    for (int i = 1; i < this->getSize(); i++) {
        std::cout << std::endl;
        result += this->getItem(i) * pow(i, value);
    }

    return result;
}

template <typename T>
Polynomial<T>& Polynomial<T>::multiply(const Polynomial<T>& another) {
    if (another.getSize() <= 0) throw Exceptions(ExceptionConsts::EMPTY_POL);

    Polynomial<T> NewPol;
    T tmp = 0;

    for (int i = 0; i < this->getSize() + another.getSize() - 1; i++) {
        for (int j = 0; j < this->getSize(); j++) {
            for (int k = 0; k < another.getSize(); k++) {
                if (j + k != i) continue;
                tmp += this->data->getItem(j) * another.data->getItem(k);
            }
        }

        NewPol.data->append(tmp);
        tmp = 0;
    }


    *this->data = *NewPol.data;
    return *this;
}


//
// ops
//

template <typename T>
Polynomial<T>& Polynomial<T>::operator+ (const Polynomial<T>& pol){
    this->add(pol);
    return *this;
}


template <typename T>
Polynomial<T>& Polynomial<T>::operator+= (const Polynomial<T>& pol){
    (*this) = add(pol);
    return *this;
}


template <typename T>
Polynomial<T>& Polynomial<T>::operator- (const Polynomial<T>& pol){
    this->sub(pol);
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator-= (const Polynomial<T>& pol){
    (*this) = sub(pol);
    return *this;
}


template <typename T>
Polynomial<T>& Polynomial<T>::operator* (const Polynomial<T>& pol){
    this->multiply(pol);
    return *this;
}


template <typename T>
Polynomial<T>& Polynomial<T>::operator*= (const Polynomial<T>& pol){
    (*this) = multiply(pol);
    return *this;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, const Polynomial<T>& polynomial) {
    T tmp;
    if (polynomial.getSize() > 0) tmp = polynomial.getItem(0);
    for (int i = 0; i < polynomial.getSize() - 1; i++) {

        out << "\033[1m\033[37m" << tmp << "\033[0m" <<"x^" << i << " ";
        tmp = polynomial.getItem(i + 1);
        if (tmp >= 0) out << "+";

    }
    if (polynomial.getSize() > 0)
        out << polynomial.getItem(polynomial.getSize() - 1) << "x^" << polynomial.getSize() - 1;
    return out;
}