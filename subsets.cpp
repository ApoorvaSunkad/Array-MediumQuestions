/*
Given an integer array nums of unique elements, return all possible 
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in 
any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))

void printSubset(vector<int>nums, vector<int>output, int index, 
vector<vector<int>>&ans){

    //base case;
    int n = nums.size();
    if(index>=n){
        ans.push_back(output);
        return;
    }

    //Include
    int element = nums[index];
    output.push_back(element);
    printSubset(nums,output,index+1,ans);

    //exclude
    output.pop_back();
    printSubset(nums,output,index+1,ans);

}
public:
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;

    vector<int>output;

    int index = 0;
    printSubset(nums,output,index,ans);
    return ans;
}