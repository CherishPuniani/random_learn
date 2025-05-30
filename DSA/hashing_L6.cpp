#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void print_freq(const vector<int>& v) {
    unordered_map<int, int> mpp;
    for (int num : v) {
        mpp[num]++;
    }

    for (auto x : mpp) {
        cout << x.first << " -> " << x.second << endl;
    }
}

int main() {
    int t;
    cin >> t;

    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    print_freq(v);
    return 0;
}