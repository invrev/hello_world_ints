#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

//geting the total # of coins is combination problem i.e. 1,2,2,3 and 2,1,2,3 are the same
//while the robot movement is permuation problem  i.e. 1,2,2,3 and 2,1,2,3 are the diff

static int path_cnt = 0;

void robot_movement (int robot_path[][4],int start_x,int start_y,int dest_x
        ,int dest_y,int off_limit[][2],int b_len,string result) {
        if (dest_x == start_x && dest_y == start_y) { 
            //cout <<  "(" << start_x  << "," << start_y << ")" << endl;
            //cout <<  "(" << dest_x << "," << dest_y << ")" << endl;
            cout << "path # = " << path_cnt++  << endl;
            cout << result << endl;
        } else if ( (start_x >=0 && start_y >= 0 )  && (start_x < b_len  && start_y < b_len )) {
            //cout <<  "(" << start_x  << "," << start_y << ")" << endl;
            result.append("(");
            ostringstream ostr; 
            ostr << start_x; 
            result.append(ostr.str());
            result.append(",");
            ostr.str("");
            ostr << start_y; 
            result.append(ostr.str());
            result.append(")");

            robot_movement (robot_path,start_x-1,start_y,dest_x,dest_y,off_limit,b_len,result);
            robot_movement (robot_path,start_x,start_y-1,dest_x,dest_y,off_limit,b_len,result);
        
        } else {
            return ;
        }
}

int main () {

    //SIMPLE MATRIX IDEA : x,y = (col,row) we can any number of columns but fixed number of rows in C
    int robot_path [][4] = {
        {'X','X','X','X'}
        ,{'X','X','X','X'}
        ,{'X','X','X','X'}
        ,{'X','X','X','X'}
    };

    int off_limit[][2] = { {2,3} , {1,3}};
    int dest_x = 0;
    int dest_y = 0;
    int start_x = 3;
    int start_y = 3;
    int b_len = 4;
    string result;
    robot_movement(robot_path,start_x,start_y,dest_x,dest_y,off_limit,b_len,result);

}
