/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1

*/

//Using sorting:
//T.C = O(NLOGN)
//S.C = O(1)

int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int mini = 1;

        for(int i = 0; i<n;i++){
            if(nums[i]<=0){
                continue;
            }
            if (nums[i] > mini) {
                return mini;
            }
            if(nums[i]==mini){
                mini++;
            }
        }
        return mini;
}


//Using Hashmap
//T.C = O(N)
//S.C = O(N)

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int,int> mp;

    for(int i = 0; i<n; i++){
        mp[nums[i]]++;
    }

    int mini = 1;
    for(int i = 1; i<=n+1; i++){
        if(mp.find(i)==mp.end()){
            mini = i;
            break;
        }
    }
    return mini;
}

//Optimised solution
//T.C = O(N)
//S.C = O(1)

class Solution {
    void swapp(vector<int>&nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while(i<n){
            //is element at the correct place
            if(nums[i]==i+1 || nums[i]<=0||nums[i] > n){
                i++;
            }
            else if(nums[i]==nums[nums[i]-1]){
                i++;
            }
            else{
                swapp(nums,i,nums[i]-1);
            }
            
        }

        int index = 0;
        while(index<n){
            if(nums[index]!=index+1){
                return index+1;
            }
            index++;
        }
        return n+1;
    }

};