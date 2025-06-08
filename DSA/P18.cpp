#include<bits/stdc++.h>
using namespace std;

// Take care of possibility of overflow
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i=0;  i<n; i++){
        int req_sum = target - nums[i];
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            
            int mid = j+1;
            int k = n-1;
            while(mid  < k){
                long long sum = (long long)nums[j] + nums[mid] + nums[k];
                if(sum > req_sum){
                    k--;
                }
                else if(sum < req_sum){
                    mid++;
                }
                else{
                    vector<int> temp = {nums[i], nums[j],nums[mid], nums[k]};
                    ans.push_back(temp);
                    mid++;
                    k--;
                    while(mid<k && nums[mid] == nums[mid-1]) mid++;
                    while(mid< k && nums[k] == nums[k+1]) k--;
                }
            }
        }
    }
    return ans;
}
