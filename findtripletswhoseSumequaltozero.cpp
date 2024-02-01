/*
Given an array arr[] of n integers. Check whether it contains a triplet that 
sums up to zero. 

Note: Return 1, if there is at least one triplet following the condition else 
return 0.

Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.
Example 2:

Input: n = 3, arr[] = {1, 2, 3}
Output: 0
Explanation: No triplet with zero sum exists. 

Your Task:
You don't need to read input or print anything. Your task is to complete 
the boolean function findTriplets() which takes the array arr[] and the size of 
the array (n) as inputs and print 1 if the function returns true else print 0 if 
the function returns false. 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)


*/

#include<bits/stdc++.h>
using namespaces std;

//T.C = O(N^3)
//S.C = O(1)

bool findTriplets(int arr[], int n){ 
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

//Using two pointer approach
//T.C = O(N^2)
//S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

bool findTriplets(int arr[], int n){
        
    //Sorting the elements.
    sort(arr, arr+n);
    
    //Traversing the array elements.
    for (int i=0; i<n-2; i++)
    {
        //Taking two pointers. One at element after ith index and another
        //at the last index.
        int l = i + 1;
        int r = n - 1;
        int x = arr[i];
        
        //Using two pointers over the array which helps in checking if
        //the triplet sum is zero.
        while (l < r)
        {
            //If sum of elements at indexes i, l and r is 0, we return true.
            if (x + arr[l] + arr[r] == 0)
            {
                return true;
            }
            //Else if the sum is less than 0, it means we need to increase the
            //sum so we increase the left pointer l.
            else if (x + arr[l] + arr[r] < 0)
            {
                l++;
            }
            //Else the sum is more than 0 and we need to decrease the
            //sum so we decrease the right pointer r.
            else
            {
                r--;
            }
        }
    }
    //returning false if no triplet with zero sum is present.
    return false;
}