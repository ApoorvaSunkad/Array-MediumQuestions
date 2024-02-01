/*
Given an array arr[] of n non-negative integers. 
The task is to find the maximum of j - i (i<=j) subjected to the constraint 
of arr[i] <= arr[j].

Example 1:

Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 
6
Explanation: 
In the given array arr[1] < arr[7]  satisfying 
the required condition (arr[i] <= arr[j])  thus 
giving the maximum difference of j - i which is
6(7-1).
Example 2:

Input:
N = 2
arr[] = {18, 17}
Output: 
0
Explanation: 
We can either take i and j as 0 and 0 
or we cantake 1 and 1 both give the same result 0.
Your Task:
Complete the function maxIndexDiff() which takes array arr and size n, as 
input parameters and returns an integer representing the answer. You don't have 
to print answer or take inputs. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/


//Brute force:
//T.C = O(n^2)
//S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n) {
    // code here
    int maxi = 0;
    
    int ans = 0;
    
    for(int i = 0;i<n;i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]<=arr[j]){
                ans = abs(j-i);
                maxi = max(maxi,ans);
            }
        }
    }
    return maxi;
}


#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)

int maxIndexDiff(int arr[], int n) {
    // code here
    vector <int> v_min(n), v_max(n);
    
    v_min[0] = arr[0];
    v_max[n - 1] = arr[n - 1];
    
    for (int i = 1; i < n; i++) {
        v_min[i] = min(v_min[i - 1], arr[i]);
        v_max[n - i - 1] = max(v_max[n - i], arr[n - i - 1]);
    }
    
    int ans = 0, i = 0, j = 0;
    
    while (i < n && j < n) {
        if (v_min[i] <= v_max[j]) {
            ans = max(ans, j - i);
            j++;
        }else{
            i++;
        }
    }
    return ans;
}