#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

int main()
{
    char buffer[102400];
    char num_str[20];
    cin >> buffer;

    int num;
    int max = INT_MIN;
    int min = INT_MAX;
    char* p = buffer;
    char* q = num_str;
    while (*p != '\0') {
        if (*p == ',') {
            *q = '\0';
            num = atoi(num_str);    //atoi函数将字符串转换成一个整数并返回，遇到非数字字符结束转换
            if (max < num) {
                max = num;
            }
            if (min > num) {
                min = num;
            }
            p++;
            q = num_str;
        } else {
            *q++ = *p++;
        }
    }

    *q = '\0';
    num = atoi(num_str);
    if (max < num) {
        max = num;
    }
    if (min > num) {
        min = num;
    }

    cout << (min + max);
}

