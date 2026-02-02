#include<bits/stdc++.h>
using namespace std;


void print_name(int i,int n){
    if(i>n) return;
    cout << "CP" << endl;
    print_name(i+1,n);
}

void func_2(int i, int n){  
    if(i>n) return;
    cout << i;
    func_2(i+1,n);
}

void func_3(int i, int n){  
    if(i<n) return;
    cout << i;
    func_3(i-1,n);
}

void func_4(int i, int n){  
    if(i<=1){
        cout << n;
        return;
    } 
    n = n+i;
    func_4(i-1,n);
}

bool is_palindrome(string s){
    string cs = "";
    for(auto ch:s){
        cout << ch << endl;
        if(isalnum(ch)) cs +=ch;
    }
    cout << cs.length() << endl;
    transform(cs.begin(),cs.end(),cs.begin(), ::tolower);
    cout << cs << endl;
    int len = cs.length();
    for(int i=0; i<len/2; i++){
        if(cs[i]!=cs[len-i-1]) return false;
    }
    return true;
}

int main(){
    string i;
    cin >> i;
    bool ans = is_palindrome(i);
    cout  << ans;
    return 0;
}