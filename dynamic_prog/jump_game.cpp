#include<iostream>
using namespace std;

//Invariant : if n can be reached from n-1 then there is path from n-1 to n.
bool canJump(int A[], int n) {
    int unit_distance = 1;
    for (int i=n-1;i>0;i--) {
        //unit_distance : distance to reach to  destination
        if (A[i-1] >= unit_distance) {
            A[i-1] = -1;
            unit_distance = 1;
        } else {
            unit_distance += 1;
        }
    }
    if (n <= 1 || A[0] == -1) {
        return true;
    }
    return false;
}

int main () {

}
