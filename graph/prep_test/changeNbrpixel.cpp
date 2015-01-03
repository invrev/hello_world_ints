#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;


//given pixel change the color of surrounding pixel
void changePixel (vector<vector <int> >& image,int x,int y,int a,int b) {

    //If 1-d array
    if ( image.size() == 0 || x < 0 || y < 0 || x > image[0].size() || y > image.size() ) {
        cout << "returning" << endl;
        return;
    } else {
        if (x == a && y == b)  {
            int row[] = {-1,1,0,0};
            int col[] = {0,0,1,-1};
            int len = sizeof(row)/sizeof(row[0]);
            for (int i=0;i<len;i++) {
                cout << "i = " << i << endl;
                changePixel (image,x+row[i],y+col[i],a,b);
            }
            //changePixel (image,x-1,y,a,b);
            //changePixel (image,x+1,y,a,b);
            //changePixel (image,x,y+1,a,b);
            //changePixel (image,x,y-1,a,b);
        } else {
            image[x][y] = '1';
            cout << "(" << x << ","<< y << ")" << endl;
            return;
        }
    }
}


void testMat() {

    int a[] = {1,2,3};
    int b[] = {4,0,6};
    int c[] = {7,8,0};
    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    vector<int> bv (b,b+sizeof(b)/sizeof(b[0]));
    vector<int> cv (c,c+sizeof(c)/sizeof(c[0]));
    //vector< vector<int> > v (4)/sizeof();
    vector< vector<int> > v;
    //v[0] (a,a+sizeof(a)) ;
    v.push_back(av) ;
    v.push_back(bv) ;
    v.push_back(cv) ;
    changePixel (v,1,1,1,1);

}


int main () {

    testMat();
}
