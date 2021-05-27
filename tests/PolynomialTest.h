#ifndef MYLAB2_POLYNOMIALTEST_H
#define MYLAB2_POLYNOMIALTEST_H

void PolynomialTestInt() {
    Polynomial<int> test1(5);
    test1.setItem(0, 1)
            .setItem(1, 2)
            .setItem(2, 3)
            .setItem(3, 4)
            .setItem(4, 5);

    Polynomial<int> test2(test1);

    assert( test1.getSize() == 5 );
    assert( test2.getSize() == 5 );

    assert( test1.getItem(1) == 2 );
    assert( test1.getItem(4) == 5 );
    assert( test2.getItem(0) == 1 );
    assert( test1.getItem(3) == 4 );



    assert( test1.add(test2).getItem(0) == 2 );
    assert( test1.add(test2).getItem(1) == 6 );
    assert( test2.add(test1).getItem(0) == 4 );
    assert( test2.add(test1).getItem(0) == 7 );

    assert( test1.sub(test2).getItem(0) == -4 );
    assert( test1.sub(test2).getItem(1) == -22 );
    assert( test2.sub(test1).getItem(2) == 54 );
    assert( test2.sub(test1).getItem(3) == 116 );

    assert( test1.multiplyByScalar(17).getItem(0) == -187);
    assert( test2.multiplyByScalar(14).getItem(1) == 812 );

}

void PolynomialTestDouble() {
    Polynomial<double> test1(5);
    test1.setItem(0, 1.0)
            .setItem(1, 2.0)
            .setItem(2, 3.0)
            .setItem(3, 4.0)
            .setItem(4, 5.0);

    Polynomial<double> test2(test1);

    assert( test1.getSize() == 5 );
    assert( test2.getSize() == 5 );

    assert( test1.getItem(1) == 2.0 );
    assert( test1.getItem(4) == 5.0 );
    assert( test2.getItem(0) == 1.0 );
    assert( test1.getItem(3) == 4.0 );



    assert( test1.add(test2).getItem(0) == 2.0 );
    assert( test1.add(test2).getItem(1) == 6.0 );
    assert( test2.add(test1).getItem(0) == 4.0 );
    assert( test2.add(test1).getItem(0) == 7.0 );

    assert( test1.sub(test2).getItem(0) == -4.0 );
    assert( test1.sub(test2).getItem(1) == -22.0 );
    assert( test2.sub(test1).getItem(2) == 54.0 );
    assert( test2.sub(test1).getItem(3) == 116.0 );

    assert( test1.multiplyByScalar(17).getItem(0) == -187.0);
    assert( test2.multiplyByScalar(14).getItem(1) == 812.0 );

}

//void PolynomialTestComplex() {
//    LinkedList<std::complex<int>> test1(testArr, 5);
//    LinkedList<std::complex<int>> test2(test1);
//
//    Polynomial<std::complex<int>> test1(5);
//    test1.setItem(0, 1.0)
//            .setItem(1, 2.0)
//            .setItem(2, 3.0)
//            .setItem(3, 4.0)
//            .setItem(4, 5.0);
//
//    Polynomial<double> test2(test1);
//
//    assert( test1.getSize() == 5 );
//    assert( test2.getSize() == 5 );
//
//    assert( test1.getItem(1) == (2, 1) );
//    assert( test1.getItem(4) == (5, 1) );
//    assert( test2.getItem(0) == (1, 1) );
//    assert( test1.getItem(3) == (4, 1) );
//    assert( test1.getFirst() == (1, 1) );
//    assert( test1.getLast()  == (5, 1) );
//    assert( test2.getFirst() == (6, 1) );
//    assert( test2.getLast()  == (5, 1) );
//
//    assert( test1.insert(1, (10, 1)).getItem(1) == (10, 1));
//    assert( test1.insert(2, (30, 1)).getItem(2) == (30, 1));
//    assert( test1.insert(1, (9, 1)).getItem(1) == (9, 1));
//    assert( test1.insert(3, (13, 1)).getItem(3) == (13, 1));
//
//    assert( test1.append( (11, 1) ).getLast() == (11, 1) );
//    assert( test2.prepend( (2, 1) ).getFirst() == (11, 1) );
//    assert( test1.remove(0).getFirst() == (1, 1) );
//}




#endif
