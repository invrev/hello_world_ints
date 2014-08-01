#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> index_vec ;
    sort(numbers.begin(),numbers.end());
    int t_nos = numbers.size();
    int start = 0;
    int end = t_nos - 1;
    while (start <= end) {
        if (numbers[start] + numbers[end] > target) {
            end -= 1;
        } else if (numbers[start] + numbers[end] < target) {
            start += 1;
        } else {
            index_vec.push_back(start);
            index_vec.push_back(end);
            break;
        }
    }
    return (index_vec);
}

int main () {
    int arr[] = {3,2,4};
    vector<int> numbers (arr,arr+3);
    vector<int> result = twoSum (numbers,6);
    for (int i=0;i<result.size();i++) {
        cout << result[i] << " ";
    }
}

