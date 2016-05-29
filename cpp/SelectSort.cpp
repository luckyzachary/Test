#include<iostream>
using std::cout;
using std::swap;

int* SelectSort(int Array[], int length)
{
    int i, j, m;
    for(i = 0; i < length - 1; i++)
    {
        m = i;
        for(j = i + 1; j < length; j++)
        {
            if(Array[m] > Array[j])
            {
                m = j;
            }
        }
        swap(Array[i], Array[m]);
    }
}

int main()
{
    int i;
    int Array[]={9,2,7,3,8,4,0,5,6,1};
    for(i=0; i<10; i++)
    {
        cout<<Array[i]<<"\t";
    }
    cout<<"\n";
    SelectSort(Array, 10);
    for(i=0; i<10; i++)
    {
        cout<<Array[i]<<"\t";
    }
    cout<<"\n";
    return 0;
}

