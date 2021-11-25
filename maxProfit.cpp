#include <bits/stdc++.h>
using namespace std;

void maxProfit(int arr[], int n){
    int profit = 0;

    for(int i = 1; i<n; i++){
        int sub = arr[i] - arr[i-1];

        if(sub > 0)
            profit += sub;        
    }

    cout<<profit<<endl;

}

int main(){

    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 6;

    maxProfit(price, n);
}