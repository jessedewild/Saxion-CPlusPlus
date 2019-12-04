#include <iostream>

using namespace std;

void printArray(int *values, int values_count) {
    for (int i = 0; i < values_count; ++i) {
        cout << values[i] << " ";
    }
    cout << endl;
}

int main() {
    int values[100] = {0, 1, 2, 3, 4, 7, 8, 9, 10, 11};
    int values_count = 10;
    printArray(values, values_count);

    int *ptr = &values[3];
    uint64_t ptr_address = (uint64_t) (ptr);
    ptr_address += 12;

    int *ptr_2 = (int *) (ptr_address);
    *ptr_2 = 42;

    printArray(values, values_count);
    return 0;
}