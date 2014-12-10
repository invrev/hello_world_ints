#include<iostream>
using namespace std;

//this approach is used in the coin picking,computing the combination using pascal traingle

//eg pascal traingle
//Choose r from c
int gen_pascal (int r,int c) {
    if (r == 1 && c == 1) {
        return 1;
    } else if (r <= 0 || c <= 0) {
        return 0;
    } else {
        //gen_pascal (r,c-1) : not pick/choose the r 
        //gen_pascal (r-1,c) : pick/choose the r from c
        return (gen_pascal (r,c-1) + gen_pascal (r-1,c) );
        //Recursive version becomes pascal_vec[i][j] = pascal_vec[i][j-1] + pascal_vec[i-1][j];
    } 
}

//A top down approach
int rec_knapsack (int a[],int val[],int item,int capacity) {

    if (capacity < 0 || item < 0 || capacity < a[item] ) {
        return 0;
    } else {
        //# of subproblems
        //pick it or not pick it
        return max ( rec_knapsack (a,val,item-1,capacity), 
                (val[item] + rec_knapsack (a,val,item-1,capacity - a[item]) ) );
    }
}

//top down approach

int dp_knapsack (int wt[],int val[],int item,int capacity) {
    
    int profit[item+1][capacity+1];

        
    //init stages 
    for (int i=0;i<=item;i++) {
        profit[i][0] = 0;
    }
    //init state 
    for (int j=0;j<=capacity;j++) {
        profit[0][j] = 0;
    }
    
    //compute the values
    for (int i=1;i<=item;i++) {
        for (int j=1;j<=capacity;j++) {
            if (wt[i] < capacity) {
                //Pick the element  
                //which is max (previous state value,previous state value by adding the current state value)
                profit[i][j] = max (profit[i-1][j],val[j] + profit[i-1][j-wt[i]] );
            } else {
                //Don't pick the element
                profit[i][j] = profit[i-1][j];
            }
        }
    }
    return profit[item][capacity];
}





int main () {
    //int val[] = {60, 100, 120};
    //int wt[] = {10, 20, 30};
    //int  W = 50;

    int val[] = {1,6,18,22,28};
    int wt[] = {1,2,5,6,7};
    int  W = 11;
    
    int no_of_items = sizeof(val)/sizeof(val[0]);
    int max = rec_knapsack (wt,val,no_of_items -1 ,W);
    cout << "the max profit " << max << endl;
    dp_knapsack (wt,val,no_of_items,W);
    cout << "the max profit " << max << endl;
    //observations
    //cannot take the item with W >

}
