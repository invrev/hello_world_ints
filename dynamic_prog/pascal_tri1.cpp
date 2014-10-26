#include<iostream>
#include<vector>
using namespace std;

//Basically, I will insert 1 at the head of vector each iteration and calculate result[j] based on result[j] and result[j+1]. For example, if I want to get [1, 3, 3, 1] from [1, 2, 1], I will first insert 1 and get [1, 1, 2, 1]. Then begin with j = 1, result[j] = result[j] + result[j+1]. second position is 1+2=3, third position is 2+1=3 Finally we get [1, 3, 3, 1]

vector<int> getRow(int rowIndex) {
        vector<int> result(1,1);
        for(int i=1;i<=rowIndex;i++){
            result.insert(result.begin(),1);
            for(int j=1;j<result.size()-1;j++){
                result[j] = result[j] + result[j+1];
            }
        }
        return result;
}

int main () {

}
