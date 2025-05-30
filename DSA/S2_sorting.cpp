#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> arr, int n){
    for(int i=0; i<n;i++){
        // int min = arr[i];
        int min_at = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_at]){
                // min =arr[j];
                min_at = j;
                }
        }
        int temp = arr[i];
        arr[i]=arr[min_at];
        arr[min_at]=temp;
    }

    for(int k=0; k<n; k++){
        cout << arr[k]<< " ";
    }

}

void bubble_sort(vector<int> v, int n){
    for(int k=n-1; k>=0;k--){
        int didSwap = 0;
       for(int j =0; j<=k-1; j++){
            if(v[j]> v[j+1]){
                int temp = v[j+1];
                v[j+1]= v[j];
                v[j]=temp;
                didSwap=1;
            }
            
        }
        if(didSwap==0){
            break;
        }
    }

    for(int p=0; p<n; p++){
        cout << v[p]<< " ";
    }
}

void insertion_sort(vector<int> v, int n){
    for(int i=0; i<n;i++){
        int j=i;
        while(j>0 && v[j-1]>v[j]){
            int temp = v[j-1];
            v[j-1] = v[j];
            v[j] = temp;

            j--;
            // cout <<"DDD"<<endl;
        }
    }

    for(int p=0; p<n; p++){
        cout << v[p]<< " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    insertion_sort(v,n);
}