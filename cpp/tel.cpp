#include <iostream>
#include <map>
#include <iterator>

using namespace std;

map<std::string, std::string> dict;

void create_dict() {
    dict["One"] = "1";
    dict["Two"] = "2";
    dict["Three"] = "3";
    dict["Four"] = "4";
    dict["Five"] = "5";
    dict["Six"] = "6";
    dict["Seven"] = "7";
    dict["Eight"] = "8";
    dict["Nine"] = "9";
    dict["Zero"] = "0";
    dict["Oh"] = "0";
}

int main()
{
    int num;
    cin >> num;
    char buffer[102400];
    char str_num[20];

    create_dict();

    for (int i = 0; i < num; i++) {
        cin >> buffer;
        char* p = buffer;
        char* q = str_num;
        string str = "";
        bool is_double = false;
        while (*p != '\0') {
            *q++ = *p++;
            char ch = *p;
            if ((ch >= 'A' && ch <= 'Z') || ch == '\0') {
                *q = '\0';
                if (string(str_num) == "Double") {
                    if (!is_double) {
                        is_double = true;
                    } else {
                        str = "ERROR";
                        break;
                    }
                } else if (dict.find(string(str_num)) == dict.end()) {
                    str = "ERROR";
                    break;
                } else {
                    str += dict[string(str_num)];
                    if (is_double) {
                        str += dict[string(str_num)];
                        is_double = false;
                    }
                }
                q = str_num;
            }
        }
        cout << str << endl;
    }
}
