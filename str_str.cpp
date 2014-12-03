#include<iostream>
using namespace std;

//Sunday algorithm 
int strStr(char *haystack, char *needle) {
    if(haystack == NULL || needle == NULL) return -1;
    int pLen = strlen(needle);
    int i = 0, j = 0;
    while (haystack[i] != '\0' && needle[j] != '\0') {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            int m;
            for (m = pLen - 1; m >= 0; --m) {
                if(needle[m] == haystack[i+pLen-j]) {
                    i = i - j + pLen - m;
                    j = 0;
                    break;
                }
            }
            if (m < 0) {
                i = i - j + pLen + 1;
                j = 0;
            }
        }
    }
    if (needle[j] == '\0')  { 
        return i-j;
    }
    else return -1;
}


