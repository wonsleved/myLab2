
int getInt() {
    int a;
    std::cin >> a;
    return a;
}

int getInt(int up) {
    int a;
    std::cin >> a;
    if (a > up) {
        std::cout << "There is no this option. Try again.\n";
        return getInt(up);
    }
    return a;
}

int getInt(int down, int up) {
    int a;
    std::cin >> a;
    if (a > up || a < down) {
        std::cout << "There is no this option. Try again.\n";
        return getInt(down, up);
    }
    return a;
}

double getDouble() {
    double a;
    std::cin >> a;
    return a;
}

std::complex<int> getComplex() {
    int real = getInt();
    int imag = getInt();
    std::complex<int> a(real, imag);
    return a;
}

std::ostream& operator << (std::ostream& out, std::complex<int> num) {
    if (num.imag() == 0) return out << num.real();

    if (num.real() != 0) {
        out << num.real();
    }

    if (num.imag() > 0) {
        if (num.real() != 0)
            out << '+';
        if (num.imag() != 1)
            out << num.imag();
        return out << 'i';
    }
    else {
        if (num.imag() == -1)
            return out << "-i";
        return out << num.imag() << 'i';
    }
}

void printPolynomial(
        int item,
        DynamicArraySequence<Polynomial<int>> &polInt,
        DynamicArraySequence<Polynomial<double>> &polDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>> &polComp
)
{
    switch (item) {
        case 1:
            std::cout << std::endl;
            std::cout << "\t\t---\033[1m\033[31m INT \033[0m---" << std::endl;
            printSimple<int>(&polInt);
            break;
        case 2:
            std::cout << std::endl;
            std::cout << "\t\t---\033[1m\033[31m DOUBLE \033[0m---" << std::endl;
            printSimple<double>(&polDouble);
            break;
        case 3:
            std::cout << std::endl;
            std::cout << "\t\t---\033[1m\033[31m COMPLEX \033[0m---" << std::endl;
            printTypePol<std::complex<int>>(&polComp);
            break;
        default: //
            return; //
    }
}

template<class T>
void printTypePol(DynamicArraySequence<Polynomial<T>>* polynomial) {
    for (int i = 0; i < polynomial->getSize(); i++) {
        std::cout << "\t\t"
                  << "\033[1m\033[31m" <<"[" << "\033[0m" << i
                  << "\033[1m\033[31m" << "]" << "\033[0m"
                  << " : ";
        for (int j = 0; j < polynomial->getItem(i).getSize() - 1; j++){
            std::cout << polynomial->getItem(i).getItem(j) << ", ";
        }
        if (polynomial->getItem(i).getSize() - 1 > 0)
            std::cout << polynomial->getItem(i).getItem(polynomial->getItem(i).getSize() - 1) << std::endl;;
    }
    std::cout << std::endl;
}

template<class T>
void printSimple(DynamicArraySequence<Polynomial<T>>* polynomial) {
    for (int i = 0; i < polynomial->getSize(); i++) {
        std::cout << "\t\t"
        << "\033[1m\033[31m" <<"[" << "\033[0m" << i
        << "\033[1m\033[31m" << "]" << "\033[0m"
        << " : " << (*polynomial)[i] << std::endl;

    }
    std::cout << std::endl;
}

template<class T>
void arrayTypePrint(Polynomial<T> &polynomial) {

    std::cout << std::endl;


    std::cout << "\tResult coefficients: ";
    for (int i = 0; i < polynomial.getSize() - 1; i++){
        std::cout << polynomial.getItem(i) << ", ";
    }
    if (polynomial.getSize() - 1 > 0)
        std::cout << polynomial.getItem(polynomial.getSize() - 1) << std::endl;;

    std::cout << std::endl;

}

template<class T>
Polynomial<T> polynomialTypeRead(int count) {
    std::cout << "\tEnter the elements:\n";
    Polynomial<T> element(count);
    for (int i = 0; i < count; i++) {
        std::cout << "\t\tx^" << i << " | ";
        T item;
        std::cin >> item;
        element.setItem(i, item);
    }
    return element;
}

void polynomialDelete(
        int item,
        DynamicArraySequence<Polynomial<int>>* polynomialInt,
        DynamicArraySequence<Polynomial<double>>* polynomialDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>>* polynomialComp
)
{
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypePolynomial<int>(polynomialInt);
            break;
        case 2:
            deleteTypePolynomial<double>(polynomialDouble);
            break;
        case 3:
            deleteTypePolynomial<std::complex<int>>(polynomialComp);
            break;
        default:
            break;
    }
}


