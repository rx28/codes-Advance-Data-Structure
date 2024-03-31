#include <iostream>
#include <string>
#include <unordered_set>
#include<vector>
#include<algorithm>
#include <cmath>
#include <stack>
using namespace std;
int main(){
    vector<int>nums{1,2,3,4};
    int n = nums.size();
    vector<int> result(n, -1);  // Initialize result vector with -1, assuming no greater element initially
    stack<int> st;  // Stack to store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            // If the current element is greater than the element at the top of the stack,
            // update the result for the element at the top of the stack.
            result[st.top()] = nums[i];
            st.pop();  // Pop the index from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }

    return result;
}