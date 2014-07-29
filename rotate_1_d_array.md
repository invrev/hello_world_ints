ROTATE 1-D ARRAY

From Leetcode
“Rotate a one-dimensional array of n elements to the right by k steps. 
For instance, with n=7 and k=3, the array {a, b, c, d, e, f, g} is rotated to {e, f, g, a, b, c, d}.”

Basic idea :
Imagine a roulette wheel and one started from a point called origin eventually 
come to the same origin by traversing constant amount of distance say ‘K’.
assume array is close bound data structure. (in c you can access any array location and can get garbage value)
    
    I.W/O in-place (Naive solution)
    1.Copy all the elements in an array in a temp array.    O(n) space, O(n) time
    2.Decide position of each element as 
        next_pos = ( current_pos + (K) ) mod array_size 
    3.Again copy all the elements from temp array to original array. O(n) time
    
    II.In place with iteration (Modification in I) (O(n) time + O(C) space)
    1.instead of using the extra array use 2 temp variables to keep track 
    of what needs to be replaced and by which value
    In short,we use cache mechanism to store the recent replaced value.
    
    III.In place with Recursion
    1.Reverse string from 0 to n-1 O(n-1)
    2.Reverse string from 0 to k-1 O(k-1)
    3.Reverse string from k to n-1  O(n-1-k)
    (Time complexity of recursion = # of recursion calls)

It reminds Josephus problems,Floyd's cycle-finding algorithm


