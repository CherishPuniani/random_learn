#include<bits/stdc++.h>
using namespace std;

list<int> extract_digits(int n){
    list<int> nums;
    int x=9;
    while(n!=0){
        x = n%10;
        if(n!=0){
            nums.push_front(x);
        }
        n = n/10;
    }
    return nums;
}

int main() {
    int number;
    list<int> digits, rev_digits;
    cin >> number;
    digits = extract_digits(number);
    
    // rev_digits=digits;
    // rev_digits.reverse();

    int n=0;
    long long y=0;
    for (int digit : digits) {
        y = y+digit*pow(10,n);
        n++;
    }
    // cout<<y<<endl;

    // for (int digit : digits) {
    //     cout << digit << " ";
    // }

    // if (y > INT_MAX || y < INT_MIN) {
    //         return 0; // Return 0 if it exceeds the range
    //     }
    if(y==number){
        return true;
    }
    else{
        return false;
    }
    // return y;
}
