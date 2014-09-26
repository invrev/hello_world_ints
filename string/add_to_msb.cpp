#include<iostream>
#include<vector>
using namespace std;
//

vector<int> plusOne(vector<int> &digits) {
    int t_size = digits.size();
    vector<int> plus_one_vec;
    int carry = 1;
    for (int i=t_size-1;i>= 0;i--) {
        int t_sum = digits[i] + carry;
        int new_no = t_sum % 10;
        carry = t_sum / 10;
        plus_one_vec.push_back(new_no);
    }
    if (carry != 0) {
        plus_one_vec.push_back(carry);
    }
    return (plus_one_vec);
}

int main () {
    vector<int> digit_vec;
    digit_vec.push_back(9);
    vector<int> t_vec = plusOne (digit_vec);
    int len = t_vec.size();
    for (int i=0;i<len;i++)  {
        cout << t_vec[i] << " " << endl;
    }

}


