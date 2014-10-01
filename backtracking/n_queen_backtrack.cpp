#include<iostream>
using namespace std;


int n_queen_solution(int q[],int k,int solution_size) {
    if (k == solution_size+1) {
        cout << "Found solution " << endl;
    } else {
        //iterate over all the columns
        for (int c=1;c<=solution_size;c++) {
            cout << "c = "  << c << endl;
            //check partial solution set 
            for (int r=1;r<=k;r++) {
               cout << "("<< c << "," << c+k-r << "," << c-k+r <<")" << endl;
            }

            n_queen_solution(q,k+1,solution_size);

        }
    }



}

int main () {
    int q[] = {0,0,0,0,0,0,0};
    n_queen_solution(q,1,4);
}
