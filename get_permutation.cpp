#include<iostream>
using namespace std;


//Recursion will use more memory, while this problem can be solved by iteration. I solved this problem before, but I didn't realize that using k = k-1 would avoid dealing with case k%(n-1)!==0. Rewrote this code, should be pretty concise now.
//
//Only thing is that I have to use a list to store the remaining numbers, neither linkedlist nor arraylist are very efficient, anyone has a better idea?
//
//The logic is as follows: for n numbers the permutations can be divided to (n-1)! groups, thus k/(n-1)! indicates the index of current number, and k%(n-1)! denotes remaining sequence (to the right). We keep doing this until n reaches 0, then we get n numbers permutations that is kth.

string getPermutation(int n, int k) {
    vector<int> num ;
    for (int i = 1; i <= n; i++) { 
        num.push_back(i) ; 
    }
    vector<int> fact(n);  // factorial
    fact[0] = 1;
    for (int i = 1; i < n; i++) { 
        fact[i] = i*fact[i-1]; 
    }
    k = k-1;
    string result = "";
    for (int i = n; i > 0; i--) {
            int ind = k/fact[i-1];
            k = k%fact[i-1];
            result += num[ind];
            num.remove(ind);
    }
    return result;
}

//https://oj.leetcode.com/discuss/11023/most-concise-c-solution-minimal-memory-required
string getPermutation(int n, int k) {
 int i,j,f=1;
    // left part of s is partially formed permutation, right part is the leftover chars.
    string s(n,'0');
    for(i=1;i<=n;i++){
        f*=i;
        s[i-1]+=i; // make s become 1234...n
    }
    for(i=0,k--;i<n;i++){
        f/=n-i;
        j=i+k/f; // calculate index of char to put at s[i]
        char c=s[j];
        // remove c by shifting to cover up (adjust the right part).
        for(;j>i;j--)
            s[j]=s[j-1];
        k%=f;
        s[i]=c;
    }
    return s;
}


//OTHER solution


//  It's obvious that if we try to come up with n! solutions one by one until it reach kth element - O(k), 
//   it will exceed the time limit. Therefore, 
//    I tried to implement a mathematical solution as follows:
//Briefly take (n,k) = (4,21) for example, in the first iteration 
//we divide the solution set into 4 groups: "1xxx", "2xxx", "3xxx", and "4xxx", 
//   while each group has 3! = 6 members.
//From 21/6 = 3...3, we know that the 21th element is the 
//3rd element in the (3+1)th group. 
//In this group, we can divide it 
//into 3 sub-groups again: "41xx", "42xx" and "43xx", and each group has 2!=2 members.
//Then, we calculate 3/2 and get 1...1, 
//    so it's the 1st element of (1+1)nd sub-group - "421x", 
//    and now it reach the base case with only one possibility - "4213".


//Refer to paullo's idea, here is my C++ code. Unlike paullo's explain, I use ceil(k / (n-1)!) to be the group number and k % (n-1)! to be the new k.
//The important point is when new generated k == 0, we need to append the rest numbers in digitList to result in descending order.
string getPermutation(int n, int k) {
    //Initialize the 
    vector<char> digitList;
    for(int i=1; i<=n; i++)
        digitList.push_back('0'+i);
    string result = "";
    int fac, num;

    while(k) {
        //Calculate the factorial of n and let n move to the next value
        fac = factorial((n--)-1);

        //Here I use ceil to get the group value
        //Thus it can get the correct value regardless of whether k can be 
        //divisible by fac
        num = (int)ceil((float)k / fac);

        //Generate new k
        k = k % fac;

        //append current number to result and remove it from digitList
        result += digitList[num-1];
        digitList.erase(digitList.begin()+num-1);

        if(!digitList.size()) break;
        if(!k) {
            //if k==0 then append the rest numbers to result in descending order
            //I don't know why:) if you figure it out, could you comment below?
            for(int i=digitList.size()-1; i>=0; i--)
                result += digitList[i];
        }
    }
    return result;
}

int factorial(int k) {
    int result = 1;
    while(k) result *= k--;
    return result;
}


