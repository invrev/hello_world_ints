#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Remove the duplicate char w/o extra space
void remove_dup_char (string given_str) {
   cout << " given str = " << given_str << endl;
    int len = given_str.length();
    for (int i=0;i<len;i++) {
        for (int j=i+1;j<len;j++) {
            if (given_str[i] == given_str[j] && given_str[j] != '1') {
                 given_str[j] = '1';
            }
        }
    }
   cout << " the new uniq str = " << given_str << endl;
   int start_index = -1;
   int end_index = 0;
   int current_ptr = 0;
   for (int i=0;i<len;i++) {
       if (given_str [i] == '1' && start_index == -1)  {
            start_index = i; 
            end_index = i;
       } else if (given_str [i] == '1') {
            end_index += 1;
       } else {
            if (start_index != -1) {
                given_str[start_index] = given_str[i];
                start_index += 1;
                end_index += 1;
                given_str[i] = '1';
            }
       }
   }
   cout << " the new uniq str = " << given_str << endl;
}

int main () {
    remove_dup_char ("ABADEAG");
    remove_dup_char ("ABAADEAG");
}
