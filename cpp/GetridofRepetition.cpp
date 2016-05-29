#include<iostream>
using std::cout;
using std::endl;
using std::string;

string GetridofRepetition(string str)
{
    bool Arr[128];
    int i;
    for(i = 0; i < 128; i++)
        Arr[i] = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(Arr[(int)str[i]] == 0)
            cout << str[i] << " ";
        Arr[(int)str[i]] = 1;
    }
    cout << endl;
    return str;
}

int main()
{
    string A = "oisdgui sdufsnc sdufnsiewoa dfa12390133904-wnsaofn/p[xzf\\0sdfiosivcs \\0sadf'';;;";
    GetridofRepetition(A);
    return 0;
}
