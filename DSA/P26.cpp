#include<bits/stdc++.h>
using namespace std;

// TRY 1
// int removeDuplicates(vector<int>& nums) {
//     vector<int> dup_nums = nums; 
//     int rem_count = 0;
//     for(int i=0; i<dup_nums.size()-1; i++){
//         if(dup_nums[i]==dup_nums[i+1]){
//             nums.erase(nums.begin()+i-rem_count);
//             rem_count++;
//         }
//     }
//     return nums.size();
// }

// Using Sets
// TC = NlogN + N
// SC = O(N)
// int removeDuplicates(vector<int>& nums) {
//     set<int> my_set;
//     int i=0;
//     for(int j=0; j<nums.size(); j++){
//         my_set.insert(nums[j]);
//     }

//     for(auto it : my_set){
//         nums[i] = it;
//         i++;
//     }

//     return my_set.size();
// }


int removeDuplicates(vector<int>& nums) {
    int i=0;
    for(int j=0;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            nums[i+1] = nums[j];
            i++;
        }
    }

    return i+1;
}



int main(){
    int t;
    cin >>t;
    vector<int> inp(t);
    for(int i=0; i<t; i++){
        cin >> inp[i];
    }

    cout << removeDuplicates(inp);
}