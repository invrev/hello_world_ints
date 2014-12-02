#include<iostream>
#include<string>
using namespace std;

string convert(string s, int nRows) {

    //1.Compute the initial_offset (2 (nRows -1))
    //2.Compute the next_offset (inc by 2 and rounding by initial_offset)
    //3. j+initial_offset-next_offset : To check the upper bound and determine valid offset in the next row
    //eg. ABCDE,4
    string result_str;
    int total_len =  s.length();
    if (nRows <= 1 || total_len  == 0 ) {
        return s;
    }
    int initial_offset = 2*(nRows - 1);
    int next_offset = 0;
    //cout << "total len " << total_len << endl;
    for (int i=0;i<nRows;i++) {
        //cout << i << ": ";
        for(int j=i;j<total_len ;j+=initial_offset) {
            //cout << j << " " ;
            result_str += s[j];
            //if (next_offset !=0 && j+next_offset < total_len ) {
            if (next_offset !=0 && j+initial_offset-next_offset < total_len ) {
                result_str += s[j+initial_offset-next_offset];
            } 
        }
        next_offset+= 2;
        next_offset %= initial_offset;
        //cout << endl;
    }
    return result_str;
}


int main () {
    string st = "PAYPALISHIRING";
    int nRows = 3;
    string zig_zag = convert(st,nRows);
    cout << zig_zag  << endl;

}
