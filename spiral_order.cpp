#include<iostream>
using namespace std;

//dir #0 : -> #1 | #2 <- #3 |
//Change arr_[x][y] = -99 To avoid revisit Remember flood fill
void print_spiral_order (int arr_[][4],int len_,int top,int bottom,int left,int right,int x,int y,int dir) {
    if (right >= left && top <= bottom)  {
        if (y < right && dir == 0 && arr_[x][y] != -99)  {
            cout <<  arr_[x][y] << " right ";
            arr_[x][y] = -99; y += 1;
            print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
        } else if (y == right) {
            if (dir == 0) {
                dir = 1; top += 1;
                print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
            }
        } 
        if( x < bottom && dir == 1 && arr_[x][y] != -99) {
            cout <<  arr_[x][y] << " down ";
            arr_[x][y] = -99; x += 1;
            print_spiral_order (arr_,len_,top,bottom,left,right,x,y,1);
        } else if (x == bottom) {
            if (dir == 1) {
                dir = 2; right -= 1;
                print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
            }
        } 
        if (y > left && dir == 2 && arr_[x][y] != -99) {
            cout <<  arr_[x][y] << " bottom ";
            arr_[x][y] = -99;y -= 1;
            print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
        } else if (y == left) {
            if (dir == 2) {
                dir = 3; bottom -= 1;
                print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
            }
        }
        if ( x > top && dir == 3 && arr_[x][y] != -99) { 
            cout <<  arr_[x][y] << " top ";
            arr_[x][y] = -99;x -= 1;
            print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
        } else if ( x == top) {
            if (dir == 3)  {
                dir = 0; //left += 1;
                //NOTE : no left += 1;
                print_spiral_order (arr_,len_,top,bottom,left,right,x,y,dir);
            }
        }
    } 
    
    //else {
    //    cout << endl;
    //    cout << " top = " << top << " bottom = " << bottom <<  " lt = " << left << " right = " << right ;
    //    cout << " >>>>>>>> " << arr_[x][y];
    //}
}

int main () {

    //int arr_ [][3] = {
    //    {1,2,3} 
    //    ,{4,5,6}
    //    ,{7,8,9}
    //};
    //print_spiral_order(arr_,3,0,2,0,2,0,0,0);


    int arr_ [][4] = {
        {1,2,3,8} 
        ,{4,5,6,10}
        ,{7,8,9,11}
        ,{17,18,19,21}
    };
    print_spiral_order(arr_,4,0,3,0,3,0,0,0);


    cout << endl;

}
