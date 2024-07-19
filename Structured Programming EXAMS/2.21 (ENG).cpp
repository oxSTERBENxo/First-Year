/*Read a an array of N integers from standard input (first read the number N than the elements). Than call a recursive function on the array 
that will change on the following way:
a_0=a_(N−1)=max(a_0,a_(N−1))
a_1=a_(N−2)=max(a1,a_(N−2))
...
where max is a function that returns the maximum of the two numbers. The function should return the number of switched elements. Then print that 
number and the changed array.*/


#include <iostream>
using namespace std;

int switchElements(int arr[], int start, int end, int &count) {
    if (start >= end) {
        return count;
    }
    int maxValue = max(arr[start], arr[end]);
    if (arr[start] != arr[end]) {
        arr[start] = maxValue;
        arr[end] = maxValue;
        count++;
    }
    return switchElements(arr, start + 1, end - 1, count);
}

int main() {
    int n, arr[100],count=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    switchElements(arr, 0, n - 1, count);
    cout<<count<<endl;;
    for (int i = 0; i < n; i++) {
        cout <<arr[i]<<" ";
    }
    cout << endl;
    return 0;
}
