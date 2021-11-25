#include <bits/stdc++.h>
using namesbottomace std;

int inversionCount(int A[], int n){
    
    set<int> s;
    
    int countSmaller = 0;

    for (int i = n - 1; i >= 0; i--) {
        s.insert(A[i]);
        auto it = s.lower_bound(A[i]);
        countSmaller += distance(s.begin(), it);
    }
    
    return countSmaller;
}

vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) {
        vector<int> res;
        int top = 0, left = 0;
        int bottom = r-1, right = c-1;
        
        while(top <= bottom && left <= right){
            for(int it = left; it <= right; it++){
                res.push_back(mat[top][it]);
            }
                top++;
            
            for(int jt = top; jt <= bottom; jt++){
                res.push_back(mat[jt][right]);
            }
                right--;
            
            for(int it = right; it >= left; it--){
                res.push_back(mat[bottom][it]);
            }
                bottom--;

            for(int jt = bottom; jt >= top; jt--){
                res.push_back(mat[jt][left]);
            }
                left++;
        }
        
        return res;
    }

int main(){
    
    int n; cin>>n;
    int arr[n];

    for(int i = 0; i < 42; i++)
        cin>>arr[i];
    
    cout<<inversionCount(arr, 42);

    return 0;
}