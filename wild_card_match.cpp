#include<iostream>


//The difference is that: the * in this problem can match any sequence independently, while the * in Regex Matching would only match duplicates, if any, of the character prior to it.
//
//The demo test case isMatch("aa", "*") for this problem and isMatch("aa", "a*") for Regex Matching problem could be the best effort to distinguish them for now. isMatch("aab", "c*a*b") → false for this problem was a bit confusing to me in the beginning. I think adding a test case such as isMatch("adcab", "*a*b") → true might be helpful.
//

//The basic idea is to have one pointer for the string and 
//one pointer for the pattern. 
//This algorithm iterates at most length(string) + length(pattern) times, for each iteration, 
//at least one pointer advance one step.

bool isMatch(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s;
    while (*s){
        //advancing both pointers when (both characters match) or ('?' found in pattern)
        //note that *p will not advance beyond its length 
        if ((*p=='?')|| (*p==*s)){ 
            s++;
            p++;
            continue;
        } 
        // * found in pattern, track index of *, only advancing pattern pointer 
        if (*p=='*'){
            star=p++; 
            ss=s;
            continue;
        } 

        //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        //only advancing pattern pointer
        if (star){ 
            p = star+1; 
            s=++ss;
            continue;
        } 

       //current pattern pointer is not star, last patter pointer was not *
       //characters do not match
        return false;
    }
    //check for remaining characters in pattern
    while (*p=='*'){
        p++;
    }

    return !*p; 
}

int main () {

}
