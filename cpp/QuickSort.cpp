#include<iostream>
using std::cout;

template<class T>
int Partition(T Array[], int left, int right) {
    T temp =  Array[right];
    while (left != right) {
        while (Array[left] <= temp && left < right)
            left++;
        if (left < right)
            Array[right--] = Array[left];
        while (Array[right] >= temp && left < right)
            right--;
        if (left < right)
            Array[left++] = Array[right];
    }
    Array[left] = temp;
    return left;
}
template<class T>
T* QuickSort(T Array[], int left, int right) {
    if (right <= left)
        return Array;
    int pivot = Partition(Array, left, right);
    QuickSort(Array, left, pivot - 1);
    QuickSort(Array, pivot + 1, right);
    return Array;
}
int main() {
    int Arr[20] = {12, 24, 18, 27, 18,      90, 72, 64, 19, 62,     924, -10, -38, 75, 04,      0, 23, 981, -974, 902};
    QuickSort(Arr, 0, 19);
    for (int i = 0; i < 20; i++)
        cout << Arr[i] << "\n";
    return 0;
}