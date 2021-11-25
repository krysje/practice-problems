#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int solve(int a[], int n){
    vector<int> v;

    v.push_back(a[0]);

    for(int i = 1; i < n; i++){

        if(v.back() < a[i])
            v.push_back(a[i]);

        else{
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
        }

    }

    return v.size();
}


int main(){
    int n; cin>>n;
    int A[n];

    for(int i = 0; i < n; i++)
        cin>>A[i];

    cout<< solve(A, n) << "\n";

    return 0;
}