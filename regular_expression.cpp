//https://oj.leetcode.com/discuss/9405/the-shortest-ac-code

#include<iostream>
using namespace std;

//1.'.' is easy to handle. if p has a '.', it can pass any single character in s except '\0'.

//2.'' is a totally different problem. if p has a '' character, it can pass any length of first-match characters in s including '\0'.
bool matchFirst(const char *s, const char *p)   {
    return (*p == *s || (*p == '.' && *s != '\0'));
}

bool isMatch(const char *s, const char *p) {
    if (*p == '\0')  { 
        return *s == '\0';  //empty
    }
    //without *
    if (*(p + 1) != '*') {
        if(!matchFirst(s,p))  {
            return false;
        }
        return isMatch(s + 1, p + 1);
    } else { 
        //next: with a * (as * is 0 or more charactes)
        
        //try the length of 0
        if(isMatch(s, p + 2))  { 
            return true;    
        }
        //try all possible lengths 
        while (matchFirst(s,p) )   {
            if (isMatch(++s, p + 2)) {
                return true;
            }
        }
    }
}


bool isMatch(const char *s, const char *p) {
  //assert(s && p);
  if (*p == '\0')  {
      //Both *p and *s should end to return true
      return *s == '\0';
  }
 
  // next char is not '*': must match current character move both s and p by 1
  if (*(p+1) != '*') {
    //assert(*p != '*');
    //Match current char 
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  // next char is '*' move p by 2
  while ((*p == *s) || (*p == '.' && *s != '\0')) {
    if (isMatch(s, p+2)) return true;
    s++;
  }
  return isMatch(s, p+2);
}

int main () {

}
