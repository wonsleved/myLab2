//#include "base/DynamicArray.h"
#include "base/LinkedList.h"
//#include "Sequence/LinkedListSequence.h"
//#include <array>
#include "Interface/interface.h"

int main() {
    try {
    interface();
    } catch (Exceptions& exception) {
        exception.getError();
    }


    return 0;
}







//int func(const int& item) {
//    return item + 1;
//}
//
//bool filt(const int& item) {
//    return item % 2;
//}
//
//int red(const int& first, const int& second) {
//    return first + second;
//}