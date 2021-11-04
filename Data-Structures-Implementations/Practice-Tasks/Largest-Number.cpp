#include <iostream>
using namespace std;

int GetLargestNumber(int *array, int size) {
    int *max = array;
    for (int *i = array; i != (array + size); i++) {
        if (*i > *max)
            max = i;
    }
    return *max;
}
int main() {
    int size = 5;
    int *p = new int[size];
    for (int i = 0; i < size; i++) {
        *(p + i) = i * 5;
    }
    cout << "Max Value In Given Array=> " << GetLargestNumber(p, size) << endl;
    delete [] p;
    return 0;
}