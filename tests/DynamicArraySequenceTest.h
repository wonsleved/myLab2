#ifndef MYLAB2_DYNAMICARRAYSEQUENCETEST_H
#define MYLAB2_DYNAMICARRAYSEQUENCETEST_H

void DynamicArraySequenceTestInt() {
    int* testArr = new int[5] {1, 2, 3, 4, 5};
    DynamicArraySequence<int> test1(testArr, 5);
    DynamicArraySequence<int> test2(test1);

    assert( test1.getSize() == 5 );
    assert( test2.getSize() == 5 );

    assert( test1.getItem(1) == 2 );
    assert( test1.getItem(4) == 5 );
    assert( test2.getItem(0) == 1 );
    assert( test1.getItem(3) == 4 );
    assert( test1.getFirst() == 1 );
    assert( test1.getLast()  == 5 );
    assert( test2.getFirst() == 1 );
    assert( test2.getLast()  == 5 );

    assert( test1.insert(1, 10).getItem(1) == 10);
    assert( test1.insert(2, 30).getItem(2) == 30);
    assert( test1.insert(1, 9).getItem(1) == 9);
    assert( test1.insert(3, 13).getItem(3) == 13);

    assert( test1.append(11).getLast() == 11 );
    assert( test1.pop().getLast() != 11 );
    assert( test2.prepend(11).getFirst() == 11 );
    assert( test1.shift().getFirst() != 11 );

    delete[] testArr;
}

void DynamicArraySequenceTestDouble() {
    double* testArr = new double[5] {1.1, 2.1, 3.1, 4.1, 5.1};
    DynamicArraySequence<double> test1(testArr, 5);
    DynamicArraySequence<double> test2(test1);

    assert( test1.getSize() == 5 );
    assert( test2.getSize() == 5 );

    assert( test1.getItem(1) == 2.1 );
    assert( test1.getItem(4) == 5.1 );
    assert( test2.getItem(0) == 1.1 );
    assert( test1.getItem(3) == 4.1 );
    assert( test1.getFirst() == 1.1 );
    assert( test1.getLast()  == 5.1 );
    assert( test2.getFirst() == 1.1 );
    assert( test2.getLast()  == 5.1 );

    assert( test1.insert(1, 10.1).getItem(1) == 10.1);
    assert( test1.insert(2, 30.1).getItem(2) == 30.1);
    assert( test1.insert(1, 9.1).getItem(1) == 9.1);
    assert( test1.insert(3, 13.1).getItem(3) == 13.1);

    assert( test1.append(11.1).getLast() == 11.1 );
    assert( test1.pop().getLast() != 11.1 );
    assert( test2.prepend(11.1).getFirst() == 11.1 );
    assert( test1.shift().getFirst() != 11.1 );

    delete[] testArr;
}

void DynamicArraySequenceTestComplex() {
    std::complex<int>* testArr = new std::complex<int>[5] {(1, 1), (2, 1), (3, 1), (4, 1), (5, 1)};
    DynamicArraySequence<std::complex<int>> test1(testArr, 5);
    DynamicArraySequence<std::complex<int>> test2(test1);

    assert( test1.getSize() == 5 );
    assert( test2.getSize() == 5 );

    assert( test1.getItem(1) == (2, 1) );
    assert( test1.getItem(4) == (5, 1) );
    assert( test2.getItem(0) == (1, 1) );
    assert( test1.getItem(3) == (4, 1) );
    assert( test1.getFirst() == (1, 1) );
    assert( test1.getLast()  == (5, 1) );
    assert( test2.getFirst() == (6, 1) );
    assert( test2.getLast()  == (5, 1) );

    assert( test1.insert(1, (10, 1)).getItem(1) == (10, 1));
    assert( test1.insert(2, (30, 1)).getItem(2) == (30, 1));
    assert( test1.insert(1, (9, 1)).getItem(1) == (9, 1));
    assert( test1.insert(3, (13, 1)).getItem(3) == (13, 1));

    assert( test1.append( (11, 1) ).getLast() == (11, 1) );
    assert( test1.pop().getLast() == (5, 1) );
    assert( test2.prepend( (2, 1) ).getFirst() == (11, 1) );
    assert( test1.shift().getFirst() == (1, 1) );

    delete[] testArr;
}


#endif
