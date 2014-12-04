#include<iostream>

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int s = 0, e = rows* cols - 1;
    while(s<=e) {
        int m = s+(e-s)/2;
        if(matrix[m/cols][m%cols]==target) {
        return true;
        }else if(matrix[m/cols][m%cols]>target) {
            e = m -1;
        }else {
            s = m + 1;
        }
    }
    return false;
}

int main () {

}
