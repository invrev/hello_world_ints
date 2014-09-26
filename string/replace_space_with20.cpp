#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//replace all the spaces with %20
void replace_spaces_with_per_twenty(string given_str) {
   
    int len = given_str.length();
    int start = 0;
    int end = 0;
    string replaced_str = "";
    for (int i=0;i<len;i++)  {
        if (given_str[i] == ' ') {
            end = i;
            //consecutive spaces will have the 0 length so return string with 0 length
            string temp_str = given_str.substr(start, (end-start)) ;
            temp_str += "%20";
            replaced_str += temp_str ;
            start = end+1;
        }
    }
    if (end < (len-1)) {
        string temp_str = given_str.substr(start, (len-start)) ;
        replaced_str += temp_str ;
    }

    cout << "the replaced str = " << replaced_str << endl;
}

int main () {

    replace_spaces_with_per_twenty ("Hi  hello test rma");
    replace_spaces_with_per_twenty ("Hi hello test ");
}
