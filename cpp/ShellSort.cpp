#include<iostream>
using std::cout;
using std::swap;

int* ShellSort(int Array[], int length)
{
    int d, c;
    int i, j, m;
    for(d = length/2; d >= 1; d /= 2)
    {
        for(c = 0; c < d; c++)
        {
            for(i = d; i < length; i += d)
            {   
                m = Array[i];
                for(j = i; j > 0 && m < Array[j - d]; j -= d)
                {
                    Array[j] = Array[j - d];
                }
                Array[j] = m;
            }
        }
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
    ShellSort(Array, 10);
    for(i=0; i<10; i++)
    {
        cout<<Array[i]<<"\t";
    }
    cout<<"\n";
    return 0;
}
