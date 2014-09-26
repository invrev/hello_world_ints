#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string intToRoman(int num) {

    int num_a[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string value_a[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int len = sizeof(num_a)/sizeof(num_a[0]);
    string str_num = "";
    int index = len - 1;
    while (num > 0) {
        int ans = num / num_a [index];
        if (ans == 0)   {
            index -= 1;
        } else {
            num = num - num_a [index];
            //cout <<  " num = "<< num << " index_val = " << num_a [index]<< endl;
            str_num += value_a[index];
        }
    }
    
   return str_num ;

}

int main () {

    string ans = intToRoman (1476);
    cout << "converted int to roman = " << ans  << endl;
}
