#include <iostream>
using namespace std;

void ThreeLargest(int *array, int size) {
    // Size if Less Then Three
    if (size < 3) {
        cout << "=> Invalid Size" << endl;
        return;
    }
    int first, second, third;
    first = second = third = *array;
    for (int *i = array; i != (array + size); i++) {
        if (*i > first) {
            third = second;
            second = first;
            first = *i;
        } else if (*i > second) {
            third = second;
            second = *i;
        } else if (*i > third) {
            third = *i;
        }
    }
    cout << "Number Are=> " << first << " " << second << " " << third << endl;
}
int main() {
    int size = 7;
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        *(array + i) = i * 5;
    }
    ThreeLargest(array, size);
    delete [] array;
    return 0;
}