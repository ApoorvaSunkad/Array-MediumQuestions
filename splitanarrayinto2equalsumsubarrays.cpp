/*
Given an array of integers greater than zero, find if it is possible to split it in 
two subarrays (without reordering the elements), such that the sum of the two subarrays 
is the same. Print the two subarrays.

Examples : 

Input : Arr[] = { 1 , 2 , 3 , 4 , 5 , 5  }
Output :  { 1 2 3 4 } 
          { 5 , 5 }

Input : Arr[] = { 4, 1, 2, 3 }
Output : {4 1}
         {2 3}

Input : Arr[] = { 4, 3, 2, 1}
Output : Not Possible


*/

//Brute force solution
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int findSplitPoint(int arr[], int n) 
{ 
    int leftSum = 0 ; 
  
    // traverse array element 
    for (int i = 0; i < n; i++) 
    { 
        // add current element to left Sum 
        leftSum += arr[i] ; 
  
        // find sum of rest array elements (rightSum) 
        int rightSum = 0 ; 
        for (int j = i+1 ; j < n ; j++ ) 
            rightSum += arr[j] ; 
  
        // split point index 
        if (leftSum == rightSum) 
            return i+1 ; 
    } 
  
    // if it is not possible to split array into 
    // two parts 
    return -1; 
} 
  
// Prints two parts after finding split point using 
// findSplitPoint() 
void printTwoParts(int arr[], int n) 
{ 
    int splitPoint = findSplitPoint(arr, n); 
  
    if (splitPoint == -1 || splitPoint == n ) 
    { 
        cout << "Not Possible" <<endl; 
        return; 
    } 
    for (int i = 0; i < n; i++) 
    { 
        if(splitPoint == i) 
            cout << endl; 
        cout << arr[i] << " " ; 
    } 
} 
  
// driver program 
int main() 
{ 
    int arr[] = {1 , 2 , 3 , 4 , 5 , 5 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printTwoParts(arr, n); 
    return 0; 
} 

/*
An Efficient solution is to first compute the sum of the whole array from left to right. 
Now we traverse array from right and keep track of right sum,
left sum can be computed by subtracting current element from whole sum.

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

// Returns split point. If not possible, then 
// return -1. 
int findSplitPoint(int arr[], int n) 
{ 
    // traverse array element and compute sum 
    // of whole array 
    int leftSum = 0; 
    for (int i = 0 ; i < n ; i++) 
        leftSum += arr[i]; 
  
    // again traverse array and compute right sum 
    // and also check left_sum equal to right 
    // sum or not 
    int rightSum = 0; 
    for (int i=n-1; i >= 0; i--) 
    { 
        // add current element to right_sum 
        rightSum += arr[i]; 
  
        // exclude current element to the left_sum 
        leftSum -=  arr[i] ; 
  
        if (rightSum == leftSum) 
            return i ; 
    } 
  
    // if it is not possible to split array 
    // into two parts. 
    return -1; 
} 
  
// Prints two parts after finding split point using 
// findSplitPoint() 
void printTwoParts(int arr[], int n) 
{ 
    int splitPoint = findSplitPoint(arr, n); 
  
    if (splitPoint == -1 || splitPoint == n ) 
    { 
        cout << "Not Possible" <<endl; 
        return; 
    } 
    for (int i = 0; i < n; i++) 
    { 
        if(splitPoint == i) 
            cout << endl; 
        cout << arr[i] << " " ; 
    } 
} 
  
// driver program 
int main() 
{ 
    int arr[] = {1 , 2 , 3 , 4 , 5 , 5 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printTwoParts(arr, n); 
    return 0; 
} 

//Source GFG