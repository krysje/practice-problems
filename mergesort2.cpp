#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int t1[n1], t2[n2];

    for(int i = 0; i < n1; i++)
        t1[i] = arr[l+i];
    for(int j = 0; j < n2; j++)
        t2[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;   

    while(i < n1 && j < n2){
        if(t1[i] <= t2[j])
            arr[k++] = t1[i++];
        
        else    
            arr[k++] = t2[j++];        
    }

        while(i < n1)
            arr[k++] = t1[i++];
        
        while(j < n2)
            arr[k++] = t2[j++];
    
}

void mergeSort(int arr[], int l, int r){
    if(l >= r)
        return;

    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;  cin>>n;
    int A[n]; 

    for(int i = 0; i < n; i++)
        cin>>A[i];

    mergeSort(A, 0, n);

    for(int i : A)
        cout<<i<<" ";
} 