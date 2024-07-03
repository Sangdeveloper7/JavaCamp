#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(string s) {
    int p_count = 0;
    int y_count = 0;

    for (char &c : s) {
        c = toupper(c);
    }
    
    for (char c : s) {
        if (c == 'P') {
            p_count++;
        } else if (c == 'Y') {
            y_count++;
        }
    }

    return p_count == y_count;
}
