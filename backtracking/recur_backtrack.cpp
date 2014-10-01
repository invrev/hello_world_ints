#include<iostream>
using namespace std;
#define NMAX 4
//PROG : print all the bin numbers from 0 to 7
//Base prog : 
//1.Print all the paths in the bin tree
//2.Fibo series
//3.Generate subset
//4.Take Maze turn


void print_solution (int a[],int k) {
    int i;
    for (i=1;i<=k;i++) {
        cout << " " << a[i] ;
    }
    cout << endl;
}

void do_recursion(int path[], int k, int solution_size)
{
    if ( k == solution_size) { //Base case to terminate the recursion
        print_solution(path,k);
    }
    else 
    {
       k = k+1; // increase the solution size
       path[k] = 0;
       do_recursion(path,k,solution_size); 
       path[k] = 1;
       do_recursion(path,k,solution_size); 
    }
}

int main () {
    int a[NMAX];                 
    do_recursion(a,0,3);
}
