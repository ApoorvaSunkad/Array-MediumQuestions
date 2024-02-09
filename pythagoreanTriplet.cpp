/*
Given an array arr of n integers, write a function that returns true if there 
is a triplet (a, b, c) from the array (where a, b, and c are on different 
indexes) that satisfies a2 + b2 = c2, otherwise return false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
Example 2:

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No
Explanation: No such triplet possible.

Your Task:
You don't have to take any input or print any thing. You have to complete 
the function checkTriplet() which takes an array arr, a single integer n, as 
input parameters and returns boolean denoting answer to the problem.
Note: The driver will print "Yes" or "No" instead of corresponding to the 
boolean value returned.

Expected Time Complexity: O(n+max(Arr[i])2)
Expected Auxiliary Space: O(max(Arr[i]))


*/

#include<bits/stdc++.h>
using namespace std;

//Brute force
//T.C = O(N^3)
//S.C = O(1)

bool checkTriplet(int arr[], int n){

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // Calculate square of array elements
                int x = arr[i] * arr[i],
                    y = arr[j] * arr[j],
                    z = arr[k] * arr[k];

                if (x == y + z || y == x + z || z == x + y)
                    return true;
            }
        }
    }

    // If we reach here, no triplet found
    return false;
}

//Brute optimised
//T.C = O(N) + O(NLOGN)
//S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

bool checkTriplet(int arr[], int n) {
	    
    for(int i = 0; i<n; i++){
        arr[i] = arr[i]*arr[i];
    }
    
    sort(arr,arr+n);
    
    for(int i = n - 1; i >= 0; i--) {
        int left = 0;
        int right = i - 1;

        while(left < right) {
        // Check if the triplet satisfies the Pythagorean condition
            if(arr[left] + arr[right] == arr[i]) {
                return true;
            } else if(arr[left] + arr[right] < arr[i]) {
            // If the sum is less than v[i], move left pointer to the right
                left++;
            } else {
            // If the sum is greater than v[i], move right pointer to the left
                right--;
            }
        }
    }

    // If no triplet is found, return false
    return false;
}


//Optimised solution
//T.C = O(n+maxEle(Arr[i])^2)
//S.C = O(maxEle)


#include<bits/stdc++.h>
using namespace std;

bool checkTriplet(int arr[], int n) {

    int maxEle = arr[0];
    //Finding max element in the array
    for(int i = 0; i<n; i++){
        maxEle = max(arr[i],maxEle);
    }
    
    //Make an array till max-Ele
    int countArr[maxEle+1];
    
    for(int i = 0;i<maxEle;i++){
        countArr[i] = 0;
    }
    
    for(int i = 0; i<n; i++){
        countArr[arr[i]]++;
    }
    
    for(int i = 1; i<=maxEle; i++){
        for(int j = i+1; j<=maxEle;j++){
            if(countArr[i]>0 && countArr[j]>0){
                int ans1 = i*i;
                int ans2 = j*j;
                
                int res = ans1+ans2;
                int sqroot = sqrt(res);
                
                if((sqroot*sqroot)==res && sqroot<=maxEle && countArr[sqroot]>0){
                    return true;
                }
            }
        }
    }
    return false;
}