/*
Given a binary array nums, return the maximum length of a contiguous subarray 
with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal 
number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray 
with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

// Imp: This problem is similar to count subarray sum equal to 0.

//Brute force:
//T.C = O(N^3)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int cnt0 = 0, cnt1 = 0;
                for(int k = i; k<=j; k++){
                    if(nums[k]==0){
                        cnt0++;
                    }else{
                        cnt1++;
                    }
                }
                int maxCnt = 0;
                if(cnt0 == cnt1){
                    for(int m = i; m<=j; m++){
                        maxCnt++;
                        ans = max(maxCnt,ans);
                    }
                }
            }
        }
        return ans;
}

//A little bit optimised
//T.C = O(N^2)
//S.C = O(1)
int findMaxLength(vector<int>& nums) {
        int maxlen = 0;
        for (int start = 0; start < nums.length; start++) {
            int zeroes = 0, ones = 0;
            for (int end = start; end < nums.length; end++) {
                if (nums[end] == 0) {
                    zeroes++;
                } else {
                    ones++;
                }
                if (zeroes == ones) {
                    maxlen = max(maxlen, end - start + 1);
                }
            }
        }
        return maxlen;
}

//Optimised solution

int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                nums[i] = -1;
            }
        }

        int sum = 0, maxlen = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];

            if(sum == 0){
                maxlen = max(maxlen, i+1);
            }
            if(mp.find(sum)!=mp.end()){
                maxlen = max(maxlen, i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return maxlen;
}