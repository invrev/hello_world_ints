#include<stdio.h>

//TWO sum on the sorted array
//O(log n)
int do_binsearch (int num[],int start,int end,int key) {
    int mid = (start + end)/2;
    if (start <= end)  {
        if (num[mid] == key)  {
            return mid;
        } else if ( num[mid] < key ) {
            do_binsearch (num,mid+1,end,key);
        }else {
            do_binsearch (num,start,mid-1,key);
        }
    }

    return -1;
}

void get_index_with_bin_search(int num[],int sum,int len) {
   int start = 0;
   int end = len - 1;
   int found_ = 0;
   int other_index = -1;
   int temp_sum  = 0;
   while (start != end) {
       temp_sum = sum - num[start];
       other_index = do_binsearch (num,(start+1),end,temp_sum);
       if (other_index != -1) {
          found_ = 1;
          break;
       }
       start += 1;
   }
   if (found_ == 1)  {
       printf ("Found_ the sum = %d at index %d , %d \n",sum,start,other_index);
   } else {
       printf("Not found sum");
   }

}



//O(n)
void get_index_for_two_sum(int num[],int sum,int len) {
   int start= 0;
   int end = len - 1;
   int found_ = 0;
   while (start != end) {
       int temp_sum = 0;
       temp_sum = (num[start]  + num [end]) ;
       if (sum > temp_sum) {
           start += 1;
       }else if (sum < temp_sum) {
           end -= 1;
       } else {
           found_  = 1;
           break; 
       }
   }
   if (found_ == 1)  {
       printf ("Found_ the sum = %d at index %d , %d \n",sum,start,end);
   } else {
       printf("Not found sum");
   }
}


int main() {
    int num[] = {1,2,5,69,12,45,75};
    int sum = 114;
    get_index_for_two_sum (num,sum,7);
    get_index_with_bin_search (num,sum,7);
}
