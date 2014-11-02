#include<iostream>
#include<vector>
using namespace std;


vector<vector<int> > generateMatrix(int n) {
    int acc = 1;
    int y = 0, x = 0;
    //(1,0) : move right , (0,1) : move down , (-1,0) : move left , (0,-1) : move up
    int dx[4] = {1, 0, -1, 0 }; //4 direction left,right,bottom,top 
    int dy[4] = {0, 1,  0, -1};
    vector<vector<int> > a(n, vector<int>(n, 0));
    //MOVE right,DOWN so dec by 2
    for (int l = n-1; l >= 0; l-= 2) { // control which level you are currently in /
        x =  y = (n - 1 - l)/2; // init x, y at level start (starting position to loop from)
        cout << "( " << x  << ","  << y << ")" << endl;
        for(int k = 0; k < 4 ; k++) { // change direction 
            cout << "RE " << endl;
            for(int i = 0 ; i < l; i++) { // fill the array
                a[y][x] = acc++;
                cout << "[ " << y  << ","  << x << "]1" << endl;
                x = x+dx[k];
                y = y+dy[k];
                cout << "[ " << x  << ","  << y << "]" << endl;
            }
        }
    }
    // special case for odd n the center of the spiral is a single element.
    if (n%2 == 1)
        a[n/2][n/2] = n*n;

    return a;
}

int main () {
    vector<vector<int> > n1 = generateMatrix(4);
}
