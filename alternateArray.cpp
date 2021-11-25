#include <bits/stdc++.h>
using namespace std;

void rearrange(int a[], int n){

    int i = 0;
    int j = n-1;

    while(i <= j){
        if(a[i] < 0 and a[j] > 0){
            swap(a[i], a[j]);
            i++; j--;
        }

        else if(a[i] > 0 and a[j] < 0){
            i++; j--;
        }

        else if(a[i] > 0)
            i++;
        
        else
            j--;
    }
        cout<<i<<" "<<j<<endl;
    // if(i == 0 or i == n){
    //     return;
    // }
        

    // else{
    //     int k = 0;
    //     while(k < n and i < n){
    //         swap(a[k], a[i]);
    //         i++;
    //         k += 2;
    //     }
    // }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
     return 0;
}