template<class T>
void deleteTypePolynomial(DynamicArraySequence<Polynomial<T>>* polynomial) {
    if (polynomial->getSize() == 0){
        std::cout << "\t\033[1m\033[31mPolynomials don't exist!\033[0m\n";
        return;
    }

    while (true){
        int size = polynomial->getSize();
        if (size == 0){
            std::cout<< "\t\033[1m\033[31mPolynomials don't exist!\033[0m\n";
            break;
        }

        std::cout << "\tThere are " << size << " polynomials\n"
                  << "\t\t => Negative number for exit\n"
                  << "\t\t => index of polynomial\n"
                  << "\t\t => number bigger than size for print all polynomial\n"
                  << "\t\t: ";
        int item1 = getInt();
        if (item1 < 0) break;

        if (item1 >= size){
            printTypePol(polynomial);
            continue;
        }
        std::cout << "\tDo you really want to "
                  << "\033[1m\033[31m" << "delete" << "\033[0m"
                  << " polynomial with index " << item1 <<"?\n"
                  << "\t\t0| no\n"
                  << "\t\t1| yes\n"
                  << "\t\t: ";
        int item3 = getInt(0, 1);
        if (item3 == 1) {
            polynomial->remove(item1);
        }
    }
}

void testFunction() {
    std::cout << "[0%] Start testing..." << std::endl;
    PolynomialTestInt();
    std::cout << "[7%] PolynomialTestInt completed" << std::endl;
    PolynomialTestDouble();
    std::cout << "[14%] PolynomialTestDouble completed" << std::endl;
    LinkedListSequenceTestInt();
    std::cout << "[21%] LinkedListSequenceTestInt completed" << std::endl;
    LinkedListSequenceTestDouble();
    std::cout << "[28%] LinkedListSequenceTestDouble completed" << std::endl;
    LinkedListSequenceTestComplex();
    std::cout << "[35%] LinkedListSequenceTestComplex completed" << std::endl;
    DynamicArraySequenceTestInt();
    std::cout << "[42%] DynamicArraySequenceTestInt completed" << std::endl;
    DynamicArraySequenceTestDouble();
    std::cout << "[49%] DynamicArraySequenceTestDouble completed" << std::endl;
    DynamicArraySequenceTestComplex();
    std::cout << "[56%] DynamicArraySequenceTestComplex completed" << std::endl;
    LinkedListTestInt();
    std::cout << "[64%] LinkedListTestInt completed" << std::endl;
    LinkedListTestDouble();
    std::cout << "[71%] LinkedListTestDouble completed" << std::endl;
    LinkedListTestComplex();
    std::cout << "[78%] LinkedListTestComplex completed" << std::endl;
    DynamicArrayTestInt();
    std::cout << "[87%] DynamicArrayTestInt completed" << std::endl;
    DynamicArrayTestDouble();
    std::cout << "[94%] DynamicArrayTestDouble completed" << std::endl;
    DynamicArrayTestComplex();
    std::cout << "[100%] DynamicArrayTestComplex completed" << std::endl;

    std::cout << std::endl;

    std::cout << "The test is done. Everything works correct." << std::endl;



}

void interface() {
    DynamicArraySequence<Polynomial<int>> polynomialInt;
    DynamicArraySequence<Polynomial<double>> polynomialDouble;
    DynamicArraySequence<Polynomial<std::complex<int>>> polynomialComplex;
    int item;
    while (true) {
        std::cout << "\tChoose option:\n"
                  << "\t\t1| Enter polynomial\n"
                  << "\t\t2| Choose operation\n"
                  << "\t\t3| Print all polynomials\n"
                  << "\t\t4| Tests\n"
                  << "\t\t5| Delete\n"
                  << "\t\t0| exit\n"
                  << "\t\t: ";
        item = getInt(0, 5);
        if (item == 0) break;

        int item2;
        switch (item) {
            case 1:
                item2 = getType();
                polynomialRead(item2, &polynomialInt, &polynomialDouble, &polynomialComplex);
                break;

            case 2:
                item2 = getType();
                polynomialOperations(item2, &polynomialInt, &polynomialDouble, &polynomialComplex);
                break;

            case 3:
                item2 = getType();
                printPolynomial(item2, polynomialInt, polynomialDouble, polynomialComplex);
                break;
            case 4:
                testFunction();
                break;
            case 5:
                item2 = getType();
                polynomialDelete(item2, &polynomialInt, &polynomialDouble, &polynomialComplex);
                break;
            default:
                break;
        }
    }

}

