#include<iostream>
using namespace std;

int countTrees(int numKeys) {
 if (numKeys <=1) {
     return(1);
 }
 else {
    // there will be one value at the root, with whatever remains
    // on the left and right each forming their own subtrees.
    // Iterate through all the values that could be the root...
    int sum = 0;
    int left, right, root;
    for (root=1; root<=numKeys; root++) {
    left = countTrees(root - 1);
    right = countTrees(numKeys - root);
    // number of possible trees with this root == left*right
    sum += left*right;
    }
    return(sum);
 }
}
 
int numTrees(int n) {
    if (n <= 1) {
        return 1;
    }
   else {
       int sum = 0;
       int left,right,i;
       for (i=1;i<=n;i++) {
        left = numTrees(i-1);
        right = numTrees(n-i);
        sum += (left * right);
       }
       return (sum);
   }
}

int main () {
    int s = numTrees(2);
    cout << "total # of trees " << s << endl;
    s = countTrees (2);
    cout << "total # of trees " << s << endl;
}
