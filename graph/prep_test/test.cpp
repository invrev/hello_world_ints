#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;


struct EdgeNode {
    int label;
    int wt;
    EdgeNode *next;
    EdgeNode (int alabel,int awt) : 
        label(alabel),wt(awt),next(NULL)
    {
    
    };

};

struct Graph {
    bool isDirected;
    int  noOfVertex;
    int  noOfEdges;
    //Vertex indexed array
    vector<EdgeNode*> adj_list;
    Graph (bool aisDirected,int anoOfVertex,int anoOfEdges) :
        isDirected (aisDirected),noOfVertex(anoOfVertex)
        ,noOfEdges(anoOfEdges),adj_list (anoOfVertex)
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

//Find any int occurs more than once
int findIntmoreThanOne (int a[],int n) {
  
   unordered_map<int,int> u_map;
   for (int i=0;i<n;i++) {
       if ( u_map.find(a[i]) == u_map.end() ) {
           u_map[a[i]] = 1;
       } else {
            return a[i];
       }
   }
   return INT_MIN;
}

bool validate_path_to_and_from (EdgeNode *p,EdgeNode *q) {
    queue<EdgeNode* > t_queue;
    t_queue.push(p);
    while (!t_queue.empty()) {
        EdgeNode* tmp = t_queue.front();
        t_queue.pop();
        if (tmp == q) {
            return true;
        } 
        while (tmp->next != NULL) {
            t_queue.push(tmp);
            tmp = tmp->next;
        }
    }
    return false;
}



void testDuplicate() {
    int a[] = {2,1,5,6,7,1,4,4,4,4,4};
    int n = sizeof(a) /sizeof(a[0]);
    int result = findIntmoreThanOne (a,n);
    cout << "the duplicate # " << result  << endl;
}



int main () {
    //int ans = compute_squrate_root (10);
    //cout << "the ans = " << ans << endl;
    //testMat();
    testDuplicate();
}
