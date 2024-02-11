/*
Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e 
first element should be max value, second should be min value, third should be second max, fourth should be 
second min and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

Example 1:

Input:
n = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.
Example 2:

Input:
n = 11
arr[]={10,20,30,40,50,60,70,80,90,100,110}
Output:110 10 100 20 90 30 80 40 70 50 60
Explanation: Max element = 110, min = 10, 
second max = 100, second min = 20, and 
so on... Modified array is : 
110 10 100 20 90 30 80 40 70 50 60.
Your Task:
The task is to complete the function rearrange() which rearranges elements as explained above. 
Printing of the modified array will be handled by driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 10^6
1 <= arr[i] <= 10^7

*/

//Brute force
//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n) { 
  
    vector<long long> v;
    
    int i = 0, j = n-1;
    
    while(i<=j){
        v.push_back(arr[j]);
        v.push_back(arr[i]);
        i++;
        j--;
    }
    
    for(int i = 0; i<n; i++){
        arr[i] = v[i];
    }
    	 
}


//Explaination

/*But the main thing why this question is set to medium is we should not use any 
extra space
this should be done in O(1) space complexity.
*/


/*
So here comes a important formula => (dividend = Quotient*divisor + remainder)

Dividend / Divisor = Quotient
Dividend % Divisor = Remainder


for this question we will take a MAXINDEX = (sizeofarray-1) i.e (n-1)
                                 MININDEX = 0

We will declare a maximum number which is max = arr[n-1]+1  

then our modified array value which is in-place will be

arr[i] = (arr[maxIndex] % max) * max + arr[i];
arr[i] = (arr[minIndex] % max) * max + arr[i];

finally we will divide the arr[i] by maximum value
traverse the array and divide by max value

*/

//Video by: Prince aggarwal - youtube channel name - Hello World

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

void rearrange(long long *arr, int n) { 

    int maxIndex = n-1;
    int minIndex = 0;
    
    int max = arr[n-1]+1;
    
    for(int i = 0; i<n; i++){
        if(i%2 == 0){
            arr[i] = (arr[maxIndex]%max)*max + arr[i];
            maxIndex--;
        }else{
            arr[i] = (arr[minIndex]%max)*max + arr[i];
            minIndex++;
        }
    }
        
    for(int i = 0; i<n; i++){
        arr[i] = arr[i]/max;
    }
}