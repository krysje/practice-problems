#include <bits/stdc++.h>
using namespace std;

int getMedian(int arr1[], int n, int arr2[], int m){
    
    int i = n-1;
    int j = 0;

    while(i >= 0 and j < m){
        if(arr1[i] > arr2[j])
            swap(arr1[i--], arr2[j++]);
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+m);

    int k = ceil((m + n) / 2);
    int ts = m+n;
    int median = 0;

    if(ts % 2 != 0){
        if(k < n)
            median = arr1[k];
        else    
            median = arr2[k - n];
    }

    else{
        if(k < n){
            median = (arr1[k] + arr1[k - 1])/2;
        }
        else
            median = (arr2[k - n] + arr2[k -n- 1])/2;
    }

    return median;    

}


int main()
{
        int ar1[] = { -5, 3, 6, 12, 15 };
        int ar2[] = { -12, -10, -6, -3, 4, 10 };
 
    int n = sizeof(ar1)/sizeof(ar1[0]);
    int m = sizeof(ar2)/sizeof(ar2[0]);

    cout<<getMedian(ar1, n, ar2, m);
    return 0;
}
 