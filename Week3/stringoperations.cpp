#include <iostream>
using namespace std;

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringConcat(char dest[], char src[]) {
    int destLength = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLength + i] = src[i];
        i++;
    }
    dest[destLength + i] = '\0';
}

bool stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return true;
    } else {
        return false;
    }
}

void stringInsert(char str[], char sub[], int pos) {
    int strLen = stringLength(str);
    int subLen = stringLength(sub);
    for (int i = strLen; i >= pos; i--) {
        str[i + subLen] = str[i];
    }
    for (int i = 0; i < subLen; i++) {
        str[pos + i] = sub[i];
    }
}

void stringDelete(char str[], char sub[]) {
    int strLen = stringLength(str);
    int subLen = stringLength(sub);
    int i, j;

    for (i = 0; i <= strLen - subLen; i++) {
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }

        if (j == subLen) {
            for (int k = i; k <= strLen - subLen; k++) {
                str[k] = str[k + subLen];
            }
            str[strLen - subLen] = '\0';
            break;
        }
    }
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char sub[100] = "Friend";

    cout << "Length of str1: " << stringLength(str1) << endl;
    stringConcat(str1, str2);
    cout << "After concatenation: " << str1 << endl;
    cout << "Comparison of str1 and str2: " << (stringCompare(str1, str2) ? "Equal" : "Not Equal") << endl;
    stringInsert(str1, sub, 5);
    cout << "After inserting substring: " << str1 << endl;
    stringDelete(str1, sub);
    cout << "After deleting substring: " << str1 << endl;

    return 0;
}

