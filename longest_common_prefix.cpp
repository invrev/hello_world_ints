#include<iostream>
#include<string>
#include<vector>
using namespace std;

//O(n2)
string longestCommonPrefix(vector<string>& strs) {
    //strs == NULL ||
    if ( strs.size() == 0) {
        return "";
    }
    //Iterate over the first string
    for (int i = 0; i < strs[0].length(); i++) {
        char c = strs[0][i];
        //Iterate over remaining strings
        for (int j = 1; j < strs.size() ; j ++) {
            //If find 1.size limit 
           // 2.first non matching char / size limit 
            if (i == strs[j].size() || strs[j][i] != c) { 
                return strs[0].substr(0, i); 
            }
        }
    }
    return strs[0];
}


//Check each char each time
 string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0) return "";
        bool done=false; 
        int pos=-1;
        while(!done)
        {
            if(++pos==strs[0].size()) break;
            char c=strs[0][pos];
            for(int i=1; i<strs.size();i++)
            {
                if(strs[i].size()<=pos || strs[i][pos] != c)
                {
                    done=true;
                    break;
                }
            }
        }
        return pos==0?"":strs[0].substr(0,pos);
    }

int main () {

}
