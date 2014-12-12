#include<iostream>


//Given triangle find the minimum value path

//  [2],
//  [3,4],
//  [6,5,7],
//  [4,1,8,3]
//]

int minimumTotal(vector<vector<int> > &triangle) {

    int ht = tri.size();
    int minV = INT_MAX;
    for (int i = ht - 2;i>=0 ;i--) {
        int width = tri[i].size();
        for (int j = 0;j<width;j++) {
            int tmp = min(tri[i][j] + tri[i-1][j],tri[i][j] + tri[i-1][j+1]);
            minV = min(tmp,minV);
        }
    }
    return minV;
}

int main () {

}
