#include<iostream>
using namespace std;

bool isPalindrome(int x) {
  int palindromeX = 0;
  int inputX = x;
  while(x>0){
      palindromeX = palindromeX*10 + (x % 10);
      x = x/10;
  }
  return palindromeX == inputX; 
}


int main () {
    bool t = isPalindrome (4334);
}
