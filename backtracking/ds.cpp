#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main () {
   map< vector<int> ,int>  test_map;
   int a[] = {1,2,3};
   vector<int> test_vec (a,a+sizeof(a)/sizeof(a[0]));
   int b[] = {2,3,4};
   vector<int> test_vec1 (b,b+sizeof(b)/sizeof(b[0]));
   test_map.insert( pair<vector<int> ,int>(test_vec,1) ); 
   map<vector<int> ,int> :: iterator it = test_map.begin();
   while (it != test_map.end() ) {
       cout << "value = " << it->second << endl;
       it++;
   }
   map<vector<int>,int > :: iterator find_it = test_map.find(test_vec);
   if (find_it != test_map.end() ) {
       cout << "element found " << endl;
   }

   find_it = test_map.find(test_vec1);
   if (find_it != test_map.end() ) {
       cout << "element found " << endl;
   } else {
       cout << "element not found " << endl;
   }

}
