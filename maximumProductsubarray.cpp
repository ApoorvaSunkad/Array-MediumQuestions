/*
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.


*/

//Brute force: Generating all subarrays
//T.C = O(N^3)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
	    // code here
    long long maxi = INT_MIN;
    
    
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            long long prod = 1;
            for(int k = i; k<=j;k++){
                prod = prod*arr[k];
            }
            maxi = max(maxi,prod);
        }
    }
    return maxi;
}


//Better approach:
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
    long long maxi = INT_MIN;
    
    
    for(int i = 0; i<n; i++){
        long long prod = 1;
        for(int j = i; j<n; j++){
            prod = prod*arr[j];
            maxi = max(maxi,prod);
        }
    }
    return maxi;
}

//Optimised approach using prefix and suffix sum
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
	    
    //T.C = O(N)
    //S.C = O(1)
    long long maxi = INT_MIN;
    
    long long prefix = 1, suffix = 1;
    
    for(int i = 0; i<n; i++){
        if(prefix == 0){
            prefix = 1;
        }
        if(suffix == 0){
            suffix = 1;
        }
        
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        
        maxi = max(maxi,max(prefix,suffix));
    }
    
    return maxi;
}