//Given a string, generate all possible subsequences.

// String str = "abc" here the size of string is 3 so the possible
//substrings are (2^n-1)

#include<bits/stdc++.h>
using namespace std;

//T.C = O(2^N * N)
//S.C = O(1)

int main(){
    string str1 = "abcde";
    string str2 = "ace";
    vector<string> v1;
    vector<string> v2;
    int n1 = 5;
    int n2 = 3;
    //int maxi = INT_MIN;

    for(int i = 1; i<(1<<n1);i++){ // T.C = O(2^N)
        string sub1 = "";
        for(int j = 0; j<n1; j++){  //T.C = O(N)
            if(i&(1<<j)){
                sub1+=str1[j];
            }
        }
        v1.push_back(sub1);
    }

      for(int i = 1; i<(1<<n2);i++){ // T.C = O(2^N)
        string sub2 = "";
        for(int j = 0; j<n2; j++){  //T.C = O(N)
            if(i&(1<<j)){
                sub2+=str2[j];
            }
        }
        v2.push_back(sub2);
    }

    for(int i = 0; i<v1.size(); i++){

        //This commented code gives the length of largest subsequence
        // string s = v[i];
        // int len = s.length();
        // if(len>maxi){
        //     maxi = max(maxi,len);
        // }
        cout << v1[i] << " ";
    }

    cout << endl;

    for(int i = 0; i<v2.size(); i++){
        cout << v2[i] << " ";
    }
}