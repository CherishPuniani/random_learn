#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mx) {
    int row = mx.size();
    int col = mx[0].size();
    vector<int> v;
    int top = 0, bottom = row-1, right = col-1, left = 0;

    while(top<=bottom && left <=right){
        for(int j = left; j <= right; j++){
            v.push_back(mx[top][j]);
        }
        top++;
        for(int i = top; i <=bottom; i++){
            v.push_back(mx[i][right]);
        }
        right--;
        
        if(top<=bottom){
            for(int j = right; j >= left; j--){
                v.push_back(mx[bottom][j]);
            }
            bottom--;
        }
        
        if(left<=right){
            for(int i = bottom; i >= top; i--){
                v.push_back(mx[i][left]);
            }
            left++;
        }
    }
    return v;

}