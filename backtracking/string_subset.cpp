#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

//solve the 
//1.number subset
//2.Alphabet permutation
//3.
void print_path(string path,int k) {
    int i;
    cout << path << endl;
}


void do_exchange (string &name,int i,int j)  {
    char temp = name[i] ;
    name[i] = name[j];
    name[j] = temp;
}


void string_permute(string path,int k,int solution_size) {
    if ( k == (solution_size -1)) {
        print_path(path,k);
    }else {
        k = k + 1;
        //iterate over the candiate 
        for (int i = k;i < solution_size;i++) {
            //do_exchange (path,i, (solution_size -1)) ;
            do_exchange (path,i, k) ;
            string_permute(path,k,solution_size);    //(n-1)!
            //do_exchange (path,i, (solution_size -1)) ;
            do_exchange (path,k,i) ; //clean up
        }
    }
}

void print_array (int a[]) {
    int len = sizeof(a)/sizeof(a[0]);
    for (int i=0;i<=len;i++) {
        cout << a[i] << "," ;
    }
    cout << endl;

}

//
void enumerate (int a[] ,int k,int solution_size) {
    if (k == (solution_size-1) ) {
        print_array(a);
    } else {
        k = k + 1;
        enumerate (a,k,solution_size); //(n-1) !
        a[k] = 1;           //set a[k]
        enumerate (a,k,solution_size); //(n-1)!
        a[k] = 0; //clean - up
    }
}

vector<int> gray_code_vec;
void print_gray_code(int a[],int k) {
    int sum = 0;
    for (int i=k,j=0;i>=0;i--,j++) {
        //cout << a[i] << ",";
        int multiplier = pow(2,j);
        sum += (multiplier * a[i]);
    }
    //cout << endl;
    gray_code_vec.push_back(sum);
}

void gray_code_enumerate (int a[] ,int k,int solution_size) {
    if (k == (solution_size-1) ) {
       print_gray_code(a,k);
    } else {
        k = k + 1;
        gray_code_enumerate (a,k,solution_size); //(n-1) !
        a[k] = 1 - a[k];                        //Flip a[k]
        gray_code_enumerate (a,k,solution_size); //(n-1)!
    }
}


int main () {
    //string path = "LIFE";    
    //string_permute(path,-1,4);
    //string path = "LIF";    
    //string_permute(path,-1,3);
    //do_exchange (path,1, 2);
    //cout << " the name = " << path<< endl;
    int a[] = {0,0,0};
    enumerate (a,-1,3);
    cout << "----------------" << endl;
    int b[] = {0,0};
    gray_code_enumerate (b,-1,2);
    for (int i=0;i<gray_code_vec.size();i++) {
        cout << gray_code_vec[i] << ",";
    }
    cout << endl;
}
