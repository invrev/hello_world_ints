#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

//Please refer the example trapping_rain_water in the tricks directory


//Draw 2-d grid ,dest = (m,n) and 2 locations (m-1,n) , (m,n-1) O(n^2) space
int minPathSum(vector<vector<int> > &grid){
    int m = grid.size();
    int n;
    if (m == 0) {
        return 0;
    }
    n = grid[0].size();
    int opt[m][n];
   
    // Intialize row and columns
    opt[0][0] = grid[0][0];
    //move down
    for (int i=1;i<m;i++) {
        opt[i][0] = grid[i][0] + opt[i-1][0];
    }
    //move right
    for (int j=1;j<n;j++)   { 
        opt[0][j] = grid[0][j] + opt[0][j-1];
    }

    //Use opt formula
    for (int i=1;i<m;i++) {
        for (int j=1;j<n;j++) {
            opt[i][j] = grid[i][j] + min(opt[i-1][j],opt[i][j-1]);
        }
    }
    return opt[m-1][n-1] ;
}

int minPathSumv1(vector<vector<int> > &grid) {
    int m = grid.size();
    if (!m) {
        return m;
    }
    int n = grid[0].size();
    int opt[n] ;
    //Req . initialization
    for (int i=0;i<n;i++) {
        opt[i] = INT_MAX;
    }
    opt[0] = 0;
    for (int i=0;i<m;i++) {
        //In short just retain the row value in the opt array and find the minimum
        opt[0] = grid[i][0] + opt[0] ;
        for (int j=1;j<n;j++) {
            //loop through each col
            opt[i] = grid[i][j] + min(opt[j],opt[j-1]);

        }
    }
    return (opt[n-1]);
}



//Paragaon of HOW Complicated one can think 
int minPathSumv2(vector<vector<int> > &grid) {
    
    //int m = grid.size();
    //int n = grid[0].size();
    //int x = 0;
    //int y = 0;
    //bool is_diag = false;
    //bool is_right = false;
    //bool is_down = false;
    //int min_path_sum = 0;
    //
    //while ( (x != m-1) && (y != n-1) ) {
    //    is_diag = false;
    //    is_right = false;
    //    is_down = false;
    //    int right_ = grid[x+1][y];
    //    int down_ = grid[x][y+1];
    //    //int diag_ = grid[x+1][y+1];
    //    int tmp_min = 0;
    //    if (right_ < down_ ) {
    //        tmp_min  = right_;
    //        is_right = true;
    //        if (dig_ < right_) {
    //            is_right = false;
    //            is_diag_ = true;
    //            tmp_min  = dig_;
    //        }
    //    }else {
    //        tmp_min  = down_;
    //        is_down = true;
    //        if (dig_ < down_) {
    //            is_down = false;
    //            is_diag_ = true;
    //            tmp_min  = dig_;
    //        }
    //    }
    //    if (is_down) {
    //        y = y+1;
    //    }
    //    if (is_diag_) {
    //        x = x+1;
    //        y = y+1;
    //    }
    //    if (is_right) {
    //        x = x+1;
    //    }
    //
    //}



}

int main () {


}
