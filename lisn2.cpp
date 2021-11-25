#include<iostream>
#include<stdio.h>
#include<cstring>
#include<limits.h>

using namespace std;

int dp[500];

int solve(int a[], int n){
    memset(dp, 0, sizeof(dp));
    
    int overallmax = 0;
    
    for(int i = 0; i < n; i++){
        int maxm = 0;

        for(int j = 0; j < i; j++){
            if(a[i] > a[j] && dp[j] > maxm){
                    maxm = dp[j];
        }
            dp[i] = maxm + 1;

            if(dp[i] > overallmax)
                overallmax = dp[i];
        }
    }

    return overallmax;
}

int main(){
    
   int n; cin>>n;

    int A[n];
    
    for(int i = 0; i < n; i++)
        cin>>A[i];


    cout<< solve(A, n) <<"\n";

}