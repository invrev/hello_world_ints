#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool is_valid(string str) {
    //value of subnet must be in range 0 to 255
    if (str.size() == 3 && stoi(str)>255) {
        return false;
    }
    //00X is invalid
    if (str.size() == 3 && str[0] == '0') {
        return false;
    }
    //0X is invalid
    if (str.size()==2 && str[0]=='0') {
        return false;
    }
    return true;
}


void restore_ip_rec(string ip,string traversed, vector<string>& solutions, int count) {
    //if (count < 0)  {
    //    //prune
    //    return;
    //}
    if (count == 0)  {
        //add
        if (ip.empty()) {
            //TO AVOID ip : "010010" , ["0.1.0.0","0.10.0.1","0.10.0.10","0.100.1.0"]
            //expected ["0.10.0.10","0.100.1.0"]
            solutions.push_back(traversed); 
        }
    } else {
        for (int i=1; i<4; i++) {
            if (ip.size() >= i && is_valid(ip.substr(0,i)) ) {
            //for the last subnet (subnetLength = 1)  '.' shouldn't be appended
            if (count == 1 ){
                restore_ip_rec(ip.substr(i),traversed+ip.substr(0,i),solutions,count-1);
            } else {
                //for the subnets 2,3,4 the first three subnets '.' need to be appended.
                restore_ip_rec(ip.substr(i),traversed+ip.substr(0,i)+".",solutions,count-1);
            }
            }
        }
    }
}


vector<string> restoreIpAddresses(string s) {
    vector<string> solutions;
    restore_ip_rec(s,"",solutions,4);
    return solutions;
}




int main () {

}
