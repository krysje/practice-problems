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

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h;

    do{
        do{i++;} while(A[i] <= pivot);
        do{j--;} while(A[j] > pivot);

        if(i < j)
            swap(&A[i], &A[j]);
    }
    while(i<j);

    swap(&A[l], &A[j]);

 return j;

}

void quickSort(int A[], int l, int h){

    if(l < h){
        int pi = partition(A, l, h);
        quickSort(A, l , pi);
        quickSort(A, pi+1, h);
    }
}



signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

int n;  cin>>n;
int A[n]; 

for0(i, n)
    cin>>A[i];

quickSort(A, 0, n);

for(int i : A)
    cout<<i<<" ";

}
