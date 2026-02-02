#include<bits/stdc++.h>
using namespace std;

// my logic is it should not increase twice when we are looping through the array
// bool check(vector<int>& nums) {
//     int count_wrongs = 0;
//         for(int i=0; i<nums.size(); i++){
//             if(i == nums.size()-1){
//                 if(nums[0]<nums[i]) count_wrongs++;
//             }
//             else{if(nums[i+1]<nums[i]) count_wrongs++;} 
//             if(count_wrongs == 2) return false;
//         }
//         return true;
//     }

// This is just cleened up version nothing else
bool check(vector<int>& nums) {
    int count_wrongs = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count_wrongs++;
            if (count_wrongs > 1) return false;
        }
    }
    
    return true;
}

int main(){
    int t;
    cin >>t;
    vector<int> inp(t);
    for(int i=0; i<t; i++){
        cin >> inp[i];
    }

    cout << check(inp);
}