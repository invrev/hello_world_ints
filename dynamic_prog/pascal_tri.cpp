#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result (numRows) ;

    vector< vector<int> > pascal_vec (numRows+1,vector<int> (numRows+1));
    //base_case 
    for (int i = 1;i <= numRows;i++) {
        pascal_vec [i][1] = 1;
    }
    for (int j = 1;j <= numRows;j++) {
        pascal_vec [1][j] = 1;
    }

    for (int i = 2;i <= numRows;i++) {
        for (int j = 2;j <= numRows;j++) {
            pascal_vec[i][j] = pascal_vec[i][j-1] + pascal_vec[i-1][j];
        }
    }

    //copy the diagonal elements
    //for (int i=1;i<=numRows;i++) {
    //    for (int j=1;j<=numRows;j++) {
    //        //cout <<  pascal_vec[i][j] << "," ;
    //    }
    //    //cout << endl;
    //}

    for (int i=1;i<=numRows;i++) {
        vector <int> tmp_vec;
        for (int j=1,r=i;j<=i;j++,r--) {
           //cout <<  pascal_vec[r][j] << "," ;
           tmp_vec.push_back(pascal_vec[r][j]);
        }
        result[i-1].resize(tmp_vec.size());
        copy(tmp_vec.begin(),tmp_vec.end(),result[i-1].begin());
        //cout << endl;
    }


    //for (int i=0;i<numRows;i++) {
    //    int len = result[i].size();
    //    for (int j=0;j<len;j++) {
    //       cout <<  result[i][j] << "," ;
    //    }
    //    cout << endl;
    //}
    
    return  result;
}

int gen_pascal (int r,int c) {
    if (r == 1 && c == 1) {
        return 1;
    } else if (r <= 0 || c <= 0) {
        return 0;
    } else {
        return (gen_pascal (r,c-1) + gen_pascal (r-1,c) );
    } 
}


int gen_pascal_dp (int r,int c) {
    
    vector< vector<int> > pascal_vec (r+1,vector<int> (c+1));
    //base_case 
    for (int i=1;i<=r;i++) {
        pascal_vec [i][1] = 1;
    }
    for (int j=1;j<=c;j++) {
        pascal_vec [1][j] = 1;
    }

    for (int i=2;i<=r;i++) {
        for (int j=2;j<=c;j++) {
            pascal_vec[i][j] = pascal_vec[i][j-1] + pascal_vec[i-1][j];
        }
    }
    return (pascal_vec[r][c]);
}


int main () {

    //int ans = gen_pascal (3,3);
    //cout << "pascal_ans = " << ans  << endl;
    //ans = gen_pascal_dp (3,3);
    //cout << "pascal_ans = " << ans  << endl;
    generate (5);
}
