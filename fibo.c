#include<iostream>
using namespace std;


static int generate_n_fibo_cnt = 0;
static int generate_n_fibo_cnt_mem = 0;

int generate_n_fibo_with_mem (int no,int result_arr[]) {
    cout << "call # " << ++generate_n_fibo_cnt_mem << endl;
    if (no < 0) {
        return 0;
    } else if (result_arr[no] != -1) {
        //cout << " found in cache # = "<< no << " with result = " << result_arr[no] << endl;
        return result_arr[no];
    } else {
        result_arr[no] = generate_n_fibo_with_mem (no - 1,result_arr) + generate_n_fibo_with_mem (no - 2,result_arr) ;
    }

}

int generate_n_fibo (int number) {
    cout << "call # " << ++generate_n_fibo_cnt << endl;
    if (number == 0 || number == 1) {
        return number ;
    } else if (number < 0){
        return 0;
    } else {
        return generate_n_fibo (number - 1) + generate_n_fibo (number - 2);
    }
}


int main () {
    //cout << "2nd fib = "<< generate_n_fibo (2) << endl;
    //cout << "3rd fib = "<< generate_n_fibo (3) << endl;
    cout << "4th fib = "<< generate_n_fibo (10) << endl;
    //cout << "5th fib = "<< generate_n_fibo (5) << endl;
    //cout << "4th fib = "<< generate_n_fibo (10) << endl;

    int result_arr [11];
    for (int i=0;i<=10;i++) {
        result_arr [i] = -1;
    }
    result_arr [0] = 0;
    result_arr [1] = 1;
    cout << generate_n_fibo_with_mem (10,result_arr) << endl;

}
