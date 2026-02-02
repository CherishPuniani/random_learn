#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
   unordered_map<char,int> mpp;
    string ans;
    for(char ch : s){
        mpp[ch]++;
    }

    vector<pair<char,int>> v(mpp.begin(), mpp.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second > b.second; });


    // for(auto it : v ){
    //     ans.append(it.second, it.first);
    // }
    // This is faster because we are not creating any copy of count and ch
    for (auto& [ch, count] : v) {
        ans.append(count, ch);  // repeat `ch` `count` times
    }

    return ans;
}