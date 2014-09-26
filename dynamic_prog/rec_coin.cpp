#include<iostream>
#include<sstream>
#include<string>

using namespace std;

static int total_number_of_ways = 0;

void get_number_of_ways (int input[] ,int k,int c,int input_sum,int total_sum,string result) {
    //cout << "input_sum = "  << input_sum << " total sum = " << total_sum  << " k = " << k << endl;
    if (input_sum == total_sum || k >= c) {
         if (input_sum == total_sum ) {
             cout << " output " << result << endl;
             total_number_of_ways += 1;
        }
    } else {
        //PROBLEM : always pick up the first coin
        for (int i=(k-1);i>=0;i--){
            input_sum += input[i];
            ostringstream ostr; //output string stream
            ostr << input[i]; //use the string stream just like cout,
            result.append(ostr.str());
            result.append(",");
            if (input_sum <= total_sum) {
                get_number_of_ways (input,k,c,input_sum,total_sum,result);
            } else if (input_sum > total_sum){
                get_number_of_ways (input,k-1,c,0,total_sum,"");
            }
        }
    }
}


int rec_formulation (int input[],int total_sum,int m) {
    //http://www.algorithmist.com/index.php/Coin_Change
    //Prereq : input[] array must be non decreaing  s1<s2<s3..<sm
    //C(N,m) = C(N,m - 1) + C(N - Sm,m) 
    //C(N,m) = 1,N = 0 (one solution -- we have no money, exactly one way to solve the problem - by choosing no coin change, or, more precisely, to choose coin change of 0)
    //C(N,m) = 0,N <= 0 (no solution -- negative sum of money)
    //C(N,m) = 0 N >= 1,m < 0(no solution -- we have money, but no change available)

    if (total_sum == 0)  {
        return 1; 
    } if (total_sum < 0) {
        return 0;
    } 
    if (m < 0) {
        return 0;
    }
    return rec_formulation (input,total_sum,m-1) + rec_formulation (input, total_sum - input[m] ,m) ;
}

int main () {
        int input[] = {1,5,10,25};
        string result = "";
        get_number_of_ways (input,3,4,0,10,result);
        cout << "total # of ways = " << total_number_of_ways << endl;
        cout << "total # of ways = " << rec_formulation(input,10,3)  << endl;
        //cout << "total # of ways = " << rec_formulation(input,9,3)  << endl;

}
