#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


bool is_palindrome(string s) {
    int end = s.length()-1;
    int start = 0;
    while (start <= end) {
        if (s[start++] != s[end--]) {
            //cout << "(" << start<< " , " << end << ")" << endl;
            return false;
        }
    }
    return true;
}

void enum_palindrome (string& s,int k,vector<string> &result_vec,vector<vector<string> >& op) {
    int len = s.length();
    if (len == 0) {
        op.push_back(result_vec);
        //cout << "The stack size = " << result_vec.size();
        return;
    } else {
        //k = k + 1;
        //cout << s << endl;
        for (int i=1;i<=len;i++) {
            //Principle here is (0,i) and (i,len)
            string sub_str = s.substr(0,i);
            if (is_palindrome(sub_str)) {
                result_vec.push_back(sub_str);
                string rest_str = s.substr(i);
                //cout << "("  << sub_str << "," << rest_str  << ")" << endl;
                enum_palindrome (rest_str,i,result_vec,op);
                cout <<  i-1 << "= ("  << sub_str << "," << rest_str  << ")" << endl;
                for (int i =0 ;i<result_vec.size();i++) {
                    cout << result_vec[i] << " " ;
                }
                cout << endl;
                //cout <<  "Removed top element " << result_vec[result_vec.size() - 1] << endl;
                //cout << "R " << result_vec[result_vec.size() - 1] << endl;
                result_vec.pop_back();
            }

        }
    }
}

vector<vector<string> > partition(string s) {
    vector<string> result_stack;
    vector<vector<string> > op;
    enum_palindrome (s,0,result_stack,op);
    return op;
}

int main () {
    string str_ = "aab";
    vector<vector<string> > p_vec = partition(str_);
    int out_len = p_vec.size();
    //for (int i=0;i<out_len;i++ ) {
    //    for (int j=0;j<p_vec[i].size();j++) {
    //        cout << p_vec[i][j] << endl;
    //    }
    //}

    //bool ans = is_palindrome ("TAAT") ;
    //cout << ans << endl;
}
