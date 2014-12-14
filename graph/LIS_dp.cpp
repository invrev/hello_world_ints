#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Always DP problem is reduced to DAG
//Modification : get the length of consecutive increasing subsequence


//def recursive_solution(remaining_sequence, bigger_than=None):                    
//  """Finds the longest increasing subsequence of remaining_sequence that is      
//  bigger than bigger_than and returns it.  This solution is O(2^n)."""           
//  # Base case: nothing is remaining.                                             
//  if len(remaining_sequence) == 0:                                               
//    return remaining_sequence                                                    
//  # Recursive case 1: exclude the current element and process the remaining.     
//  best_sequence = recursive_solution(remaining_sequence[1:], bigger_than)        
//  # Recursive case 2: include the current element if it's big enough.            
//  first = remaining_sequence[0]                                                  
//  if (first > bigger_than) or (bigger_than is None):                             
//    sequence_with = [first] + recursive_solution(remaining_sequence[1:], first)  
//    # Choose whichever of case 1 and case 2 were longer.                         
//    if len(sequence_with) >= len(best_sequence):                                 
//      best_sequence = sequence_with                                              
//  return best_sequence  

//Designing the good interface 
int get_lis_length (int prev,int start,vector<int> input_sub) {
    if (input_sub.size() == start) {
        return 0;    
    }else {
        start += 1;
        //TODO : is there necessary of max computation ? any way always 2 calls if for loop 1 call else 2 calls
        int max = get_lis_length (prev,start,input_sub);
        int current = start - 1;
        if (input_sub[current] > prev ) {  
            //If current input is part of subsequence
            int l = 1 + get_lis_length (input_sub[current],start,input_sub);
            if (l > max) {
                max = l;
            }
        }
        return max; //if current is not part of input subsequence
    }
}

//init will be prev = input_sub[0] -1
int get_lis_length_c (int prev,int start,vector<int> input_sub) {
    if (input_sub.size() == start) {
        return 0;    
    }else {
        start += 1;
        int max = get_lis_length (prev,start,input_sub);
        int current = start - 1;
        if (input_sub[current] - prev == 1 ) {  
            //If current input is part of subsequence
            int l = 1 + get_lis_length (input_sub[current],start,input_sub);
            if (l > max) {
                max = l;
            }
        }
        return max; //if current is not part of input subsequence
    }
}

int get_lis_length_dp (vector<int> a) {
    int n = a.size();
    vector<int> L(n,0);
    int max_len = INT_MIN;
    for (int i=0;i<n;i++) {
        L[i] = 1;
        for (int j = 0;j < i-1; j++) {
            if (a[j] <= a[i] && 1 + L[j] > L[i] ) {
                L[i] = 1 + L[j];
            }
        }
        max_len = max(L[i],max_len);
    }
    cout << L[n-1] << endl;
    return max_len;
}

//Find longest increasing subsequence
int LIS_wrapper (int a[],int n,int &max) {

    //base case
    if (n == 1) {
        return n;
    }
    int lis_found;
    int max_ending_here = 1;
    for (int i=1;i<n;i++) {
        //L(j) = 1 + max{L(1),L(2), . . . ,L(j − 1)}.
        lis_found = LIS_wrapper (a,i,max);
        if (a[i-1] < a[n-1] && 1 + lis_found > max_ending_here ) {
            max_ending_here = 1 + lis_found ;
        }
    }
    if (max < max_ending_here) {
        max = max_ending_here;
    }
    return max_ending_here;
}

int LIS (int a[],int n) {
    int max = 1;
    LIS_wrapper (a,n,max);
}



int main () {
    int a[] = {5,2,6,3,6,9,7};
    int n = sizeof(a)/sizeof(a[0]);
    int max = LIS(a,n);
    cout << "Longest max subseq = " << max << endl;
    vector<int> input_vec (a,a+sizeof(a)/sizeof(a[0]));
    max = get_lcs_length(-999,0,input_vec);
    cout << "Longest max subseq = " << max << endl;
    max = get_lis_length_dp (input_vec);
    cout << "the maximum len = " << max << endl;
}


