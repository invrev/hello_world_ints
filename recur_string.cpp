#include<iostream>
#include<string>
using namespace std;


void print_path(string path,int k) {
    int i;
    cout << path << endl;
}


void do_exchange (string &name,int i,int j)  {
    char temp = name[i] ;
    name[i] = name[j];
    name[j] = temp;
    //cout << "after exchange " << name << endl;
}


void recur_string(string path,int k,int solution_size) {
    if ( k == (solution_size -1)) {
        print_path(path,k);
    }else {
        k = k + 1;
        //iterate over the candiate 
        for (int i = k;i < solution_size;i++) {
            do_exchange (path,i, (solution_size -1)) ;
            recur_string (path,k,solution_size);
            do_exchange (path,i, (solution_size -1)) ;
        }
    }
}


int main () {
    string path = "LIFE";    
    string name = "XXXX";
    int visited[] = {0,0,0,0};
    recur_string(path,-1,4);
    //do_exchange (path,1, 2);
    //cout << " the name = " << path<< endl;
}