int getType() {
    std::cout << "\tChoose data type: \n"
              << "\t\t1| Int\n"
              << "\t\t2| Double\n"
              << "\t\t3| Complex\n"
              << "\t\t0| exit\n"
              << "\t\t: ";
    return getInt(0, 3);
}


void polynomialRead(
        int item,
        DynamicArraySequence<Polynomial<int>>* polynomialInt,
        DynamicArraySequence<Polynomial<double>>* polynomialDouble,
        DynamicArraySequence<Polynomial<std::complex<int>>>* polynomialComp
)
{
    if (item == 0) return;

    std::cout
    << "\tEnter count of elements or negative number to exit\n"
    << "\t\t: ";
    int count;
    std::cin >> count;

    if (count < -1)
        return;


    Polynomial<int> polynomialInt1;
    Polynomial<double> polynomialDouble1;
    Polynomial<std::complex<int>> polynomialComp1;
    switch (item) {
        case 1:
            polynomialInt1 = polynomialTypeRead<int>(count);
            polynomialInt->append(polynomialInt1);
            break;
        case 2:
            polynomialDouble1 = polynomialTypeRead<double>(count);
            polynomialDouble->append(polynomialDouble1);
            break;
        case 3:
            polynomialComp1 = polynomialTypeRead<std::complex<int>>(count);
            polynomialComp->append(polynomialComp1);
            break;
        default:
            break;
    }
}


void polynomialOperations
        (
                int item,
                DynamicArraySequence<Polynomial<int>> *polynomialInt,
                DynamicArraySequence<Polynomial<double>> *polynomialDouble,
                DynamicArraySequence<Polynomial<std::complex<int>>> *polynomialComp
        )
{
    if (item == 0) return;

    switch (item) {
        case 1:
            polynomialTypeOperations<int>(polynomialInt);
            break;
        case 2:
            polynomialTypeOperations<double>(polynomialDouble);
            break;
        case 3:
            polynomialTypeOperations<std::complex<int>>(polynomialComp);
            break;
        default: break;
    }
}

template<class T>
void polynomialTypeOperations(DynamicArraySequence<Polynomial<T>> *polynomials) {
    if (polynomials->getSize() == 0){
        std::cout << "\t\033[1m\033[31mPolynomials don't exist!\033[0m\n";
        return;
    }

    while (true){
        auto length = polynomials->getSize();
        std::cout << "\tThere are " << length << " polynomials.\n"
                  << "\t\t| Negative number for exit\n"
                  << "\t\t| Index of polynomial\n"
                  << "\t\t| Number bigger than length to see all the polynomials\n"
                  << "\t\t: ";
        int item1 = getInt();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypePol(polynomials);
            continue;
        }
        Polynomial<T> polynomial;
        polynomial = polynomials->getItem(item1);

        std::cout << "\tChoose operation:\n"
                  << "\t\t0| exit\n"
                  << "\t\t1| Sum polynomial\n"
                  << "\t\t2| Sub polynomial\n"
                  << "\t\t3| Multiply by scalar polynomial\n"
                  << "\t\t4| Multiply polynomial\n"
                  << "\t\t5| Value of polynomial\n"
                  << "\t\t: ";
        int item = getInt(0, 5);

        if (item == 0) break;

        Polynomial<T> pol1;
        Polynomial<T> result;
        T value;

        if (item == 3 || item == 5){
            T element;
            std::cout << "\t\tEnter scalar: ";
            std::cin >> element;

            if (item == 3) {
                result = polynomial.multiplyByScalar(element);
            }

            if (item == 5) {
                std::cout << "\t\tThe value is " << polynomial.value(element) << "\n";
                return;
            }
        }
        else{
            std::cout
            << "\tEnter count of elements or negative number to exit: \n"
            << "\t\t: ";
            int count;
            std::cin >> count;
            if (count < -1)
                return;

            pol1 = polynomialTypeRead<T>(count);

            switch (item) {
                default: break;
                case 1: result = pol1 + polynomial; break;
                case 2: result = polynomial - pol1; break;
                case 4: result = pol1 * polynomial; break;
            }

        }
        arrayTypePrint(result);

        std::cout << "\tSave polynomial?\n"
                  << "\t\t0| No\n"
                  << "\t\t1| Yes\n"
                  << "\t\t: ";
        int item2 = getInt(0, 1);

        if (item2 == 1){
            polynomials->append(result);
        }
    }
}
