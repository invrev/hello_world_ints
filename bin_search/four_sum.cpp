#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

//(n-4,n-3,n-2,n-1)
//(i,i+1,i+2,i+3)
//O(n^3)
vector<vector<int> > fourSum(vector<int> &num, int target) {
    int n = num.size();
    vector<vector <int> >  result;
    if (n < 4) {
        return result;
    } else {
        sort(num.begin(),num.end());
        for (int i=0;i<n-3;i++) {
            //As array are sorted we can remove the duplicates
            if (i > 0 && num[i-1] == num[i]) {
                continue;
            }
            
            for (int j = n-1;j >= i+3;j--) {
                if ( j < n-1 && num[j] == num [j+1]) {
                    continue;
                }
                int first_two_sum = num[i] + num [j];
                int new_target = target - first_two_sum;
                int start_index = i+1;
                int end_index = j-1;
                while (start_index < end_index) {
                    vector<int> tmp_vec;
                    int four_sum = new_target - num[start_index] - num[end_index];

                    if (start_index > i+1 && num[start_index] == num[start_index-1]) {
                        start_index++;
                        continue;
                    }
                    if (end_index < j-1 && num[end_index] == num[end_index+1]) {
                        end_index--;
                        continue;
                    }
                    if (four_sum == 0) {
                       //align correctly in increasing order 
                        tmp_vec.push_back(num[i]);
                        tmp_vec.push_back(num[start_index]);
                        tmp_vec.push_back(num[end_index]);
                        tmp_vec.push_back(num[j]);
                        result.push_back(tmp_vec);
                        start_index++;
                        //while (start_index < j-1 && num[start_index] == num[start_index-1]) {
                        //    start_index++;
                        //}
                        end_index--;
                        //while (end_index < i+1  && num[end_index] == num[end_index + 1]) {
                        //    end_index--;
                        //}

                    } else if (four_sum < 0) {
                        start_index++;
                    } else {
                        end_index--;
                    }
                }
            }
        }
    }
    return result;
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
    //vector<vector <int> > result =  fourSum(av,0);
    vector<vector <int> > result =  fourSum0(av,0);
    cout << "the total tuples = "  << result.size() << endl;
    print_result(result);



}

