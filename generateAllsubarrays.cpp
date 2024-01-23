/*
A subarray is a contiguous part of any given array. Basically speaking, an array that 
is present inside another array or a part of that array, but in a continuous manner.

For eg., consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays in this. 
The subarrays are [1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4] and [1,2,3,4]. In general, for an array/string of size n, 
there are n*(n+1)/2 non-empty subarrays/substrings.

*/


//Code for generating all subarrays of an array
//T.C = O(N^2)
//S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4] = {1,2,3,4};
    int n = 4;

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            for(int k = i; k<=j;k++){
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}