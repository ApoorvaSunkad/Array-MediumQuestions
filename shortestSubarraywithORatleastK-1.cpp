/*
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at 
least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Note that [2] is also a special subarray.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 50
0 <= nums[i] <= 50
0 <= k < 64

*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//T.C = O(N^2)
//S.C = O(1)

int minimumSubarrayLength(vector<int>& nums, int k) {

       int n = nums.size();

        int res = INT_MAX;

        for(int i = 0; i<n; i++){
            int ans = 0, len = 0;
            for(int j = i; j<n; j++){
                ans |=nums[j];
                len++;

                if(ans>=k) res = min(res,len);
            }
        }

        return res == INT_MAX ? -1:res;

    }