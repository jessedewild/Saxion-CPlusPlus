#include <iostream>

using namespace std;

void printArray(int *values, int values_count) {
    for (int i = 0; i < values_count; ++i) {
        cout << values[i] << " ";
    }
    cout << endl;
}

int searchArray(int const *values, int values_count, int value) {
    // Loop through total m_values
    for (int pos = 0; pos < values_count; ++pos) {
        if (values[pos] >= value) {
            // If value is equals or larger, return position
            return pos;
        }
    }
    // Else return no position
    return -1;
}

int insertArray(int *values, int values_count, int value) {
    // Position at which element is to be inserted
    int pos = searchArray(values, values_count, value);

    // If the position is found
    if (pos != -1) {
        // Loop through m_values starting from the end
        for (int i = (values_count + 1); i > pos; i--) {
            values[i] = values[i - 1];
        }
        // Place value that needs to be inserted
        values[pos] = value;

        // Return total m_values + 1 because the list is larger
        return values_count + 1;
    }

    // Return current total m_values when number is not inserted
    return values_count;
}

int main() {
    int search_values[] = {1, 2, 3, 4, 5};
    if (searchArray(search_values, sizeof(search_values) / sizeof(int), 3) != 2) {
        cout << "searchArray returned an incorrect value!!";
        return 0;
    }

    if (searchArray(search_values, sizeof(search_values) / sizeof(int), 4) != 3) {
        cout << "searchArray returned an incorrect value!!";
        return 0;
    }

    cout << "searchArray OK!!" << std::endl;

    int values[100] = {0, 1, 2, 3, 4, 7, 8, 9, 10, 11};
    int values_count = 10;

    values_count = insertArray(values, values_count, 10);
    values_count = insertArray(values, values_count, 1);
    values_count = insertArray(values, values_count, 8);
    values_count = insertArray(values, values_count, 3);
    values_count = insertArray(values, values_count, 6);
    values_count = insertArray(values, values_count, 5);
    values_count = insertArray(values, values_count, 4);
    values_count = insertArray(values, values_count, 7);
    values_count = insertArray(values, values_count, 2);
    values_count = insertArray(values, values_count, -1);
    printArray(values, values_count);

    return 0;
}
