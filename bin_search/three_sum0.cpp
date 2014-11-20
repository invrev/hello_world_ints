#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Remove the duplicates w/o hashmap
//As array is sorted we can remove the duplicates 

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector <int> > result;
    int size = num.size();
    if (size < 3)  {
        return result;
    }else {
        sort(num.begin(),num.end());
        //(size-3,size-2,size-1)
        for (int i=0;i <= size-3 ;i++) {
            //cout << i << endl; 
            //avoid first duplicate element
            if (i > 0 && num[i-1] == num[i]) {
                //cout << i << endl; 
                continue;
            }
            int a = num[i];
            int start_index = i+1;
            int end_index = size - 1;
            while (start_index < end_index) {
                //cout << "(" << start_index << "," << end_index << ")" << endl;
                vector <int> tmp_vec;
                int b = num[start_index];
                int c = num[end_index];
                if (a+b+c == 0) {
                    tmp_vec.push_back(a);
                    tmp_vec.push_back(b);
                    tmp_vec.push_back(c);
                    result.push_back(tmp_vec);
                    
                    //Avoid 2 duplicated element
                    start_index++;
                    while (start_index < size && num[start_index -1] == num[start_index]) {
                        start_index++;
                    }

                    //Avoid 3rd duplicate element
                    end_index--;
                    while (end_index >= 0 && num[end_index] == num[end_index+1])  {
                        end_index--;
                    }
                 } else if (a+b+c > 0) {
                     end_index--;
                 } else {
                     start_index++;
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
