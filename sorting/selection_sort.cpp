#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &vec,int i,int j) {
       int temp = vec[i];
       vec[i] = vec[j];
       vec[j] = temp;
}
void selection_sort(vector<int> &vec) {
    int t_len = vec.size();
    int i = 0;
    int j = 0;
    int min_index = 0;
    cout << "Before the sort " << endl;
    for (i=0;i<t_len;i++) {
        cout << vec[i] << " ";
    }
    for (i=0;i<t_len;i++) {
        min_index = i;
        for (j= i+1;j<t_len;j++) {
            if(vec[min_index] > vec[j])  {
                min_index = j ;
            }
        }
        swap(vec,min_index,i);
    }

    cout << "\nAfter the selection sort " << endl;
    for (i=0;i<t_len;i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

}

int main () {
    int a[] = {6,5,3,1,8,7,2,4};
    vector<int> vec(a,a+8);
    selection_sort(vec);
     
}
