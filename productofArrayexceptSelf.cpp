/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of 
all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? 
(The output array does not count as extra space for space complexity analysis.)

*/

//Extreme Brute force:
#include<bits/stdc++.h>
using namespace std;

//T.C = O(N^2)
//S.C = O(N)

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> v;

    for(int i = 0; i<nums.size();i++){
        int prod = 1;
        for(int j = 0; j<nums.size();j++){
            if(i!=j){
                prod=prod*nums[j];
            }
        }
        v.push_back(prod);
    }
    return v;
}

//Optimising it:
//T.C = O(N)
//S.C = O(N)

/*
But this solution will fail if we have 0 in the input array because anything we divide by zero
will give zero by division error hence will end up in runtime error
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> v(n);

    int prod = 1;
    for(int i = 0; i<n;i++){
        prod = prod*nums[i];
    }

    for(int i = 0; i<n;i++){
        v[i] = prod/nums[i];
    }
    return v;
}

//Optimising it again
//Using prefix sum and suffix concept
//T.C = O(3N)
//S.C = O(2N)

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<int> pre(n,1),suff(n,1);
    vector<int> ans(n);

    for(int i = 1; i<n; i++){
        pre[i] = pre[i-1] * nums[i-1];
    }

    for(int i = n-2; i>=0; i--){
        suff[i] = suff[i+1] * nums[i+1];
    }

    for(int i = 0; i<n; i++){
        ans[i] = pre[i]*suff[i];
    }

    return ans;
}

//Further optimising it
//T.C = O(2N)
//S.C = O(N) or O(1) if storing and returning output is not considered in S.C

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n,1);

    for(int i = 1; i<n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffProd = 1;
    for(int i = n-2; i>=0; i--){

        suffProd = suffProd*nums[i+1];

        ans[i] = ans[i]*suffProd;
    }

    return ans;
}