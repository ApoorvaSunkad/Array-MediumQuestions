/*
Given an array of positive integers arr, return the sum of all possible odd-length 
subarrays of arr.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000
 

*/
//Brute force: 
//T.C = O(N^3)
//S.C = O(1)

int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();

    int sum = 0;

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if((j-i+1)%2 == 1){
                int currentSum = 0;
                for(int k = i;k<j+1;k++){
                    currentSum+=arr[k];
                }
                sum+=currentSum;
            }
        }
    }
    return sum;
}

//Better approach: 
//T.C = O(N^2)
//S.C = O(1)

int sumOddLengthSubarrays(vector<int>& arr) {
    int n = int(arr.size()), answer = 0;

    
    for (int left = 0; left < n; ++left) {
        int currentSum = 0; 
        for (int right = left; right < n; ++right) {
            currentSum += arr[right];
            answer += (right - left + 1) % 2 == 1 ? currentSum : 0;
        }
    }
    return answer;
}