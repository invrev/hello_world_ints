// a5.cpp
// ~~~~~~
// hqn
// my solution to problems from assignment 5

#include <iostream>
#include <vector>
#include <stack>
using namespace std; // bad practice

// returns number of negative integers in the input stack
size_t iterative_num_negatives(stack<int> int_stack)
{
    size_t count=0;
    while (!int_stack.empty()) {
        count += int_stack.top() < 0 ? 1 : 0;
        int_stack.pop();
    }
    return count;
}

// returns number of negative integers in the input stack
size_t recursive_num_negatives(stack<int> int_stack)
{
    if (int_stack.empty())
        return 0;
    size_t k = int_stack.top() < 0 ? 1 : 0;
    int_stack.pop();
    return k + recursive_num_negatives(int_stack);
}

// returns true if a is a sub-vector of b
bool iterative_sub_vector(const vector<int>& a, const vector<int>& b)
{
    size_t i, k;
    for (k=0; k+a.size() < b.size(); ++k) {
        for (i=0; i<a.size(); ++i)
            if (a[i] != b[k+i])
                break;
        if (i == a.size())
            return true;
    }
    return false;
}

/** 
 * returns true if a is a sub-vector of b
 * the recurive solution, you CAN NOT call erase NOR copy many elements of 
 * b into a separate vector. The function prototype is already a hint
 * the initial call is recursive_sub_vector(a, b, 0)
 */
bool recursive_sub_vector(const vector<int>& a, const vector<int>& b, size_t k)
{
    if (k + a.size() >= b.size())
        return false;
    size_t i;
    for (i=0; i<a.size(); ++i)
        if (a[i] != b[k+i])
            break;
    return i == a.size() ? true : recursive_sub_vector(a, b, k+1);
}

/**
 * return true iff there's a subset of elements summing to target
 * the initial call is sum_to_target(vec, target, 0)
 */
bool sum_to_target(const vector<int>& int_vec, int target, size_t k)
{
    if (target == 0)
        return true;
    if (k >= int_vec.size())
        return false;
    return sum_to_target(int_vec, target - int_vec[k], k+1) 
           || sum_to_target(int_vec, target, k+1);
}

// some tests
int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {0, -1, 1, 2, 1, 2, 3, 1, -4, 1, 50};
    int c[] = {1, 2, 3};
    vector<int> va(a, a+4);
    vector<int> vb(b, b+11);
    vector<int> vc(c, c+3);
    cout << iterative_sub_vector(va, vb) << endl;    // NO
    cout << iterative_sub_vector(vc, vb) << endl;    // YES
    cout << recursive_sub_vector(va, vb, 0) << endl; // NO
    cout << recursive_sub_vector(vc, vb, 0) << endl; // YES
    cout << sum_to_target(vb, 45, 0) << endl; // YES
    cout << sum_to_target(vb, 46, 0) << endl; // YES
    cout << sum_to_target(vb, 44, 0) << endl; // NO
    stack<int> st;
    for (size_t i=0; i<vb.size(); i++)
        st.push(vb[i]);
    cout << iterative_num_negatives(st) << endl; // 2
    cout << recursive_num_negatives(st) << endl; // 2
    return 0;
}

