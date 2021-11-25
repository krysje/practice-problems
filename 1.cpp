// Count of unique pairs (i, j) in an array such that sum of A[i] and reverse of A[j] is equal to sum of reverse of A[i] and A[j]
// A[i] + rev(A[j]) = A[j] + rev(A[i])

// -- >  A[i] - rev(A[i]) = A[j] - rev(A[j])


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing

int reverse(int n){

    int temp = n, rev = 0, r;

    while(temp){

        r = temp % 10;
        rev = rev * 10 + r;
        temp /= 10;
    }

    return rev;
}

void countPairs(int A[], int N){

    unordered_map <int, int> ul;
    int pairs = 0;


    for0(i, N){

        int val = A[i] - reverse(A[i]);
        pairs = pairs + ul[val];

       // cout<<pairs<<endl;

        ul[val]++;

    }

    for(auto x: ul){
            cout<<x.first<<" - >> "<<x.second<<endl;
        }


    cout<<pairs;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n];

    for0(i, n){
        cin>>arr[i];
    }

    countPairs(arr, n);
    
}