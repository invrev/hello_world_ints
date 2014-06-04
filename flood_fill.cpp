#include<iostream>
using namespace std;

//Alternate solution is the BFS use the queue
//With queu
//Queue q = Ø
//Add the seed to q
//While(!q.empty()) {
//  P = q.removefirst();
//  For (x = P’s neighboring pixels) {
//    If (getPixel(x) == old) {
//         setPixel(x, fill);
//         q.insert(x);
//    }
//  }
//}

//LAW of bactracking : 
//Identify you search space or input eg. board SEARCH
//always remind your self your current move e.g. current_x,current_y REMIND
//what ever you do in backtracking store eg. buffer_board STORE
//find the way eg. result RESULT
//Base cases help to stop/terminate our processs TERMINATE
//Pruning reduces the search space 
void color_board_with_flood_fill (int current_x,int current_y,char buffer_board[][4]
        ,int width,int height
        ,char src_color,int dest_color) {
    //Base case for the recursion
    if (current_x < 0 || current_x > width) return;
    if (current_y < 0 || current_y > height) return;
    if (board[current_x][current_y] != dest_color) {
        board[current_x][current_y] = dest_color;
        color_board_with_flood_fill ( (current_x+1) ,current_y,board,4,4,'x','o');
        color_board_with_flood_fill ( (current_x-1) ,current_y,board,4,4,'x','o');
        color_board_with_flood_fill (current_x,(current_y+1),board,4,4,'x','o');
        color_board_with_flood_fill (current_x,(current_y-1),board,4,4,'x','o');
    }
}

void print_board (char board[][4],int m,int n) {
    cout << endl;
    for (int i=0;i<m;i++) {
       cout << "\t\t\t"; 
       for (int j=0;j<n;j++)  {
            cout << board [i][j] << " ";
       }
       cout << endl;
    }
    cout << endl;
}

int main () {

    char board [][4] = {
         {'x','x','x','x'} 
        ,{'x','x','x','x'} 
        ,{'x','x','x','x'} 
        ,{'x','x','x','x'} 
    };
   print_board (board,4,4) ;
   color_board_with_flood_fill (0,0,board,4,4,'x','o');
   print_board (board,4,4) ;

}
