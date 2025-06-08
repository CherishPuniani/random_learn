#include<bits/stdc++.h>
using namespace std;

// Easier to understand lol
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> tria;

    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);  
        for (int j = 1; j < i; j++) {
            row[j] = tria[i - 1][j - 1] + tria[i - 1][j]; 
        }
        tria.push_back(row);
    }

    return tria;
}

// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> tria;

//     for(int i=0; i<numRows; i++){
//         int x = 1;
//         tria[i].push_back(x);
//         for(int j = 1; j<numRows; j++){
//             x *= (numRows-1);
//             x /= j;
//             tria[i].push_back(x);
//         }
//     }

//     return tria;
// }