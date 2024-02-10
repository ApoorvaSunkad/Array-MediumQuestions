/*
Given an array of integers arr, a lucky integer is an integer that has a 
frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer 
return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500


*/


#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

int findLucky(vector<int>& arr) {
        
    int maxi = -1;

    int n = arr.size();

    unordered_map<int,int>mp;

    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
    }

    for(auto it:mp){
        if(it.first == it.second){
            maxi = max(maxi,it.first);
        }
    }
    return maxi;
}


//T.C = O(N)
//S.C = O(1) /Constant

#include<bits/stdc++.h>
using namespace std;

int findLucky(vector<int>& arr) {

    int frequency[501]; // Assuming values are between 1 and 500

    for (int i = 0; i<arr.size();i++) {
        frequency[arr[i]]++;
    }

    for (int i = arr.size(); i > 0; i--) {
        if (frequency[i] == i) {
            return i;
        }
    }

    return -1; // No lucky integer found
}