#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> v;
    int m = matrix.size(); 
    int n = matrix[0].size();
    int left = 0;
    int right = n;
    int top = 0;
    int bottom = n;
    int direction = 0; 
    while (left < right && top < bottom) {
        //print first row
        /* Print the first row from the remaining rows */
        for (int i = top; i < bottom; ++i) {
             //cout << endl;
             //cout << " left_right " << endl;
             //cout << matrix[left][i] << " " ;
             v.push_back(matrix[left][i]);
        }
        left++;
        /* Print the last column from the remaining columns */
        for (int i = left; i < right; ++i) {
            //cout << " top_bottom " << endl;
            //cout << matrix[i][bottom-1] << " ";
            v.push_back(matrix[i][bottom-1]);
        }
        bottom--;
        /* Print the last row from the remaining rows */
        if ( left < right) {
            for (int i = bottom-1; i >= top; --i) {
                //cout << "last_rows" << endl;
                //cout << matrix[right-1][i] << " ";
                v.push_back(matrix[right-1][i]);
            }
            right--;
        }
        /* Print the first column from the remaining columns */
        if (top < bottom) {
            for (int i = right-1; i >= left; --i) {
                //cout << endl;
                //cout << "last_cols = "  << "(" << i << "," << top << ")" << endl;
                //cout << matrix[i][top] << " ";
                v.push_back(matrix[i][top]);
            }
            top++;    
        }        
    }
    //cout << endl; 
    return v;
}

vector<int> spiralOrder0(vector<vector<int> > &matrix) {
    vector<int> result;
    if (!matrix.size() || !matrix[0].size()) return result;
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;
    //For rectangular size matrix
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        if (top > bottom) continue;
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (left > right) continue;
        for (int i = right; i >= left; i--) {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;
        if (top > bottom) continue;
        for (int i = bottom; i >= top; i--) {
            result.push_back(matrix[i][left]);
        }
        left++;
    }
    return result;
}

int main () {
    int a[] = {1,2,3};
    int b[] = {4,5,6};
    int c[] = {7,8,9};
    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    vector<int> bv (b,b+sizeof(b)/sizeof(b[0]));
    vector<int> cv (c,c+sizeof(c)/sizeof(c[0]));
    vector<vector <int> > matrix;
    matrix.push_back(av);
    matrix.push_back(bv);
    matrix.push_back(cv);
    spiralOrder(matrix);
}
