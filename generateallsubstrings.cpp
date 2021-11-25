// #include<bits/stdc++.h>
// using namespace std;
 
// void subString(string s, int n){
//     for(int i = 0; i < n; i++){
//         for(int l = 1; l <= n-i; l++)
//             cout<< s.substr(i, l)<<endl;
//     }
// }
 
// int main(){
//     string s = "abcd";
//     subString(s,s.length());
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

// Generate a map of all character occurances of the 2nd string, i.e char and its count.
// The window size becomes the length of 2nd string, as the anangrams wil also be of this length, amd another variable count denotes the distinct characters left in a sliding window.
// In a window if the current character is present in map, then decrease its count, and if the count becomes 0, decrease the 'count' variable.
// If the window size is lesser than k just move forward the window
// When the window is hit ->
// If the count is 0, it means all the characters needed for its anagram is here in it, therefore increase your answer
// To remove the last part (arr[i] part) so that the window can be shifted ->
// If the s[i] is present in map then increase its count and if it changes from 0->1 then increase the 'count' variable

int solve(string s, string pat){

    unordered_map<char, int> m;

    for(auto it : pat) 
        m[it]++;

    int k = pat.length();
    int count = m.size();
    
    int i=0, j=0;
    int ans=0;
    
    while(j<s.length()){
    
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }
        
        if((j-i+1)<k) j++;
        
        else if((j-i+1)==k){

            if(count==0) ans++;

            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]==1) count++;
            }

            i++;
            j++;
        }
    }
    return ans;
}

// TC : O(n)
// SC : O(distinctChars(pat))


int main(){
    
    string s = "forxxorfxdofr";
    string pat = "for";

    int ans = solve(s, pat);
    cout << ans << endl; 

    return 0;
}