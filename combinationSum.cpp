/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers 
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that 
sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

*/

//Using recursion and backtracking
//T.C = O(2^t * k) where the is the target and k os the length of array
//S.C = cannot be determined (length of array * x combinations)

class Solution {
    void findCombination(int index,int target,vector<int>candidates,vector<vector<int>>&ans, vector<int>&sum){
        // index = 0;
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(sum);
            }
            return;
        }

        //Pick up the element
        if(candidates[index]<=target){
            sum.push_back(candidates[index]);
            findCombination(index,target-candidates[index],candidates,ans,sum);
            sum.pop_back();
        }
        //Not pick
        findCombination(index+1,target,candidates,ans,sum);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;

        vector<int>sum;

        //int index = 0;

        //Function
        findCombination(0,target,candidates,ans,sum);
        return ans;
    }
};