#include<iostream>
#include<string>
#include<vector>
using namespace std;

//255122344
//255.122.34.4
//k = depth
void enum_ips (string& input,int k,int start,string result,vector<string> &sv) {
   
    //Weed out the extra result 
    if (k == 4) {
        //Remove the last dot
        if (input.length() == (result.length() - 4 ) ) {
            result.pop_back();
            cout <<  result << endl;
        } 
        return;
    } else {
        //FFT : put the dot at every place and upper limit is 3 places
        int num = 0;
        for (int i=start;i<=start+2;i++) {
            //Idea to keep track of numerical value on the STACK FRAME
            num = num * 10 + input[i] - '0';
            if (num <= 255)  {
                result += input[i];
                enum_ips (input,k+1,i+1,result+".",sv);
            }
            if (num == 0) {
                break;
            }
        }
    }
}



int main () {

    string input = "255122344";
    int k = 0;
    int start = 0;
    string result;
    vector<string> sv;
    enum_ips (input,k,start,result,sv);

}
