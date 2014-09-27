#include<iostream>
#include<string>
#include<sstream>
using namespace std;

static int path_cnt = 0;

void get_backtrack_result (string result) {
    path_cnt += 1;
    cout << result <<  " path # = " << path_cnt << endl;
}

//path_cnt : only for the bookkeeping purpose
//print all the path,print the path with no x's
void print_all_paths (int a[][4],int len,int start_x,int start_y
        ,int dest_x,int dest_y,string buffer_path) {
    if ((start_x < 0) || (start_x > dest_x) ) return;
    if ((start_y < 0) || (start_y > dest_y) ) return;
    
    if (start_x == dest_x && start_y == dest_y ) {
        get_backtrack_result(buffer_path);
        //buffer_path = "";
    } else {
        stringstream ss;
        ss << "(" << start_x << "," << start_y << ")";
        buffer_path += ss.str();
        print_all_paths (a,len,(start_x + 1),start_y , dest_x,dest_y,buffer_path);
        print_all_paths (a,len,start_x,(start_y + 1),dest_x,dest_y,buffer_path);
        //print_all_paths (a,len,(start_x-1),start_y   ,dest_x,dest_y,buffer_path);
        //print_all_paths (a,len,start_x ,(start_y -1),dest_x,dest_y,buffer_path);
    }

}

int main () {

    int a[][4] = { {0,1,2,3}
       ,{4,5,6,7}
       ,{8,9,10,11}
       ,{12,13,14,15}
    };

    string buffer_path = "";
    print_all_paths(a,4,0,0,3,3,buffer_path);

}
