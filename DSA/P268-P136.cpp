#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor_result = 0;

    for (int i = 0; i < n; i++) {
        xor_result ^= nums[i];  // XOR the current array element
        xor_result ^= i;        // XOR the current index
    }

    xor_result ^= n;  // XOR the last number in the range (n)
    return xor_result;
}

int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_result = 0;

        for (int i = 0; i < n; i++) {
            xor_result ^= nums[i];  
        }


        return xor_result;
        }