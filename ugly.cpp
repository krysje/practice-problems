#include<bits/stdc++.h>
using namespace std;	
    
    bool ugly(int n){
	    
	   int rr = n;
	   
	   while(rr % 2 == 0)
	    rr = rr/2;
	    
	   while(rr % 3 == 0)
	    rr = rr/3;
	     
	    while(rr % 5 == 0)
	     rr = rr/5;
	   
	    if(rr == 1)
	        return true;
	    else
	        return false;
	}
	
	int getNthUglyNo(int n) {
 
	    int dp[n+1] = {0};
	    
	    dp[0] = 1;
	    dp[1] = 2;
	    
	    
	    for(int i = 2; i <= n; i++){
	        for(int j = 1; j <= n; j++){
                
	            if(ugly(dp[i-1] + j)){
	                dp[i] = dp[i-1] + j;
	                j = 0;
	            }
	        }
	    }
	            
	    return dp[n];
	}

    int main(){
        int n; cin>>n;

        int ans = getNthUglyNo(n);

        cout<<ans<<endl;
    }