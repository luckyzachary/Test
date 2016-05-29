#include<iostream>
using std::cout;
using std::swap;

int* InsertSort(int Array[], int length)
{
    int i, j, m;
    for(i = 1; i < length; i++)
	{
        m = Array[i];
		for(j = i; j > 0 && m < Array[j - 1]; j--)
		{
            Array[j] = Array[j-1];
       	}
        Array[j] = m;
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
    InsertSort(Array, 10);
    for(i=0; i<10; i++)
    {
        cout<<Array[i]<<"\t";
    }
    cout<<"\n";
    return 0;
}
