#include <iostream>
#include <ctime>

using namespace std;

int main() {
    char buffer[1024];
    struct tm end;
    struct tm start;

    start.tm_year = 1990;
    start.tm_mon = 1;
    start.tm_mday = 1;
    start.tm_sec = 0;
    start.tm_min = 0;
    start.tm_hour = 0;

    cin >> end.tm_year >> end.tm_mon >> end.tm_mday;
    end.tm_sec = 0;
    end.tm_min = 0;
    end.tm_hour = 0;

    time_t s = mktime(&start);
    time_t e = mktime(&end);
    
    int diff = (int)e - (int)s;
    diff /= 3600;
    diff /= 24;
    diff %= 5;

    if (diff <= 2) {
        cout << "Fishing";
    } else {
        cout << "Sleeping";
    }

    return 0;
}
