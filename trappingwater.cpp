#include <bits/stdc++.h>
using namespace std;


    int trappingWater(int arr[], int n){
        int water = 0;
        
     vector<pair<int, int>> vc;
     
        for(int j = 1; j < n -1; j++){

            int l = j-1, r = j+1;
            int maxL = 0, maxR = 0;
            
            while(l >= 0)
                maxL = max(maxL, arr[l--]);
            
            
            while(r < n)
                maxR = max(maxR, arr[r++]);
            
          vc.push_back(make_pair(maxL, maxR));
        }

        
        for(int i = 1; i < n-1; i++){
            int j = i-1;
            int smallestpillar = min(vc[j].first, vc[j].second);

            if(smallestpillar - arr[i] <= 0)
                water += 0;
            else
            water += smallestpillar - arr[i]; 
        } 
        
        return water;
    }

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; cin>>n;
        int a[n];

        for(int i = 0; i < n; i++)
            cin>>a[i];

        cout<<trappingWater(a,n)<<endl;

    }
}