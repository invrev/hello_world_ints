#include<iostream>
#include<stdlib.h>
using namespace std;

//TODO : Never use fancy struct 
struct point_node {
    int x,y;
};
typedef struct point_node point;

static int number_of_calls = 0;


void print_board (char board[][4],int b_len,int b_width) {
    for (int i=0;i<b_len;i++) {
        for (int j=0;j<b_width;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

void paint_board (char board[][4],int x,int y,char new_color,int b_len,int b_width) {
    cout << "# of calls =  " << number_of_calls++   << endl;
    cout << "(" << (x) << "," << (y) << ")" << endl;
    //Total # of board positions = 16 
    //Total # of calls in each iteration = 4
    //So Total # of calls = 16 * 4 = 64
    if ( (x < b_len && x >= 0) && (y < b_width && y >= 0)) {
        if (board[x][y] == 'X') {
            board[x][y] = new_color;
            //go above
            paint_board (board,x+1,y,new_color,b_len,b_width);
            //go below
            paint_board (board,x-1,y,new_color,b_len,b_width);
            //go right
            paint_board (board,x,y+1,new_color,b_len,b_width);
            //go left
            paint_board (board,x,y-1,new_color,b_len,b_width);
        } 
    }
}

void rec_paint_board (char board[][4],int x,int y,char new_color,int b_len,int b_width) {
    
    cout << "# of calls =  " << number_of_calls++   << endl;
    for (int i=0;i<b_len;i++) {
        for (int j=0;j<b_width;j++) {
            if ( (i == x && j == y) || board[i][j] == new_color ) {
                continue;
            } else {
                board[i][j] = new_color;
            }
        }
    }
}

int main () {
    char board [][4] =  {
        {'X','X','X','X'}
        ,{'X','X','X','X'}
        ,{'X','X','X','X'}
        ,{'X','X','X','X'}
    } ;
    char new_color = 'Y';
    paint_board (board,2,2,new_color,4,4);
    print_board (board,4,4) ;
 
    number_of_calls = 0;
    
    new_color = 'O';
    rec_paint_board (board,2,2,new_color,4,4);
    print_board (board,4,4) ;

}
