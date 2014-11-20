#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

//O(n^2logn)
vector<vector<int> > fourSum(vector<int> &num, int target) {
    int n = num.size();
    //set of vector to avoid duplicates
    set<vector <int> >  result;
    unordered_map<int, set<pair<int,int>>> hash_map;
    
    if (n < 4) {
        return vector<vector <int> > () ;
    } else {
        //sort(num.begin(),num.end());
        for (int i=0;i<n;i++) {
            for (int j= i+1;j<n;j++) {
                int two_sum = num[i] + num[j];
                //Get the entries/pair from map that satisfies the two_sum condition
                if (hash_map.count(target-two_sum)) {
                    for (auto &p:hash_map[target-two_sum]) {
                        vector<int> tmp_result = {p.first,p.second,num[i],num[j]};
                        result.insert(tmp_result); //set has insert not push_back
                    }
                }
            }
            //Update the map with pair
            for (int j=0;j<i;j++) {
                int a = num[i];
                int b = num[j];
                hash_map[a+b].insert( make_pair (a,b) );

            }
        
        }
    }
    return vector<vector<int> > (result.begin(),result.end());
    //return result;
}


void print_result (vector<vector<int> >& res) {
    int m = res.size();
    for (int i=0;i<m;i++) {
        for (int j=0;j< res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}

int main () {


    int a[] = {1,0,-1,0,-2,2};
    vector <int> av(a,a+sizeof(a)/sizeof(a[0]));
    vector<vector <int> > result =  fourSum(av,0);
    cout << "the total tuples = "  << result.size() << endl;
    print_result(result);



}


