#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int i = 0 , pos = 0, neg = 1;
    int max_p = 0, max_n = 0;
    if(n%2==0){
        max_p = n/2 + 1;
        max_n = max_p + 1;
    }
    else{
        max_p = n/2 +2;
        max_n = max_p-1;
    }
    vector<int> ans(n);
    while(i<n && pos <= max_p && neg <= max_n){
        if(nums[i] >= 0){
            ans[pos]=nums[i];
            pos = pos+2;
        }
        else{
            ans[neg] = nums[i];
            neg = neg+2;
        }
        i++;
    }

    return ans;
}