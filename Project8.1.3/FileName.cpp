#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s) {
    int k = 0;
    char* t;
    while (t = strpbrk(s, "abc")) {
        k++;
        s = t + 3;
    }
    return k;
}


char* Change(char* s) {
    char* t = new char[strlen(s) * 2]; // розмір більший, ніж strlen(s), щоб помістити додаткові '**'
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = 0;
    while (p = strpbrk(s + pos1, "abc")) { // p = вказівник на 'a', 'b', або 'c'
        pos2 = p - s; // pos2 = позиція 'a', 'b', або 'c'
        strncat(t, s + pos1, pos2 - pos1);
        strcat(t, "**");
        pos1 = pos2 + 3; // pos1 = позиція після 'c'
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of 'abc'" << endl;
    char* dest = new char[strlen(str) * 2]; // розмір більший, ніж strlen(str), щоб помістити додаткові '**'
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
