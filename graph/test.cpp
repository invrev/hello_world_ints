#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;


void addSpace (string& input,int k,string &result,int &l) {
    if (k == l-1) {
        string ans = "";
        //cout << result << endl;
        for (int i=0;i<result.length();i++) {
            if (result[i] != '*') {
                ans += result[i];
            }
        }
        cout << ans << endl;

    } else {
        k++;
        //for (int i=k;i<input.length();) {
            addSpace (input,k,result,l);
            if (result[k] == ' ') {
                result[k] = '*';
                addSpace (input,k,result,l);
            } 
            if (result[k] == '*') { //backtrack
                result[k] = ' ';
            } 
        //}
        //
    }
}



void addSpace0 (string& input,int k,string &result,int &l) {
    if (k == l) {
        string ans = "";
        //cout << result << endl;
        for (int i=0;i<result.length();i++) {
            if (result[i] != '*') {
                ans += result[i];
            }
        }
        cout << ans << endl;

    } else {
        //k++;
        for (int i=k+1;i<input.length();i++) {
            //addSpace (input,i,result,l);
            if (result[i] == ' ') {
                result[i] = '*';
                addSpace (input,i,result,l);
            } 
            if (result[i] == '*') { //backtrack
                result[i] = ' ';
            } 
        }
    }
}



struct graph {
    int label;
    vector<graph *> neighbours;
    graph (int num) : 
        label (num),neighbours(num)
    {

    };
};

//Binary search 
int compute_squrate_root (int x) {
    int left = 1;
    int right = x;
    int res = 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            right -= 1;
        } else {
            left += 1;
            res = mid;
        }
    }
    return res;
}

//Two SUm problem
bool two_sum (vector<int> a,int sum) {
    int n = a.size();
    int next_sum = 0;
    for (int i=0;i<n;i++) {
        next_sum = a[i];
        for (int j=i+1;j<n;j++) {
            if (next_sum + a[j] == sum) {
                return true;
            }
        }
    }
    return false;
}



bool validate_path_to_and_from (graph *p,graph *q) {
    queue<graph *> t_queue;
    t_queue.push(p);
    while (!t_queue.empty()) {
        graph* tmp = t_queue.front();
        t_queue.pop();
        if (tmp == q) {
            return true;
        } 
        vector<graph *> nbrs = tmp->neighbours;
        for (int i=0;i<nbrs.size();i++) {
            t_queue.push(nbrs[i]);
        }
    }
    return false;
}

int main () {

    //int ans = compute_squrate_root (10);
    //cout << "the ans = " << ans << endl;
    string input = "A B C D";
    string result = "A B C D";
    int l = input.length();
    int k = -1;
    //addSpace (input,k,result,l);
    addSpace0 (input,k,result,l);

}
