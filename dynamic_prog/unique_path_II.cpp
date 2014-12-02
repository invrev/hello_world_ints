#include<iostream>
#include<vector>
using namespace std;


 int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        /* first position is obstacle */
        if (obstacleGrid[0][0] == 1)  {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        /* exit position is obstacle */
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        int sol[100][100];
        vector<vector <int> > opt (m,vector<int> (n) );
        //2 -d vector initialization
        //vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        opt[0][0] = 1;
        //If obstacle reset
        /* fill the first row */
        for (int i = 1; i < n; i ++) {
            if (obstacleGrid[0][i] == 1) {
                opt[0][i] = 0; // it is an obstacle so none paths.
            } else {
                opt[0][i] = opt[0][i - 1];
            }
        }
        /* fill the first column */
        for (int i = 1; i < m; i ++) {
            if (obstacleGrid[i][0] == 1) {
                opt[i][0] = 0;// it is an obstacle so none paths.
            } else {
                opt[i][0] = opt[i - 1][0];    
            }
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                int c = 0;
                /* the up position is not blocked */
                if (obstacleGrid[i - 1][j] == 0)  {
                    c += opt[i - 1][j];
                }
                /* the left position is not blocked ? */
                if (obstacleGrid[i][j - 1] == 0)  { 
                    c += opt[i][j - 1];
                }
                opt[i][j] = c;
            }
        }
        return opt[m - 1][n - 1];        
}

int main () {

}
