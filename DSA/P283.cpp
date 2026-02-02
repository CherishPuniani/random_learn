#include<bits/stdc++.h>
using namespace std;

// void moveZeroes(vector<int>& nums) {
//     int n = nums.size();
//     if(n==0) return;
//     int i = 0;
//     int j = n-1;
//     while(i<=j){
//         if(nums[i]==0 && nums[j]!=0){
//             int temp = nums[i];
//             nums[i] = nums[j];
//             nums[j] = temp;
//             i++;
//             j--;
//         }
//         else if(nums[i]!=0){
//             i++;
//         }
//     }
// }

void moveZeroes(vector<int>& nums) {
    int j = -1;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }

    if(j==-1) return;

    for(int i=j+1; i<n; i++){
        if(nums[i] !=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}


int main(){
    int t;
    cin >>t;
    vector<int> inp(t);
    for(int i=0; i<t; i++){
        cin >> inp[i];
    }

    moveZeroes(inp);

    for(int i = 0; i < inp.size(); i++) {
        cout << inp[i] << " ";
    }
    cout << endl;

}