#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = -1;

        for(int j=n-2; j>=0 ; j--){
            if(nums[j] < nums[j+1]){
                i=j;
                break;
            }
        }
        if(i==-1){
            reverse(nums.begin(), nums.end());
            return;
        }  

        for(int k=n-1; k>i; k--){
            if(nums[k]>nums[i]){
                swap(nums[i], nums[k]);
                break;
            }

        sort(nums.begin()+i+1,nums.end());

        }
}