#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {

    vector<vector <int> > result;
    int size = num.size();
    if (size < 3)  {
        return result;
    }else {
        sort(num.begin(),num.end());
        for (int i=0;i< size-3;i++) {
            int a = num[i];
            int start_index = i+1;
            int end_index = size - 1;
            while (start_index < end_index) {
               vector <int> tmp_vec;
               int b = num[start_index];
               int c = num[end_index];
               if (a+b+c == 0) {
                   tmp_vec.push_back(a);
                   tmp_vec.push_back(b);
                   tmp_vec.push_back(c);
                   result.push_back(tmp_vec);
                   start_index++;
                   end_index--;
                } else if (a+b+c > 0) {
                    end_index--;
                } else {
                    start_index++;
                }

            }
        }
    }


    //find duplicate 
    int m = result.size();
    if (m >= 2) {
        for (int i=0;i<result.size();i++) {
            for (int j=i+1;j<result.size();j++) {
                if ( (result[i][0] == result[j][0]) 
                        && (result[i][1] == result[j][1]) 
                        && (result[i][2] == result[j][2]) ) { 
                    j--;
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
    int a[] = {-1,0,1,2,-1,-4};
    vector <int> av(a,a+sizeof(a)/sizeof(a[0]));
    vector<vector <int> > result =  threeSum(av);
    cout << "the total tuples = "  << result.size() << endl;
    print_result(result);
}
