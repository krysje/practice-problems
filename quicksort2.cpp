#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l, j = r;
        
        do{
            while(arr[i] <= pivot)
                i++;
                
            while(arr[j] > pivot)
                j--;
            
            if(i < j)
                swap(arr[i], arr[j]);
                
        } while(i < j);
        
        swap(arr[l], arr[j]);
        return j;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;  cin>>n;
    int A[n]; 

    for(int i = 0; i < n; i++)
        cin>>A[i];

    quickSort(A, 0, n);

    for(int i : A)
        cout<<i<<" ";
}