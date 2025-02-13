#pragma once
#include <iostream>
using namespace std;

class dArray {
private:
    int* arr;
    int size;
public:
    dArray() {
        arr = nullptr;
        size = 0;
    }
    ~dArray() {
        delete[] arr;
    }
    //Returns the size of the array
    int Size() { return size; }

    //Adds an element to the back of the array
    void PushBack(int value);
    //Finds the index of a number in the array
    int FindInteger(int value);
    //Removes an integer from the array
    void RemoveInteger(int index);
    //Replaces an integer at the given index
    int ReplaceInteger(int index, int value);
    //Returns the integer at the given index
    void GetAt(int index);
    //Prints out the array
    void Print();
};
