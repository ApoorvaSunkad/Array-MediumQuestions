/*
Given an integer array nums of size n, return the minimum number of 
moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

 

Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments 
two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Example 2:

Input: nums = [1,1,1]
Output: 0
 

Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
The answer is guaranteed to fit in a 32-bit integer.

*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//T.C = O(2N)
//S.C = O(1)

int minMoves(vector<int>& nums) {
    int n = nums.size();

    int cnt = 0;
    int mini = INT_MAX;

    for(int i = 0; i<n; i++){
        if(nums[i]<mini){
            mini = nums[i];
        }
    }

    for(int i = 0; i<n; i++){
        cnt = cnt + nums[i]-mini;
    }
    return cnt;
}