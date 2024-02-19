/*
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the 
container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by 
array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) 
the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

//Brute force: 
//T.C = O(N^2)
//S.C = O(1)

int maxArea(vector<int>& height) {

    int n = height.size();
    int area = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            area = max(area , min(height[i] , height[j])* (j-i)) ;
        }
	}
    return area;
}

//Optimal solution: Using greedy and two pointers algorithm

//T.C = O(N)
//S.C = O(1)
//Video Link: https://youtu.be/-xS3P0dgYEo?si=dWjroo5RTITToOFB

int maxArea(vector<int>& height) {
    int n = height.size();
    int maxi = INT_MIN;

    int start = 0, end = n-1;

    while(start<end){
        int dist = end-start;
        int area = dist * min(height[start],height[end]);
        maxi = max(area,maxi);

        if(height[start]<height[end]){
            start++;
        }else{
            end--;
        }
    }
    return maxi;
}