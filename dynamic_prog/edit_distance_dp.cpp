#include<iostream>
#include<string>
using namespace std;

int is_match  (string a,string b) {
    if (a[0] == b[0]) {
        return 0;
    } return 1;
}

//Iterative version
//Row Major 
int edit_distance_dp (string word1,string word2) {
    int m = word1.length();
    int n = word2.length();
    int solution_vector[m+1][n+1];
    //cout << "(" << m << "," << n << ")" << endl;
    //cout << word1 << " , " << word2 << endl;
    //Initialize columns
    for (int j=0;j<=n;j++) {
        solution_vector[0][j] = j;
    }
    for (int i=1;i<=m;i++) {
        //Lazy row initialization
        solution_vector[i][0] = i;
        for (int j=0;j<=n;j++) {
            //min_cost of insert and delete
            int min_cost = min( solution_vector[i-1][j] + 1,solution_vector[i][j-1] + 1);
            //As initialization start at 0th row and column use i-1,j-1 as the current string index for 
            //word1 and word2
            if (word1[i-1] == word2[j-1]) {
                //cout << "match char ("<< i << "," << j << ")" << endl;
                solution_vector[i][j] = min(solution_vector[i-1][j-1],min_cost);
            } else {
                solution_vector[i][j] = min(solution_vector[i-1][j-1] + 1,min_cost);
            }
        }
    }
    return (solution_vector[m][n]);
}


int main () {
    //string st = "kitten";
    //string st1 = "sitten";

    //string st = "ramayan";
    //string st1 = "mahabhart";
    string st = "algorithm";
    string st1 = "altruistic";

    dist = edit_distance_dp (st,st1);
    cout << "the edit distance = " << dist << endl;
}


