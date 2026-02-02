#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int c1 = 0, c2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    int n = nums.size();

    for(int i=0; i<n; i++){
        if(c1 == 0 && nums[i] != el2){
            el1 = nums[i];
            c1 = 1;
        }
        else if(c2 == 0 && nums[i] != el1){
            el2 =nums[i];
            c2 = 1;
        }
        else if(el1 == nums[i]) c1++;
        else if(el2 == nums[i]) c2++;

        else{
            c1--,c2--;
        }
    }
    vector<int> ans;
    c1 = 0, c2 = 0;
    for(int i=0; i<n; i++){
        if(el1 == nums[i]) c1++;
        if(el2 == nums[i]) c2++;
    }
    int freq = n/3 + 1;
    if(c1 >= freq) ans.push_back(el1);
    if(c2 >= freq) ans.push_back(el2);

    return ans;
}


// vector<int> majorityElement(vector<int>& nums) {
//     unordered_map<int,int> mpp;
//     vector<int> ans;
//     int freq = nums.size()/3;
//     for(int i = 0; i< nums.size(); i++){
//         mpp[nums[i]]++;
//         if(mpp[nums[i]] == 3) ans.push_back(nums[i]);
//     }
//     // for(auto it : mpp){
//     //     if(mpp[it.second] > freq){
//     //         ans.push_back(it.first);
//     //         if(ans.size() > 2) return ans;
//     //     }
//     // }

//     return ans;
// }