#include <bits/stdc++.h>
using namespace std;

bool checkarr(vector<int> pfr, vector<int> sfr){
        if(pfr == sfr)
            return true;
            
        for(int i = 0; i < 26; i++){
            if(pfr[i] > 0 && sfr[i] == 0)
                return false;
        }
            return true;
    }
    
string smallestWindow (string s, string p){
    vector<int> pfr(26, 0);
    vector<int> sfr(26, 0);
    int n = s.length();
    
    for(auto x : p)
        pfr[x - 'a']++; 
        
    int i = 0, j = 0;
    
    while(j < n){
        sfr[s[j] - 'a']++;
        
        if(checkarr(pfr, sfr) == false)
            j++;
        
        if(checkarr(pfr, sfr) == true){
            while(checkarr(pfr, sfr)){
                sfr[i]--;
                i++;
            }
             //   i++;
                break;
        }
    }

    return s.substr(i, j-i+1);
}

int main(){

    string s = "zoomlazapzo";
    string p = "oza";

    cout << smallestWindow(s, p) << endl;

    return 0;
}