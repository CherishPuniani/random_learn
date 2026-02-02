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

void insertion_sort(vector<int>& v, int n){
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

void merge(vector<int> &a,int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right =  mid+1;

    while(left<=mid && right <= high){
        if(a[left]>=a[right]) {
            temp.push_back(a[right]);
            right++;
        }
        else{
            temp.push_back(a[left]);
            left++;
        }
    }
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }

    for(int i=low; i<=high; i++){
        a[i]= temp[i-low];
    }
}
void merge_sort(vector<int> &v, int low, int high){
    int mid = (low+high)/2;
    if(high<=low) return;

    merge_sort(v,low,mid);
    merge_sort(v,mid+1,high);

    merge(v, low,mid,high);
}

int qs_func(vector<int> &v,int low, int high){
    int pivot=v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot && i<high){
            i++;
        }
        while(v[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[low],v[j]);
    
    return j;
}
void quick_sort(vector<int> &v,int low, int high){
    if(low<high){
        int part_i = qs_func(v,low,high);
        quick_sort(v,low,part_i-1);
        quick_sort(v,part_i+1,high);
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    quick_sort(v,0,n-1);

    for(int i=0; i<n;i++){
        cout << v[i]<< " ";
    }
}