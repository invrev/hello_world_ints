#include<iostream>
using namespace std;

//You can maintain a row length of Integer array H recorded its height of '1's, and scan and update row by row to find out the largest rectangle of each row.
//For each row, if matrix[row][i] == '1'. H[i] +=1, or reset the H[i] to zero. and accroding the algorithm of [Largest Rectangle in Histogram], to update the maximum area.

//It records the current height of columns during the loop of rows, where the height is defined as:
//
//for row of index `row`, the consecutive number of 1's from `row` to `0`
//As it is mentioned, the height for column i H[i] is reset to 0 where matrix[row][i] is 0 while looping through row.
//
//I also like the trick you use for the last fake column H[cLen]. =)
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/



int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty()) { 
        return 0;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea = 0;
    vector<int> heights(cols + 1, 0);
    vector<int> stack;
    for (int i = 0; i < rows; i++) {
        stack.clear();
        for (int j = 0; j < cols + 1; j++) {
            if (j < cols) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            if (stack.empty() || heights[j] >= heights[stack.back()]) {
                stack.push_back(j);
                continue;
            }
            while (!stack.empty() && heights[j] < heights[stack.back()]) {
                int top = stack.back();
                stack.pop_back();
                int begin ;
                if (stack.empty()) {
                    begin = 0 ;
                } else {
                    begin = stack.back() + 1;
                }
                int area = heights[top] * (j - begin);
                if (area > maxArea) maxArea = area;
            }
            stack.push_back(j);
        }
    }
    return maxArea;
}
