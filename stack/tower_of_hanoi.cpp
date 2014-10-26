#include<iostream>
#include<vector>
using namespace std;

void move_disc (int n,vector< vector <int> >& pegs,int from,int to,int mid) {
    if (n > 0) {
        move_disc (n-1,pegs,from,mid,to);
        pegs[to].push_back(pegs[from].back());
        pegs[from].pop_back();
        cout << "Move from peg " << from << " to peg " << to << endl;
        move_disc (n-1,pegs,mid,to,from);
    }

}

void solve_tower_of_hanoi (int no_of_discs ) {
    vector< vector<int> > pegs (3);
    for (int i = no_of_discs; i >= 1; --i ) {
        pegs[0].push_back(i);
    }
    move_disc (no_of_discs,pegs,0,1,2);
}



int main () {
    solve_tower_of_hanoi(3);
}
