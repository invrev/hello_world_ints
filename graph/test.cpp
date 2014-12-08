#include<iostream>
using namespace std;

//Binary search 
int compute_squrate_root (int x) {
    int left = 1;
    int right = x;
    int mid = (left + right) / 2;
    while (left <= right) {
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            right -= 1;
        } else {
            left += 1;
        }
    }
    return mid;
}

bool two_sum (vector<int> a,int sum) {
    int n = a.size();
    for (int i=0;i<n;i++) {
        int next_num = a[i];
        for (int j=i+1;j<n;j++) {
            if (next_sum + a[j] == sum) {
                return true;
            }
        }
    }
}

bool validate_path_to_and_from (graph *p,graph *q) {

    queue<graph *> t_queue;
    t_queue.push(p);
    while (!t_queue.empty()) {
        graph *tmp = t_queue.pop();
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

    int ans = compute_squrate_root (9);
    cout << "the ans = " << ans << endl;

}
