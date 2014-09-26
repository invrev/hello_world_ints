#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
        vector<string> lst_str;
        int len = strs.size();
        map<string,vector<string> > map_str;
        for (int i=0;i<len ; i++) {
            string temp_str = strs[i];
            sort(temp_str.begin(),temp_str.end());
            if (map_str.find(temp_str) == map_str.end()) {
                vector<string> tmp_vec;
                tmp_vec.push_back(strs[i]);
                map_str[temp_str] = tmp_vec ;
                string org_str= strs[i];
            } else {
                 vector<string> tmp_vec = map_str[temp_str];
                 tmp_vec.push_back(strs[i]);
                map_str[temp_str] = tmp_vec ;
            }
        }
    
      if (map_str.size() != 0) {
          for (map<string,vector<string> >::iterator it=map_str.begin(); it!=map_str.end(); ++it) {
              vector<string> result = it->second;
            if (result.size() > 1) {
                  return result;
              }
           }
      }
      return strs;
    }


int main () {
    vector<string> input;
    input.push_back("dog");
    input.push_back("god");
    input.push_back("bob");
    vector<string> result = anagrams (input);
    int len = result.size();
    for (int i=0;i<len;i++)  {
        cout << " " << result[i] << endl;
    }

}
