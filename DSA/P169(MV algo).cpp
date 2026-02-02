// Moore's Voting Algo
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v){
    int cnt = 0;
    int el;
    for(int i=0; i<v.size(); i++){
        if(cnt ==0){
            cnt=1;
            el = v[i];
        }
        else if(v[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    // This check is only to be done if there is a chance that no majority exists
    int num;
    for(int j=0; j<v.size(); j++){
        if(v[j] == el) num++;
    }
    if(num >v.size()/2) return el;

    return -1;
}