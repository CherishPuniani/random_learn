#include<bits/stdc++.h>
using namespace std;

int longestSubarraywithsumK(vector<int> a, long long k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i=0; i<a.size(); i++){
        sum +=a[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // To cover the edge case of 0s in between and also this is the best solution if there are negatives present in your vector
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
        
    }
    return maxLen;
}

// This is the optimal solution for non negative elements present in the array
int longestSubarraywithsumK(vector<int> a, long long k){
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while(right < n){
        while(left<= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n) sum += a[right];
    }
    return maxLen;
}


int main(){
    int t;
    cin >>t;
    vector<int> inp(t);
    for(int i=0; i<t; i++){
        cin >> inp[i];
    }

    // moveZeroes(inp);

    for(int i = 0; i < inp.size(); i++) {
        cout << inp[i] << " ";
    }
    cout << endl;

}