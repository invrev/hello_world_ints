#include<iostream>
using namespace std;


int kmpsearch (char *a) {
   int i = -1;
   sm : i++;
   s0 : if (a[i] != '1') goto sm; i++;
   s1 : if (a[i] != '0') goto s0; i++;
   s2 : if (a[i] != '1') goto s0; i++;
   s3 : if (a[i] != '0') goto s1; i++;
   return i-8;
}

int main () {
    
}


