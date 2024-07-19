/*An array of integers is to be read from SI. First the number N (N<=100) is entered followed by N integers. Write a program that will transform the array in the following way:
starting at the beginning of the array, for each element that is equal to the next element in the array, double the value of the first one and overwrite the second one with 0.
After that, rearrange the array so that all the zeroes will be moved at the end of the array, keeping the order of the other elements. Print all the elements of the array on the SO in a single line,
separated by space. Write separate functions for transforming the array and for reordering the elements.
Example: 
6
2 2 0 4 8 8
(Intermediate: 4, 0, 0, 4, 16, 0)
Output: 
4 4 16 0 0 0*/


#include <iostream>
using namespace std;
void transformArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            arr[i] *= 2;
            arr[i + 1] = 0;
        }
    }
}
void reorderArray(int arr[], int n) {
    int id = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[id++] = arr[i];
        }
    }
    while (id < n) {
        arr[id++] = 0;
    }
}

int main() {
    int n, arr[100];

    // Read input N and array elements
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    transformArray(arr, n);
    reorderArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
