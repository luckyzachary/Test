#include<iostream>
using std::cout;
using std::swap;

int* BubbleSort(int Array[], int length)
{
    int i, j, m;
    bool NoSwap;	//设置断点
    for(i = 0; i < length - 1; i++)
    {
        NoSwap = true;
        for(j = length - 1; j > i; j--)
        {
            if(Array[j] < Array[j - 1])
            {
                swap(Array[j], Array[j-1]);
                NoSwap=false;
            }
        }
        if(NoSwap)
            break;
    }
    return Array;
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
    BubbleSort(Array, 10);
    for(i=0; i<10; i++)
    {
        cout<<Array[i]<<"\t";
    }
    cout<<"\n";
    return 0;
}
