#include<iostream>
#include<vector>
#include<queue>
using namespace std;


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

    int ans = compute_squrate_root (10);
    cout << "the ans = " << ans << endl;

}
