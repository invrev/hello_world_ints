#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//combination sum

void print_solution (vector<int>& solution,vector<vector<int> >& solution_store) {
    vector<int> tmp ;
    for (int i=0;i<solution.size();i++) {
        cout << solution[i] << ",";
        tmp.push_back(solution[i]);
    }
    solution_store.push_back(tmp);
    cout << endl;
}


//This picks the single element 
void enum_combination_sum(vector<int>& input,int k,vector<int>& solution,int& total_sum
        ,vector<vector<int> >&solution_store) {
    if (k == input.size() - 1) {
        //got the solution set
        if (total_sum == 0 ) {
            print_solution (solution,solution_store);
        }
    } else {
        k = k + 1;
        if (input[k] > total_sum) {
            //pruning
            return;
        }
        //NOTE : this version is not efficient due to # of calls
        solution.push_back(input[k]);
        total_sum = total_sum-input[k];
        enum_combination_sum (input,k,solution,total_sum,solution_store);
        //backtrack add element
        solution.pop_back();
        total_sum = total_sum+input[k];
        enum_combination_sum (input,k,solution,total_sum,solution_store);
    }

}

//Select the item with repeatition
void enum_combination_sum_with_repeat(vector<int>& input,int k
        ,vector<int>& solution,int total_sum
        ,vector<vector<int> >&solution_store) {
        //got the solution set
        if (total_sum == 0) {
            print_solution (solution,solution_store);
            return;
        } 
        //NOTE : when its for loop w/o updating the start condition do not call the line #67
        for (int i=k+1; i<input.size();i++) {
            //pruning
            if (input[i] > total_sum) {
                return;
            }
            //NOTE : this version is not efficient due to # of calls
            solution.push_back(input[i]);
            total_sum = total_sum-input[i];
            //as it is pass by value ,no change in total sum while backtrack
            enum_combination_sum_with_repeat(input,k,solution,total_sum,solution_store);
            //backtrack add element
            solution.pop_back();
            total_sum = total_sum+input[i];
        }
}


//Select the item with repeatition
void enum_combination_sum_wo_repeat(vector<int>& input,int k
        ,vector<int>& solution,int total_sum
        ,vector<vector<int> >&solution_store) {
        //got the solution set
        if (total_sum == 0) {
            print_solution (solution,solution_store);
            return;
        } 
        //NOTE : when its for loop w/o updating the start condition do not call the line #67
        
        for (int i = k+1 ;  i<input.size();i++) {
            //pruning
            if (input[i] > total_sum) {
                return;
            }
            //NOTE : this version is not efficient due to # of calls
            solution.push_back(input[i]);
            total_sum = total_sum-input[i];
            //as it is pass by value ,no change in total sum while backtrack
            enum_combination_sum_wo_repeat(input,i,solution,total_sum,solution_store);
            //backtrack add element
            solution.pop_back();
            total_sum = total_sum+input[i];
            while (i < input.size() && input[i] == input[i+1])  {
                i++;
            }
        }
}

int main () {
    int a[] = {2,3,5,6,7,8};
    int sum = 7;
    vector<int> input(a,a+sizeof(a)/sizeof(a[0]));
    sort(input.begin(),input.end());
    vector<int> solution;
    vector< vector<int> > solution_store;
    //enum_combination_sum(input,-1,solution,sum,solution_store);
    enum_combination_sum_with_repeat(input,-1,solution,sum,solution_store);
    cout << "subset sum w/o repeat" << endl;
    enum_combination_sum_wo_repeat (input,-1,solution,sum,solution_store);

}
