#include<iostream>
using namespace std;

template<class T>
int BinarySearch(T Array[], unsigned int length, T value)
{
    unsigned int a = 0, b = length - 1;
    if(a == b && Array[0] == value)
        return 0;
    while(a < b)
    {
        if(a == b - 1 && Array[a] != value && Array[b] != value)
            return -1;
        if(value > Array[(a+b)/2])
            a = (a + b) / 2;
        else if(value < Array[(a+b)/2])
            b = (a + b) / 2;
        else
            return (a + b) / 2;
    }
    return -1;
}

int main()
{
    int arr1[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20};
    int arr2[1] = {43};
    cout << BinarySearch(arr1, 19, 19) << endl;
    cout << BinarySearch(arr1, 19, 10) << endl;
    cout << BinarySearch(arr2, 1, 43) << endl;
    cout << BinarySearch(arr2, 1, 34) << endl;
    return 0;
}
