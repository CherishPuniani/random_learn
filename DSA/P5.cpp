#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if(n == 1) return s;
    int len = 0;
    string ans;

    int i = 1;
    while(i<n){
        int x = 1;
        string temp = "";
        s.push_back(s[i]);
        while((i+x)<=n-1){
            if((i-x) >= 0 && s[i-x] == s[i+x]){
                temp.push_back(s[i+x]);
                temp.insert(temp.begin(), s[i-x]);
                x++;
            }
            if((i+x) < n && s[i] == s[i+x]) {
                temp.push_back(s[i+x]);
                x++;
            }
            else break;
        }
        if(temp.length() > len) ans = temp;
        i++;
    }
    return ans;
}