/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the 
function find3Numbers() which takes the array arr[], the size of the array (n) 
and the sum (X) as inputs and returns True if there exists a triplet in the array 
arr[] which sums up to X and False otherwise.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

*/

//Brute force:
//T.C = O(n^3)  Gives TLE
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X){
    //Your Code Here
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (A[i] + A[j] + A[k] == X) {
                   return true;
                }
            }
        }
    }

    // If no triplet found then return false

    return false;
}


#include<bits/stdc++.h>
using namespace std;

//T.C = O(n^2) sorting takes O(nlogn) but overall T.C is O(n^2)
//S.C = O(1)

bool find3Numbers(int A[], int n, int X){
    
    //Sorting the elements.
    sort(A, A+n);
    
    //Traversing the array elements.
    for (int i=0; i<n-2; i++)
    {
        //Taking two pointers. One at element after ith index and another
        //at the last index.
        int l = i + 1;
        int r = n - 1;
        int x = A[i];
        
        //Using two pointers over the array which helps in checking if
        //the triplet sum is zero.
        while (l < r)
        {
            //If sum of elements at indexes i, l and r is 0, we return true.
            if (x + A[l] + A[r] == X)
            {
                return true;
            }
            //Else if the sum is less than 0, it means we need to increase the
            //sum so we increase the left pointer l.
            else if (x + A[l] + A[r] < X)
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


#include<bits/stdc++.h>
using namespace std;

//T.C = O(n^2)
//S.C = O(N)

bool find3Numbers(int A[], int n, int X){
    //Your Code Here
    for (int i = 0; i < n - 2; i++) 
    {

        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = X - A[i];
        for (int j = i + 1; j < n; j++) 
        {
            if (s.find(curr_sum - A[j]) != s.end()) 
            {
                return true;
            }
            s.insert(A[j]);
        }
    }

    // If we reach here, then no triplet was found
    return false;
}