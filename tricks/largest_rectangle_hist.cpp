#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//2,3,3,4,5,3
//2,1,5,6,2,3
//Linear search using a stack of incomplete subproblems 
//We process the elements in left-to-right order 
//and maintain a stack of information about started but yet unfinished subhistograms. 
//Whenever a new element arrives it is subjected to the following rules. 
//1.If the stack is empty we open a new subproblem by pushing the element onto the stack. 
//Otherwise we compare it to the element on top of the stack. 
//If the new one is greater we again push it. 
//If the new one is equal we skip it. In all these cases, we continue with the next new element. 
//2.If the new one is less, we finish the topmost subproblem 
//by updating the maximum area w.r.t. the element at the top of the stack. 
//Then, we discard the element at the top, and repeat the procedure keeping the current new element. 
//This way, all subproblems are finished until the stack becomes empty, 
//     or its top element is less than or equal to the new element
//     , leading to the actions described above. 
//3.If all elements have been processed, and the stack is not yet empty
//, we finish the remaining subproblems by updating the maximum area w.r.t. to the elements at the top. 
//4.For the update w.r.t. an element, we find the largest rectangle that includes that element. 
//Observe that an update of the maximum area is carried out for all elements except for those skipped. 
//If an element is skipped, however, it has the same largest rectangle as the element on top of the stack at that time that will be updated later. 
//The height of the largest rectangle is, of course, the value of the element. 
//At the time of the update, we know how far the largest rectangle extends to the right of the element
//, because then, for the first time, a new element with smaller height arrived. 
//The information, how far the largest rectangle extends to the left of the element, is available 
//if we store it on the stack, too. 
//We therefore revise the procedure described above. If a new element is pushed immediately, either because the stack is empty or it is greater than the top element of the stack, the largest rectangle containing it extends to the left no farther than the current element. If it is pushed after several elements have been popped off the stack, because it is less than these elements, the largest rectangle containing it extends to the left as far as that of the most recently popped element. 
//Every element is pushed and popped at most once and in every step of the procedure at least one element is pushed or popped. Since the amount of work for the decisions and the update is constant, the complexity of the algorithm is O(n) by amortized analysis.

int largestRectangleArea(vector<int> &height) {
    stack<int> stack_height;
    int max_area = 0;
    int n = height.size();
    int i = 0;
    if (n == 0) {
        return n;
    } else {
        for (;i<n;i++) {
            int current_ht = height[i];
            if (stack_height.empty() || height[stack_height.top()] <= current_ht) {
                //push new subproblem to the stack
                stack_height.push(i);
            } else {
                while (!stack_height.empty() && (current_ht < height[stack_height.top()]) ) {
                    int top_index = stack_height.top();
                    stack_height.pop();
                    int area = 0;
                    //compute the area with popped element
                    if (stack_height.empty()) {
                        area  = height[top_index] * i;
                    } else {
                        //height[top_index] = current height
                        //Width = (current_index - 1) - (Remaining max index from stack)
                        area = height[top_index] * (i-1-stack_height.top());
                    }
                    max_area = max (max_area,area);
                }
                stack_height.push(i);
            }
        }
        while (!stack_height.empty()) {
                int top_index = stack_height.top();
                stack_height.pop();
                int area = 0;
                if (stack_height.empty()) {
                    area  = height[top_index] * i;
                } else {
                    //cout << " ( " << i << "," << stack_height.top()  << ")" << endl;
                    area = height[top_index] * (i-stack_height.top()-1) ;
                }
                max_area = max (max_area,area);
        }
    }
    return max_area;
}

int max_area (vector<int>& hist) {
    int n = hist.size();
    //Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;


}



int main () {
    int a[] = {2,1,5,6,2,3};
    //int a[] = {1000,1000,1000,1000};
    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    int height = largestRectangleArea (av);
    cout << "height = " << height << endl;
    cout << "max_area = "  << max_area (av) << endl;
}
