#include<iostream>
using namespace std;


int get_fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n > 0) {
        int ans = n * get_fact (n-1);
        return ans;
    }

}

int main () {
    int fact_ans = get_fact (6);
    cout << "the factrial = " << fact_ans << endl;
}
