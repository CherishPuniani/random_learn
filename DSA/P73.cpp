#include<bits/stdc++.h>
using namespace std; 

void setZeroes(vector<vector<int>>& matrix) {
    int col = matrix[0].size();
    int row = matrix.size();
    int col0 = -1;
    for(int i=0; i<row; i++){
        for(int j = 0; j<col; j++){
            if (matrix[i][j] == 0){
                if(j==0){
                    col0 = 0;
                    matrix[i][0] = 0;
                }
                else{
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for(int i=row-1; i>=0; i--){
        for(int j = col-1; j>=0; j--){
        if(j==0){
            if(col0 == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
            else if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
}


// int main(){
//     vector<vector<int>> mtrx = {{1,1,1},{1,0,1},{1,1,1},{1,1,1}};
//     cout << mtrx.size();

// }