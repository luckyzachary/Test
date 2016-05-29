#include<iostream>
using std::cout;
using std::endl;

//最大公约数 * 最小公倍数 = 两数之积

//穷举法求N个数的最大公约数与最小公倍数
int MaxSubmultiple_MinMultiple(int Array[], int length) {
    bool flag = true;
    int i, j, div, smaller, t;
    int MaxSubmultiple = 1, MinMultiple;
    while (flag) {
        flag = false;
        for (i = 0; i < length - 1; i++) {
            for (j = i + 1; j < length; j++) {
                smaller = Array[i] < Array[j] ? Array[i] : Array[j];
                for (div = 2; div < smaller; div++) {
                    if (Array[i] % div == 0 && Array[j] % div == 0) {
                        Array[i] /= div;
                        Array[j] /= div;
                        MaxSubmultiple *= div;
                        flag = true;
                    }
                }
            }
        }
    }
    MinMultiple = MaxSubmultiple;
    for (t = 0; t < length; t++)
        MinMultiple *= Array[t];
    cout << "最大公约数为：    " << MaxSubmultiple[0] << endl;
    cout << "最小公倍数为：    " << MinMultiple[1] << endl;
    return 0;
}

//辗转相除法
int MaxMinDivision(int a, int b) {
}

//辗转相减法
int MaxMinSubtraction(int a, int b) {
}

int main() {
    int N;
    cout << "请输入数字个数：    "；
    cin >> N;
    int Arr[N];
    cout << "请输入数字：    "；
    for(int i = 0; i < N; i++) {
        cin >> Arr[i];
    }
}
