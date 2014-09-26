#include<iostream>
#include<string>
using namespace std;

//Determine wheather number is palindorme or not

//NOTE : conversion into number
//char converted_char = number +  '0';

/*
    Check the palindorme lexicographically.
    1.Convert the number into the string and check the string  
*/
int check_palindrome_ver1 (int number) {
        string number_str = "";
        int temp_number = number ;
        while (number > 0) {
            char converted_number_char = (number % 10) + '0';
            number /= 10;
            //cout << converted_number_char  ;
            number_str += converted_number_char ;
        }
        //cout << number_str << endl;
        int start = 0;
        int end = number_str.length() - 1;
        int is_palindrome = 1;
        while (start < end) {
            if (number_str[start] != number_str[end])  {
                is_palindrome = 0;
                break;
            }
            start += 1;
            end -= 1;
        }
        if (is_palindrome == 1) {
            cout << "Lexicographiclly  " << temp_number << " is palindrome." << endl;
        } else {
            cout << "Lexicographiclly  " << temp_number << " is not palindrome." << endl;
        }

} 


/*
    1.Compute the other number by reversing the input number
    2.Compare to numbers
*/ 
int check_palindrome_ver2 (int num)  {
    int temp_num = num;
    int rev_num = 0;
    int digit = 0;
    while (temp_num > 0) {
        digit = temp_num % 10; 
        //uplift the rev_num by 10 and add the digit
        rev_num = rev_num * 10 + digit;
        temp_num = temp_num / 10;
    }
    if (num == rev_num) {
        cout << "The number = " << num << " is a palindrome."  << endl;
    } else {
        cout << "The number = " << num << " is not palindrome."  << endl;
    }

}

void check_palindrome_test (int number) {
   
    int temp_number = number ;
    int factor = 1;
    int new_number = 0;    
    temp_number =  temp_number - factor;
    while (temp_number > 0) {
        factor *= 10;
        temp_number =  temp_number - factor;
    }
    factor = (factor/10);
    temp_number = number ;
    //cout << "factor = " << factor << endl;
    
    while (number > 0) {
        int rem =  number % 10;
        number = number / 10;
        new_number += (rem * factor);
        factor = factor /10;
    }

    //cout << "new_number = " <<  new_number << endl;
    if ( temp_number == new_number) {
        cout << "Number = " << new_number << " is palindrome." << endl;
    } else {
        cout << "Number = " << new_number << " is not palindrome." << endl;
    }
}

int main() {
    check_palindrome_test(14444);
    check_palindrome_ver1 (14444);
    check_palindrome_ver2 (14444) ;
}
