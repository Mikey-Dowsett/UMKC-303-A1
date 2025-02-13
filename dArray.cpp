#include "dArray.h"

void dArray::PushBack(int value) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;

    delete[] arr;
    arr = newArr;
    ++size;
}

int dArray::FindInteger(int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void dArray::RemoveInteger(int index) {
    int* newArr = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = index; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    --size;
}

int dArray::ReplaceInteger(int index, int value) {
    int oldValue = arr[index];
    arr[index] = value;
    return oldValue;
}

void dArray::GetAt(int index) {
    cout << arr[index] << endl;
}

void dArray::Print() {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}