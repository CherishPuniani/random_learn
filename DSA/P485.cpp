#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 1){
                count = 0;
            }
            else{
                count++;
                if(count>maxi){
                    maxi=count;
                }
            }
        }

        return maxi;
    }

int main(){
    int t;
    cin >>t;
    vector<int> inp(t);
    for(int i=0; i<t; i++){
        cin >> inp[i];
    }

    int maxi = findMaxConsecutiveOnes(inp);

    cout << maxi;
    // for(int i = 0; i < inp.size(); i++) {
    //     cout << inp[i] << " ";
    // }
    // cout << endl;

}