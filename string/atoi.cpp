#include<iostream>
#include<limits.h>
using namespace std;


int atoi (const char *str) {
    int i = 0;
    int sign = 1;
    int ans = 0;
    //Discard leading whitespaces
    while (str[i] == ' ') {
        i++;
    }
    //Get Sign
    if (str[i] == '-' || str[i] == '+') {
        //bool success returns 1
        sign = 1 - 2 * (str[i++] == '-');
        //i++; SAVE ONE LINE CODE
    }
    while (str[i] >= '0' && str[i] <= '9') {
        //Detect overflow
        if (ans > INT_MAX/10 || (ans == INT_MAX/10  && str[i] - '0' > 7 ) ) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        ans = ans * 10  + (str[i++] - '0');
        cout << "and "
    }
    return ans * sign;
}

int atoi1(const char *str) {
    int i = 0;
    int ans = 0;
    bool is_plus = false;
    bool is_minus = false;
    //discard leading whitespaces
    bool is_non_wp = false;
    while (str[i] != '\0') {
        if (str[i] == ' ' ) {
            i++;
            if (is_non_wp) {
                return ans;
            }
            continue;
        } else if(str[i] == '+') {
            if (is_plus == true) {
                return 0;
            }
            is_plus = true;
            is_non_wp = true;
        } else if (str[i] == '-') {
            if (is_minus == true) {
                return 0;
            }
            is_minus = true;
            is_non_wp = true;
        } else if ( (str[i] - 'a') >= 0 && (str[i] - 'a') < 26) {
            break;
        } 
        else {
           ans = ans * 10;
           is_non_wp = true;
           int next_ans = ans + (str[i] - '0');
           if ( (ans < 0 or ans > next_ans) && is_minus == false) {
               return INT_MAX;
           } else if ((ans < 0 or ans > next_ans)  && is_minus == true) {
               return INT_MIN;
           }
           ans = next_ans ;
        }
        i++;
    }
    if (is_plus == is_minus && is_minus == false)  {
        return ans;
    } else if (is_plus == is_minus && is_minus == true) {
        return 0;
    }
    else if (is_minus == true) {
        return -ans;
    } else {
        return ans;
    }
}

int atoi0(const char *str) {
    int i = 0;
    int ans = 0;
    bool is_plus = false;
    bool is_minus = false;
    while (str[i] != '\0') {
        int t = (str[i] - 'a') ;
        if (str[i] == ' ' ) {
            i++;
            continue;
        } else if(str[i] == '+') {
            is_plus = true;
        } else if (str[i] == '-') {
            is_minus = true;
        } else if ( (str[i] - 'a') >= 0 && (str[i] - 'a') < 26) {
            break;
        } 
        else {
            ans = ans * 10;
            int next_ans = ans + (str[i] - '0');
            //ans > 0 : not reliable way to detect the overflow
            if ( (ans < 0 or ans > next_ans) && is_minus == false) {
                return INT_MAX;
            } else if ((ans < 0 or ans > next_ans)  && is_minus == true) {
                return INT_MIN;
            }
            //cout << "The ans = " <<ans  << " next sum = " << next_ans << endl;
            ans = next_ans ;
            
        }
        i++;
    }
    if (is_plus == is_minus && is_minus == false)  {
        return ans;
    } else if (is_plus == is_minus && is_minus == true) {
        return 0;
    }
    else if (is_minus == true) {
        return -ans;
    } else {
        return ans;
    }
}
int main () {
    //How to detect overflow
    //char str[] = " 10522545459";
    char str[] = "+1";
    int res = atoi(str);
    cout << "The result = " << res << endl;
}
