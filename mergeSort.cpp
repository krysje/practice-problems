// xx Krysje xx

// “Fake people have an image to maintain. Real people just don’t care.” - Hachiman Hikigaya

#include <bits/stdc++.h> 
using namespace std;

#define ll long long int
#define ld long double

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

// <3 Senjougahara Hitagi <3

//short hand for usual tokens
#define pb push_back
#define pp pop_back
#define fi first
#define se second


void Merge(int A[], int l, int mid, int h){

    int i=l, j = mid+1, k = l;
    int B[100];

    while (i<=mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        
        else    
            B[k++] = A[j++];
    }

    for(; i<=mid; i++)
        B[k++] = A[i];

    for(; j<=h; j++)
        B[k++] = A[j];  

    for(int i = l; i<=h; i++)
        A[i] = B[i];
   
}
      

void IMergeSort(int A[], int n){
    int p, l , h, mid, i;

    for(p = 2; p <= n; p = p*2){
        for(int i = 0; i+p-1 <=n; i++){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
    }
    if(p/2 < n){
        Merge(A, 0, p/2-1, n);
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

int n;  cin>>n;
int A[n]; 

for0(i, n)
    cin>>A[i];

IMergeSort(A, n);

for(int i : A)
    cout<<i<<" ";


}