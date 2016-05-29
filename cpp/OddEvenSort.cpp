#include<iostream>
using std::cout;
using std::endl;
using std::swap;

template<class T>
T* OddEvenSort(T Array[], int length)
{
    bool flag = 0;
    int i;
    while(!flag)
    {
        flag = 1;
        for(i = 0; i < length - 1; i += 2)
        {
            if(Array[i] > Array[i + 1])
            {
                swap(Array[i], Array[i + 1]);
                flag = 0;
            }
        }
        for(i = 1; i < length - 1; i += 2)
        {
            if(Array[i] > Array[i + 1])
            {
                swap(Array[i], Array[i + 1]);
                flag = 0;
            }
        }
    }
    return Array;
}

int main()
{
    int Arr[] = {12, 12, 24, 978, -9, -2, 0, -0, 6, 10, 234, 12, 999, 12, 34, 67, 100, 12, 76, 56};
    OddEvenSort(Arr, 20);
    for(int i = 0; i < 20; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
