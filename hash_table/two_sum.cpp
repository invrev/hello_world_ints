#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//g++ two_sum.cpp  -std=c++11
//O(n) solution
vector<int> twoSum(vector<int> &numbers, int target) {
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> number_index_map;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int search_key = target - numbers[i];
        //if search_key is found in map, return them
        if (number_index_map.find(search_key) != number_index_map.end()) {
            //+1 because indices are NOT zero based
            result.push_back(number_index_map[search_key] + 1);
            result.push_back(i + 1);            
            return result;
        }
        //number was not found. Put it in the map.
        number_index_map[numbers[i]] = i;
    }
    return result;
}


vector<int> twoSumV1(vector<int> &numbers, int target) {

    int len = numbers.size();
    vector<int> index_pair;

    unordered_map<int,int> number_index_map;
    for (int i=0;i<len;i++) {
        number_index_map[numbers[i]] = i+1;
    }
    for (int i=0;i<len;i++) {
       int search_key =  target - numbers[i];
       if (number_index_map.find(search_key) != number_index_map.end() ) {
            //int next_index = number_index_map.find(search_key)->second;
            int next_index = number_index_map[search_key];
            if (next_index != i+1) {
                index_pair.push_back(min(next_index,i+1));
                index_pair.push_back(max(next_index,i+1));
                return index_pair;
            }
       }
    }
   return index_pair;
}



int main () {
    int no [] = {2,7,11,15};
    vector<int> n_vec (no, no+sizeof(no)/sizeof(no[0]));
    vector<int> t_vec = twoSum (n_vec,9);
    cout << " the sizze = " << t_vec.size() << endl;
    for (int i=0;i<t_vec.size();i++) {
        cout << t_vec[i] << ",";
    }
    cout << endl;
}
