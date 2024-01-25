/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some 
characters (can be none) deleted without changing the relative order of the remaining 
characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.


*/

//This below solution is an extreme naive/brute force solution that came up to my mind
//while solving this question but the efficient solution to this problem is 
//applying "Dynamic programming concept".

/*

It's important to note that the below code has an exponential 
time complexity, making it inefficient for larger inputs.
*/

int longestCommonSubsequence(string text1, string text2) {
    //T.C = O(2^m * 2^n) exponential
    //S.C = O(2^m + 2^n)

    int m = text1.length();
    int n = text2.length();

    set<string> s1;
    set<string> s2;
    int maxi = 0;

    //generating all the possible subsequences of text1
    for(int i = 1; i<(1<<m);i++){ // T.C = O(2^M)
        string sub = "";
        for(int j = 0; j<m; j++){  //T.C = O(M)
            if(i&(1<<j)){
                sub+=text1[j];
            }
        }
        s1.insert(sub);
    }

        //generating all the possible subsequences of text2
        
    for(int i = 1; i<(1<<n);i++){ // T.C = O(2^N)
        string sub = "";
        for(int j = 0; j<n; j++){  //T.C = O(N)
            if(i&(1<<j)){
                sub+=text2[j];
            }
        }
        s2.insert(sub);
    }

    for(auto it = s1.begin(); it!=s1.end(); it++){
        string str = (*it);
        if(s2.find(str)!=s2.end()){
            int len = str.length();
            maxi = max(maxi,len);
        }
    }
    return maxi;
}