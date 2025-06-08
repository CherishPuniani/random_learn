#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> set;
    for(int i; i<n; i++){
        set.insert(nums[i]);
    }
    int longest = 1;

    for( auto it : set){
        if(set.find(it-1) == set.end()){
            int cnt = 1;
            int x = it;
            while(set.find(x+1) != set.end()){
                cnt ++;
                x++; 
            }
            longest = max(longest,cnt);
        }
        
    }
    return longest;
}