#include<stdio.h>

int check_palindrome(char *input_str,int start_pos,int len) {
    int last_pos = len - 1;
    while (start_pos < last_pos ) {
        if (input_str[start_pos] != input_str[last_pos] ) {
            return 0;
        }
        start_pos += 1;
        last_pos -= 1;
    }
    return 1;
}

int iterate_palindrome (char *input_str,int start,int len,int interval) {
    int i = 0;
    int step_size = interval;
    for (i = start;i<len;i++) {
        if (len >= (i+step_size)) {
            int result = check_palindrome (input_str,i,i+interval);
            if ( result == 1) {
                interval = step_size;
            }
        }
        step_size += 1;
        //printf ("step_size = %d and i = %d and len =%d\n",step_size,i,interval);
    }
    return interval;
}


void print_longest_palindrome (char *input_str,int start,int interval) {
    int end = start + interval ;
    int i = 0;
    for (i=start;i<=end;i++) {
        printf("%c",input_str[i]);
    }
    printf("\n");
}

int get_largest_palindrome (char *input_str,int len) {
    int larget_interval = 0;
    int i = 0;
    int start_pos = -1;
    for (i=0;i< len;i++) {
        int interval_len = iterate_palindrome (input_str,i,len,larget_interval);
        if (interval_len > larget_interval) {
            larget_interval = interval_len;
            start_pos = i;
        }
    }
    printf("start_pos = %d and interval= %d\n",start_pos,larget_interval);
    if (start_pos != -1) {
        print_longest_palindrome (input_str,start_pos,larget_interval);
    }
    return larget_interval;
}

int main () {
    //char input_str[] = "ABA";
    char input_str[] = "ABADEA";
    get_largest_palindrome (input_str,6);
    //char input_str[] = "AB";
    int result = check_palindrome (input_str,0,3);
    if ( result == 1) {
        printf ("The string = %s is palindrome\n",input_str);
    } else {
        printf ("The string = %s is not palindrome\n",input_str);
    }

}
