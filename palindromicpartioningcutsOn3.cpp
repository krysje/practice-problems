#include<bits/stdc++.h>
using namespace std;

int minPalindromicCut(string s){
    int n = s.length();

    bool dp[n][n];

    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            
            if(g == 0)
                dp[i][j] = true;
            
            else if(g == 1){
                if(s[i] == s[j])
                    dp[i][j] = true;
            }
            
            else{
                if(s[i] == s[j] && dp[i+1][j-1] == true)
                    dp[i][j] = true;

                else    
                    dp[i][j] = false;
            }
        }
    }

    int stg[n][n];

    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){

            if(g == 0)
                stg[i][j] = 0;
            
            else if(g == 1){
                if(s[i] == s[j])
                    stg[i][j] = 0;
                
                else
                    stg[i][j] = 1;
            }

            else{
                if(dp[i][j])
                    stg[i][j] = 0;

                else{ 
                    int min = INT_MAX;
                    for(int k = 0; k < j; k++){
                        int left = stg[i][k];
                        int right = stg[k+1][j];

                        if(left + right + 1 < min)
                            min = left + right + 1;
                    }
                    stg[i][j] = min;
                }

            }
        }
    }

    return stg[0][n-1];

}

int main(){
    string s;   cin>>s;

    cout << minPalindromicCut(s);

    return 0;
}