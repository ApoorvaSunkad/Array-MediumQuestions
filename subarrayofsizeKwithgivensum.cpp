/*
Given an array arr[], an integer K and a Sum. The task is to check 
if there exists any subarray with K elements whose sum is equal to the given sum. 
If any of the subarray with size K has the sum equal to the given sum then print 
YES otherwise print NO.

Examples: 

Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 4, sum = 18
Output: YES
Subarray = {4, 2, 10, 2}

Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 3, sum = 6
Output: YES

*/

//A simple solution is to use nested loops, where we check every subarray of size k.

#include <bits/stdc++.h>
using namespace std;

void subarraySumExists(vector<int>& arr, int k, int targetSum) {
    int n = arr.size();

    for (int i = 0; i <= n; ++i) {
        int currentSum = 0;
        for (int j = i; j < i + k; ++j) {
            currentSum += arr[j];
        }

        if (currentSum == targetSum) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    // Example usage:
    vector<int> arr1 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k1 = 4, sum1 = 18;
    subarraySumExists(arr1, k1, sum1);  // Output: YES

    vector<int> arr2 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k2 = 3, sum2 = 6;
    subarraySumExists(arr2, k2, sum2);  // Output: YES

    return 0;
}