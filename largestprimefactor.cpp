#include <bits/stdc++.h>
using namespace std;

long long int largestPrimeFactor(int n){
        int ans = 1;
    
        for(int i = 2; i*i <= n; i++){
            while(n % i == 0){
                ans = i;
                n = n/i;
                cout<<ans<<" "<<n<<endl;
            }
        }
        
        if(n > 1)
            ans = n;
      
        return ans;
}


int main(){

    cout<<largestPrimeFactor(64);

    return 0;
}