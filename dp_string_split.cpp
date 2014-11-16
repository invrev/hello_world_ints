#include<iostream>
#include<string>
using namespace std;


void string_split0(string& s) {
    int n = s.length();
    for (int m=0 ;m<n;m++) {
        for (int d=0;d<n-1;d++) {
            for (int i=1;i<n-d;i++) {
                int j = i+ d;
                for (int k=i;k<=j;k++) {
                    cout << "(" << j << "," << k << ")" << endl;
                }
            }
        }
    }
}


//void string_split(string& s,int start,int end,int k,int n) {
//    
//    if (k == n || k == 0) {
//       return; 
//    }
//    for (int i=1;i<n;i++) {
//        string_split (s,i-1,k,k,n);
//        string_split (s,k+1,end,k,n);
//        cout << "( " << start  << "," << k  << "," << end << " )" << endl;
//    }
//}

void string_split (string &s) {

    int len = s.length();
    if (len == 0) {
        return;
    }
    for (int k=1;k<=len;k++) {
        string first_half = s.substr(0,k);
        string second_half = s.substr(k);
        cout << "B(" << first_half <<"," << second_half <<")" << endl;
        string_split (second_half);
        cout << "(" << first_half <<"," << second_half <<")" << endl;
    }
    

}



int main () {

    //char name[] = {'s','t','a','\0','t','a','t','\0' };
    //cout << name << endl;
    string st = "safaricarrbi";
    string_split (st);
    //string_split (st,0,st.length(),1,st.length();
}
